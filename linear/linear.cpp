// linear.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <typeinfo>
#include "findFilmsByKey.h"
#include "readFilms.h"
#include "addFilm.h"

using namespace std;

struct Film {
    string name;
    string budget;
    double price;
    int quantity;
    int age_limit;
};

int main()
{
    setlocale(LC_ALL, "ru");
    for (;;) {
        int f_move;
        cout << "[1] Добавить фильм\n[2] Посмотреть каталог фильмов\n[3] Поиск фильмов по атрибуту\n";
        cin >> f_move;
        int rows_count = 0;
        fstream rows;
        rows.open("rows.bin", ios::in | ios::binary);
        rows.read((char*)&rows_count, sizeof(int));
        rows.close();


        string sub_str;

        fstream add;
        fstream read;
        vector<Film_linear> films(rows_count);

        Film_linear film{};
        switch (f_move) {
        default:
            break;
        case 1:
            addFilm(film, add, rows, rows_count);
            break;
        case 2:
            readFilms(read, rows_count);
            break;
        case 3:
            findFilmsByKey(read, rows_count);
            break;
        }
    }
}