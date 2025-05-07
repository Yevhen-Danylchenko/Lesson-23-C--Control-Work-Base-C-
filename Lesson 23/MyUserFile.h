#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

//#include "MyTestFile.h"
//#include "TestResult.h"
//
//struct Users {
//private:
//	std::string name;
//	std::string address;
//	std::string phone;
//	std::string login;
//	std::string password;
//public:
//	Users() {}
//	Users(std::string name, std::string address, std::string phone, std::string login, std::string password)
//		: name(name), address(address), phone(phone), login(login), password(password) {}
//
//	std::string getName() const {
//		return name;
//	}
//	std::string getAddress() const {
//		return address;
//	}
//	std::string getPhone() const {
//		return phone;
//	}
//	std::string getLogin() const {
//		return login;
//	}
//	std::string getPassword() const {
//		return password;
//	}
//
//	void setName(const std::string& name) {
//		this->name = name;
//	}
//	void setAddress(const std::string& address) {
//		this->address = address;
//	}
//	void setPhone(const std::string& phone) {
//		this->phone = phone;
//	}
//	void setLogin(const std::string& login) {
//		this->login = login;
//	}
//	void setPassword(const std::string& password) {
//		this->password = password;
//	}
//	void display() const {
//		std::cout << "Name: " << name << "\n";
//		std::cout << "Address: " << address << "\n";
//		std::cout << "Phone: " << phone << "\n";
//		std::cout << "Login: " << login << "\n";
//		std::cout << "Password: " << password << "\n";
//	}
//
//	friend std::ostream& operator<<(std::ostream& output, const Users& user) {
//		output << "��'�: " << user.getName() << '\n';
//		output << " ������: " << user.getAddress() << '\n';
//		output << " �������: " << user.getPhone() << '\n';
//		output << " ����: " << user.getLogin() << '\n';
//		output << " ������: " << user.getPassword() << '\n';
//		return output;
//	}
//
//	friend std::istream& operator>>(std::istream& input, Users& user) {
//		std::string temp;
//		std::getline(input, temp);
//		user.setName(temp);
//
//		std::getline(input, temp);
//		user.setAddress(temp);
//
//		std::getline(input, temp);
//		user.setPhone(temp);
//
//		std::getline(input, temp);
//		user.setLogin(temp);
//
//		std::getline(input, temp);
//		user.setPassword(temp);
//
//		return input;
//	}
//};

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
