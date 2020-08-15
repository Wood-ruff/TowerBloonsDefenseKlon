#include "MathUtils.h"
#include <iostream>

double MathUtils::getNormalizedCoord(double position, int screenBounds) {
	if (position < 0) {
		return -1.0f;
	}

	if (position >= screenBounds)
		return 1.0f;

	float screenHalf = screenBounds / 2.0f;

	if (position - screenHalf == 0) {
		return 0;
	}

	return (position - screenHalf) / screenHalf;
}