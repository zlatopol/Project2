#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdio>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251); //����� ��������� UTF-8 ��� ��������� ���������

    int n;
    const int lim = 10;

    cout << "������� ����������� ���������� �������" << endl;
    cin >> n; //���� ����������� �������

    while ((cin.fail()) || (n < 1) || (n > lim)) //�������� ������������ �����
    {
        cin.clear();
        cin.ignore(BUFSIZ, '\n');
        cout << "�������������� �������� �������� �� 1 �� " << lim << endl << "������� ����������� ���������� �������" << endl;
        cin >> n; //���� ����������� �������
    }


    // cin.clear();
    cin.ignore(BUFSIZ, '\n');

    int array[lim][lim]; //�������� ������� ����������� n
    cout << endl << "������� ���������� ������� " << n << " �� " << n << endl;

    for (int i = 0; i < n; i++) //���� �������
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j];
            while (cin.fail()) //�������� ������������ �����
            {
                cin.clear();
                cin.ignore(BUFSIZ, '\n');
                cout << "������, ������� ���������� ��������, ������� ���������� �������� ������� � ������ " << i + 1 << " " << j + 1 << endl;
                cin >> array[i][j];
            }
        }
    }
    cout << endl;

    cout << "��� ������:" << endl << endl;
    for (int i = 0; i < n; i++) //����� ���������� �������
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(50 / n) << right << array[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i < n; i++) //��������� �������
    {
        for (int j = 0; j < i; j++)
        {
            array[i][j] = 0;
        }
    }
    cout << "���������� ������:" << endl << endl;
    for (int i = 0; i < n; i++) //����� ����������� �������
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