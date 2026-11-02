#ifndef CHECKER_SHADER_H
#define CHECKER_SHADER_H

#include <cmath>

inline bool checkerIsWhite(float x, float y)
{
  int column = std::floor(x * 5);
  int row = std::floor(y * 5);

  // Alternate between the two colors
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
