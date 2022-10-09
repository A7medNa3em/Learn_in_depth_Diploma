#ifndef PLATFORM_TYPES
#define PLATFORM_TYPES

typedef unsigned char boolean;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;

typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef volatile signed char vsint8;
typedef volatile unsigned char vuint8;
typedef volatile signed short vsint16;
typedef volatile unsigned short vuint16;
typedef volatile signed long vsint32;
typedef volatile signed long long vsint64;
typedef volatile unsigned long vuint32;
typedef volatile unsigned long long vuint64;

typedef signed char sint8_least;
typedef unsigned char uint8_least;
typedef signed short sint16_least;
typedef unsigned short uint16_least;
typedef signed long sint32_least;
typedef unsigned long uint32_least;

typedef float float32;
typedef double float64;

#endif