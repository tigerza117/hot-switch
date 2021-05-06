<template>
  <div class="navbar">
    <div class="px-8 py-6 lg:flex justify-between container mx-auto">
      <div class="flex w-full justify-between">
        <router-link class="py-2" to="/">ComPro // MiniProject</router-link>
        <div class="lg:hidden">
          <i class="fas fa-bars" @click="show = !show" />
        </div>
      </div>
      <div class="lg:space-x-14 lg:flex my-4 lg:m-0" v-if="collapse">
        <router-link class="block py-2" to="/">Home</router-link>
        <a class="block py-2" href="https://github.com/tigerza117/hot-switch">
          Github
        </a>
        <router-link class="block py-2" to="/document">Document</router-link>
        <router-link class="block py-2" to="/team">Team</router-link>

        <a class="block py-2" href="http://103.91.205.130"> Dashboard </a>
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
      return window.innerWidth > 992 || (this.show && window.innerWidth <= 992);
    },
  },
};
</script>

<style scoped></style>
