/* /home/user/kasperskyos/samba/bin/default/source4/heimdal/lib/wind/combining_table.h */
/* Automatically generated at 2021-12-16T09:30:30.848914 */

#ifndef COMBINING_TABLE_H
#define COMBINING_TABLE_H 1

#include <krb5-types.h>

struct translation {
  uint32_t key;
  unsigned combining_class;	
};

extern const struct translation _wind_combining_table[];

extern const size_t _wind_combining_table_size;
#endif /* COMBINING_TABLE_H */
