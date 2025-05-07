#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

#include "Structs.h"
#include "TestResult.h"


//======================= Регістрація юзера ======================

std::string register_user() {
	Users user;
	std::string name;
	std::string address;
	std::string phone;
	std::string login;
	std::string password;
	std::cout << "Введiть ваше iм'я: \t";
	std::cin.ignore();
	std::getline(std::cin, name);
	user.setName(name);

	std::cout << "Введiть вашу адресу: \t";
	std::getline(std::cin, address);
	user.setAddress(address);

	std::cout << "Введiть ваш номер телефону: \t";
	std::getline(std::cin, phone);
	user.setPhone(phone);

	std::cout << "Введiть ваш логiн: \t";
	std::getline(std::cin, login);
	user.setLogin(login);

	std::cout << "Введiть ваш пароль: \t";
	std::getline(std::cin, password);
	user.setPassword(password);

	setlocale(LC_ALL, "ukr");

	std::ofstream file("users.txt", std::ios::app);
	if (file.is_open()) {
		std::ifstream check_user("users.txt");
		if (check_user.is_open()) {
			std::string line;
			while (std::getline(check_user, line)) {
				if (line.find(login) != std::string::npos) {
					std::cout << "Користувач з таким логiном вже iснує!" << std::endl;
					return "";
				}
			}
			check_user.close();
		}
		else {
			std::cout << "Не вдалося вiдкрити файл для читання!" << std::endl;
			return "";
		}
		file << user;
		file.close();
		std::cout << "Користувач успiшно зареєстрований!" << std::endl;
		std::string user_login = user.getLogin();
		return user_login;
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для запису!" << std::endl;
	}
}

//======================= Проходження тесту ======================

int category;
void takeTest(Test test, Users user);
void takeTest1(Test test1, Users user);
Test createTest(int category);



void takeTest(Test test, Users user) {
	std::cout << "Ви проходите тест з категорiї: " << test.getCategory() << "\n";
	std::cout << "Пiдкатегорiя: " << test.getSubCategory() << "\n";
	std::cout << "Вiдповiдайте на запитання, вибираючи номер вiдповiдi.\n";

	int correct_answers = 0;
	for (size_t i = 0; i < test.getQuestions().size(); ++i) {
		std::cout << "Питання " << i + 1 << ": " << test.getQuestions()[i].text << "\n";
		for (int j = 0; j < 4; ++j) {
			std::cout << j + 1 << ". " << test.getQuestions()[i].options[j] << "\n";
		}
		int answer;
		std::cout << "Ваш вибiр: ";
		std::cin >> answer;

		if (answer == test.getQuestions()[i].correct_answer) {
			correct_answers++;
		}
	}
	double score = (double)correct_answers / test.getQuestions().size() * 12;
	std::cout << "Ваш результат: " << correct_answers << "/" << test.getQuestions().size() << " правильних вiдповiдей.\n";

	TestResult result(user.getLogin(), test.getCategory(), correct_answers, score);
	std::cout << "Результати тестування:\n";
	std::cout << "Логiн: " << result.getLogin() << "\n";
	std::cout << "Назва тесту: " << result.getTestName() << "\n";
	std::cout << "Кiлькiсть правильних вiдповiдей: " << result.getCorrectAnswers() << "\n";
	std::cout << "Оцiнка: " << result.getScore() << "%\n";

	std::ofstream file("test_results.txt", std::ios::app);
	
	if (file.is_open()) {
		file << "Логiн: " << result.getLogin() << "\n";
		file << "Назва тесту: " << result.getTestName() << "\n";
		file << "Кiлькiсть правильних вiдповiдей: " << result.getCorrectAnswers() << "\n";
		file << "Оцiнка: " << result.getScore() << "%\n";
		file.close();
		std::cout << "Результати тестування збережено у файл.\n";
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для запису.\n";
	}
}

