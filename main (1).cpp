#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

// Структура для хранения информации об игрушке
struct Toy {
    string name;
    int price;
    int age_min;
    int age_max;
};

class FileOperations {
public:
    // Заполнение бинарного файла случайными числами
    static void fillBinaryFile(const string& filename, int size) {
        ofstream file(filename, ios::binary);
        if (file) {
            srand(time(0));
            for (int i = 0; i < size; ++i) {
                int num = rand() % 1000;  // Генерация случайного числа от 0 до 999
                file.write(reinterpret_cast<char*>(&num), sizeof(num));
            }
        }
    }

    // Чтение бинарного файла
    static void readBinaryFile(const string& filename) {
        ifstream file(filename, ios::binary);
        if (file) {
            int num;
            while (file.read(reinterpret_cast<char*>(&num), sizeof(num))) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    // Заполнение бинарного файла структурой Toy
    static void fillToyBinaryFile(const string& filename, int size) {
        ofstream file(filename, ios::binary);
        if (file) {
            srand(time(0));
            for (int i = 0; i < size; ++i) {
                Toy toy = {
                    "Toy" + to_string(i + 1),
                    rand() % 500 + 100,  // Цена от 100 до 599
                    rand() % 10 + 1,     // Минимальный возраст от 1 до 10
                    rand() % 10 + 5      // Максимальный возраст от 5 до 15
                };
                file.write(reinterpret_cast<char*>(&toy), sizeof(toy));
            }
        }
    }

    // Чтение бинарного файла с Toy структурами
    static void readToyBinaryFile(const string& filename) {
        ifstream file(filename, ios::binary);
        if (file) {
            Toy toy;
            while (file.read(reinterpret_cast<char*>(&toy), sizeof(toy))) {
                cout << "Name: " << toy.name << ", Price: " << toy.price
                     << ", Age: " << toy.age_min << "-" << toy.age_max << endl;
            }
        }
    }

    // Заполнение текстового файла случайными целыми числами (по одному числу на строку)
    static void fillTextFile(const string& filename, int size) {
        ofstream file(filename);
        if (file) {
            srand(time(0));
            for (int i = 0; i < size; ++i) {
                file << rand() % 1000 << endl;  // Генерация случайных чисел от 0 до 999
            }
        }
    }

    // Заполнение текстового файла случайными целыми числами (несколько чисел на строку)
    static void fillTextFileMultiple(const string& filename, int rows, int numbers_per_row) {
        ofstream file(filename);
        if (file) {
            srand(time(0));
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < numbers_per_row; ++j) {
                    file << rand() % 1000 << " ";
                }
                file << endl;
            }
        }
    }

    // Задание 1: Сформировать новый файл на основе исходного
    static void task1(const string& inputFilename, const string& outputFilename) {
        ifstream inFile(inputFilename);
        if (inFile) {
            vector<int> numbers;
            int num;
            while (inFile >> num) {
                numbers.push_back(num);
            }

            ofstream outFile(outputFilename);
            for (size_t i = 1; i <= numbers.size(); ++i) {
                for (size_t j = 0; j < i; ++j) {
                    outFile << numbers[j] << " ";
                }
                outFile << endl;
            }
        }
    }

