#include <iostream>
#include <istream>
#include <fstream>
#include <limits>


double getValue()
{
    while (true)
    {
        double a{};
        std::cin >> a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Попробуйте еще раз. \n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return a;
        }
    }
}

double** inputFromConsole(int* sizeOfData)
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите размерность таблицы, которую вы хотите ввести: " << std::endl;
    float n = getValue();
    while (n <= 0 || n != round(n)) {
        if (n <= 0) {
            std::cout << "Размерность матрицы должна быть больше нуля. Попробуйте еще раз: ";
            n = getValue();
        }
        else {
            std::cout << "Размерность матрицы должна быть целым числом: ";
            n = getValue();
        }
    }
    *sizeOfData = (int)n;
    double** arr = new double* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            std::cout << "Введите значение элемента: " << "[" << i << "]" << "[" << j << "]" << " = ";
            arr[i][j] = getValue();
        }
    }
    return arr;
}

double** inputFromFile(int* sizeOfData, std::ifstream& fin)
{
    int n{ 0 };
    fin >> n;
    *sizeOfData = n;
    double** arr = new double* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[n];
        for (int j = 0; j < n; j++) {
            fin >> arr[i][j];
        }
    }
    return arr;
}

char getWay()
{
    setlocale(LC_ALL, "Russian");
    char n{};
    std::cin >> n;
    while (n != '1' && n != '0') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Попробуйте еще раз. \n";
        std::cin >> n;
    }
    return n;
}

bool getNext()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Хотите повторить ввод данных? (Да - 1, Нет - 0)\n";
    char n{};
    std::cin >> n;
    while (n != '1' && n != '0') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Попробуйте еще раз. \n";
        std::cin >> n;
    }
    return n == '1';
}

void Task(double** arr, int size, std::ostream& f)
{
    f << "Входные данные: \n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            f << arr[i][j] << " ";
        }
        f << '\n';
    }
    f << "Результат работы программы: \n";
    for (int i = 0; i < size; i++)
    {
        double s = 0;
        if (arr[i][i] < 0) { // Сумма всех чисел предшествующих первому отрицательному числу
            for (int j = 0; j < size; j++)
            {
                if (arr[i][j] < 0) break;
                s += arr[i][j];
            }
        }
        else
        {
            int indexOfFirstPositiveNum = size;
            for (int k = 0; k < size; k++) // Поиск индекса первого неотрицательного числа
            {
                if (arr[i][k] >= 0)
                {
                    indexOfFirstPositiveNum = k;
                    break;
                }
            }
            for (int j = indexOfFirstPositiveNum; j < size; j++) //сумма последних элементов начиная с первого неотрицательного числа
            {
                s += arr[i][j];
            }
        }
        f << 'a' << i << " = " << s << '\n';
    }
}