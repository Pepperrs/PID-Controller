# PID Controller
This is a PID controller steering an autonomous vehicle across a racetrack.
You can see it in action [here](https://youtu.be/oYYgaLZbULg).

## Effects of each of the PID parameters
A PID controller is a simple way to control the steering of a vehicle across a predefined trajectory. It uses three parameters to calculate the required steering angle:
* P, the proportional part of the equation. This component increases the steering more the further away the vehicle is from the trajectory, i.e. the higher its cross track error (CTE) is.
* I, the integral part of the equation. The integral is used to move the vehicle closer to the trajectory when both P and D combined let the car steer across a tangential path. It also influences how fast the car can approach its target trajectory.
* D is the derivative part of the equation. Its calculated by the difference of the current CTE and the previous CTE. The derivative component is used to keep a vehicle that has found the trajectory close to it by reducing the rate of change in the CTE.

## The final hyper parameters
For my final results i used:
* P: -0.2
* I: -0.01
* D: -30.0

I arrived at these values by starting at some values that successfully allowed the vehicle to complete a full round in the simulator (-0.25, 0.0 and -0.75) and then slowly altered them to make the round smoother and more reliable.
Using the final parameters, the car can complete the course on full throttle.
Driving on full throttle is unfortunately only possible on a strong computer, as I learned when recording the video, which required me to reduce the throttle to 50%.
Aforementioned is due to lag caused by the recording and the program not being able to calculate the steering angle as often, which causes the vehicle to steer wildly across the course.

## Dependencies

* cmake \>= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make \>= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g
  * Linux: gcc / g
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
	```
	git clone https://github.com/uWebSockets/uWebSockets
	cd uWebSockets
	git checkout e94b6e1
	```
	Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions
1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings
We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style
This project uses [Google's C](https://google.github.io/styleguide/cppguide.html).
