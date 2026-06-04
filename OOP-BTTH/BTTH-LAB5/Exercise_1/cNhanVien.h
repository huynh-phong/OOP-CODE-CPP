#ifndef CNHANVIEN_H
#define CNHANVIEN_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NHANVIEN{
    protected:
    string HoTen, NgaySinh;
    double Luong;

    public:
    NHANVIEN();
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong() = 0;
    int TinhTuoi();
    double GetLuong();
    string GetHoTen();
};

class NHANVIENSANXUAT:public NHANVIEN{
    private:
    int SoSanPham;
    double LuongCanBan;

    public:
    void Nhap();
    double TinhLuong();
    void Xuat();
};

class NHANVIENVANPHONG:public NHANVIEN{
    private:
    int SoNgayLamViec;

    public:
    void Nhap();
    double TinhLuong();
    void Xuat();
};

#endif 