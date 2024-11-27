#include "FileOperations.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <climits>

// Задание 1: Заполнение бинарного файла случайными числами
void FileOperations::fillBinaryFileWithRandomNumbers(const std::string& filename, int numCount) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    srand(time(0));  // Инициализация генератора случайных чисел
    for (int i = 0; i < numCount; ++i) {
        int num = rand();
        outFile.write(reinterpret_cast<char*>(&num), sizeof(num));
    }

    outFile.close();
}

// Задание 2: Чтение данных из бинарного файла и вывод на экран
void FileOperations::readBinaryFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    int num;
    while (inFile.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    inFile.close();
}

// Задание 3: Заполнение бинарного файла структурами (Toy)
void FileOperations::fillBinaryFileWithToys(const std::string& filename, int toyCount) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < toyCount; ++i) {
        Toy toy;
        toy.name = "Toy_" + std::to_string(i);
        toy.price = static_cast<float>(rand() % 100) + 1;
        toy.minAge = rand() % 10 + 1;
        toy.maxAge = toy.minAge + rand() % 5;

        outFile.write(reinterpret_cast<char*>(&toy), sizeof(Toy));
    }

    outFile.close();
}

// Задание 4: Чтение данных из бинарного файла (Toy) и вывод информации
void FileOperations::readBinaryFileWithToys(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    Toy toy;
    while (inFile.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        std::cout << "Toy Name: " << toy.name << ", Price: " << toy.price 
                  << ", Age Range: " << toy.minAge << "-" << toy.maxAge << std::endl;
    }

    inFile.close();
}

// Задание 5: Заполнение текстового файла случайными числами (по одному числу на строку)
void FileOperations::fillTextFileWithRandomNumbers(const std::string& filename, int numCount) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < numCount; ++i) {
        int num = rand();
        outFile << num << std::endl;
    }

    outFile.close();
}

// Задание 6: Заполнение текстового файла случайными числами (по несколько чисел на строку)
void FileOperations::fillTextFileWithMultipleNumbersPerLine(const std::string& filename, int numLines, int numbersPerLine) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < numLines; ++i) {
        for (int j = 0; j < numbersPerLine; ++j) {
            int num = rand();
            outFile << num << " ";
        }
        outFile << std::endl;
    }

    outFile.close();
}

// Задание 7: Создание нового файла на основе исходного (нарастающим порядком чисел)
void FileOperations::createCumulativeFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Unable to open file " << inputFile << std::endl;
        return;
    }

    std::vector<int> numbers;
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }

    inFile.close();

    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Unable to open file " << outputFile << std::endl;
        return;
    }

    for (size_t i = 1; i <= numbers.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            outFile << numbers[j] << " ";
        }
        outFile << std::endl;
    }

    outFile.close();
}

// Задание 8: Копирование данных из файла в квадратную матрицу и поиск строки с минимальной суммой
void FileOperations::copyToMatrixAndFindMinSumRow(const std::string& filename, int n) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    std::vector<int> numbers;
    int num;
    while (inFile >> num) {
        numbers.push_back
