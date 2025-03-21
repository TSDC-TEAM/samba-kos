/* 
   Unix SMB/CIFS implementation.
   Safe string handling routines.
   Copyright (C) Andrew Tridgell 1994-1998
   Copyright (C) Andrew Bartlett <abartlet@samba.org> 2003
   
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

#ifdef __KOS__
#define _SAFE_STRING_H
#endif

#ifndef _SAFE_STRING_H
#define _SAFE_STRING_H
#ifndef _SPLINT_ /* http://www.splint.org */

/* Some macros to ensure people don't use buffer overflow vulnerable string
   functions. */

#ifdef bcopy
#undef bcopy
#endif /* bcopy */
#define bcopy(src,dest,size) __ERROR__XX__NEVER_USE_BCOPY___;

#ifdef strcpy
#undef strcpy
#endif /* strcpy */
#define strcpy(dest,src) __ERROR__XX__NEVER_USE_STRCPY___;

#ifdef strcat
#undef strcat
#endif /* strcat */
#define strcat(dest,src) __ERROR__XX__NEVER_USE_STRCAT___;

#ifdef sprintf
#undef sprintf
#endif /* sprintf */
#define sprintf __ERROR__XX__NEVER_USE_SPRINTF__;

/*
 * strcasecmp/strncasecmp aren't an error, but it means you're not thinking about
 * multibyte. Don't use them. JRA.
 */
#ifdef strcasecmp
#undef strcasecmp
#endif
#define strcasecmp __ERROR__XX__NEVER_USE_STRCASECMP__;

#ifdef strncasecmp
#undef strncasecmp
#endif
#define strncasecmp __ERROR__XX__NEVER_USE_STRNCASECMP__;

#endif /* !_SPLINT_ */

#endif
