<template>
  <div class="w-full p-8 text-center space-y-6">
    <p class="text-2xl font-bold">{{position}}</p>
    <div>
      <img class="rounded-full w-full h-full " alt="avatar" :src="require(`../assets/${no}.jpg`)"/></div>
    <div>
      <p class="text-xl font-semibold">{{ name }}</p>
      <p>{{ no }}</p>
    </div>
  </div>
</template>

<script>
export default {
  name: "Avatar",
  props: ['name', 'no', 'position'],
}
</script>

<style scoped>

</style>