void takeTest1(Test test1, Users user) {
	std::cout << "Ви проходите тест з категорiї: " << test1.getCategory() << "\n";
	std::cout << "Пiдкатегорiя: " << test1.getSubCategory() << "\n";
	std::cout << "Вiдповiдайте на запитання, вибираючи номер вiдповiдi.\n";

	int correct_answers = 0;
	for (size_t i = 0; i < test1.getQuestions().size(); ++i) {
		std::cout << "Питання " << i + 1 << ": " << test1.getQuestions()[i].text << "\n";
		for (int j = 0; j < 4; ++j) {
			std::cout << j + 1 << ". " << test1.getQuestions()[i].options[j] << "\n";
		}
		int answer;
		std::cout << "Ваш вибiр: ";
		std::cin >> answer;

		if (answer == test1.getQuestions()[i].correct_answer) {
			correct_answers++;
		}
	}
	double score = (double)correct_answers / test1.getQuestions().size() * 12;
	std::cout << "Ваш результат: " << correct_answers << "/" << test1.getQuestions().size() << " правильних вiдповiдей.\n";

	TestResult result(user.getLogin(), test1.getCategory(), correct_answers, score);
	std::cout << "Результати тестування:\n";
	std::cout << "Логiн: " << result.getLogin() << "\n";
	std::cout << "Назва тесту: " << result.getTestName() << "\n";
	std::cout << "Кiлькiсть правильних вiдповiдей: " << result.getCorrectAnswers() << "\n";
	std::cout << "Оцiнка: " << result.getScore() << "%\n";

	std::ofstream file("test_results.txt", std::ios::app);
	
	if (file.is_open()) {
		file << "Логiн: " << result.getLogin() << "\n";
		file << "Назва тесту: " << result.getTestName() << "\n";
		file << "Кiлькiсть правильних вiдповiдей: " << result.getCorrectAnswers() << "\n";
		file << "Оцiнка: " << result.getScore() << "%\n";
		file.close();
		std::cout << "Результати тестування збережено у файл.\n";
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для запису.\n";
	}
}

//======================= Логiн юзера ======================

void testName();

void login_user() {
	Users user;
	std::string login, password;
	std::cout << "Введiть ваш логiн: \t";
	std::cin >> login;
	std::cout << "Введiть ваш пароль: \t";
	std::cin >> password;

	setlocale(LC_ALL, "ukr");

	std::ifstream file("users.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			if (line.find(login) == std::string::npos && line.find(password) == std::string::npos) {
				std::cout << "Логiн i пароль вiрнi!" << std::endl;
				testName();
				return;
			}
		}
		file.close();
		std::cout << "Логiн або пароль невiрнi!" << std::endl;
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для читання!" << std::endl;
	}
}

//======================= Створення тесту ======================

