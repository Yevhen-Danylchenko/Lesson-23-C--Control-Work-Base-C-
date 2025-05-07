#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

#include "MyTestFile.h"
#include "TestResult.h"
#include "MyUserFile.h"

struct Users {
private:
	std::string name;
	std::string address;
	std::string phone;
	std::string login;
	std::string password;
public:
	Users() {}
	Users(std::string name, std::string address, std::string phone, std::string login, std::string password)
		: name(name), address(address), phone(phone), login(login), password(password) {}

	std::string getName() const {
		return name;
	}
	std::string getAddress() const {
		return address;
	}
	std::string getPhone() const {
		return phone;
	}
	std::string getLogin() const {
		return login;
	}
	std::string getPassword() const {
		return password;
	}

	void setName(const std::string& name) {
		this->name = name;
	}
	void setAddress(const std::string& address) {
		this->address = address;
	}
	void setPhone(const std::string& phone) {
		this->phone = phone;
	}
	void setLogin(const std::string& login) {
		this->login = login;
	}
	void setPassword(const std::string& password) {
		this->password = password;
	}
	void display() const {
		std::cout << "Name: " << name << "\n";
		std::cout << "Address: " << address << "\n";
		std::cout << "Phone: " << phone << "\n";
		std::cout << "Login: " << login << "\n";
		std::cout << "Password: " << password << "\n";
	}

	friend std::ostream& operator<<(std::ostream& output, const Users& user) {
		output << "Ім'я: " << user.getName() << '\n';
		output << " Адреса: " << user.getAddress() << '\n';
		output << " Телефон: " << user.getPhone() << '\n';
		output << " Логін: " << user.getLogin() << '\n';
		output << " Пароль: " << user.getPassword() << '\n';
		return output;
	}

	friend std::istream& operator>>(std::istream& input, Users& user) {
		std::string temp;
		std::getline(input, temp);
		user.setName(temp);

		std::getline(input, temp);
		user.setAddress(temp);

		std::getline(input, temp);
		user.setPhone(temp);

		std::getline(input, temp);
		user.setLogin(temp);

		std::getline(input, temp);
		user.setPassword(temp);

		return input;
	}
};

struct Question {
	std::string text;
	std::string options[4];
	int correct_answer;
};

struct Test {
private:
	std::string category;
	std::string sub_category;
	std::vector<Question> questions;
public:
	Test() {}
	Test(std::string category, std::string sub_category, std::vector<Question> questions)
		: category(category), sub_category(sub_category), questions(questions) {}

	std::string getCategory() const {
		return category;
	}
	std::string getSubCategory() const {
		return sub_category;
	}
	const std::vector<Question>& getQuestions() const {
		return questions;
	}


	void setCategory(const std::string& category) {
		this->category = category;
	}
	void setSubCategory(const std::string& sub_category) {
		this->sub_category = sub_category;
	}

	void addQuestion(const Question& q) {
		questions.push_back(q);
	}
};

struct TestResult {
private:
	std::string login;
	std::string test_name;
	int correct_answers;
	double score;
public:
	TestResult() {}
	TestResult(std::string login, std::string test_name, int correct_answers, double score)
		: login(login), test_name(test_name), correct_answers(correct_answers), score(score) {}

	std::string getLogin() const {
		return login;
	}
	std::string getTestName() const {
		return test_name;
	}
	int getCorrectAnswers() const {
		return correct_answers;
	}
	double getScore() const {
		return score;
	}

	void setLogin(const std::string& login) {
		this->login = login;
	}
	void setTestName(const std::string& test_name) {
		this->test_name = test_name;
	}
	void setCorrectAnswers(int correct_answers) {
		this->correct_answers = correct_answers;
	}
	void setScore(double score) {
		this->score = score;
	}
};