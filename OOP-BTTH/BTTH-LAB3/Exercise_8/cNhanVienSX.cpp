#include <iostream>
#include <algorithm>
#include "cNhanVienSX.h"

using namespace std;

cNhanVienSX::cNhanVienSX(){
    maNV = "";
    hoTen = "";
    ngaySinh = "";
    soSanPham = 0;
    donGia = 0;
}

void cNhanVienSX::Nhap(){
    cin.ignore();

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNV);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);

    cout << "Nhap so san pham: ";
    cin >> soSanPham;

    cout << "Nhap don gia moi san pham: ";
    cin >> donGia;
}

void cNhanVienSX::Xuat(){
    cout << "Ma NV: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "So san pham: " << soSanPham << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Luong: " << TinhLuong() << endl;
}

double cNhanVienSX::TinhLuong(){
    return soSanPham * donGia;
}

int cNhanVienSX::GetNamSinh(){
    string nam = ngaySinh.substr(6,4);
    return stoi(nam);
}

void cListNhanVienSX::Nhap(){
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "\nNhap nhan vien thu " << i+1 << ":\n";
        ds[i].Nhap();
    }
}

void cListNhanVienSX::Xuat(){
    for(int i = 0; i < n; i++){
        cout << "\n===== Nhan vien " << i+1 << " =====\n";
        ds[i].Xuat();
    }
}

cNhanVienSX cListNhanVienSX::LuongThapNhat(){
    cNhanVienSX min = ds[0];

    for(int i = 1; i < n; i++){
        if(ds[i].TinhLuong() < min.TinhLuong()){
            min = ds[i];
        }
    }

    return min;
}

double cListNhanVienSX::TongLuong(){
    double tong = 0;

    for(int i = 0; i < n; i++){
        tong += ds[i].TinhLuong();
    }

    return tong;
}

cNhanVienSX cListNhanVienSX::TuoiCaoNhat(){
    cNhanVienSX maxTuoi = ds[0];

    for(int i = 1; i < n; i++){
        if(ds[i].GetNamSinh() < maxTuoi.GetNamSinh()){
            maxTuoi = ds[i];
        }
    }

    return maxTuoi;
}

void cListNhanVienSX::SapXepTangDanTheoLuong(){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].TinhLuong() > ds[j].TinhLuong()){
                swap(ds[i], ds[j]);
            }
        }
    }
}