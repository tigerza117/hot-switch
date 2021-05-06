<template>
  <div class="w-full p-10 text-center" @click="$emit('call')">
    <div class="text-2xl font-semibold">
      {{ name }}
    </div>
    <div class="text-4xl font-bold">
      {{ state ? 'ON' : 'OFF' }}
    </div>
    <div class="mt-16">
      <img
        class="mx-auto rounded-full btn"
        :class="{ enable: state }"
        alt="btn"
        src="../assets/button.svg"
      />
    </div>
  </div>
</template>

<script>
export default {
  name: 'SwitchBtn',
  props: ['name', 'port', 'state'],
};
</script>

<style>
.btn {
  transition: all 0.3s;
  box-shadow: 0px 0px 100px -0px red;
}
.btn:hover {
  box-shadow: 0px 0px 50px -10px red;
}
.enable {
  box-shadow: 0px 0px 100px -0px green;
}
.enable:hover {
  box-shadow: 0px 0px 50px -10px green;
}
</style>
