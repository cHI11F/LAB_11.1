#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція для читання вмісту файлу
string read_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Файл не знайдено." << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();
    return content;
}

// Функція для фільтрації символів, які не є цифрами
string filter_non_digit_characters(const string& data) {
    string filtered_data;
    for (char c : data) {
        if (isdigit(c)) {
            filtered_data += c;
        }
    }
    return filtered_data;
}

// Функція для запису вмісту у файл
void write_file(const string& filename, const string& filtered_data) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не вдалося створити файл." << endl;
        return;
    }

    file << filtered_data;
    file.close();
}

// Функція для виведення вмісту файлу на екран
void print_file_content(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Файл не знайдено." << endl;
        return;
    }

    cout << "Зміст файлу " << filename << ":" << endl;
    cout << file.rdbuf();
    file.close();
}

int main() {
    string input_filename, output_filename;
    cout << "Введіть шлях до файлу: ";
    getline(cin, input_filename);

    // Видаляємо префікс "filtered_" та зберігаємо лише оригінальне ім'я файлу
    output_filename = input_filename;

    string data = read_file(input_filename);
    if (!data.empty()) {
        string filtered_data = filter_non_digit_characters(data);
        write_file(output_filename, filtered_data);
        cout << "Результати було записано у файл: " << output_filename << endl;
        print_file_content(output_filename);
    }

    return 0;
}
