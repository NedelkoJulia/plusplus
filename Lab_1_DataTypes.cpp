// Lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <bitset>
#include <iomanip>// чтобы использовать setbase

int main()
{
    setlocale(LC_ALL, "Rus");//Чтобы русский текст в консоле выводился нормально
    using std::cout;//Чтобы не писать каждый раз std::
    using std::cin;

    cout << "Задание 1\n";
    cout << "Неделько Юлия Кирилловна, 201-331\n\n";

    
    cout << "Задание 2\n";
    cout << "min int=" << INT_MIN << ", max int=" << INT_MAX << ", size of int=" << sizeof(int) << "\n";
    cout << "min unsigned int=" << 0 << ", max unsigned int=" << UINT_MAX << ", size of unsigned int=" << sizeof(unsigned int) << "\n";
    cout << "min short=" << SHRT_MIN << ", max short=" << SHRT_MAX << ", size of short=" << sizeof(short) << "\n";
    cout << "min unsigned short=" << 0 << ", max unsigned short=" << USHRT_MAX << ", size of unsigned short=" << sizeof(unsigned short) << "\n";
    cout << "min long=" << LONG_MIN << ", max long=" << LONG_MAX << ", size of long=" << sizeof(long) << "\n";
    cout << "min long long=" << LLONG_MIN << ", max long long=" << LLONG_MAX << ", size of long long=" << sizeof(long long) << "\n";
    cout << "min double=" << DBL_MIN << ", max double=" << DBL_MAX << ", size of double=" << sizeof(double) << "\n";
    cout << "min char=" << CHAR_MIN << ", max char=" << CHAR_MAX << ", size of char=" << sizeof(char) << "\n";
    cout << "min bool=" << false << ", max bool=" << true << ", size of bool=" << sizeof(bool) << "\n\n";


    cout << "Задание 3\n";
    int num1;
    cout << "Введите число:"; 
    cin >> num3;
    cout << "В бинарном виде " << std::bitset<16>(num3) << "\n";
    cout << "В шестнадцатиричном виде " << std::setbase(16) << num3 << "\n";
    cout << "Bool " << bool num3 << "\n";
    cout << "Double " << double num3 << "\n";
    cout << "Char " << char num3 << "\n\n";

    cout << "Задание 4\n";
    int a, b;
    double x;
    cout << "Введите коэффиценты a*x=b: ";
    cin >> a >> b;
    cout << a << "*x=" << b << "\n";
    cout << "x=" << b << "/" << a << "\n";
    x = double b / a;
    cout << "x=" << x <<"\n\n";

    cout << "Задание 5\n";
    int y1, y2;
    cout << "Введите координаты отрезка на прямой: ";
    cin >> y1 >> y2;
    double y = (y1 + y2) / 2.0;
    cout << "Середина отрезка находится в точке с координатой " << y << "\n";


    return 0;
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
