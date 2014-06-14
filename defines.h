#ifndef MC_DEFINES_H
#define	MC_DEFINES_H

/**
 * some usefull constants
 */

namespace mc {

#ifndef UINT_TYPE
#define UINT_TYPE
    typedef unsigned int uint;
    typedef unsigned char uint8;
    typedef uint8 byte;
    typedef unsigned short int uint16;
    /***
     * uint32 is missing
     */
    typedef unsigned long long uint64;
#endif

    const double PI = 3.14159265358979;
    const double EPS = 0.000001;
    const uint MAX_ITERATIONS = 10000;
}
#endif	/* DEFINES_H */

