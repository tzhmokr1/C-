// --------------------------------------------------------
// Header file: ex07_04.h
// Defines the macros isBlank(), isPunct() and isXDigit()
// --------------------------------------------------------
#ifndef _EX07_04_
#define _EX07_40_

#define isBlank(c)   ((c) == ' ')

#define isPunct(c)   ( (c)=='.' || (c)==',' || (c)==';' \
                    || (c)==':' || (c)=='?' || (c)=='!' )

#define isXDigit(c)  ( ((c) >= '0' && (c) <= '9') \
                    || ((c) >= 'A' && (c) <= 'F') \
                    || ((c) >= 'a' && (c) <= 'f') )

#endif  // _EX07_04_
