#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>

using namespace std;

class NHANVIEN{
    protected:
    string HoTen;
    string NgaySinh;
    double LuongCoBan;

    public:
    NHANVIEN();

    virtual double TinhLuong() = 0;
    virtual void Nhap();
    virtual void Xuat();

    string getHoTen();
};

class NHANVIENVP : public NHANVIEN{
    private:
    int SoNgayLam;
    double TroCap;

    public:
    double TinhLuong();
    void Nhap();
    void Xuat();
};

class NHANVIENSX : public NHANVIEN{
    private:
    int SoSanPham;

    public:
    double TinhLuong();
    void Nhap();
    void Xuat();
};

class NHANVIENQL : public NHANVIEN{
    private:
    double HeSoChucVu;
    double Thuong;

    public:
    double TinhLuong();
    void Nhap();
    void Xuat();
};

#endif