Test createTest(int category) {
	Test test;
	Test test1;

	test.setCategory("Математика");
	test.setSubCategory("Дискретна математика");

	test1.setCategory("Фiзика");
	test1.setSubCategory("Механiка");

	Question q1 = { "Скiльки граней має куб?", {"4", "6", "8", "12"}, 2 };
	Question q2 = { "Яке число є парним?", {"15", "21", "28", "39"}, 3 };
	Question q3 = { "Яка формула для обчислення площi кола?", {"2Pir", "Pir^2",  "Pid", "4Pir^2"}, 2 };
	Question q4 = { "Яка формула для обчислення об'єму цилiндра?", {"2Pirh", "Pid^2h", "Pir^2h", "4/3Pir^3"}, 3 };
	Question q5 = { "Яка формула для обчислення площi трикутника?", {"a^2 + b^2 = c^2", "Pir^2", "4/3Pir^3", "1/2 * a * b"}, 4 };
	Question q6 = { "Яка формула для обчислення об'єму кулi?", {"4/3Pir^3", "Pir^2h", "2Pirh", "Pid^2h"}, 1 };
	Question q7 = { "Яка формула для обчислення площi прямокутника?", {"a * b", "2(a + b)", "a^2 + b^2 = c^2", "Pir^2"}, 1 };
	Question q8 = { "Яка формула для обчислення периметра квадрата?", { "2(a + b)", "4a", "a^2 + b^2 = c^2", "Pir^2"}, 2 };
	Question q9 = { "Яка формула для обчислення площi трапецiї?", {"(a + b)h/2", "a^2 + b^2 = c^2", "Pir^2", "4/3Pir^3"}, 1 };
	Question q10 = { "Яка формула для обчислення об'єму конуса?", {"2Pirh", "Pid^2h", "1/3Pir^2h", "4/3Pir^3"}, 3 };

	Question q1_1 = { "Яка формула для обчислення швидкостi?", {"v = s/t", "v = at", "v = a + b", "v = s + t"}, 1 };
	Question q1_2 = { "Яка формула для обчислення прискорення?", {"a = s/v", "a = t/v", "a = v + t", "a = v/t",}, 4 };
	Question q1_3 = { "Яка формула для обчислення сили?", {"F = mv", "F = ma", "F = at", "F = s/t"}, 2 };
	Question q1_4 = { "Яка формула для обчислення роботи?", {"A = F / s", "A = F + s", "A = F * s", "A = F - s"}, 3 };
	Question q1_5 = { "Яка формула для обчислення енергiї?", {"E = F * s", "E = m * g", "E = m * a", "E = F / t"}, 1 };
	Question q1_6 = { "Яка формула для обчислення тиску?", {"P = F * S", "P = F / S", "P = S / F", "P = F + S"}, 2 };
	Question q1_7 = { "Яка формула для обчислення об'єму?", {"V = S * h", "V = S / h", "V = S + h", "V = S - h"}, 1 };
	Question q1_8 = { "Яка формула для обчислення густини?", {"d = V / m", "d = m + V", "d = m / V", "d = m - V"}, 3 };
	Question q1_9 = { "Яка формула для обчислення моменту сили?", {"M = F * r", "M = F / r", "M = F + r", "M = F - r"}, 1 };
	Question q1_10 = { "Яка формула для обчислення кутової швидкостi?", {"w = v * r", "w = v + r", "w = v - r", "w = v / r", }, 4 };

	test.addQuestion(q1);
	test.addQuestion(q2);
	test.addQuestion(q3);
	test.addQuestion(q4);
	test.addQuestion(q5);
	test.addQuestion(q6);
	test.addQuestion(q7);
	test.addQuestion(q8);
	test.addQuestion(q9); 
	test.addQuestion(q10);

	test1.addQuestion(q1_1);
	test1.addQuestion(q1_2);
	test1.addQuestion(q1_3);
	test1.addQuestion(q1_4);
	test1.addQuestion(q1_5);
	test1.addQuestion(q1_6);
	test1.addQuestion(q1_7);
	test1.addQuestion(q1_8);
	test1.addQuestion(q1_9);
	test1.addQuestion(q1_10);

	if (category == 1) {
		return test;
	}
	else if (category == 2) {
		return test1;
	}
	else {
		std::cout << "Невiрна категорiя тесту!" << std::endl;
	}
}

//======================= Вибiр тесту ======================

void testName() {
	int test_name;
	int sub_category;
	std::cout << "Введiть назву тесту: 1 - 2 \t";
	std::cin >> test_name;
	if (test_name == 1) {
		std::cout << "Введiть пiдкатегорiю тесту: 1 \t";
		std::cin >> sub_category;
		if (sub_category == 1) {
			std::cout << "Ви вибрали тест з категорiї: " << test_name << "\n";
			std::cout << "Пiдкатегорiя: " << sub_category << "\n";
			category = 1;
			takeTest(createTest(category), Users());
		}

		else {
			std::cout << "Пiдкатегорiя не знайдена!" << std::endl;
		}
	}
	else if (test_name == 2) {
		std::cout << "Введiть пiдкатегорiю тесту: \t";
		std::cin >> sub_category;
		if (sub_category == 1) {
			std::cout << "Ви вибрали тест з категорiї: " << test_name << "\n";
			std::cout << "Пiдкатегорiя: " << sub_category << "\n";
			category = 2;
			takeTest1(createTest(category), Users());
		}
		else {
			std::cout << "Пiдкатегорiя не знайдена!" << std::endl;
		}
	}
	else {
		std::cout << "Тест не знайдено!" << std::endl;
	}
}

//======================= Інтерфейс користувача ======================

void user_interface() {
	int choice;

	std::cout << "Вас вiтає тестова система!" << std::endl;
	std::cout << "1. Реєстрацiя" << std::endl;
	std::cout << "2. Логiн" << std::endl;
	std::cout << "3. Результати тестiв" << std::endl;
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
}
