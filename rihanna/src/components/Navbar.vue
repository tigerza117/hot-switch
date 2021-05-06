<template>
  <div class="navbar">
    <div class="px-14 py-6 md:flex justify-between container mx-auto">
      <div class="flex w-full justify-between">
        <router-link to="/">ComPro // MiniProject</router-link>
        <div class="md:hidden">
          <i class="fas fa-bars" @click="show = !show" />
        </div>
      </div>
      <div class="space-x-14 md:flex my-8 md:m-0" v-if="collapse">
        <router-link to="/">Home</router-link>
        <a href="https://github.com/tigerza117/hot-switch">Github</a>
        <router-link to="/document">Document</router-link>
        <router-link to="/team">Team</router-link>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'Navbar',
  data() {
    return {
      show: false,
    };
  },
  computed: {
    collapse() {
      return window.innerWidth >= 768 || (this.show && window.innerWidth < 768);
    },
  },
};
</script>

<style scoped></style>
