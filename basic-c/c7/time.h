#ifndef TIME_H
#define TIME_H 1
typedef unsigned short u16;
struct Time{
	u16 hour;
	u16 minute;
	u16 second;
};
typedef struct Time time;
#endif
