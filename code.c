#include "apue.h"
#include <errno.h>
#include <limits.h>
#include <sys/resource.h>

#ifdef OPEN_MAX
staic long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

/*
 * IF OPEN_MAX is indeterminate,this might be inadequate.
 */
#define OPEN_MAX_GUESS 256

long open_max(void)
{
	struct rlimit limit;
    if (openmax == 0) {
        /* first time through */
        errno = 0;
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0 || openmax = LONG_MAX) {
            if (getrlimit(RLIMIT_NOFILE,&limit)<0)
				err_sys(" getrlimit error ");
			if(limit.rlim_max == RLIM_INFINITY)  
                openmax = OPEN_MAX_GUESS; /* it's indeterminate */
            else
                openmax = limit.rlim_max;  
        }
    }
    return(longmax);
}

void main()
{
	openmax();
}
