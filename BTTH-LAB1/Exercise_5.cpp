#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    float toan, van, dtb;

    cout << "Nhap ho ten: ";
    getline(cin, name);

    cout << "Nhap diem Toan: ";
    cin >> toan;

    cout << "Nhap diem Van: ";
    cin >> van;
    while (toan < 0 || toan > 10 || van < 0 || van > 10)
    {
        if (toan < 0 || toan > 10)
        {
            cout << "Diem Toan khong hop le! Nhap lai: ";
            cin>> toan;
        }
        if (van < 0 || van > 10)
        {
            cout << "Diem Van khong hop le! Nhap lai: ";
            cin >> van;
        }
    }

    dtb = (toan + van) / 2;

    cout << "\nHo ten: " << name << endl;
    cout << "Diem trung binh: " << dtb << endl;

    return 0;
}