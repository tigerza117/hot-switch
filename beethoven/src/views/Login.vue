<template>
  <div class="container m-auto login rounded">
    <div class="logo">
      <img alt="logo" class="mx-auto" src="../assets/logo.png" />
    </div>
    <div>
      <section id="firebaseui-auth-container"></section>
    </div>
  </div>
</template>

<script>
import firebase from 'firebase';
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
.login {
  background: white;
  width: auto;
}
.logo {
  height: 200px;
}
.logo img {
  height: 100%;
}
</style>
