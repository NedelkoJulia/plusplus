// Lab_3_1_StaticArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

//Задание 1. Сортировка пузырьком
void bubble(int *arr, const int size)
{
    int n;
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-1-i; j++) {
            if (arr[j] > arr[j + 1]) {
                n = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = n;
            }

        }
    }
    cout << "Массив после сортировки пузырьком\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i]<< "\t";
    }
    cout << "\n\n";
}

//Задание 2. Сортировка подсчетом
void counting(char *Array, int n) {
    const int x = 33;//Кол-во различных элементов
    int i, j, k;
    int с = 0;
    char min(97), max(122);// минимальный символ a (код буквы 97), максимальный символ z (код буквы 122)
    k = 26;
    int* B = new int[k];
    for (i = 0; i < k; i++) 
        B[i] = 0;//Заполняем массив B нулями
    for (i = 0; i < n; i++) 
        B[Array[i] - min]++;//Считаем кол-во каждого элемента
    for (i = min; i <= max; i++) 
        for (j = 0; j < B[i - min]; j++) 
            Array[с++] = i;
    cout << "Массив после сортировки подсчетом\n";
    for (int i = 0; i < n; i++) {
        cout << Array[i] << "\t";
    }
    cout << "\n\n";
    delete[] B;
}

//Функция сливающая массивы
void merge(int *Array, int first, int last)
{
    // first last - начало и конец массива соответственно 
    int middle, start, final, j;
    int* mas = new int[1000];
    middle = (first + last) / 2; //Определение среднего элемента
    start = first; 
    final = middle + 1; 
    for (j = first; j <= last; j++) 
        //start - начало левой части, middle - конец левой части, final - начало правой части
        if ((start <= middle) && ((final > last) || (Array[start] < Array[final])))
        {
            mas[j] = Array[start];
            start++;
        }
        else
        {
            mas[j] = Array[final];
            final++;
        }
    for (j = first; j <= last; j++)//Возвращение результата в массив 
        Array[j] = mas[j];
    delete[]mas;
}

void MergeSort(int *Array, int first, int last)
{
    {
        if (first < last)
        {
            MergeSort(Array, first, (first + last) / 2); //сортировка левой части
            MergeSort(Array, (first + last) / 2 + 1, last); //сортировка правой части
            merge(Array, first, last); //слияние двух частей
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");//Чтобы русский текст в консоле выводился нормально
    int choice = 0; // в этой переменной будет храниться выбор пользователя
    while (true) {
        cout << "Что вы хотите выполнить? \n"
            << "1. Сортировка пузырьком\n"
            << "2. Сортировка подсчетом\n"
            << "3. Сортировка слиянием\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            const int size1 = 7;
            int arr1[size1];
            cout << "Введите значения 7 элементов массива: ";
            for (int i = 0; i < size1; i++) {
                cin >> arr1[i];
            }
            cout << "Ваш массив до сортировки\n";
            for (int i = 0; i < size1; i++) {
                cout << arr1[i] << "\t";
            }
            cout << "\n";
            bubble(arr1, size1);
            break;
        }
        case 2:
        {
            char* arr2 = new char[1000];
            const int size2 = 7;
            cout << "Введите 7 элементов массива: ";
            for (int i = 0; i < size2; i++)
                cin >> arr2[i];
            cout << "Ваш массив до сортировки" << "\n";
            for (int i = 0; i < size2; i++)
                cout << arr2[i] << "\t";
            cout << "\n";
            counting(arr2, size2);
            delete[] arr2;
            break;
        }
        case 3:
        {
            int i;
            const int n = 7;
            int* arr3 = new int[1000];
            cout << "Введите 7 элементов массива: ";
            for (i = 0; i < n; i++)
                cin >> arr3[i];
            cout << "Ваш массив до сортировки" << "\n";
            for (i = 0; i < n; i++)
                cout << arr3[i] << "\t";
            MergeSort(arr3, 0, n);
            cout << "\nМассив после сортировки слиянием:\n";
            for (i = 1; i <= n; i++)
                cout << arr3[i] << "\t";
            cout << "\n\n";
            delete[] arr3;
            break;
        }
        default:
        {
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
