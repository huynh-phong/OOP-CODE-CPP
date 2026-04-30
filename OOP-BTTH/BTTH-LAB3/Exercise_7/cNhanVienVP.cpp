#include <iostream>
#include <algorithm>
#include "cNhanVienVP.h"

using namespace std;

cNhanVienVP::cNhanVienVP(){
    maNV = "";
    hoTen = "";
    ngaySinh = "";
    luong = 0;
}

void cNhanVienVP::Nhap(){
    cin.ignore();

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNV);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);

    cout << "Nhap luong: ";
    cin >> luong;
}

void cNhanVienVP::Xuat(){
    cout << "Ma NV: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Luong: " << luong << endl;
}

double cNhanVienVP::GetLuong(){
    return luong;
}

int cNhanVienVP::GetNamSinh(){
    string nam = ngaySinh.substr(6,4);
    return stoi(nam);
}

void cListNhanVienVP::Nhap(){
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "\nNhap nhan vien thu " << i+1 << ":\n";
        ds[i].Nhap();
    }
}

void cListNhanVienVP::Xuat(){
    for(int i = 0; i < n; i++){
        cout << "\n===== Nhan vien " << i+1 << " =====\n";
        ds[i].Xuat();
    }
}

cNhanVienVP cListNhanVienVP::LuongCaoNhat(){
    cNhanVienVP max = ds[0];

    for(int i = 1; i < n; i++){
        if(ds[i].GetLuong() > max.GetLuong()){
            max = ds[i];
        }
    }

    return max;
}

double cListNhanVienVP::TongLuong(){
    double tong = 0;

    for(int i = 0; i < n; i++){
        tong += ds[i].GetLuong();
    }

    return tong;
}

cNhanVienVP cListNhanVienVP::TuoiCaoNhat(){
    cNhanVienVP maxTuoi = ds[0];

    for(int i = 1; i < n; i++){
        if(ds[i].GetNamSinh() < maxTuoi.GetNamSinh()){
            maxTuoi = ds[i];
        }
    }

    return maxTuoi;
}

void cListNhanVienVP::SapXepTangDanTheoLuong(){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].GetLuong() > ds[j].GetLuong()){
                swap(ds[i], ds[j]);
            }
        }
    }
}