#include "Stand.h"
#include <iostream>

void Stand::startOverheatTest(Engine* engine) {
	engine->Start(environment_temp);
	std::cout << "Скорость перегрева: " << engine->getOverheatTime() << " едениц времени" << std::endl;
}

void Stand::startPowerTest(Engine *engine) {
	engine->Start(environment_temp);
	std::cout << "Максимальная мощность: " << engine->getNMax() << " кВТ" << std::endl;
}