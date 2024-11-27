#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>
#include <vector>

class FileOperations {
public:
    // Задание 1: Заполнение бинарного файла случайными числами
    static void fillBinaryFileWithRandomNumbers(const std::string& filename, int numCount);
    
    // Задание 2: Чтение данных из бинарного файла и вывод на экран
    static void readBinaryFile(const std::string& filename);
    
    // Задание 3: Заполнение бинарного файла структурами (Toy)
    struct Toy {
        std::string name;
        float price;
        int minAge;
        int maxAge;
    };
    static void fillBinaryFileWithToys(const std::string& filename, int toyCount);
    
    // Задание 4: Чтение данных из бинарного файла (Toy) и вывод информации
    static void readBinaryFileWithToys(const std::string& filename);
    
    // Задание 5: Заполнение текстового файла случайными числами (по одному числу на строку)
    static void fillTextFileWithRandomNumbers(const std::string& filename, int numCount);
    
    // Задание 6: Заполнение текстового файла случайными числами (по несколько чисел на строку)
    static void fillTextFileWithMultipleNumbersPerLine(const std::string& filename, int numLines, int numbersPerLine);
    
    // Задание 7: Создание нового файла на основе исходного (нарастающим порядком чисел)
    static void createCumulativeFile(const std::string& inputFile, const std::string& outputFile);
    
    // Задание 8: Копирование данных из файла в квадратную матрицу и поиск строки с минимальной суммой
    static void copyToMatrixAndFindMinSumRow(const std::string& filename, int n);
    
    // Задание 9: Поиск игрушек для детей 4 и 10 лет
    static void findToysForChildren4And10(const std::string& filename);
    
    // Задание 10: Поиск произведения максимального и минимального чисел в файле
    static void findProductOfMinMaxInFile(const std::string& filename);
    
    // Задание 11: Подсчет нечётных чисел в файле
    static void countOddNumbersInFile(const std::string& filename);
    
    // Задание 12: Создание нового текстового файла с длиной строк из исходного файла
    static void createTextFileWithLineLengths(const std::string& inputFile, const std::string& outputFile);
};

#endif // FILE_OPERATIONS_H
