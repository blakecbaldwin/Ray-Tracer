#ifndef TRIANGLE_4620
#define TRIANGLE_4620

#include "Vector3.hpp"

class Triangle{
  public:
  Vector3 one, two, three;
  Vector3 color = Vector3{255, 255, 255};
  bool use_checker_shader = false;
  bool use_gradient_shader = false;
  bool use_mountain_shader = false;
  float reflectivity = 0.5f; // 0 = no reflection, 1 = fully reflective
};


#endif
