#include "MathUtils.h"

float MathUtils::getNormalizedCoord(int position, int screenBounds) {
	if (position <= 0)
		return -1.0f;

	if (position >= screenBounds)
		return 1.0f;

	float screenHalf = screenBounds / 2.0f;
	return (position - screenHalf) / screenHalf;
}