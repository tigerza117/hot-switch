<template>
  <div class="navbar">
    <div class="px-14 py-6 flex justify-between container mx-auto">
      <div>
        ComPro // MiniProject
      </div>
      <div>
        <div class="hidden md:flex space-x-14">
          <router-link to="/">Home</router-link>
          <a href="https://github.com/tigerza117/hot-switch">Github</a>
          <router-link to="/document">Document</router-link>
          <router-link to="/team">Team</router-link>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "Navbar"
}
</script>

<style scoped>

</style>
