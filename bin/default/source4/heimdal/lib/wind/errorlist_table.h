/* /home/user/kasperskyos/samba/bin/default/source4/heimdal/lib/wind/errorlist_table.h */
/* Automatically generated at 2021-12-16T09:30:29.812015 */

#ifndef ERRORLIST_TABLE_H
#define ERRORLIST_TABLE_H 1

#include "windlocl.h"

struct error_entry {
  uint32_t start;
  unsigned len;
  wind_profile_flags flags;
};

extern const struct error_entry _wind_errorlist_table[];

extern const size_t _wind_errorlist_table_size;

#endif /* ERRORLIST_TABLE_H */
