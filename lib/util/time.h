/* 
   Unix SMB/CIFS implementation.
   time utility functions

   Copyright (C) Andrew Tridgell 		1992-2004
   Copyright (C) Stefan (metze) Metzmacher	2002
   Copyright (C) Jeremy Allison			2007
   Copyright (C) Andrew Bartlett                2011

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _SAMBA_TIME_H_
#define _SAMBA_TIME_H_

#include <stdbool.h>
#include <stdint.h>
#include <talloc.h>

#ifdef __KOS__
#include <sys/time.h>
#endif

#ifndef TIME_T_MIN
/* we use 0 here, because (time_t)-1 means error */
#define TIME_T_MIN 0
#endif

/*
 * we use the INT32_MAX here as on 64 bit systems,
 * gmtime() fails with INT64_MAX
 */
#ifndef TIME_T_MAX
#define TIME_T_MAX MIN(INT32_MAX,_TYPE_MAXIMUM(time_t))
#endif

/*
 * According to Windows API FileTimeToSystemTime() documentation the highest
 * allowed value " ... must be less than 0x8000000000000000.".
 */
#define NTTIME_MAX INT64_MAX

/*
 * The lowest possible value when NTTIME=0 is used as sentinel value.
 */
#define NTTIME_MIN 1

/*
 * NTTIME_OMIT in a setinfo tells us to not modify the corresponding on-disk
 * timestamp value.
 */
#define NTTIME_OMIT 0

/*
 * Disable automatic timestamp updates, as described in MS-FSA. Samba doesn't
 * implement this yet.
 */
#define NTTIME_FREEZE UINT64_MAX

#define SAMBA_UTIME_NOW UTIME_NOW
#define SAMBA_UTIME_OMIT UTIME_OMIT

/* 64 bit time (100 nanosec) 1601 - cifs6.txt, section 3.5, page 30, 4 byte aligned */
typedef uint64_t NTTIME;

/**
 External access to time_t_min and time_t_max.
**/
time_t get_time_t_max(void);

/**
a gettimeofday wrapper
**/
void GetTimeOfDay(struct timeval *tval);

/**
a wrapper to preferably get the monotonic time
**/
void clock_gettime_mono(struct timespec *tp);

/**
a wrapper to preferably get the monotonic time in s
**/
time_t time_mono(time_t *t);

/**
interpret an 8 byte "filetime" structure to a time_t
It's originally in "100ns units since jan 1st 1601"
**/
time_t nt_time_to_unix(NTTIME nt);

/**
put a 8 byte filetime from a time_t
This takes GMT as input
**/
void unix_to_nt_time(NTTIME *nt, time_t t);

/**
check if it's a null unix time
**/
bool null_time(time_t t);

/**
check if it's a null NTTIME
**/
bool null_nttime(NTTIME t);

/**
put a dos date into a buffer (time/date format)
This takes GMT time and puts local time in the buffer
**/
void push_dos_date(uint8_t *buf, int offset, time_t unixdate, int zone_offset);

/**
put a dos date into a buffer (date/time format)
This takes GMT time and puts local time in the buffer
**/
void push_dos_date2(uint8_t *buf,int offset,time_t unixdate, int zone_offset);

/**
put a dos 32 bit "unix like" date into a buffer. This routine takes
GMT and converts it to LOCAL time before putting it (most SMBs assume
localtime for this sort of date)
**/
void push_dos_date3(uint8_t *buf,int offset,time_t unixdate, int zone_offset);

/**
  create a unix date (int GMT) from a dos date (which is actually in
  localtime)
**/
time_t pull_dos_date(const uint8_t *date_ptr, int zone_offset);

/**
like make_unix_date() but the words are reversed
**/
time_t pull_dos_date2(const uint8_t *date_ptr, int zone_offset);

/**
  create a unix GMT date from a dos date in 32 bit "unix like" format
  these generally arrive as localtimes, with corresponding DST
**/
time_t pull_dos_date3(const uint8_t *date_ptr, int zone_offset);

/**
 Return a date and time as a string (optionally with microseconds)

 format is %Y/%m/%d %H:%M:%S if strftime is available
**/

char *timeval_string(TALLOC_CTX *ctx, const struct timeval *tp, bool hires);

struct timeval_buf;
const char *timespec_string_buf(const struct timespec *tp,
				bool hires,
				struct timeval_buf *buf);

/**
 Return the current date and time as a string (optionally with microseconds)

 format is %Y/%m/%d %H:%M:%S if strftime is available
**/
char *current_timestring(TALLOC_CTX *ctx, bool hires);

/**
 Return a date and time as a string (optionally with microseconds)

 format is %Y%m%d_%H%M%S or %Y%m%d_%H%M%S_%us
**/

char *minimal_timeval_string(TALLOC_CTX *ctx, const struct timeval *tp, bool hires);

/**
 Return the current date and time as a string (optionally with microseconds)

 format is %Y%m%d_%H%M%S or %Y%m%d_%H%M%S_%us
**/
char *current_minimal_timestring(TALLOC_CTX *ctx, bool hires);

/**
return a HTTP/1.0 time string
**/
char *http_timestring(TALLOC_CTX *mem_ctx, time_t t);

/**
 Return the date and time as a string

 format is %a %b %e %X %Y %Z
**/
char *timestring(TALLOC_CTX *mem_ctx, time_t t);

/**
  return a talloced string representing a NTTIME for human consumption
*/
const char *nt_time_string(TALLOC_CTX *mem_ctx, NTTIME nt);

/**
  put a NTTIME into a packet
*/
void push_nttime(uint8_t *base, uint16_t offset, NTTIME t);

/**
  pull a NTTIME from a packet
*/
NTTIME pull_nttime(uint8_t *base, uint16_t offset);

