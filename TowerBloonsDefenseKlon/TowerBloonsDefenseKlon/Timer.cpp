#include"Timer.h"

CTimer::CTimer() {
	this->curTime = Time::now();
	this->elapsed = 0.0;
	this->lastTime = Time::now();
	this->elapsedAct = 0.0;
	this->lastElapsed = NULL;
}

void CTimer::update() {
	this->curTime = Time::now();
	this->elapsed = std::chrono::duration_cast<fsec>(this->curTime - this->lastTime).count();
	this->elapsedAct = std::chrono::duration_cast<fsec>(this->curTime - this->lastTime).count();
	this->lastTime = this->curTime;
	//Legacy Code: Fixed  die Geschwindigkeit auf 0.01 Sekunden pro Frame
	//this->catchBig();
}

void CTimer::updateElapsed() {
	this->curTime = Time::now();
	this->elapsed = std::chrono::duration_cast<fsec>(this->curTime - this->lastTime).count();
}

double CTimer::getRealElapsed() {
	return this->elapsedAct;
}

void CTimer::catchBig() {
	if (this->elapsed >= middle) {
		this->elapsed = middle;
	}
	if (this->elapsed < middle) {
		this->elapsed = middle;
	}
}

double CTimer::getElapsed() {
	return this->elapsed;
}