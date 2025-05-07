
#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "MyTestFile.h"



//================= ������������ � ����� ===================

void TestResults() {
	std::ifstream file("test_results.txt");
	if (file.is_open()) {
        std::ifstream file("test_results.txt");
        if (!file.is_open()) {
            std::cerr << "�� ������� �i������ ���� ��� �������.\n";
            return;
        }
		
		std::string line;
		std::cout << "���������� ����i�:\n";
		while (std::getline(file, line)) {
			
			std::cout << line << std::endl;
		}
	}
	else {
		std::cerr << "�� ������� �i������ ���� ��� �������.\n";
	}
}

#endif 
