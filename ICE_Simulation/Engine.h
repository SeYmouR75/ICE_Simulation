#pragma once

class Engine
{
public:
	virtual void Start(int environment_temp) = 0;

	virtual int getOverheatTime() const = 0;
	virtual double getNMax() const = 0;
 };

