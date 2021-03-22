//如果某线程申请了读锁 其他线程可以申请读锁 不可以申请写锁
//如果某线程申请了写锁 其他线程不可以申请读锁 不可以申请写锁

//pthread_rwlock_init       初始化读写锁
//pthread_rwlock_destroy    销毁读写锁
//pthread_rwlock_rdlock     阻塞加读锁
//pthread_rwlock_wrlock     阻塞加写锁
//pthread_rwlock_trywrlock  非阻塞尝试加写锁
//pthread_rwlock_unlock     解锁
