#pragma once
#define M_PI 3.14159265358979323846
class TVS_Calculate
{
public:
	TVS_Calculate(void);
	~TVS_Calculate(void);
	
	static double getI(double &SizeA, double &SizeB, double &Flow);
	static double getdP(double &SizeA, double &SizeB, double &Flow, double &Length);
	static double getSpeed(double &SizeA, double &SizeB, double &Flow);
	static double getFlow(double &SizeA, double &SizeB, double &Speed);
	static bool roundCheck(double &SizeA, double &SizeB);


};

