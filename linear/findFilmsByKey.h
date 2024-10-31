#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Film_linear {
    char name[50];
    char budget[30];
    double price;
    int quantity;
    int age_limit;
};

void findFilmsByKey(std::fstream& read, int& rows_count) {
    int s_move;
    cout << "[1] По совпадению с названием\n[2] По интервалу цены билета\n[3] По совпадению с описанием\n[4] По интервалу количества свободных мест\n[5] По интервалу возрастного ограничения\n";
    cin >> s_move;
    read.open("bin.bin", ios::in | ios::binary);
    string name;
    string sub_str;
    int a, b;
    switch (s_move) {
    default:
        break;
    case 1:
        cout << "Введите строковый атрибут: ";
        cin >> sub_str;
        for (int i = 0; i < rows_count; i++) {
            Film_linear temp{};

            read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

            name = temp.name;

            std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
            if (name.find(sub_str) != std::string::npos) {
                std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
            }
        }
        read.close();
        break;
    case 2:
        

        cout << "Введите первое значение интервала: ";
        cin >> a;
        cout << "Введите второе значение интервала: ";
        cin >> b;


        for (int i = 0; i < rows_count; i++) {
            Film_linear temp{};

            read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

            std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
            if ((temp.price >= a) && (temp.price <= b)) {
                std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
            }
        }
        read.close();
        break;
    case 3:
        cout << "Введите строковый атрибут: ";
        cin >> sub_str;
        for (int i = 0; i < rows_count; i++) {
            Film_linear temp{};

            read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

            name = temp.budget;

            std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
            if (name.find(sub_str) != std::string::npos) {
                std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
            }
        }
        read.close();
        break;
    case 4:


        cout << "Введите первое значение интервала: ";
        cin >> a;
        cout << "Введите второе значение интервала: ";
        cin >> b;


        for (int i = 0; i < rows_count; i++) {
            Film_linear temp{};

            read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

            std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
            if ((temp.quantity >= a) && (temp.quantity <= b)) {
                std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
            }
        }
        read.close();
        break;
    case 5:


        cout << "Введите первое значение интервала: ";
        cin >> a;
        cout << "Введите второе значение интервала: ";
        cin >> b;


        for (int i = 0; i < rows_count; i++) {
            Film_linear temp{};

            read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

            std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
            if ((temp.age_limit >= a) && (temp.age_limit <= b)) {
                std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
            }
        }
        read.close();
        break;
    }
}