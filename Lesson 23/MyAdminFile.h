#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MyTestFile.h"
#include "Structs.h"

//================= Створення адміністратора ===================

void login_admin(){
	std::string username, password;
	std::cout << "Введiть логiн адмiнiстратора: ";
	std::cin >> username;
	std::cout << "Введiть пароль адмiнiстратора: ";
	std::cin >> password;

	std::ifstream adminFile("admin.txt");
	if (adminFile.is_open()) {
		std::string line_user, line_pass;
		if (adminFile >> line_user >> line_pass) {
			std::cout << "Адмiнiстратор вже iснує. Неможливо зареєструватись." << std::endl;
			adminFile.close();
			return;
		}
		adminFile.close();
	}
	std::ofstream file("admin.txt");
	if (file.is_open()) {
		file << username << " " << password << std::endl;
		std::cout << "Адмiнiстратор успiшно зареєстрований." << std::endl;
		file.close();
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для запису." << std::endl;
	}
}
	
//================= Зміна логіна та пароля адміністратора ===================

void rename_admin() {
	std::string username, password, new_username, new_password;
	std::cout << "Введiть логiн адмiнiстратора: ";
	std::cin >> username;
	std::cout << "Введiть пароль адмiнiстратора: ";
	std::cin >> password;

	std::ifstream file("admin.txt");
	if (file.is_open()) {
		std::string line_user, line_pass;
		file >> line_user >> line_pass;
		file.close();
		if (username == line_user && password == line_pass) {
			std::cout << "Введiть новий логiн адмiнiстратора: ";
			std::cin >> new_username;
			std::cout << "Введiть новий пароль адмiнiстратора: ";
			std::cin >> new_password;
			std::ofstream file("admin.txt", std::ios::trunc);
			if (file.is_open()) {
				file << new_username << " " << new_password << std::endl;
				std::cout << "Адмiнiстратор успiшно зареєстрований." << std::endl;
				file.close();
			}
			else {
				std::cout << "Не вдалося вiдкрити файл для запису." << std::endl;
			}
		}
		file.close();
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для читання." << std::endl;
	}
}

//================= Створення користувачів ===================

