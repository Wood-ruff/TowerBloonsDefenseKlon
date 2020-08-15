#pragma once

#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<double> fsec;
constexpr auto middle = 0.01;

class CTimer {
public:
	CTimer();
	void update();
	double getElapsed();
	double getRealElapsed();
	void updateElapsed();
private:
	void catchBig();
	double elapsed;
	double lastElapsed;
	double elapsedAct;
	Time::time_point curTime;
	Time::time_point lastTime;
};