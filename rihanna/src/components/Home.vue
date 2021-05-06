<template>
  <div class="home min-w-full md:flex my-auto p-8 space-y-16">
    <div class="w-full md:w-1/2 space-y-6">
      <div class="logo mx-auto md:mx-0">
        <img alt="logo" src="../assets/logo.png" />
      </div>
      <div
        class="title text-6xl font-bold text-center md:text-left md:text-7xl lg:text-8xl xl:text-9xl"
      >
        HOT SWITCH
      </div>
      <p class="description break-words lg:w-1/2">
        A new way to control your life. Power of controlling your electronic
        devices in your phone, anywhere, that have an internet.
      </p>
      <div
        class="links space-x-4 lg:space-x-2 flex justify-center md:justify-start"
      >
        <a
          class="flex github items-center space-x-2 rounded-2xl p-4 lg:p-2 md:border-4"
          href="https://github.com/tigerza117/hot-switch"
        >
          <img alt="github" src="../assets/github.svg" />
          <p class="hidden lg:inline">Github</p>
        </a>
        <router-link
          to="/document"
          class="flex document items-center space-x-2 rounded-2xl p-4 lg:p-2 md:border-4"
        >
          <img alt="document" src="../assets/document.svg" />
          <p class="hidden lg:inline">Document</p>
        </router-link>
        <a
          href="http://103.91.205.130"
          class="flex dashboard items-center space-x-2 rounded-2xl p-4 lg:p-2 md:border-4"
        >
          <img alt="dashboard" src="../assets/dashboard.svg" />
          <p class="hidden lg:inline">Dashboard</p>
        </a>
      </div>
    </div>
    <div class="w-full md:w-1/2">
      <div class="my-auto">
        <img alt="isometric" src="../assets/Isometric_Art.svg" />
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'Home',
};
</script>

<style scoped>
.home .logo {
  width: 100px;
}
.links .github {
  border-color: #7d2dff;
}
.links .document {
  border-color: black;
}
.links .dashboard {
  border-color: #2d9aff;
}
</style>
