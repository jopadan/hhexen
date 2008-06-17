/*
	h2stdinc.h
	includes the minimum necessary stdc headers,
	defines common and / or missing types.

	$Id: h2stdinc.h,v 1.1 2008-06-17 13:41:57 sezero Exp $
*/

#ifndef __H2STDINC_H
#define __H2STDINC_H

#include <config.h>

#include <sys/types.h>
#include <stddef.h>
#include <limits.h>

/* We expect these type sizes:
   sizeof (char)	== 1
   sizeof (short)	== 2
   sizeof (int)		== 4
   sizeof (float)	== 4
   sizeof (long)	== 4 / 8
   sizeof (pointer *)	== 4 / 8
   For this, we need stdint.h (or inttypes.h)
   FIXME: Properly replace certain short and int usage
	  with int16_t and int32_t.
 */
#if defined(HAVE_STDINT_H)
# include <stdint.h>
#endif
#if defined(HAVE_INTTYPES_H)
# include <inttypes.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#ifdef HAVE_STRINGS_H
# include <strings.h>	/* strcasecmp and strncasecmp	*/
#endif

/*==========================================================================*/

#ifndef NULL
#if defined(__cplusplus)
#define	NULL		0
#else
#define	NULL		((void *)0)
#endif
#endif

#define	MAXCHAR		((char)0x7f)
#define	MAXSHORT	((short)0x7fff)
#define	MAXINT		((int)0x7fffffff)	/* max positive 32-bit integer */
#define	MAXLONG		((long)0x7fffffff)

#define	MINCHAR		((char)0x80)
#define	MINSHORT	((short)0x8000)
#define	MININT		((int)0x80000000)	/* max negative 32-bit integer */
#define	MINLONG		((long)0x80000000)

/* Make sure the types really have the right
 * sizes: These macros are from SDL headers.
 */
#define	COMPILE_TIME_ASSERT(name, x)	\
	typedef int dummy_ ## name[(x) * 2 - 1]

COMPILE_TIME_ASSERT(char, sizeof(char) == 1);
COMPILE_TIME_ASSERT(float, sizeof(float) == 4);
COMPILE_TIME_ASSERT(long, sizeof(long) >= 4);
COMPILE_TIME_ASSERT(int, sizeof(int) == 4);
COMPILE_TIME_ASSERT(short, sizeof(short) == 2);


/*==========================================================================*/

typedef unsigned char		byte;

#undef true
#undef false
#if defined(__cplusplus)
typedef bool	boolean;
#else
typedef	enum	{false, true} boolean;
#endif


/*==========================================================================*/

/* math */
#define	FRACBITS		16
#define	FRACUNIT		(1 << FRACBITS)

typedef int	fixed_t;


/*==========================================================================*/

/* compatibility with M$ types */
#if !(defined(_WIN32) || defined(_WIN64))

#define	PASCAL
#define	FAR
#define	APIENTRY

#endif	/* ! WINDOWS */

/*==========================================================================*/


#endif	/* __H2STDINC_H */
