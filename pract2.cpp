#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Определяем структуру для хранения информации о дате
struct Date {
    int day;
    int month;
    int year;
};

// Определяем структуру для хранения информации о автомобиле
struct CarInfo {
    Date date;
    string carNumber;
};

int main() {
    setlocale(0, "");

    // Открываем файл для чтения
    ifstream inputFile("D:\\автомобили.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка при открытии файла." << endl;
        return 1;
    }

    vector<CarInfo> carList; // Вектор массива для хранения информации о автомобилях

    CarInfo car; // Создаем объект структуры для хранения информации о текущем автомобиле

    // Считываем дату и номер автомобиля из файла и сохраняем в векторе
    while (inputFile) {
        if (!(inputFile >> car.date.day)) {
            break;  // Прерываем цикл если не удалось считать день
        }
        inputFile.get();  // Считываем разделитель
        if (!(inputFile >> car.date.month)) {
            break;  // Прерываем цикл если не удалось считать месяц
        }
        inputFile.get();  // Считываем разделитель
        if (!(inputFile >> car.date.year)) {
            break;  // Прерываем цикл если не удалось считать год
        }
        inputFile >> car.carNumber;

        carList.push_back(car);
    }

    // Закрываем файл
    inputFile.close();

    // Выводим информацию о всех автомобилях
    for (const CarInfo& car : carList) {
        cout << "Дата: " << car.date.day << "." << car.date.month << "." << car.date.year
            << ", Номер автомобиля: " << car.carNumber << endl;
    }

    return 0;
}