#include <iostream>
#include "stdio.h"

using namespace std;

//Total impulse, change in momentum (p) solving for dv
//Conservation of momentum
double dv(double m_r, double m_e, double v_e)
{
  //Consider only the change in velocity
  //Do this by solving for the rocket's velocity in the rest frame
  return (m_e * v_e) / (-m_r);
}

double gravity(double height)
{
  double earth_radius = 6371000.0; //earth's radius in meters
  double earth_mass = 5972000000000000000000000.0; //5.972 × 10^24 kg
  double G = 0.00000000006674; //Gravitational constant 6.674×10−11 m3⋅kg−1⋅s−2
                               //calculate g from law of gravity
  return (G * earth_mass) / ((earth_radius + height) * (earth_radius + height));
}

double simulate_field_g(double m_r, double m_e, double v_e, double dt, double ship_payload)
{
  //declare to update the velocity and height
  //rocket velocity, initially at rest
  double v_r = 0.0;
  //distance from surface, initially on the ground
  double height = 0;
  //gravitational acceleration (to be calculated)
  double g = 0;
  //original mass of the rocket
  double m_r_new = m_r;
  //loop code
  //calculate g
  //update velocity
  //update the mass
  //update height
  while (m_r_new / m_r  > ship_payload)
  {
    g = gravity(height);
    v_r += (dv(m_r_new, m_e, v_e) - g) * dt;
    m_r_new -= m_e * dt;
    height += v_r * dt;
  }
  //return the height
  return height;
}

int main()
{
  double m_r, m_e, v_e, dt, ship_payload;
  m_r = 100.0; //kg mass of the rocket
  m_e = 0.1; //kg mass of the exhaust (burnt per time step)
  v_e = -10000.0; //m/s velocity of exhaust
  dt = 0.1;
  ship_payload = 0.1; //ratio of weight to stop sim, 0.1 -> 90% fuel burned
                      // dv = 10
                      // gravity (m/s^2) = 9.81953
                      // height (m) when fuel is spent = 2.93755e+06

                       //cin >> m_r;
                       //cin >> m_e;
                       //cin >> v_e;
                       //cin >> dt;
                       //cin >> ship_payload;

  cout << "dv = " << dv(m_r, m_e, v_e) << endl;
  cout << "gravity (m/s^2) = " << gravity(0) << endl;
  double burned_fuel_height = simulate_field_g(m_r, m_e, v_e, dt, ship_payload);
  cout << "height (m) when fuel is spent = " << burned_fuel_height << endl;
  getchar();
  return 0;
}
