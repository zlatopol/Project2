#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdio>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251); //Выбор кодировки UTF-8 для поддержки Кириллицы

    int n;
    const int lim = 10;

    cout << "Введите размерность квадратной матрицы" << endl;
    cin >> n; //Ввод размерности матрицы

    while ((cin.fail()) || (n < 1) || (n > lim)) //Проверка правильности ввода
    {
        cin.clear();
        cin.ignore(BUFSIZ, '\n');
        cout << "Поддерживаются числовые значения от 1 до " << lim << endl << "Введите размерность квадратной матрицы" << endl;
        cin >> n; //Ввод размерности матрицы
    }


    // cin.clear();
    cin.ignore(BUFSIZ, '\n');

    int array[lim][lim]; //Создание массива размерности n
    cout << endl << "Введите квадратную матрицу " << n << " на " << n << endl;

    for (int i = 0; i < n; i++) //Ввод массива
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j];
            while (cin.fail()) //Проверка правильности ввода
            {
                cin.clear();
                cin.ignore(BUFSIZ, '\n');
                cout << "Ошибка, введено нечисловое значение, введите правильные значения начиная с ячейки " << i + 1 << " " << j + 1 << endl;
                cin >> array[i][j];
            }
        }
    }
    cout << endl;

    cout << "Ваш массив:" << endl << endl;
    for (int i = 0; i < n; i++) //Вывод введенного массива
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(50 / n) << right << array[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i < n; i++) //Изменение массива
    {
        for (int j = 0; j < i; j++)
        {
            array[i][j] = 0;
        }
    }
    cout << "Измененный массив:" << endl << endl;
    for (int i = 0; i < n; i++) //Вывод измененного массива
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(50 / n) << array[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}