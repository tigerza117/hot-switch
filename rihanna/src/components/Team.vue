<template>
  <div class="w-full">
    <div class="flex mx-auto w-72">
      <img alt="logo" src="../assets/logo.png" />
    </div>
    <div class="team w-full grid grid-cols-1 md:grid-cols-2 xl:grid-cols-4">
      <Avatar
        v-bind="person"
        v-for="(person, index) in teams"
        v-bind:key="index"
      />
    </div>
  </div>
</template>

<script>
const teams = [
  {
    name: 'Noppawan Pakisee',
    no: '63070092',
    position: 'Developer',
  },
  {
    name: 'Peerawit Kongkitkul',
    no: '63070126',
    position: 'Designer',
  },
  {
    name: 'Panuwat Kongchansawang',
    no: '63070135',
    position: 'Hardware',
  },
  {
    name: 'Santakorn Wongsiripa',
    no: '63070127',
    position: 'Writer',
  },
];
import Avatar from './Avatar';
export default {
  name: 'Team',
  components: { Avatar },
  data() {
    return {
      teams,
    };
  },
};
</script>

<style scoped></style>
