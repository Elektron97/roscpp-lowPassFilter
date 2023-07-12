
#ifndef _LOWPASSFILTER_H_
#define _LOWPASSFILTER_H_

#include <cmath>

class LowPassFilter{
public:
	//constructors
	LowPassFilter();
	LowPassFilter(float iCutOffFrequency, float iDeltaTime);
	//functions
	float update(float input);
	float update(float input, float deltaTime, float cutoffFrequency);
	//get and configure funtions
	float getOutput() const{return output;}
	void reconfigureFilter(float deltaTime, float cutoffFrequency);
private:
	float output;
	float ePow;
};

#endif //_LOWPASSFILTER_H_
