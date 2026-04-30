#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <string>

class cNhanVienSX{
private:
    std::string maNV;
    std::string hoTen;
    std::string ngaySinh;

    int soSanPham;
    double donGia;

public:
    cNhanVienSX();

    void Nhap();
    void Xuat();

    double TinhLuong();

    int GetNamSinh();
};

class cListNhanVienSX{
private:
    int n;
    cNhanVienSX ds[100];

public:
    void Nhap();
    void Xuat();

    cNhanVienSX LuongThapNhat();
    double TongLuong();

    cNhanVienSX TuoiCaoNhat();

    void SapXepTangDanTheoLuong();
};

#endif