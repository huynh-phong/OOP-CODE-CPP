#include <iostream>
#include <iomanip>
#include "Nhanvien.h"

using namespace std;

//nhanvien
NHANVIEN::NHANVIEN(){
    HoTen = "";
    NgaySinh = "";
    LuongCoBan = 0;
}

void NHANVIEN::Nhap(){
    cin.ignore();
    cout<<"Nhap Ho Ten: ";
    getline(cin,HoTen);
    cout<<"Nhap Ngay Sinh: ";
    getline(cin,NgaySinh);
    cout<<"Nhap Luong Co Ban: ";
    cin>>LuongCoBan;
}

void NHANVIEN::Xuat() {
    cout << fixed << setprecision(0);
    cout << "Ho ten: " << HoTen << endl;
    cout << "Ngay sinh: " << NgaySinh << endl;
    cout << "Luong: " << TinhLuong() << endl;
}

string NHANVIEN::getHoTen() {
    return HoTen;
}

//nhanvienVP
void NHANVIENVP::Nhap(){
    NHANVIEN::Nhap();
    cout<<"Nhap So Ngay Lam: ";
    cin>>SoNgayLam;
    cout<<"Nhap Tro Cap: ";
    cin>>TroCap;
}

void NHANVIENVP::Xuat(){
    cout<<"Nhan Vien Van Phong"<<endl;
    NHANVIEN::Xuat();
    cout << fixed << setprecision(0);
    cout<<"So Ngay Lam: "<<SoNgayLam<<endl;
    cout<<"Tro Cap: "<<TroCap<<endl;
}

double NHANVIENVP::TinhLuong(){
    return LuongCoBan + SoNgayLam*200000 + TroCap;
}

//nhanvienSX
void NHANVIENSX::Nhap(){
    NHANVIEN::Nhap();
    cout<<"Nhap So San Pham: ";
    cin>>SoSanPham;
}

void NHANVIENSX::Xuat(){
    cout<<"Nhan Vien San Xuat"<<endl;
    NHANVIEN::Xuat();
    cout << fixed << setprecision(0);
    cout<<"So San Pham: "<<SoSanPham<<endl;
}

double NHANVIENSX::TinhLuong(){
    return LuongCoBan + SoSanPham*2000;
}

//nhanvienQL
void NHANVIENQL::Nhap(){
    NHANVIEN::Nhap();
    cout<<"Nhap He So Chuc Vu: ";
    cin>>HeSoChucVu;
    cout<<"Nhap Thuong: ";
    cin>>Thuong;
}

void NHANVIENQL::Xuat(){
    cout<<"Nhan Vien Quan Ly"<<endl;
    NHANVIEN::Xuat();
    cout << fixed << setprecision(0);
    cout<<"He So Chuc Vu: "<<HeSoChucVu<<endl;
    cout<<"Thuong: "<<Thuong<<endl;
}

double NHANVIENQL::TinhLuong(){
    return LuongCoBan*HeSoChucVu + Thuong;
}