/**
  return (tv1 - tv2) in microseconds
*/
int64_t usec_time_diff(const struct timeval *tv1, const struct timeval *tv2);

/**
  return (tp1 - tp2) in nanoseconds
*/
int64_t nsec_time_diff(const struct timespec *tp1, const struct timespec *tp2);

/**
  return a zero timeval
*/
struct timeval timeval_zero(void);

/**
  return true if a timeval is zero
*/
bool timeval_is_zero(const struct timeval *tv);

/**
  return a timeval for the current time
*/
struct timeval timeval_current(void);

/**
  return a timeval struct with the given elements
*/
struct timeval timeval_set(uint32_t secs, uint32_t usecs);

/**
  return a timeval ofs microseconds after tv
*/
struct timeval timeval_add(const struct timeval *tv,
			   uint32_t secs, uint32_t usecs);

/**
  return the sum of two timeval structures
*/
struct timeval timeval_sum(const struct timeval *tv1,
			   const struct timeval *tv2);

/**
  return a timeval secs/usecs into the future
*/
struct timeval timeval_current_ofs(uint32_t secs, uint32_t usecs);

/**
  return a timeval milliseconds into the future
*/
struct timeval timeval_current_ofs_msec(uint32_t msecs);

/**
  return a timeval microseconds into the future
*/
struct timeval timeval_current_ofs_usec(uint32_t usecs);

/**
  compare two timeval structures. 
  Return -1 if tv1 < tv2
  Return 0 if tv1 == tv2
  Return 1 if tv1 > tv2
*/
int timeval_compare(const struct timeval *tv1, const struct timeval *tv2);

/**
  return true if a timer is in the past
*/
bool timeval_expired(const struct timeval *tv);

/**
  return the number of seconds elapsed between two times
*/
double timeval_elapsed2(const struct timeval *tv1, const struct timeval *tv2);

/**
  return the number of seconds elapsed since a given time
*/
double timeval_elapsed(const struct timeval *tv);

/**
  return the number of seconds elapsed between two times
*/
double timespec_elapsed2(const struct timespec *ts1,
			 const struct timespec *ts2);
/**
  return the number of seconds elapsed since a given time
*/
double timespec_elapsed(const struct timespec *ts);

/**
  return the lesser of two timevals
*/
struct timeval timeval_min(const struct timeval *tv1,
			   const struct timeval *tv2);

/**
  return the greater of two timevals
*/
struct timeval timeval_max(const struct timeval *tv1,
			   const struct timeval *tv2);

/**
  return the difference between two timevals as a timeval
  if tv1 comes after tv2, then return a zero timeval
  (this is *tv2 - *tv1)
*/
struct timeval timeval_until(const struct timeval *tv1,
			     const struct timeval *tv2);

/**
  convert a timeval to a NTTIME
*/
NTTIME timeval_to_nttime(const struct timeval *tv);

/**
  convert a NTTIME to a timeval
*/
void nttime_to_timeval(struct timeval *tv, NTTIME t);

/**
  return the UTC offset in seconds west of UTC, or 0 if it cannot be determined
 */
int get_time_zone(time_t t);

/**
  check if 2 NTTIMEs are equal.
*/
bool nt_time_equal(NTTIME *t1, NTTIME *t2);

void interpret_dos_date(uint32_t date,int *year,int *month,int *day,int *hour,int *minute,int *second);

struct timespec nt_time_to_unix_timespec(NTTIME nt);

time_t convert_timespec_to_time_t(struct timespec ts);

struct timespec convert_time_t_to_timespec(time_t t);

bool null_timespec(struct timespec ts);

struct timespec convert_timeval_to_timespec(const struct timeval tv);
struct timeval convert_timespec_to_timeval(const struct timespec ts);
struct timespec timespec_current(void);
struct timespec timespec_min(const struct timespec *ts1,
			     const struct timespec *ts2);
int timespec_compare(const struct timespec *ts1, const struct timespec *ts2);
void round_timespec_to_sec(struct timespec *ts);
void round_timespec_to_usec(struct timespec *ts);
void round_timespec_to_nttime(struct timespec *ts);
NTTIME unix_timespec_to_nt_time(struct timespec ts);
void normalize_timespec(struct timespec *ts);

/*
 * Functions supporting the full range of time_t and struct timespec values,
 * including 0, -1 and all other negative values. These functions don't use 0 or
 * -1 values as sentinel to denote "unset" variables, but use the POSIX 2008
 * define UTIME_OMIT from utimensat(2).
 */
bool is_omit_timespec(const struct timespec *ts);
struct timespec make_omit_timespec(void);
NTTIME full_timespec_to_nt_time(const struct timespec *ts);
struct timespec nt_time_to_full_timespec(NTTIME nt);
time_t full_timespec_to_time_t(const struct timespec *ts);
time_t nt_time_to_full_time_t(NTTIME nt);
struct timespec time_t_to_full_timespec(time_t t);

/*
 * Functions to get and set the number of nanoseconds for times in a stat field.
 * If the stat has timestamp granularity less than nanosecond, then the set_*
 * operations will be lossy.
 */
struct stat;
time_t get_atimensec(const struct stat *);
time_t get_mtimensec(const struct stat *);
time_t get_ctimensec(const struct stat *);
void set_atimensec(struct stat *, time_t);
void set_mtimensec(struct stat *, time_t);
void set_ctimensec(struct stat *, time_t);

/* These are convenience wrappers for the above getters. */
struct timespec get_atimespec(const struct stat *);
struct timespec get_mtimespec(const struct stat *);
struct timespec get_ctimespec(const struct stat *);

#endif /* _SAMBA_TIME_H_ */
