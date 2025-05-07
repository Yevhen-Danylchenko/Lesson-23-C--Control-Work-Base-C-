#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

#include "Structs.h"
#include "TestResult.h"


//======================= ���������� ����� ======================

std::string register_user() {
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

//======================= ����������� ����� ======================

int category;
void takeTest(Test test, Users user);
void takeTest1(Test test1, Users user);
Test createTest(int category);



void takeTest(Test test, Users user) {
	std::cout << "�� ��������� ���� � �������i�: " << test.getCategory() << "\n";
	std::cout << "�i��������i�: " << test.getSubCategory() << "\n";
	std::cout << "�i����i����� �� ���������, ��������� ����� �i����i�i.\n";

	int correct_answers = 0;
	for (size_t i = 0; i < test.getQuestions().size(); ++i) {
		std::cout << "������� " << i + 1 << ": " << test.getQuestions()[i].text << "\n";
		for (int j = 0; j < 4; ++j) {
			std::cout << j + 1 << ". " << test.getQuestions()[i].options[j] << "\n";
		}
		int answer;
		std::cout << "��� ���i�: ";
		std::cin >> answer;

		if (answer == test.getQuestions()[i].correct_answer) {
			correct_answers++;
		}
	}
	double score = (double)correct_answers / test.getQuestions().size() * 12;
	std::cout << "��� ���������: " << correct_answers << "/" << test.getQuestions().size() << " ���������� �i����i���.\n";

	TestResult result(user.getLogin(), test.getCategory(), correct_answers, score);
	std::cout << "���������� ����������:\n";
	std::cout << "���i�: " << result.getLogin() << "\n";
	std::cout << "����� �����: " << result.getTestName() << "\n";
	std::cout << "�i���i��� ���������� �i����i���: " << result.getCorrectAnswers() << "\n";
	std::cout << "��i���: " << result.getScore() << "%\n";

	std::ofstream file("test_results.txt", std::ios::app);
	
	if (file.is_open()) {
		file << "���i�: " << result.getLogin() << "\n";
		file << "����� �����: " << result.getTestName() << "\n";
		file << "�i���i��� ���������� �i����i���: " << result.getCorrectAnswers() << "\n";
		file << "��i���: " << result.getScore() << "%\n";
		file.close();
		std::cout << "���������� ���������� ��������� � ����.\n";
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� ������.\n";
	}
}

void takeTest1(Test test1, Users user) {
	std::cout << "�� ��������� ���� � �������i�: " << test1.getCategory() << "\n";
	std::cout << "�i��������i�: " << test1.getSubCategory() << "\n";
	std::cout << "�i����i����� �� ���������, ��������� ����� �i����i�i.\n";

	int correct_answers = 0;
	for (size_t i = 0; i < test1.getQuestions().size(); ++i) {
		std::cout << "������� " << i + 1 << ": " << test1.getQuestions()[i].text << "\n";
		for (int j = 0; j < 4; ++j) {
			std::cout << j + 1 << ". " << test1.getQuestions()[i].options[j] << "\n";
		}
		int answer;
		std::cout << "��� ���i�: ";
		std::cin >> answer;

		if (answer == test1.getQuestions()[i].correct_answer) {
			correct_answers++;
		}
	}
	double score = (double)correct_answers / test1.getQuestions().size() * 12;
	std::cout << "��� ���������: " << correct_answers << "/" << test1.getQuestions().size() << " ���������� �i����i���.\n";

	TestResult result(user.getLogin(), test1.getCategory(), correct_answers, score);
	std::cout << "���������� ����������:\n";
	std::cout << "���i�: " << result.getLogin() << "\n";
	std::cout << "����� �����: " << result.getTestName() << "\n";
	std::cout << "�i���i��� ���������� �i����i���: " << result.getCorrectAnswers() << "\n";
	std::cout << "��i���: " << result.getScore() << "%\n";

	std::ofstream file("test_results.txt", std::ios::app);
	
	if (file.is_open()) {
		file << "���i�: " << result.getLogin() << "\n";
		file << "����� �����: " << result.getTestName() << "\n";
		file << "�i���i��� ���������� �i����i���: " << result.getCorrectAnswers() << "\n";
		file << "��i���: " << result.getScore() << "%\n";
		file.close();
		std::cout << "���������� ���������� ��������� � ����.\n";
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� ������.\n";
	}
}

//======================= ���i� ����� ======================

void testName();

void login_user() {
	Users user;
	std::string login, password;
	std::cout << "����i�� ��� ���i�: \t";
	std::cin >> login;
	std::cout << "����i�� ��� ������: \t";
	std::cin >> password;

	setlocale(LC_ALL, "ukr");

	std::ifstream file("users.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			if (line.find(login) == std::string::npos && line.find(password) == std::string::npos) {
				std::cout << "���i� i ������ �i��i!" << std::endl;
				testName();
				return;
			}
		}
		file.close();
		std::cout << "���i� ��� ������ ���i��i!" << std::endl;
	}
	else {
		std::cout << "�� ������� �i������ ���� ��� �������!" << std::endl;
	}
}

//======================= ��������� ����� ======================

