import VueRouter from 'vue-router';
import Dashboard from '../views/Dashboard';
import Login from '../views/Login';
import Page404 from '../views/Page404';

const router = new VueRouter({
  mode: 'history',
  routes: [
    {
      path: '/dashboard',
      component: Dashboard,
      meta: {
        auth: true,
      },
    },
    {
      path: '/login',
      component: Login,
      meta: {
        guest: true,
      },
    },
    {
      path: '*',
      component: Page404,
    },
  ],
});

import firebase from 'firebase';

router.beforeEach((to, from, next) => {
  if (to.matched.some((record) => record.meta.auth)) {
    firebase.auth().onAuthStateChanged((user) => {
      if (user) {
        next();
      } else {
        next({
          path: '/login',
        });
      }
    });
  } else if (to.matched.some((record) => record.meta.guest)) {
    firebase.auth().onAuthStateChanged((user) => {
      if (user) {
        next({
          path: '/dashboard',
        });
      } else {
        next();
      }
    });
  } else {
    next();
  }
});

export default router;
