// database.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<fstream>

using std::cout, std::cin, std::endl, std::string;

class Record {
    int age_{};
    string name_{};

public:
    void Din(int a, string n);
    int GetAge();
    string GetName();
};

void Record::Din(int a, string n) {
    age_ = a;
    name_ = n;
}

int Record::GetAge() {
    return age_;
}

string Record::GetName() {
    return name_;
}

using vr = std::vector<Record>;

std::ostream& operator<< (std::ostream& o, Record& data) {

    o << data.GetName() << "     " << data.GetAge() << endl;

    return o;
}

std::ostream& operator<< (std::ostream& o, vr& data) {

    o << "\nImie        |       Wiek\n";
    for (int i = 0; i < data.size(); ++i) {
        o << data[i];
    }

    return o;
}

std::istream& operator>> (std::istream& i, Record& data) {

    string n{};
    int a{};

    i >> n >> a;

    data.Din(a, n);

    return i;
}



void add(vr& data) {

    int c{};
    int a{};
    string n{};

    cout << "Tworzenie danych\nPodaj liczbe danych do wprowadzenia: ";
    cin >> c;
    cout << "\n";

    for (int i = 0; i < c; ++i) {

        Record d;
        cout << i + 1 << endl;;

        cout << endl << "Podaj kolejno: Imie [ENTER] Wiek [ENTER]:\n ";
        cin >> d;

        data.push_back(d);
    }

}



int main()
{
    std::ofstream file("data.txt");


    vr data{};

    add(data);

    cout << data;

    return 0;
}