Test createTest(int category) {
	Test test;
	Test test1;

	test.setCategory("����������");
	test.setSubCategory("��������� ����������");

	test1.setCategory("�i����");
	test1.setSubCategory("�����i��");

	Question q1 = { "��i���� ������ �� ���?", {"4", "6", "8", "12"}, 2 };
	Question q2 = { "��� ����� � ������?", {"15", "21", "28", "39"}, 3 };
	Question q3 = { "��� ������� ��� ���������� ����i ����?", {"2Pir", "Pir^2",  "Pid", "4Pir^2"}, 2 };
	Question q4 = { "��� ������� ��� ���������� ��'��� ���i����?", {"2Pirh", "Pid^2h", "Pir^2h", "4/3Pir^3"}, 3 };
	Question q5 = { "��� ������� ��� ���������� ����i ����������?", {"a^2 + b^2 = c^2", "Pir^2", "4/3Pir^3", "1/2 * a * b"}, 4 };
	Question q6 = { "��� ������� ��� ���������� ��'��� ���i?", {"4/3Pir^3", "Pir^2h", "2Pirh", "Pid^2h"}, 1 };
	Question q7 = { "��� ������� ��� ���������� ����i ������������?", {"a * b", "2(a + b)", "a^2 + b^2 = c^2", "Pir^2"}, 1 };
	Question q8 = { "��� ������� ��� ���������� ��������� ��������?", { "2(a + b)", "4a", "a^2 + b^2 = c^2", "Pir^2"}, 2 };
	Question q9 = { "��� ������� ��� ���������� ����i ������i�?", {"(a + b)h/2", "a^2 + b^2 = c^2", "Pir^2", "4/3Pir^3"}, 1 };
	Question q10 = { "��� ������� ��� ���������� ��'��� ������?", {"2Pirh", "Pid^2h", "1/3Pir^2h", "4/3Pir^3"}, 3 };

	Question q1_1 = { "��� ������� ��� ���������� ��������i?", {"v = s/t", "v = at", "v = a + b", "v = s + t"}, 1 };
	Question q1_2 = { "��� ������� ��� ���������� �����������?", {"a = s/v", "a = t/v", "a = v + t", "a = v/t",}, 4 };
	Question q1_3 = { "��� ������� ��� ���������� ����?", {"F = mv", "F = ma", "F = at", "F = s/t"}, 2 };
	Question q1_4 = { "��� ������� ��� ���������� ������?", {"A = F / s", "A = F + s", "A = F * s", "A = F - s"}, 3 };
	Question q1_5 = { "��� ������� ��� ���������� �����i�?", {"E = F * s", "E = m * g", "E = m * a", "E = F / t"}, 1 };
	Question q1_6 = { "��� ������� ��� ���������� �����?", {"P = F * S", "P = F / S", "P = S / F", "P = F + S"}, 2 };
	Question q1_7 = { "��� ������� ��� ���������� ��'���?", {"V = S * h", "V = S / h", "V = S + h", "V = S - h"}, 1 };
	Question q1_8 = { "��� ������� ��� ���������� �������?", {"d = V / m", "d = m + V", "d = m / V", "d = m - V"}, 3 };
	Question q1_9 = { "��� ������� ��� ���������� ������� ����?", {"M = F * r", "M = F / r", "M = F + r", "M = F - r"}, 1 };
	Question q1_10 = { "��� ������� ��� ���������� ������ ��������i?", {"w = v * r", "w = v + r", "w = v - r", "w = v / r", }, 4 };

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
		std::cout << "���i��� �������i� �����!" << std::endl;
	}
}

//======================= ���i� ����� ======================

void testName() {
	int test_name;
	int sub_category;
	std::cout << "����i�� ����� �����: 1 - 2 \t";
	std::cin >> test_name;
	if (test_name == 1) {
		std::cout << "����i�� �i��������i� �����: 1 \t";
		std::cin >> sub_category;
		if (sub_category == 1) {
			std::cout << "�� ������� ���� � �������i�: " << test_name << "\n";
			std::cout << "�i��������i�: " << sub_category << "\n";
			category = 1;
			takeTest(createTest(category), Users());
		}

		else {
			std::cout << "�i��������i� �� ��������!" << std::endl;
		}
	}
	else if (test_name == 2) {
		std::cout << "����i�� �i��������i� �����: \t";
		std::cin >> sub_category;
		if (sub_category == 1) {
			std::cout << "�� ������� ���� � �������i�: " << test_name << "\n";
			std::cout << "�i��������i�: " << sub_category << "\n";
			category = 2;
			takeTest1(createTest(category), Users());
		}
		else {
			std::cout << "�i��������i� �� ��������!" << std::endl;
		}
	}
	else {
		std::cout << "���� �� ��������!" << std::endl;
	}
}

//======================= ��������� ����������� ======================

void user_interface() {
	int choice;

	std::cout << "��� �i�� ������� �������!" << std::endl;
	std::cout << "1. �������i�" << std::endl;
	std::cout << "2. ���i�" << std::endl;
	std::cout << "3. ���������� ����i�" << std::endl;
	std::cout << "4. ���i�" << std::endl;
	std::cout << "�����i�� �i�: \t";
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
		std::cout << "���i� � ��������." << std::endl;
		break;
	default:
		std::cout << "���i���� ���i�. ��������� �� ���." << std::endl;
	};
}
