<template>
  <div class="navbar">
    <div class="px-8 py-6 md:flex justify-between container mx-auto">
      <div class="flex w-full justify-between">
        <router-link class="py-2" to="/">ComPro // MiniProject</router-link>
        <div class="md:hidden">
          <i class="fas fa-bars" @click="show = !show" />
        </div>
      </div>
      <div class="md:space-x-14 md:flex my-8 md:m-0" v-if="collapse">
        <router-link class="block py-2" to="/">Home</router-link>
        <a class="block py-2" href="https://github.com/tigerza117/hot-switch">
          Github
        </a>
        <router-link class="block py-2" to="/document">Document</router-link>
        <router-link class="block py-2" to="/team">Team</router-link>
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
