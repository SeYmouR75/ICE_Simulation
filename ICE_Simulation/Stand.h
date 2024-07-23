#pragma once
#include "Engine.h"

class Stand
{
public:
	Stand() = default;

	void startOverheatTest(Engine* engine);
	void startPowerTest(Engine *engine);

	void setEnvironmentTemp(int temperature) { this->environment_temp = temperature; }

	int getEnvironmentTemp() const { return environment_temp; }

private:
	int environment_temp = 0;
};

