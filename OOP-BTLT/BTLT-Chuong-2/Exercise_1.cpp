#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
};

void nhap(PhanSo &p) {
    cin >> p.tu >> p.mau;
}

void xuat(PhanSo p) {
    cout << p.tu << "/" << p.mau;
}

PhanSo tong(PhanSo a, PhanSo b) {
    return {a.tu*b.mau + b.tu*a.mau, a.mau*b.mau};
}

PhanSo hieu(PhanSo a, PhanSo b) {
    return {a.tu*b.mau - b.tu*a.mau, a.mau*b.mau};
}

PhanSo tich(PhanSo a, PhanSo b) {
    return {a.tu*b.tu, a.mau*b.mau};
}

PhanSo thuong(PhanSo a, PhanSo b) {
    return {a.tu*b.mau, a.mau*b.tu};
}

int main() {
    PhanSo a, b;
    nhap(a); nhap(b);

    cout << "Tong: "; xuat(tong(a,b)); cout << endl;
    cout << "Hieu: "; xuat(hieu(a,b)); cout << endl;
    cout << "Tich: "; xuat(tich(a,b)); cout << endl;
    cout << "Thuong: "; xuat(thuong(a,b));
}