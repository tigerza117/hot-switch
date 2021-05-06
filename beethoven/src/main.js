import Vue from 'vue';
import App from './App.vue';
import firebase from 'firebase/app';
import router from './router';

import VueRouter from 'vue-router';

Vue.use(VueRouter);

const firebaseConfig = {
  apiKey: 'AIzaSyCmbEnk_MsJT37TV5EbcSg_TnT37WFg3Kc',
  authDomain: 'hot-switch.firebaseapp.com',
  projectId: 'hot-switch',
  storageBucket: 'hot-switch.appspot.com',
  messagingSenderId: '33501097320',
  appId: '1:33501097320:web:b766ac58fc29ef4b4cfadd',
};
firebase.initializeApp(firebaseConfig);

Vue.config.productionTip = false;

new Vue({
  router,
  render: (h) => h(App),
}).$mount('#app');