std::string register_users() {
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

//================= Видалення користувача ===================

void delete_users() {
	std::string login;
	std::cout << "Введiть логiн користувача, якого потрiбно видалити: \t";
	std::cin >> login;

	std::ifstream file("users.txt");
	if (file.is_open()) {
		std::string line;
		bool found = false;
		while (std::getline(file, line)) {
			if (line.find(login) != std::string::npos) {
				found = true;
				break;
			}
		}
		file.close();

		if (found) {
			std::ifstream file("users.txt");
			std::ofstream temp("temp.txt");
			if (temp.is_open()) {
				while (std::getline(file, line)) {
					if (line.find(login) == std::string::npos) {
						temp << line << std::endl;
					}
				}
				file.close();
				temp.close();
				remove("users.txt");
				rename("temp.txt", "users.txt");
				std::cout << "Користувач успiшно видалений!" << std::endl;
			}
			else {
				std::cout << "Не вдалося вiдкрити файл для запису!" << std::endl;
			}
		}
		else {
			std::cout << "Користувач не знайдений!" << std::endl;
		}
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для читання!" << std::endl;
	}
}

//================= Змінення данних користувача ===================

void change_users() {
	std::string login;
	std::cout << "Введiть логiн користувача, якого потрiбно змiнити: \t";
	std::cin >> login;

	std::ifstream file("users.txt");
	if (file.is_open()) {
		std::string line;
		bool found = false;
		while (std::getline(file, line)) {
			if (line.find(login) != std::string::npos) {
				found = true;
				break;
			}
		}
		file.close();

		if (found) {
			std::ifstream file("users.txt");
			std::ofstream temp("temp.txt");
			if (temp.is_open()) {
				while (std::getline(file, line)) {
					if (line.find(login) == std::string::npos) {
						temp << line << std::endl;
					}
				}
				file.close();
				temp.close();
				remove("users.txt");
				rename("temp.txt", "users.txt");
				std::cout << "Користувача успiшно змiнено!" << std::endl;
			}
			else {
				std::cout << "Не вдалося вiдкрити файл для запису!" << std::endl;
			}
		}
		else {
			std::cout << "Користувач не знайдений!" << std::endl;
		}
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для читання!" << std::endl;
	}
}

//================= Перегляд статистики тестування ===================

void view_statistics() {
	std::ifstream file("test_results.txt");
	if (file.is_open()) {
		std::string line;
		std::cout << "Статистика тестування:\n";
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для читання!" << std::endl;
	}
}

//================= Додавання тестів питань відповідей ===================

void add_test() {
	std::string category, sub_category;
	
	std::cout << "Введiть категорiю тесту: \t";
	std::cin.ignore();
	std::getline(std::cin, category);
	std::cout << "Введiть пiдкатегорiю тесту: \t";
	std::getline(std::cin, sub_category);

	
	std::vector<Question> questions;

	for (int i = 0; i < 10; ++i) {
		Question question;
		std::cout << "Введiть текст запитання: \t";
		std::getline(std::cin, question.text);
		std::cout << "Введiть варiанти вiдповiдi (4 варiанти): \n";
		for (int j = 0; j < 4; ++j) {
			std::cout << "Варiант " << j + 1 << ": ";
			std::getline(std::cin, question.options[j]);
		}
		std::cout << "Введiть номер правильної вiдповiдi (1-4): \t";
		std::cin >> question.correct_answer;
		std::cin.ignore();
		questions.push_back(question);
	}
	Test test{ category, sub_category, std::vector<Question>() };

	test.setCategory(category);
	test.setSubCategory(sub_category);
	for (const auto& q : questions) {
		test.addQuestion(q);
	}

	std::ofstream file("tests.txt", std::ios::app);
	if (file.is_open()) {
		file << test.getCategory() << "\n";
		file << test.getSubCategory() << "\n";
		for (const auto& q : test.getQuestions()) {
			file << q.text << "\n";
			for (int j = 0; j < 4; ++j) {
				file << q.options[j] << "\n";
			}
			file << q.correct_answer << "\n";
		}
		file.close();
		std::cout << "Тест успiшно додано!" << std::endl;
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для запису!" << std::endl;
	}
}

//================= Перегляд тестів ===================

void view_tests() {
	std::ifstream file("tests.txt");
	if (file.is_open()) {
		std::string line;
		std::cout << "Тести:\n";
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для читання!" << std::endl;
	}
}

//================= Інтерфейс адміністратора ===================

void admin_interface() {
	std::string username;
	std::string password;
	std::cout << "Введiть логiн адмiнiстратора: ";	
	std::cin >> username;

	std::cout << "Введiть пароль адмiнiстратора: ";	
	std::cin >> password;
	std::ifstream file("admin.txt");
	if (file.is_open()) {
		std::string line_user, line_pass;
		file >> line_user >> line_pass;
		file.close();
		if (username == line_user && password == line_pass) {
			std::cout << "Логiн та пароль вiрнi!" << std::endl;
			int choice;
			do {
				std::cout << "Виберiть дiю:\n";
				std::cout << "1. Додати тест\n";
				std::cout << "2. Переглянути тести\n";
				std::cout << "3. Переглянути статистику тестування\n";
				std::cout << "4. Змiнити логiн та пароль адмiнiстратора\n";
				std::cout << "5. Створити користувача\n";
				std::cout << "6. Видалити користувача\n";
				std::cout << "7. Змiнити данi користувача\n";
				std::cout << "8. Вийти з програми\n";
				std::cin >> choice;

				switch (choice) {
				case 1:
					add_test();
					break;
				case 2:
					view_tests();
					break;
				case 3:
					view_statistics();
					break;
				case 4:
					rename_admin();
					break;
				case 5:
					register_users();
					break;
				case 6:
					delete_users();
					break;
				case 7:
					change_users();
					break;
				case 8:
					std::cout << "Вихiд з програми." << std::endl;
					break;
				default:
					std::cout << "Невiрний вибiр. Спробуйте ще раз." << std::endl;
				}
			} while (choice != 8);
		}
		else {
			std::cout << "Логiн або пароль невiрнi!" << std::endl;
			return;
		}
	}
	else {
		std::cout << "Не вдалося вiдкрити файл для читання!" << std::endl;
		return;
	}
}