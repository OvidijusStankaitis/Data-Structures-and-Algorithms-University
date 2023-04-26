#ifndef LONG_NUMBER
#define LONG_NUMBER

#include <stddef.h>

typedef struct Digit {
  char value;
  struct Digit *next;
} *Digit;

typedef struct LongNumber {
  char sign;
  Digit first;
  size_t size;
  char *str;
} *LongNumber;

LongNumber longNumberCreateFromString(const char *c);
LongNumber longNumberCreateFromLL(long long x);
LongNumber longNumberCopy(LongNumber x);
const char* longNumberConvertToString(LongNumber x);
long long longNumberConvertToLL(LongNumber x);
int longNumberGetSign(LongNumber x); 
size_t longNumberGetDigitCount(LongNumber x); 
void longNumberFree(LongNumber x);
LongNumber longNumberAdd(LongNumber a, LongNumber b);
LongNumber longNumberSubtract(LongNumber a, LongNumber b);
LongNumber longNumberMultiply(LongNumber a, LongNumber b);
LongNumber longNumberDivide(LongNumber a, LongNumber b);
LongNumber longNumberModulo(LongNumber a, LongNumber b);
int longNumberCompare(LongNumber a, LongNumber b);

#endif
