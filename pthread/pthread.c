#include <errno.h>
#include <pthread.h>

#define _m_lock __u.__vi[1]

int pthread_mutex_init(pthread_mutex_t *restrict m,
                       const pthread_mutexattr_t *restrict a) {
  *m = (pthread_mutex_t){0};
  return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *mutex) { return 0; }

int pthread_mutex_lock(pthread_mutex_t *m) { return pthread_mutex_trylock(m); }

int pthread_mutex_trylock(pthread_mutex_t *m) {
  if (m->_m_lock == EBUSY) {
    return EBUSY;
  } else {
    m->_m_lock = EBUSY;
    return 0;
  }
}

int pthread_mutex_unlock(pthread_mutex_t *m) {
  if (m->_m_lock == EBUSY) {
    m->_m_lock = 0;
    return 0;
  } else {
    return EDEADLK;
  }
}

int pthread_cond_init(pthread_cond_t *restrict c,
                      const pthread_condattr_t *restrict a) {
  return 0;
}

int pthread_cond_destroy(pthread_cond_t *c) { return 0; }

int pthread_cond_wait(pthread_cond_t *restrict c, pthread_mutex_t *restrict m) {
  return EINVAL;
}

int pthread_cond_broadcast(pthread_cond_t *c) { return 0; }

int pthread_cond_signal(pthread_cond_t *c) { return 0; }
