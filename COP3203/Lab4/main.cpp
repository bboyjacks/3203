#include <iostream>

void PartOne()
{
  const float v_final_f = 0.0f;
  const float v_initial_f = 30.0f;
  const float change_in_velocity_f = -9.8f;
  const float time_f = (v_final_f - v_initial_f) / change_in_velocity_f;
  const float y_max_f = v_initial_f * time_f + (0.5f) * change_in_velocity_f * time_f * time_f;
  std::cout << "Max height (float): " << y_max_f << std::endl;

  const double y_max_d = (0.5 * 30 * 30)/9.8;
  std::cout << "Max height (double): " << y_max_d << std::endl;

  const float dt = 0.01f;
  float v_numerical_f = v_initial_f;
  float y_max_numerical_f = 0.0f;

  while (true)
  {

  }

  std::cout << y_max_numerical_f << std::endl;
}

int main()
{
  PartOne();
  std::getchar();
  return 0;
}