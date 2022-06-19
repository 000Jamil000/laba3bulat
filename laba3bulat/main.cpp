#include <iostream>
#include <fstream>
#include "myfuncs.h"
#include "const.h"



int main()
{
    setlocale(LC_ALL, "Russian");
    char inputWay{}, outputWay{};
    bool next{ true }; //флаг - запрос на повторный ввод данных
    int size{ 0 };//переменная для получения размера массива через указатель при инициализации
    std::ifstream fin(inputFile);
    std::ofstream fout(outputFile);

    while (next) {
        std::cout << "Ввод с консоли (0) или из файла(1): " << std::endl;
        inputWay = getWay();
        std::cout << "Вывод в консоль (0) или в файл (1): " << std::endl;
        outputWay = getWay();

        if (inputWay == '0' && outputWay == '0') { //консоль - консоль
            double** arr = inputFromConsole(&size);
            Task(arr, size, std::cout);
            next = getNext();
        }

        else if (inputWay == '0' && outputWay == '1') //консоль - файл
        {
            if (fout.is_open())
            {
                double** arr = inputFromConsole(&size);
                Task(arr, size, fout);
                next = getNext();
            }
        }

        else if (inputWay == '1' && outputWay == '0') //файл - консоль
        {
            if (fin.is_open())
            {
                double** arr = inputFromFile(&size, fin);
                Task(arr, size, std::cout);
                next = false;
            }
        }

        else if (inputWay == '1' && outputWay == '1') // файл - файл
        {
            if (fin.is_open() && fout.is_open())
            {
                double** arr = inputFromFile(&size, fin);
                Task(arr, size, fout);
                next = false;
            }
        }
    }
    std::cout << "Программа успешно завершила свою работу\n";
    fout.close();
    fin.close();
    return 0;
}


