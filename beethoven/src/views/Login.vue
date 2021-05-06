<template>
  <div class="app flex">
    <div class="container m-auto w-auto bg-white rounded">
      <div class="logo">
        <img alt="logo" class="mx-auto h-full" src="../assets/logo.png" />
      </div>
      <div>
        <section id="firebaseui-auth-container"></section>
      </div>
    </div>
  </div>
</template>

<script>
import firebase from 'firebase/app';
import * as firebaseui from 'firebaseui';
import 'firebaseui/dist/firebaseui.css';
export default {
  name: 'Login',
  mounted() {
    let ui = new firebaseui.auth.AuthUI(firebase.auth());
    if (ui) {
      let uiConfig = {
        signInSuccessUrl: '/',
        signInOptions: [firebase.auth.GoogleAuthProvider.PROVIDER_ID],
        tosUrl: '<your-tos-url>',
        // Privacy policy url/callback.
        privacyPolicyUrl: function () {
          window.location.assign('<your-privacy-policy-url>');
        },
        signInFlow: 'popup',
      };
      ui.start('#firebaseui-auth-container', uiConfig);
    }
  },
};
</script>

<style scoped>
.app {
  background: #ecf0f1;
  height: 100vh;
}
.logo {
  height: 200px;
}
</style>
