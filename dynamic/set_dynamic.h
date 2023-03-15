#ifndef __SET_DYNAMIC_H__
#define __SET_DYNAMIC_H__


struct set {
  int  *s;
  size_t capacity;
  size_t size;
};

#include "set.h"



// returns the expected position of c in sorted array s
// the returned value p is such that either s[p]==c,
// or c should be inserted in position p in s
size_t find(int const s[], size_t size, int c);

// translates elements in s[begin..end[ to s[begin+1..end+1[
// assuming all indices are valid, s[begin] is left unchanged
void shift_right(int s[], size_t begin, size_t end);

// translates elements in s[begin..end[ tp [begin-1..end-1[
// assuming all indices are valid, s[end-1] is left unchanged
void shift_left(int s[], size_t begin, size_t end);

#endif
