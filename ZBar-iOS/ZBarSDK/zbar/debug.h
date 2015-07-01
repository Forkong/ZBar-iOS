/*------------------------------------------------------------------------
 *  Copyright 2007-2009 (c) Jeff Brown <spadix@users.sourceforge.net>
 *
 *  This file is part of the ZBar Bar Code Reader.
 *
 *  The ZBar Bar Code Reader is free software; you can redistribute it
 *  and/or modify it under the terms of the GNU Lesser Public License as
 *  published by the Free Software Foundation; either version 2.1 of
 *  the License, or (at your option) any later version.
 *
 *  The ZBar Bar Code Reader is distributed in the hope that it will be
 *  useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser Public License
 *  along with the ZBar Bar Code Reader; if not, write to the Free
 *  Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 *  Boston, MA  02110-1301  USA
 *
 *  http://sourceforge.net/projects/zbar
 *------------------------------------------------------------------------*/

/* varargs variations on compile time debug spew */

# include <stdio.h>

#ifndef DEBUG_LEVEL

# ifdef __GNUC__
    /* older versions of gcc (< 2.95) require a named varargs parameter */
#  define dbprintf(args...) while(0)
# else
    /* unfortunately named vararg parameter is a gcc-specific extension */
#  define dbprintf(...) while(0)
# endif

#else

# ifdef __GNUC__
#  define dbprintf(level, args...) do { \
        if((level) <= DEBUG_LEVEL)      \
            fprintf(stderr, args);      \
    } while(0)
# else
#  define dbprintf(level, ...) do {         \
        if((level) <= DEBUG_LEVEL)          \
            fprintf(stderr, __VA_ARGS__);   \
    } while(0)
# endif

#endif /* DEBUG_LEVEL */

/* spew warnings for non-fatal assertions.
 * returns specified error code if assertion fails.
 * NB check/return is still performed for NDEBUG
 * only the message is inhibited
 * FIXME don't we need varargs hacks here?
 */
#if NDEBUG

# include <stdio.h>

#if __STDC_VERSION__ < 199901L && !defined(__func__)
# if __GNUC__ >= 2
#  define __func__ __FUNCTION__
# else
#  define __func__ "<unknown>"
# endif
#endif

# define zassert(condition, retval, format, ...) do {                   \
        if(!(condition)) {                                              \
            fprintf(stderr, "WARNING: %s:%d: %s:"                       \
                    " Assertion \"%s\" failed.\n\t" format,             \
                    __FILE__, __LINE__, __func__, #condition ,          \
                    ##__VA_ARGS__);                                     \
            return(retval);                                             \
        }                                                               \
    } while(0)

#else

# define zassert(condition, retval, format, ...) do {   \
        if(!(condition))                                \
            return(retval);                             \
    } while(0)

#endif


//#include <mach/mach_time.h>
//#define xNSSTR(s) @#s
//#define NSSTR(s) xNSSTR(s)
//
//#ifdef DEBUG_OBJC
//# ifndef MODULE
//#  define MODULE ZBarReaderController
//# endif
//# define zlog(fmt, ...) \
//NSLog(NSSTR(MODULE) @": " fmt , ##__VA_ARGS__)
//
//#define timer_start \
//uint64_t t_start = timer_now();
//
//#else
//# define zlog(...) while(0)
//# define timer_start
//#endif
//
//static inline uint64_t timer_now ()
//{
//    return(mach_absolute_time());
//}
//
//static inline double timer_elapsed (uint64_t start, uint64_t end)
//{
//    mach_timebase_info_data_t info;
//    mach_timebase_info(&info);
//    return((double)(end - start) * info.numer / (info.denom * 1000000000.));
//}

