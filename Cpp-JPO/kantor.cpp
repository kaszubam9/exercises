// kantor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using std::string, std::cout, std::cin, std::endl, std::vector;


class currency {
private:
    string name;
    double ctp;
    double ptc;
public:
    class currency(string n = "PLN", double ct = 0.0, double pt = 0.0) {
        name = n;
        ctp = ct;
        ptc = pt;
    }

    double Ctp(double value) { return value * ctp; }
    double Ptc(double value) { return value * ptc; }

    double GetCtp() { return ctp; }
    double GetPtc() { return ptc; }
    string GetName() { return name; }

    void SetCtp(double ct) { ctp = ct; }
    void SetPtc(double pt) { ptc = pt; }

};

std::ostream& operator<< (std::ostream& o, currency& curr) {

    o << "\nCurrency: " << curr.GetName() << endl;
    o << curr.GetName() << " to PLN: " << curr.GetCtp() << endl;
    o << "PLN to " << curr.GetName() << ": " << curr.GetPtc() << endl;

    return o;
}

using Record = vector<currency>;

double count(Record& data, string c1, string c2, double value) {

    if (c1 == c2) {
        return value;
    }

    for (int i = 0; i < data.size(); i++) {
        if (data[i].GetName() == c1) {
            for (int j = 0; j < data.size(); j++) {
                if (data[j].GetName() == c2) {
                    return data[i].Ptc(data[j].Ctp(value));
                }
            }
        }

    }
    cout << "\n!Currency not found!\n";
    return value;
}



int main()
{
    Record data{};

    currency dolar("USD", 4.17, 0.24);
    currency funt("GBP", 5.55, 0.18);
    currency forint("HUF", 0.013, 78.17);
    currency frsz("CHF", 4.46, 0.22);
    currency euro("EUR", 4.67, 0.21);


    data.push_back(dolar);
    data.push_back(funt);
    data.push_back(forint);
    data.push_back(frsz);
    data.push_back(euro);

    cout << dolar;
    cout << funt;

    cout << "\n100 PLN to GBP:" << data[1].Ptc(14560);

    double value = 1;

    cout << "\n" << value << " EUR to HUF : " << count(data, "HUF", "EUR", value);
    cout << "\n" << value << " HUF to CHF : " << count(data, "EUR", "HUF", value);
    // cout << "\n" << value << " USD to EUR : " << count(data, "USD", "EUR", value);

}