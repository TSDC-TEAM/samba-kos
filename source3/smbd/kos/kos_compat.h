#ifndef _KOS_COMPAT_H_
#define _KOS_COMPAT_H_
#ifdef __KOS__

#include <errno.h>
#include <rtl/compiler.h>
#include <hal/page.h>

#define getpagesize(...) (PAGE_SIZE)
#define WIFSTOPPED(...) (0)

static __rtl_unused int fork(void)
{
    errno = ENOSYS;
    return -1;
}

static __rtl_unused int __kos_exec(void)
{
    errno = EPERM;
    return -1;
}

#define execle(...) __kos_exec()
#define execl(...)  __kos_exec()
#define execvp(...) __kos_exec()
#define execve(...) __kos_exec()
#define execv(...)  __kos_exec()

#endif /* __KOS__ */
#endif /* _KOS_COMPAT_H_ */