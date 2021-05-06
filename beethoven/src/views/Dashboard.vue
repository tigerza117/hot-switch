<template>
  <div class="flex flex-col h-screen">
    <div>
      <div
        v-if="user"
        class="title text-xl lg:text-4xl lg:text-center px-4 font-bold py-16 text-white relative"
      >
        <div>Welcome back {{ user.displayName }}</div>
        <img
          @click="logout"
          alt="logout"
          class="logout absolute inset-y-0 px-8 right-0 my-auto"
          src="../assets/logout.svg"
        />
      </div>
      <div class="w-full tab">
        <div class="container mx-auto flex space-x-4">
          <div
            class="bg-white rounded-t p-4 px-6 cursor-pointer"
            v-for="(item, index) in devices"
            v-bind:key="index"
            @click="select(item)"
            :class="{
              unselect: device && item.deviceId !== device.deviceId,
            }"
          >
            {{ item.name }}
          </div>
          <div class="bg-white rounded-t p-4 px-6" @click="add">+</div>
        </div>
      </div>
    </div>
    <div class="flex-grow flex mx-auto container">
      <div v-if="device" class="w-full m-auto">
        <div class="text-center text-4xl font-bold mt-16 xl:-mt-16">
          {{ device.name.toUpperCase() }}
        </div>
        <div
          class="team w-full grid grid-cols-1 sm:grid-cols-2 xl:grid-cols-4 mb-16"
        >
          <SwitchBtn
            v-bind="sw"
            v-for="(sw, index) in switches"
            v-bind:key="index"
            @call="doPublish(index)"
          />
        </div>
      </div>
    </div>
    <Footer />
  </div>
</template>

<script>
import mqtt from 'mqtt';
import firebase from 'firebase';
import SwitchBtn from './SwitchBtn';
import swal from 'sweetalert2';
import Footer from '../components/Footer';

export default {
  name: 'Dashboard',
  components: { Footer, SwitchBtn },
  data() {
    return {
      devices: [],
      switches: [],
      user: null,
      device: null,
      connection: {
        host: 'broker.mqttdashboard.com',
        port: 8000,
        endpoint: '/mqtt',
        clean: true,
        connectTimeout: 4000,
        reconnectPeriod: 4000,
        clientId: 'clientId-' + Math.random().toString(36).substring(7),
      },
      unsubscribe: null,
    };
  },
  mounted() {
    this.createConnection();
  },
  beforeDestroy() {
    this.destroyConnection();
  },
  beforeCreate() {
    firebase.auth().onAuthStateChanged(async (user) => {
      if (user) {
        this.user = user;
        const db = firebase.firestore();
        let device_attend = await db
          .collection('user_devices')
          .where('userId', '==', user.uid)
          .get();
        this.devices = device_attend.docs.map((doc) => doc.data());
        if (this.devices.length > 0) {
          this.select(this.devices[0]);
        }
      }
    });
  },
  watch: {
    devices(val) {
      if (!this.device) {
        this.select(val[0]);
      }
    },
  },
  methods: {
    logout() {
      firebase
        .auth()
        .signOut()
        .then(() => {
          this.$router.push('/login');
        });
    },
    createConnection() {
      const { host, port, endpoint, ...options } = this.connection;
      const connectUrl = `ws://${host}:${port}${endpoint}`;
      try {
        this.client = mqtt.connect(connectUrl, options);
      } catch (error) {
        console.log('mqtt.connect error', error);
      }
      this.client.on('connect', () => {
        console.log('Connection succeeded!');
      });
      this.client.on('error', (error) => {
        console.log('Connection failed', error);
      });
    },
    doPublish(index) {
      let sw = this.switches[index];
      let payload = {
        action: sw.state ? 'off' : 'on',
        port: sw.port,
      };
      this.switches[index].state = !this.switches[index].state;
      const db = firebase.firestore();
      db.collection('devices')
        .doc(this.device.deviceId)
        .update({
          switches: this.switches.map((sw) => sw.state),
        })
        .then(() => {
          console.log('Document successfully updated!');
          this.client.publish(
            this.device.channel,
            JSON.stringify(payload),
            3,
            (error) => {
              if (error) {
                console.log('Publish error', error);
              }
              console.log('Publish!');
            }
          );
        })
        .catch((error) => {
          console.error('Error updating document: ', error);
        });
    },
    destroyConnection() {
      if (this.client.connected) {
        try {
          this.client.end();
          this.client = {
            connected: false,
          };
          console.log('Successfully disconnected!');
        } catch (error) {
          console.log('Disconnect failed', error.toString());
        }
      }
    },
    select(data) {
      if (this.device && data.deviceId === this.device.deviceId) return;
      console.log('select');
      this.unsubscribe && this.unsubscribe();
      const db = firebase.firestore();
      this.unsubscribe = db
        .collection('devices')
        .doc(data.deviceId)
        .onSnapshot((doc) => {
          this.switches = doc.data().switches.map((sw, index) => {
            return { name: `Light Bulb ${index + 1}`, port: index, state: sw };
          });
          this.device = { ...data, channel: doc.data().channel };
        });
    },
    async add() {
      const { value: id } = await swal.fire({
        title: 'Enter your deviceID',
        input: 'password',
        inputLabel: 'DeviceID',
        inputPlaceholder: 'Enter your deviceID',
      });
      const { value: name } = await swal.fire({
        title: 'Enter your device name',
        input: 'text',
        inputLabel: 'Device name',
        inputPlaceholder: 'Enter your device name',
      });

      if (id && name) {
        const db = firebase.firestore();
        const device = (await db.collection('devices').doc(id).get()).data();
        if (device) {
          let device_attend = await db
            .collection('user_devices')
            .where('userId', '==', this.user.uid)
            .where('deviceId', '==', id)
            .get();
          if (!device_attend.docs.length) {
            db.collection('user_devices')
              .add({
                userId: this.user.uid,
                deviceId: id,
                name: name,
              })
              .then(() => {
                swal.fire(
                  'Success!',
                  'Success add device to you account!',
                  'success'
                );
                this.devices.push({
                  userId: this.user.uid,
                  deviceId: id,
                  name: name,
                });
              });
          } else {
            await swal.fire('Fail!', 'You already add device!', 'error');
          }
        } else {
          await swal.fire('Fail!', 'Device not found!', 'error');
        }
      }
    },
  },
};
</script>

<style scoped>
.title {
  background: #005aae;
}
.tab {
  background: #005aae;
}
.unselect {
  background: #ecf0f1;
}
</style>
