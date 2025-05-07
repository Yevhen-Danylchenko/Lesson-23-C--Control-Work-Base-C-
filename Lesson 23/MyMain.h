#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <locale>

int MyFunc();

int MyFunc()
{
	setlocale(LC_ALL, "ukr");

	int choice;

	std::cout << "Вас вiтає тестова система!" << std::endl;
	std::cout << "1. Реєстрацiя" << std::endl;
	std::cout << "2. Логiн" << std::endl;
	std::cout << "3. Результати тестів" << std::endl;
	std::cout << "4. Вихiд" << std::endl;
	std::cout << "Виберiть дiю: \t";
	std::cin >> choice;

	switch (choice) {
	case 1:
		register_user();
		break;
	case 2:
		login_user();
		break;
	case 3:
		TestResults();
		break;
	case 4:
		std::cout << "Вихiд з програми." << std::endl;
		break;
	default:
		std::cout << "Невiрний вибiр. Спробуйте ще раз." << std::endl;
	};	

	return 0;
}


