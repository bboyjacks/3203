#include <iostream>
#include "stdio.h"

using namespace std;

double max_heightd(double v_i, double g)
{
  // v_f - v_i = a * t
  // solve for t

  // h = v_i * t + 1/2 * a * t^2
  // return h as the max height
  return 0;
}

float max_heightf(float v_i, float g)
{
  // v_f - v_i = a * t
  // solve for t

  // h = v_i * t + 1/2 * a * t^2
  // return h as the max height
  return 0;
}

float simulatef(float v_i, float g, float dt)
{
  //declare float versions to update the velocity and height
  //loop code
  //condition to break the loop
  //update velocity
  //update height
  //return the height
  return 0;
}

double simulated(double v_i, double g, double dt)
{
  //declare double versions to update the velocity and height
  //loop code
  //condition to break the loop
  //update velocity
  //update height
  //return the height
  return 0;
}

int main()
{
  double gd = -9.81; // gravitational acceleration
  double v_id = 500.0; // initial velocity
  double dtd = 0.01; // delta t, change in time, time resolution
                     // analytic (double) height (m) = 12742.1
                     // analytic (float) height (m) = 12742.1
                     // simulation (double) height (m) = 12739.6
                     // simulation (float) height (m) = 12738.3

                     // cin >> gd;
                     // cin >> v_id;
                     // cin >> dtd;
  float gf = gd;
  float v_if = v_id;
  float dtf = dtd;
  cout << "analytic (double) height (m) = " << max_heightd(v_id, gd) << endl;
  cout << "analytic (float) height (m) = " << max_heightf(v_if, gf) << endl;
  cout << "simulation (double) height (m) = " << simulated(v_id, gd, dtd) << endl;
  cout << "simulation (float) height (m) = " << simulatef(v_if, gf, dtf) << endl;
  return 0;
}
