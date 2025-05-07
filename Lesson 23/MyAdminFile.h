#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MyTestFile.h"
#include "Structs.h"

//================= ��������� ������������ ===================

void login_admin(){
	std::string username, password;
	std::cout << "����i�� ���i� ���i�i��������: ";
	std::cin >> username;
	std::cout << "����i�� ������ ���i�i��������: ";
	std::cin >> password;

	std::ifstream adminFile("admin.txt");
	if (adminFile.is_open()) {
		std::string line_user, line_pass;
		if (adminFile >> line_user >> line_pass) {
			std::cout << "���i�i������� ��� i���. ��������� ��������������." << std::endl;
			adminFile.close();
			return;
		}
		adminFile.close();
	}
	std::ofstream file("admin.txt");
	if (file.is_open()) {
		file << username << " " << password << std::endl;
		std::cout << "���i�i������� ���i��� �������������." << std::endl;
		file.close();
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� ������." << std::endl;
	}
}
	
//================= ���� ����� �� ������ ������������ ===================

void rename_admin() {
	std::string username, password, new_username, new_password;
	std::cout << "����i�� ���i� ���i�i��������: ";
	std::cin >> username;
	std::cout << "����i�� ������ ���i�i��������: ";
	std::cin >> password;

	std::ifstream file("admin.txt");
	if (file.is_open()) {
		std::string line_user, line_pass;
		file >> line_user >> line_pass;
		file.close();
		if (username == line_user && password == line_pass) {
			std::cout << "����i�� ����� ���i� ���i�i��������: ";
			std::cin >> new_username;
			std::cout << "����i�� ����� ������ ���i�i��������: ";
			std::cin >> new_password;
			std::ofstream file("admin.txt", std::ios::trunc);
			if (file.is_open()) {
				file << new_username << " " << new_password << std::endl;
				std::cout << "���i�i������� ���i��� �������������." << std::endl;
				file.close();
			}
			else {
				std::cout << "�� ������� �i������ ���� ��� ������." << std::endl;
			}
		}
		file.close();
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� �������." << std::endl;
	}
}

//================= ��������� ������������ ===================

std::string register_users() {
	Users user;
	std::string name;
	std::string address;
	std::string phone;
	std::string login;
	std::string password;
	std::cout << "����i�� ���� i�'�: \t";
	std::cin.ignore();
	std::getline(std::cin, name);
	user.setName(name);

	std::cout << "����i�� ���� ������: \t";
	std::getline(std::cin, address);
	user.setAddress(address);

	std::cout << "����i�� ��� ����� ��������: \t";
	std::getline(std::cin, phone);
	user.setPhone(phone);

	std::cout << "����i�� ��� ���i�: \t";
	std::getline(std::cin, login);
	user.setLogin(login);

	std::cout << "����i�� ��� ������: \t";
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
					std::cout << "���������� � ����� ���i��� ��� i���!" << std::endl;
					return "";
				}
			}
			check_user.close();
		}
		else {
			std::cout << "�� ������� �i������ ���� ��� �������!" << std::endl;
			return "";
		}
		file << user;
		file.close();
		std::cout << "���������� ���i��� �������������!" << std::endl;
		std::string user_login = user.getLogin();
		return user_login;
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� ������!" << std::endl;
	}
}

//================= ��������� ����������� ===================

void delete_users() {
	std::string login;
	std::cout << "����i�� ���i� �����������, ����� ����i��� ��������: \t";
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
				std::cout << "���������� ���i��� ���������!" << std::endl;
			}
			else {
				std::cout << "�� ������� �i������ ���� ��� ������!" << std::endl;
			}
		}
		else {
			std::cout << "���������� �� ���������!" << std::endl;
		}
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� �������!" << std::endl;
	}
}

//================= ������� ������ ����������� ===================

void change_users() {
	std::string login;
	std::cout << "����i�� ���i� �����������, ����� ����i��� ��i����: \t";
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
				std::cout << "����������� ���i��� ��i����!" << std::endl;
			}
			else {
				std::cout << "�� ������� �i������ ���� ��� ������!" << std::endl;
			}
		}
		else {
			std::cout << "���������� �� ���������!" << std::endl;
		}
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� �������!" << std::endl;
	}
}

//================= �������� ���������� ���������� ===================

void view_statistics() {
	std::ifstream file("test_results.txt");
	if (file.is_open()) {
		std::string line;
		std::cout << "���������� ����������:\n";
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� �������!" << std::endl;
	}
}

//================= ��������� ����� ������ �������� ===================

void add_test() {
	std::string category, sub_category;
	
	std::cout << "����i�� �������i� �����: \t";
	std::cin.ignore();
	std::getline(std::cin, category);
	std::cout << "����i�� �i��������i� �����: \t";
	std::getline(std::cin, sub_category);

	
	std::vector<Question> questions;

	for (int i = 0; i < 10; ++i) {
		Question question;
		std::cout << "����i�� ����� ���������: \t";
		std::getline(std::cin, question.text);
		std::cout << "����i�� ���i���� �i����i�i (4 ���i����): \n";
		for (int j = 0; j < 4; ++j) {
			std::cout << "���i��� " << j + 1 << ": ";
			std::getline(std::cin, question.options[j]);
		}
		std::cout << "����i�� ����� ��������� �i����i�i (1-4): \t";
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
		std::cout << "���� ���i��� ������!" << std::endl;
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� ������!" << std::endl;
	}
}

//================= �������� ����� ===================

void view_tests() {
	std::ifstream file("tests.txt");
	if (file.is_open()) {
		std::string line;
		std::cout << "�����:\n";
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� �������!" << std::endl;
	}
}

//================= ��������� ������������ ===================

void admin_interface() {
	std::string username;
	std::string password;
	std::cout << "����i�� ���i� ���i�i��������: ";	
	std::cin >> username;

	std::cout << "����i�� ������ ���i�i��������: ";	
	std::cin >> password;
	std::ifstream file("admin.txt");
	if (file.is_open()) {
		std::string line_user, line_pass;
		file >> line_user >> line_pass;
		file.close();
		if (username == line_user && password == line_pass) {
			std::cout << "���i� �� ������ �i��i!" << std::endl;
			int choice;
			do {
				std::cout << "�����i�� �i�:\n";
				std::cout << "1. ������ ����\n";
				std::cout << "2. ����������� �����\n";
				std::cout << "3. ����������� ���������� ����������\n";
				std::cout << "4. ��i���� ���i� �� ������ ���i�i��������\n";
				std::cout << "5. �������� �����������\n";
				std::cout << "6. �������� �����������\n";
				std::cout << "7. ��i���� ���i �����������\n";
				std::cout << "8. ����� � ��������\n";
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
					std::cout << "���i� � ��������." << std::endl;
					break;
				default:
					std::cout << "���i���� ���i�. ��������� �� ���." << std::endl;
				}
			} while (choice != 8);
		}
		else {
			std::cout << "���i� ��� ������ ���i��i!" << std::endl;
			return;
		}
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� �������!" << std::endl;
		return;
	}
}