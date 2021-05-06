<template>
  <div class="m-auto notfound">
    <lottie-animation path="lotties/404.json" />
  </div>
</template>

<script>
import LottieAnimation from 'lottie-vuejs/src/LottieAnimation.vue'; // import lottie-vuejs
export default {
  name: 'Page404',
  components: {
    LottieAnimation,
  },
};
</script>

<style scoped>
.notfound {
  width: 50vh;
}
</style>
