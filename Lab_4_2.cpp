// Lab_4_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//C:\Users\swan1\source\repos\Nedelko_201_331\Test42.txt
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string file_format(const string file_path_full) {
    int dot_index;
    string format = "";
    for (int i = file_path_full.length() - 1; i >= 0; i--) {
        if (file_path_full[i] == '.') {
            dot_index = i;
            cout << "Формат: ";
            for (int j = dot_index + 1; j < file_path_full.length(); j++)
                format += file_path_full[j];
            break;
        }
    }
    cout << format;
    return string(format);
}

string file_name(const string file_path_full) {
    int slash_index = -1, dot_index = -1;
    string name = "";
    for (int i = file_path_full.length() - 1; i >= 0; i--) {
        if (file_path_full[i] == '.' && dot_index == -1)
            dot_index = i;
        else if (file_path_full[i] == '\\') {
            slash_index = i;
            break;
        }
    }
    cout << "Название: ";
    for (int i = slash_index + 1; i < dot_index; i++)
        name += file_path_full[i];
    cout << name << endl;
    return string(name);
}

string file_path(const string file_path_full) {
    int slash_index;
    string path = "";
    for (int i = file_path_full.length() - 1; i >= 0; i--) {
        if (file_path_full[i] == '\\') {
            slash_index = i;
            break;
        }
    }
    cout << "Путь: ";
    for (int i = 0; i < slash_index; i++)
        path += file_path_full[i];
    cout << path << endl;
    return string(path);
}

char file_disk(const string file_path_full) {
    cout << "Диск: " << file_path_full[0] << file_path_full[1] << endl;
    return '\n';
}

void file_rename(string& file_path_full, string new_name) {
    string path, format;
    int slash_index = -1, dot_index = -1;
    for (int i = file_path_full.length() - 1; i >= 0; i--) {
        if (file_path_full[i] == '.' && dot_index == -1)
            dot_index = i;
        else if (file_path_full[i] == '\\') {
            slash_index = i;
            break;
        }
    }
    for (int i = 0; i < slash_index; i++)
        path += file_path_full[i];
    for (int i = dot_index + 1; i < file_path_full.length(); i++)
        format += file_path_full[i];
    file_path_full = path + '\\' + new_name + '.' + format;
    cout << file_path_full << endl;
}

bool file_copy(const string file_path_full) {
    ifstream file;
    ofstream file_copy;
    int dot_index;
    string format = "", path_with_name = "";
    for (int i = file_path_full.length() - 1; i >= 0; i--) {
        if (file_path_full[i] == '.') {
            dot_index = i;
            for (int j = dot_index + 1; j < file_path_full.length(); j++)
                format += file_path_full[j];
            for (int j = 0; j < dot_index; j++)
                path_with_name += file_path_full[j];
            break;
        }
    }
    file.open(file_path_full);
    file_copy.open(path_with_name + "_copy." + format);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return false;
    }
    if (!file_copy.is_open()) {
        cout << "Не удалось создать(открыть) копию" << endl;
        return false;
    }
    file_copy << file.rdbuf();
    file.close();
    file_copy.close();
    return true;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    string str;
    int choice = 0;
    cout << "Введите полный путь, название и формат файла: ";
    cin >> str;
    while (true) {
        cout << "Что вы хотите выполнить? \n"
            << "1. Формат\n"
            << "2. Название\n"
            << "3. Путь\n"
            << "4. Диск\n"
            << "5. Сменить название\n"
            << "6. Скопировать файл\n"
            << "7. Выход\n Введите свой выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
        {
            file_format(str);
            cout << "\n";
            break;
        }
        case 2:
        {
            file_name(str);
            break;
        }
        case 3:
        {
            file_path(str);
            break;
        }
        case 4:
        {
            file_disk(str);
            break;
        }
        case 5:
        {
            string new_name;
            cout << "Введите новое название файла: ";
            cin >> new_name;
            file_rename(str, new_name);
            break;
        }
        case 6:
        {
            file_copy(str);
            break;
        }
        case 7:
        {
            return 0;
            break;
        }
        default:
        {
            continue;
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
