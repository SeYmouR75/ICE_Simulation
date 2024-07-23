#include <iostream>
#include "ICEngine.h"
#include "Stand.h"

int main()
{
	setlocale(LC_ALL, "ru");
	int choice;
	Stand testStand;
	Engine *choosenEngine;
	void (Stand:: * choosenTest)(Engine * engine) = nullptr;

	std::cout << "Добро пожаловать в тестировщик двигателей!" << std::endl;
	std::cout << "Пожалуйста выберите двигатель который хотите протестировать:" << std::endl;
	std::cout << "1 - Двигатель внутреннего сгорания / 0 - Выход" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		choosenEngine = new ICEngine();
		break;
	case 0:
		exit(EXIT_SUCCESS);
	default:
		std::cout << "Некорретный ввод" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Температура окружающей среды в градусах Цельсия:" << std::endl;
	std::cin >> choice;
	testStand.setEnvironmentTemp(choice);

	std::cout << "Далее выберите тест который хотите произвести:" << std::endl;
	std::cout << "1 - Тест перегрева / 2 - Тест максимальной мощности / 0 - Выход" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		choosenTest = &Stand::startOverheatTest;
		break;
	case 2:
		choosenTest = &Stand::startPowerTest;
		break;
	case 0:
		exit(EXIT_SUCCESS);
	default:
		std::cout << "Некорретный ввод" << std::endl;
		if (choosenEngine != nullptr) delete choosenEngine;
		exit(EXIT_FAILURE);
	}

	(testStand.*choosenTest)(choosenEngine);

	if (choosenEngine != nullptr) delete choosenEngine;
}