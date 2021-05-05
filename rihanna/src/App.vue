<template>
  <div id="app" class="flex flex-col h-screen">
    <Navbar />
    <div class="flex-grow flex mx-auto container">
      <router-view />
    </div>
    <Footer />
  </div>
</template>

<script>
import Navbar from './components/Navbar';
import Footer from './components/Footer';
export default {
  name: 'App',
  components: {
    Footer,
    Navbar,
  },
};
</script>

<style>
body {
  font-family: 'Roboto Mono', monospace;
}
@media (min-width: 576px) {
  .container {
    max-width: 540px;
  }
}
@media (min-width: 768px) {
  .container {
    max-width: 720px;
  }
}

@media (min-width: 992px) {
  .container {
    max-width: 960px;
  }
}

@media (min-width: 1200px) {
  .container {
    max-width: 1440px;
  }
}
</style>
