#include <iostream>
#include <cstring>
using namespace std;

struct NhanVien {
    char ma[9];
    char ten[21];
    char phong[11];
    int luong;
    int thuong;
    int thucLanh;
};

void nhap(NhanVien &nv) {
    cout << "Ma NV: "; cin >> nv.ma;
    cin.ignore();
    cout << "Ten: "; cin.getline(nv.ten, 21);
    cout << "Phong: "; cin.getline(nv.phong, 11);
    cout << "Luong: "; cin >> nv.luong;
    cout << "Thuong: "; cin >> nv.thuong;
    nv.thucLanh = nv.luong + nv.thuong;
}

void xuat(NhanVien nv) {
    cout << nv.ma << " | " << nv.ten << " | " << nv.phong
         << " | " << nv.luong << " | " << nv.thuong
         << " | " << nv.thucLanh << endl;
}

int main() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;

    NhanVien a[100];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap NV thu " << i + 1 << endl;
        nhap(a[i]);
    }

    // a. Tong thuc lanh
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i].thucLanh;
    }
    cout << "\nTong thuc lanh: " << tong << endl;

    // b. NV luong thap nhat
    int minLuong = a[0].luong;
    for (int i = 1; i < n; i++) {
        if (a[i].luong < minLuong)
            minLuong = a[i].luong;
    }

    cout << "\nNhan vien luong thap nhat:\n";
    for (int i = 0; i < n; i++) {
        if (a[i].luong == minLuong)
            xuat(a[i]);
    }

    // c. Dem thuong >= 1200000
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].thuong >= 1200000)
            dem++;
    }
    cout << "\nSo NV thuong >= 1200000: " << dem << endl;

    // d. Sap xep
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i].phong, a[j].phong) > 0 ||
               (strcmp(a[i].phong, a[j].phong) == 0 &&
                strcmp(a[i].ma, a[j].ma) < 0)) {
                swap(a[i], a[j]);
            }
        }
    }

    cout << "\nDanh sach sau sap xep:\n";
    for (int i = 0; i < n; i++) {
        xuat(a[i]);
    }

    return 0;
}