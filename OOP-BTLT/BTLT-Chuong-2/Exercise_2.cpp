#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
};

void nhap(PhanSo &p) {
    cin >> p.tu >> p.mau;
}

PhanSo tongDay(PhanSo a[], int n) {
    PhanSo s = {0,1};
    for (int i = 0; i < n; i++) {
        s.tu = s.tu * a[i].mau + a[i].tu * s.mau;
        s.mau = s.mau * a[i].mau;
    }
    return s;
}

PhanSo maxPS(PhanSo a[], int n) {
    PhanSo max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].tu * max.mau > max.tu * a[i].mau)
            max = a[i];
    }
    return max;
}

void xuat(PhanSo p) {
    cout << p.tu << "/" << p.mau;
}

int main() {
    int n;
    cin >> n;
    PhanSo a[100];

    for (int i = 0; i < n; i++) nhap(a[i]);

    cout << "Tong: "; xuat(tongDay(a,n)); cout << endl;
    cout << "Max: "; xuat(maxPS(a,n));
}