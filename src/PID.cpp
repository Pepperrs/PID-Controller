#include "PID.h"
#include <vector>
#include <numeric>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  // init coefficients
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error; // p_error contains the previous cte
  p_error = cte;
  i_error += cte;

}

double PID::TotalError() {

  double steer_value;
  steer_value = Kp * p_error
      + Ki * i_error
      + Kd * d_error;

  //catch to big steering values
  if (steer_value < -1) steer_value = -1;
  if (steer_value > 1) steer_value = 1;



  // get the average of the last n steer values
  average_steering.push_back(steer_value);
  if (average_steering.size() >= 3) {
    average_steering.erase(average_steering.begin());
    steer_value =
        1.0 * std::accumulate(average_steering.begin(), average_steering.end(), 0.0) / average_steering.size();
  }
  return steer_value;
}