    // Задание 2: Скопировать элементы в матрицу n×n и найти строку с минимальной суммой
    static void task2(const string& filename, int n) {
        ifstream file(filename);
        vector<int> numbers;
        int num;
        while (file >> num) {
            numbers.push_back(num);
        }

        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int idx = 0;
        for (int i = 0; i < n && idx < numbers.size(); ++i) {
            for (int j = 0; j < n && idx < numbers.size(); ++j) {
                matrix[i][j] = numbers[idx++];
            }
        }

        // Найти строку с минимальной суммой
        int minSum = INT_MAX;
        int rowIndex = -1;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += matrix[i][j];
            }
            if (sum < minSum) {
                minSum = sum;
                rowIndex = i;
            }
        }

        cout << "Строка с суммой, близкой к нулю: " << rowIndex + 1 << endl;
    }

    // Задание 3: Найти игрушки, которые подходят детям 4 и 10 лет
    static void task3(const string& filename) {
        ifstream file(filename, ios::binary);
        if (file) {
            Toy toy;
            while (file.read(reinterpret_cast<char*>(&toy), sizeof(toy))) {
                if (toy.age_min <= 4 && toy.age_max >= 4 && toy.age_min <= 10 && toy.age_max >= 10) {
                    cout << "Suitable toy: " << toy.name << ", Price: " << toy.price << endl;
                }
            }
        }
    }

    // Задание 4: Произведение максимального и минимального элементов
    static void task4(const string& filename) {
        ifstream file(filename);
        int num, minVal = INT_MAX, maxVal = INT_MIN;
        while (file >> num) {
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
        }
        cout << "Произведение максимального и минимального элементов: " << maxVal * minVal << endl;
    }

    // Задание 5: Количество нечётных элементов
    static void task5(const string& filename) {
        ifstream file(filename);
        int num, count = 0;
        while (file >> num) {
            if (num % 2 != 0) {
                ++count;
            }
        }
        cout << "Количество нечётных элементов: " << count << endl;
    }

    // Задание 6: Длины строк в текстовом файле
    static void task6(const string& filename, const string& outputFilename) {
        ifstream inFile(filename);
        ofstream outFile(outputFilename);
        string line;
        while (getline(inFile, line)) {
            outFile << line.length() << endl;
        }
    }
};

// Главное меню
void menu() {
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Заполнить бинарный файл случайными числами\n";
        cout << "2. Прочитать бинарный файл с числами\n";
        cout << "3. Заполнить бинарный файл игрушками\n";
        cout << "4. Прочитать бинарный файл с игрушками\n";
        cout << "5. Заполнить текстовый файл случайными числами (по одному числу на строку)\n";
        cout << "6. Заполнить текстовый файл случайными числами (несколько чисел на строку)\n";
        cout << "7. Выполнить задание 1\n";
        cout << "8. Выполнить задание 2\n";
        cout << "9. Выполнить задание 3\n";
        cout << "10. Выполнить задание 4\n";
        cout << "11. Выполнить задание 5\n";
        cout << "12. Выполнить задание 6\n";
        cout << "0. Выход\n";
        cout << "Введите номер задания: ";
        cin >> choice;

        string filename, outputFilename;
        int n, size;
        switch (choice) {
        case 1:
            cout << "Введите имя файла: ";
            cin >> filename;
            cout << "Введите размер файла: ";
            cin >> size;
            FileOperations::fillBinaryFile(filename, size);
            break;
        case 2:
            cout << "Введите имя файла: ";
            cin >> filename;
            FileOperations::readBinaryFile(filename);
            break;
        case 3:
            cout << "Введите имя файла: ";
            cin >> filename;
            cout << "Введите количество игрушек: ";
            cin >> size;
            FileOperations::fillToyBinaryFile(filename, size);
            break;
        case 4:
            cout << "Введите имя файла: ";
            cin >> filename;
            FileOperations::readToyBinaryFile(filename);
            break;
        case 5:
            cout << "Введите имя файла: ";
            cin >> filename;
            cout << "Введите количество чисел: ";
            cin >> size;
            FileOperations::fillTextFile(filename, size);
            break;
        case 6:
            cout << "Введите имя файла: ";
            cin >> filename;
            cout << "Введите количество строк: ";
            cin >> size;
            FileOperations::fillTextFileMultiple(filename, size, 5);
            break;
        case 7:
            cout << "Введите имя исходного файла: ";
            cin >> filename;
            cout << "Введите имя выходного файла: ";
            cin >> outputFilename;
            FileOperations::task1(filename, outputFilename);
            break;
        case 8:
            cout << "Введите имя файла: ";
            cin >> filename;
            cout << "Введите размер матрицы n: ";
            cin >> n;
            FileOperations::task2(filename, n);
            break;
        case 9:
            cout << "Введите имя файла: ";
            cin >> filename;
            FileOperations::task3(filename);
            break;
        case 10:
            cout << "Введите имя файла: ";
            cin >> filename;
            FileOperations::task4(filename);
            break;
        case 11:
            cout << "Введите имя файла: ";
            cin >> filename;
            FileOperations::task5(filename);
            break;
        case 12:
            cout << "Введите имя исходного файла: ";
            cin >> filename;
            cout << "Введите имя выходного файла: ";
            cin >> outputFilename;
            FileOperations::task6(filename, outputFilename);
            break;
        case 0:
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
