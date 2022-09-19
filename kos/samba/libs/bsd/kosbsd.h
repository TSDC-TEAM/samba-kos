#ifndef KOSBSD_H
#define KOSBSD_H

#include <strings.h>
#include <unistd.h>

size_t strlcpy(char *dst, const char *src, size_t siz);
size_t strlcat(char * restrict dst, const char * restrict src, size_t maxlen);
int getpeereid(int s, uid_t *euid, gid_t *egid);
void closefrom(int lowfd);
void setproctitle(const	char *fmt, ...);

#endif // KOSBSD_H