<template>
  <div class="home min-w-full md:flex my-auto p-8 space-y-16">
    <div class="w-full md:w-1/2 space-y-4">
      <div class="logo mx-auto md:mx-0">
        <img alt="logo" src="../assets/logo.png" />
      </div>
      <div
        class="title text-6xl font-bold text-center md:text-left xl:text-9xl"
      >
        HOT k
      </div>
      <p class="description break-words md:w-1/2">
        A new way to control your life. Power of controlling your electronic
        devices in your phone, anywhere, that have an internet.
      </p>
      <div class="links space-x-2 flex justify-center md:justify-start">
        <a class="flex github items-center space-x-2">
          <img alt="github" src="../assets/github.svg" />
          <p>Github</p>
        </a>
        <a class="flex document items-center space-x-2">
          <img alt="document" src="../assets/document.svg" />
          <p>Document</p>
        </a>
        <a class="flex dashboard items-center space-x-2">
          <img alt="dashboard" src="../assets/dashboard.svg" />
          <p>Dashboard</p>
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
.links > * {
  border-radius: 30px;
  padding: 5px 10px;
}
.links .github {
  border: 4px solid #7d2dff;
}
.links .document {
  border: 4px solid black;
}
.links .dashboard {
  border: 4px solid #2d9aff;
}
</style>
