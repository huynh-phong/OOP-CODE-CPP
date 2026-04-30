#ifndef CNHANVIENVP_H
#define CNHANVIENVP_H

#include <string>

class cNhanVienVP{
private:
    std::string maNV;
    std::string hoTen;
    std::string ngaySinh;

    double luong;

public:
    cNhanVienVP();

    void Nhap();
    void Xuat();

    double GetLuong();
    int GetNamSinh();
};

class cListNhanVienVP{
private:
    int n;
    cNhanVienVP ds[100];

public:
    void Nhap();
    void Xuat();

    cNhanVienVP LuongCaoNhat();
    double TongLuong();

    cNhanVienVP TuoiCaoNhat();

    void SapXepTangDanTheoLuong();
};

#endif