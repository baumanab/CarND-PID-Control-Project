#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    // note this -> var is anologous to self.var = var in python
    this -> Kp = Kp;
    this -> Ki = Ki;
    this -> Kd = Kd;

    p_error = 0, i_error = 0, d_error = 0;
}

void PID::UpdateError(double cte) {
   // TODO Add link to Sebastion lecure and make sure this is consitent
   i_error += cte;
   d_error = cte - p_error;
   p_error = cte;
}

double PID::TotalError() {

    return Kp * p_error + Ki * i_error + Kd * d_error;

}

