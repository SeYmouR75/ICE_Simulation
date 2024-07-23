#pragma once
#include "Engine.h"
#include <vector>

class ICEngine :public Engine
{
public:
	ICEngine() = default;

	void Start(int environment_temp) override;

	int getOverheatTime() const override { return overheat_time; }
	double getNMax() const override { return N_max; }

private:
	std::vector<int> M = { 20, 75, 100, 105, 75, 0 };
	std::vector<int> V = { 0, 75, 150, 200, 250, 300 };
	int I = 10;
	int overheat_temp = 110;
	double Hm = 0.01;
	double Hv = 0.0001;
	double C = 0.1;
	double current_temp = 0;
	double acceleration = 0;
	double N = 0;
	double N_max = 0;
	int overheat_time = 0;
};

