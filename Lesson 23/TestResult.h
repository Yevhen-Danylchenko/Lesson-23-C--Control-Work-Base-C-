
#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "MyTestFile.h"



//================= Завантаження з файлу ===================

void TestResults() {
	std::ifstream file("test_results.txt");
	if (file.is_open()) {
        std::ifstream file("test_results.txt");
        if (!file.is_open()) {
            std::cerr << "Не вдалося вiдкрити файл для читання.\n";
            return;
        }
		
		std::string line;
		std::cout << "Результати тестiв:\n";
		while (std::getline(file, line)) {
			
			std::cout << line << std::endl;
		}
	}
	else {
		std::cerr << "Не вдалося вiдкрити файл для читання.\n";
	}
}

#endif 
