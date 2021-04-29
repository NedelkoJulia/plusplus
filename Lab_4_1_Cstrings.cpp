// Lab_4_1_Cstrings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
using namespace std;

bool Palindrom(char* text)
{
    int i = 0, j = strlen(text)-1;
    for (int i = 0; i < j; i++) {
        text[i] = tolower(text[i]);
        text[j] = tolower(text[j]);
        if (text[i] == ' ') 
            i++;
        if (text[j] == ' ')
            j--;
        if (text[i] != text[j])
            return false;
        j--;
    }
    return true;
}

int &Substring(char* text, char* sub, int start){
    int counter = 0;
    int* a;
    int tmp = 0;
    int k = 0;
    int size = 1000;
    a = new int[size];
    for (int i = start; i < strlen(text); i++) {
        if (text[i] == sub[0]) {
            k = i;
            counter = 0;
            for (int j = 0; j < strlen(sub); j++) {
                if (text[k] == sub[j]) {
                    counter++;
                    k++;
                }
            }
            if (counter == strlen(sub)) {
                a[tmp] = i;
                tmp++;
            }
        }
    }
    for (int i = 0; i < tmp; i++)
        cout << a[i] << " ";
    return a[0];
}

void Caesar(char* text, int sdv) {
    char cipher[255];
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            cipher[i] = ' ';
            i++;
        }
        if (int(text[i] + sdv) < 123)
            cipher[i] = (int(text[i] + sdv));
        else
            cipher[i] = (int(text[i] + sdv) - 26);
    }
    for (int i = 0; i < strlen(text); i++)
        cout << cipher[i];
    cout << "\n";
}

void Quotes(char* text) {
    int flag = -1;
    int fl = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '"') {
            flag *= -1; 
                i++;
            fl += 1;
        }
        if (fl % 3 == 0) {
            cout << "|";
            fl += 1;
        }
        if (flag == 1)
            cout << text[i];
    }
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Rus");
    
    int choice = 0;
    char text[255];
    cout << "Введите строку\n";
    cin.getline(text, 255); //Do geese see God
    cin.ignore();
    cout << "Ваша строка: " << text << "\n";
       
        while (true) {
        cout << "Что вы хотите выполнить? \n"
            << "1. Проверка на палиндром\n"
            << "2. Поиск подстроки в строке\n"
            << "3. Шифр Цезаря\n"
            << "4. Поиск названия\n"
            << "5. Выход\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (Palindrom(text) == true)
                cout << "Строка является палиндромом\n";
            else
                cout << "Строка не палиндром\n";
            break;
        }
        case 2:
        {
            cout << "Введите подстроку\n";
            cin.ignore();
            char substr[255];
            cin.getline(substr, 255);
            int start;
            cout << "Введите начало поиска: ";
            cin >> start;
            Substring(text, substr, start);
            cout << "\n";
            break;
        }
        case 3:
        {
            cout << "Введите число сдвига";
            int sdv;
            cin >> sdv;
            Caesar(text, sdv);
            break; 
        }
        case 4:
        {
            Quotes(text);
            break;
        }
        case 5:
            return 0;
        default:
            break;
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
