#pragma once

#include <fstream>

void readFilms(std::fstream& read, int& rows_count) {
    read.open("bin.bin", ios::in | ios::binary);
    std::cout << std::left << setw(20) << "�������� " << setw(20) << "| �������� " << setw(10) << "| ���� " << setw(10) << "| ����.����� " << setw(10) << "| ���.���" << endl;
    for (int i = 0; i < rows_count; i++) {
        Film_linear temp{};
        read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));
        std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
    }
    read.close();
}
