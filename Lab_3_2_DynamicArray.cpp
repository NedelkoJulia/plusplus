// Lab_3_2_DynamicArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void task1(int *& arr, int *size)
{
    if (arr != nullptr) delete[]arr;
    cout << "Введите размер массива: ";
    cin >> *size;
    arr = new int[*size];
    cout << "Элементы массива:\n";
    for (int i = 0; i < *size; i++)
        cin >> arr[i];
}

void task2(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
}

void task3(int* arr, int size)
{
    int n1, n2, m;
    int* sum = new int[size];
    for (int i = 0; i < size; i++)
        sum[i] = 0;
    for (int i = 0; i < size; i++) {
        n1 = arr[i];
        n2 = arr[i];
        m = 0;
        while (n1 != 0) {
            n1 /= 10;
            m++;
        }
        if (m % 2 == 0)
            while (n2 > 10) {
                sum[i] += n2 % 10;
                n2 /= 100;
            }
        else {
            n2 /= 10;
            while (n2 > 10) {
                sum[i] += n2 % 10;
                n2 /= 100;
            }
        }
    }
    int n;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (sum[j] > sum[j + 1]) {
                n = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = n;
            }

        }
    }
    task2(arr, size);
    delete[]sum;
}

void task4(int* arr, int size)
{
    int n;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j]%10 > arr[j + 1]%10) {
                n = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = n;
            }
        }
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if((arr[j]%10 == arr[j+1]%10) && (arr[j]<arr[j+1])) {
                n = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = n;
            }
        }
    }
    cout << "Упорядоченный массив\n";
    task2(arr, size);
     
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int size =0;
    int* arr = nullptr;
    int choice; 
    while (true) {
        cout << "Что вы хотите выполнить? \n"
            << "1. Ввод массива\n"
            << "2. Вывод массива в консоль\n"
            << "3. Сортировка  по сумме цифр, стоящих на четных местах \n"
            << "4. Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних цифр - по убыванию\n"
            << "5. Выход\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            task1(arr, &size);
            cout << "\n\n";
            break;
        }
        case 2:
        {
            task2(arr, size);
            cout << "\n\n";
            break;
        }
        case 3:
        {
            task3(arr, size);
            cout << "\n\n";

            break;
        }
        case 4:
        {
            task4(arr, size);
            cout << "\n\n";
            break;
        }
        case 5:
        {
            delete[] arr;
            return 0;
        }
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
