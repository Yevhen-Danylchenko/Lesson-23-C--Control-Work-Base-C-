#include <iostream>
#include <locale>
#include <string>
#include "MyTestFile.h"
#include "TestResult.h"
#include "MyAdminFile.h"
#include "Structs.h"

int main()
{
	setlocale(LC_ALL, "ukr");

	int choice;
	do {
		std::cout << "Виберiть дiю:\n";
		std::cout << "1. Вхiд вiд iменi адмiнiстратора\n";
		std::cout << "2. Вхiд вiд iменi користувача\n";
		std::cout << "3. Вихiд з програми\n";
		
		std::cin >> choice;

		switch (choice) {
		case 1:
			admin_interface();			
			break;
		case 2:
			user_interface();
			break;
		case 3:
			std::cout << "Вихiд з програми." << std::endl;
			break;
		default:
			std::cout << "Невiрний вибiр. Спробуйте ще раз." << std::endl;
		}
	} while (choice != 3);

	std::cout << "Для виходу з програми введіть будь який символ" << std::endl;
	std::cin.get();

    return 0;
}


