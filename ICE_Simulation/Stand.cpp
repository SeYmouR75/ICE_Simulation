#include "Stand.h"
#include <iostream>

void Stand::startOverheatTest(Engine* engine) {
	engine->Start(environment_temp);
	std::cout << "�������� ���������: " << engine->getOverheatTime() << " ������ �������" << std::endl;
}

void Stand::startPowerTest(Engine *engine) {
	engine->Start(environment_temp);
	std::cout << "������������ ��������: " << engine->getNMax() << " ���" << std::endl;
}