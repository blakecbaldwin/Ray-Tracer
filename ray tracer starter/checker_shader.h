#ifndef CHECKER_SHADER_H
#define CHECKER_SHADER_H

#include <cmath>

inline bool checkerIsWhite(float x, float y)
{
  // Each square is 0.2 units wide. floor also handles positions below zero.
  int column = std::floor(x * 5);
  int row = std::floor(y * 5);

  // Even squares are white, odd squares are blue.
  if ((column + row) % 2 == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

#endif
