import VueRouter from 'vue-router';
import Home from '../components/Home';
import Document from '../components/Document';
import Team from '../components/Team';

const router = new VueRouter({
  mode: 'history',
  routes: [
    {
      path: '',
      component: Home,
      meta: {
        auth: true,
      },
    },
    {
      path: '/document',
      component: Document,
      meta: {
        guest: true,
      },
    },
    {
      path: '/team',
      component: Team,
    },
  ],
});

export default router;
