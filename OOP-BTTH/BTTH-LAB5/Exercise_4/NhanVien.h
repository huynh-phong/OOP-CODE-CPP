#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;

public:
    virtual ~NhanVien() {}

    virtual void Nhap();
    virtual void Xuat() const;
    virtual double TinhLuong() const = 0;
};

class LapTrinhVien : public NhanVien {
private:
    int gioOT;

public:
    void Nhap() override;
    void Xuat() const override;
    double TinhLuong() const override;
};

class KiemChungVien : public NhanVien {
private:
    int soLoi;

public:
    void Nhap() override;
    void Xuat() const override;
    double TinhLuong() const override;
};

class QuanLy {
private:
    vector<NhanVien*> ds;

public:
    ~QuanLy();

    void Nhap();
    void Xuat();

    double LuongTB();

    void LuongThapHonTB();
    void NVCaoLuongNhat();
    void NVLuongThapNhat();

    void LTVLuongCaoNhat();
    void KCVLuongThapNhat();
};