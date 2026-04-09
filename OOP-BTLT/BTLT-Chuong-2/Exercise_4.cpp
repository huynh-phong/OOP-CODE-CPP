#include <iostream>
#include <cstring>
using namespace std;

struct HocSinh {
    char ma[20];
    char ten[50];
    char gioiTinh[10];
    float toan, ly, hoa;
    float dtb;
};

void nhap(HocSinh &hs) {
    cin.ignore();
    cout << "Ma: "; cin.getline(hs.ma, 20);
    cout << "Ten: "; cin.getline(hs.ten, 50);
    cout << "Gioi tinh: "; cin.getline(hs.gioiTinh, 10);
    cout << "Toan Ly Hoa: ";
    cin >> hs.toan >> hs.ly >> hs.hoa;

    hs.dtb = (hs.toan + hs.ly + hs.hoa) / 3;
}

void xuat(HocSinh hs) {
    cout << hs.ma << " | " << hs.ten << " | " << hs.gioiTinh
         << " | DTB: " << hs.dtb << endl;
}

int main() {
    HocSinh hs;
    nhap(hs);
    xuat(hs);
}