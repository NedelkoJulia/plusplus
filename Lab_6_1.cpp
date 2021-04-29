// Lab_6_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void check(string text)
{
    stack<char> mystack;

    bool res = true;

    for (int i = 0; i < text.length(); i++)
    {
        switch (text[i])
        {
        case '(':
        case '{':
        case '[':
            mystack.push(text[i]);
            break;
        case ')':
            if (!mystack.empty() && mystack.top() == '(')
                mystack.pop();
            else
                res = false;
            break;
        case '}':
            if (!mystack.empty() && mystack.top() == '{')
                mystack.pop();
            else
                res = false;
            break;
        case ']':
            if (!mystack.empty() && mystack.top() == '[')
                mystack.pop();
            else
                res = false;
            break;
        }
    }

    if (mystack.empty() && res == true)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

int main()
{
    string text;
    cin >> text;

    check(text);
    system("pause");
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
