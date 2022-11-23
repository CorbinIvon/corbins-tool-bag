#ifndef _FILE_RANDS_
#define _FILE_RANDS_

#include <stdlib.h>
#include <cassert>

// --------------------------- Randoms ---------------------------

// Float
float randf(int limit_, float minimalPart_ = 0.01);

// Integer
int randi(int limit_);

// Luck
bool luck(float chance_, float limit_ = 100.0);

#endif // _FILE_RANDS_

