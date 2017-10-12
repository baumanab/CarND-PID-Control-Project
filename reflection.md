## Reflection

PID is an acronym comprised of it's 3 components.  Position, Integral, Derivative.  These 3 components work together to ensure a stable trajectory.  Our vehicle adjusts its sterring angle based on the total error, in the form of:

```
Kp * p_error + Ki * i_error + Kd * d_error;
```

where each error type is multiplied by a coefficient.  To stabalize the vehilce for track circumnavigation, we must tune the weights properly (Kp, Ki, Kd).

### Role of each Component

- **(P)osition (weight = Kp):**  We correct the position based on our hueristic. In this case our heuristic is cross-track-error (CTE) the distance of the vehicle center from the track center.  In the absence of other terms our steering angle will change in direct proportion to CTE magnitude.  When this is our only factor the vehicle has a tendency to jerk and wildly oscillate, eventually leaving the road.

- **(D)eriviative (weight = Kd):** This term governs the rate of change of the steering angle, where the angle is inversely proportional to the magnitude of Kd.  The purpose of this term is to smooth the return to track center by adding a bias to the total error, but too a high a value can make it difficult to corner, particularly at high speeds.  This term is simplified/estimated as the p_error - CTE.

- **(I)ntegral (weight = Ki):**  This term represents the cumulative CTE and is meant to account for systematic error, such as wheel misalignment.  

### Method for choosing final parameters
The weights were tuned manually, using a classic PID method.  All values were set to 0 and then behavior was observed.  The car readily left the road.  Next, Kp was incremented in units of 0.25 until a steady oscillation was achieved.  The vehicle left the road at the throttle set point (0.3, ~ 30mph) on corners.  Kd was set high (10) and reduced by 0.5 increments until the vehicle transitions smoothed, in the absence of missed corners.  Values of Kd that were too high resulted in very smooth center movement, but the rate of adjustment was too slow to handle higher speed corners.  Ki was adjusted randomly at first to see it's impact.  Even seemingly low values, such as 0.01, took a stable vehicle and caused it to quickly jerk from the track.  Finally, a value of 0.0 was used, since values explored (from 1.0 down to 0.0001) did not seem to have a positive effect. 
