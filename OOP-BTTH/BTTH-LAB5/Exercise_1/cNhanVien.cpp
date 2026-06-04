#include <iostream>
#include <vector>
#include <string>
#include "cNhanVien.h"

using namespace std;

NHANVIEN::NHANVIEN(){
    HoTen = "";
    NgaySinh = "";
    Luong = 0;
}

void NHANVIEN::Nhap(){
    cin.ignore();
    cout<<"Nhap Ho Ten:";
    getline(cin,HoTen);
    cout<<"Nhap Ngay Sinh (dd/mm/yyyy)";
    getline(cin,NgaySinh);
}

void NHANVIEN::Xuat() {
    cout << "Ho ten: " << HoTen << endl;
    cout << "Ngay sinh: " << NgaySinh << endl;
    cout << "Luong: " << Luong << endl;
}

int NHANVIEN::TinhTuoi(){
    int NamSinh = stoi(NgaySinh.substr(6,4));
    return 2026-NamSinh;
}

double NHANVIEN::GetLuong(){
    return Luong;
}
string NHANVIEN::GetHoTen(){
    return HoTen;
}

void NHANVIENSANXUAT::Nhap(){
    NHANVIEN::Nhap();
    cout<<"Nhap Luong Can Ban";
    cin>>LuongCanBan;
    cout<<"Nhap So San Pham";
    cin>>SoSanPham;
}

double NHANVIENSANXUAT::TinhLuong(){
    Luong = LuongCanBan + SoSanPham*5000;
    return Luong;
}

void NHANVIENSANXUAT::Xuat(){
    NHANVIEN::Xuat();
    cout << "So san pham: " << SoSanPham << endl;
}

void NHANVIENVANPHONG::Nhap(){
    NHANVIEN::Nhap();
    cout<<"Nhap So Ngay Lam Viec: ";
    cin>>SoNgayLamViec;
}

double NHANVIENVANPHONG::TinhLuong(){
    Luong = SoNgayLamViec*100000;
    return Luong;
}

void NHANVIENVANPHONG::Xuat(){
    NHANVIEN::Xuat();
    cout << "So Ngay Lam Viec: " << SoNgayLamViec << endl;
}