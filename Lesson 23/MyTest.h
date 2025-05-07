#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


const count_users = 100;
const count_test = 4;

struct User
{
	std::string name;
	std::string address;
	std::string phone;
	std::string login;
	std::string password;
};

struct Question
{
	std::string question;
	std::string answer[4];
	int correct_answer;
};

struct Test
{
	std::string category;
	std::string description;
	std::string question[10];
	std::string answer[10];
	std::vector<Question> questions;
};

struct TestResult
{
	std::string test_name;
	std::string login;
	int correct_answers;
	double score;
};

User users[count_users];
int user_count = 0;

Test tests[count_test];
int test_count = 0;


void add_user()
{
	if (user_count < count_users)
	{
		std::cout << "Enter user name: ";
		std::string name;
		std::getline(std::cin, name);
		std::cout << "Enter user address: ";
		std::string address;
		std::getline(std::cin, address);
		std::cout << "Enter user phone: ";
		std::string phone;
		std::getline(std::cin, phone);
		std::cout << "Enter user login: ";
		std::string login;
		std::getline(std::cin, login);
		if (login.empty())
		{
			std::cout << "Login cannot be empty.\n";
			return;
		}
		else {
			for (int i = 0; i < user_count; i++)
			{
				if (users[i].login == login)
				{
					std::cout << "Login already exists.\n";
					return;
				}
				else {
					std::cout << "Login is available.\n";
					users[user_count].login = login;
				}
			}
			
		}
		std::cout << "Enter user password: ";
		std::string password;
		std::getline(std::cin, password);

		users[user_count].name = name;
		users[user_count].address = address;
		users[user_count].phone = phone;		
		users[user_count].password = password;
		user_count++;
		std::cout << "User added successfully.\n";
	}
	else
	{
		std::cout << "User limit reached.\n";
	}
}

bool login_user()
{
	std::cout << "Enter login: ";
	std::string login;
	std::getline(std::cin, login);
	std::cout << "Enter password: ";
	std::string password;
	std::getline(std::cin, password);

	for (int i = 0; i < user_count; i++)
	{
		if (users[i].login == login && users[i].password == password)
		{
			std::cout << "Login successful.\n";
			return true;
		}
	}
	std::cout << "Invalid login or password.\n";
	return false;
}


void take_test() {	
	std::cout << "Enter test name: ";
	std::string test_name;
	std::getline(std::cin, test_name);
	for (int i = 0; i < test_count; i++)
	{
		if (tests[i].category == test_name)
		{
			std::cout << "Test found.\n";
			std::cout << "Test description: " << tests[i].description << "\n";
			for (int j = 0; j < 10; j++)
			{
				std::cout << "Question " << j + 1 << ": " << tests[i].question[j] << "\n";
				std::cout << "Answer: " << tests[i].answer[j] << "\n";
				std::string correct_answer = "";
				int count_correct = 0;
				std::cout << "Enter your answer (1-4): ";
				std::cin >> correct_answer;
				if (correct_answer == tests[i].answer[j])
				{
					count_correct++;
					std::cout << "Correct answer!\n";
				}
				else
				{
					std::cout << "Wrong answer.\n";
				}
			}
			return;
		}
	}
	std::cout << "Test not found.\n";
}

void add_test()
{
	if (test_count < count_test)
	{
		std::cout << "Enter test name: ";
		std::string test_name;
		std::getline(std::cin, test_name);
		std::cout << "Enter test description: ";
		std::string test_description;
		std::getline(std::cin, test_description);
		tests[test_count].category = test_name;
		tests[test_count].description = test_description;

		for (int i = 0; i < 10; i++)
		{
			std::cout << "Enter question " << i + 1 << ": ";
			std::string question;
			std::getline(std::cin, question);
			tests[test_count].question[i] = question;

			for (int j = 0; j < 4; j++)
			{
				std::cout << "Enter answer " << j + 1 << ": ";
				std::string answer;
				std::getline(std::cin, answer);
				tests[test_count].answer[j] = answer;
			}
			test_count++;
		}
		std::cout << "Test added successfully.\n";
	}
	else
	{
		std::cout << "Test limit reached.\n";
	}
}

void save_test_results()
{
	std::ofstream file("test_results.txt");
	if (file.is_open())
	{
		for (int i = 0; i < test_count; i++)
		{
			file << tests[i].category << "\n";
			file << tests[i].description << "\n";
			for (int j = 0; j < 10; j++)
			{
				file << tests[i].question[j] << "\n";
				file << tests[i].answer[j] << "\n";
			}
		}
		file.close();
		std::cout << "Test results saved successfully.\n";
	}
	else
	{
		std::cout << "Unable to open file.\n";
	}
}

void load_test_results()
{
	std::ifstream file("test_results.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string test_name;
			std::getline(file, test_name);
			std::string test_description;
			std::getline(file, test_description);
			tests[test_count].category = test_name;
			tests[test_count].description = test_description;

			for (int j = 0; j < 10; j++)
			{
				std::string question;
				std::getline(file, question);
				tests[test_count].question[j] = question;

				for (int k = 0; k < 4; k++)
				{
					std::string answer;
					std::getline(file, answer);
					tests[test_count].answer[k] = answer;
				}
			}
			test_count++;
		}
		file.close();
		std::cout << "Test results loaded successfully.\n";
	}
	else
	{
		std::cout << "Unable to open file.\n";
	}
}