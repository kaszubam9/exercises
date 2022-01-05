// struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<fstream>

using std::cout, std::cin, std::endl, std::string;

struct Record {
    int age{};
    string name{};
};

using vr = std::vector<Record>;


vr din() {

    vr data;

    int c{};
    int a{};
    string n{};


    cout << "Tworzenie danych\nPodaj liczbe danych do wprowadzenia: ";
    cin >> c;
    cout << "\n";

    for (int i = 0; i < c; ++i) {

        cout << i + 1;

        cout << endl << "Podaj imie: ";
        cin >> n;
        cout << endl << "Podaj wiek: ";
        cin >> a;
        cout << "\n\n";
        data.push_back(Record(a, n));
    }

    return data;
}

void add(vr& data) {

    int c{};
    int a{};
    string n{};

    cout << "Dodawanie danych\nPodaj liczbe danych do dodania: ";
    cin >> c;
    cout << "\n";

    for (int i = 0; i < c; ++i) {

        cout << i + 1;

        cout << endl << "Podaj imie: ";
        cin >> n;
        cout << endl << "Podaj wiek: ";
        cin >> a;
        cout << "\n\n";
        data.push_back(Record(a, n));
    }

}


void out(std::ostream& o, vr data) {

    for (int i = 0; i < data.size(); ++i) {
        o << "\nImie: " << data[i].name << "  |  Wiek: " << data[i].age << "\n";
    }

}


int main()
{
    std::ofstream file("data.txt");


    vr data = din();

    add(data);

    out(cout, data);
    out(file, data);

    return 0;
}
