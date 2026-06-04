#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GiaoDich {
protected:
    string maGD;
    string ngayGD;
    double donGia;
    double dienTich;

public:
    virtual ~GiaoDich() {}

    virtual void Nhap();
    virtual void Xuat() const;
    virtual double ThanhTien() const = 0;

    string GetNgay() const {
        return ngayGD;
    }
};

class GiaoDichDat : public GiaoDich {
private:
    char loaiDat;

public:
    void Nhap() override;
    void Xuat() const override;
    double ThanhTien() const override;
};

class GiaoDichNhaPho : public GiaoDich {
private:
    string loaiNha;
    string diaChi;

public:
    void Nhap() override;
    void Xuat() const override;
    double ThanhTien() const override;
};

class GiaoDichCanHo : public GiaoDich {
private:
    string maCan;
    int tang;

public:
    void Nhap() override;
    void Xuat() const override;
    double ThanhTien() const override;
};

class QuanLy {
private:
    vector<GiaoDich*> ds;

public:
    ~QuanLy();

    void Nhap();
    void Xuat();

    void DemSoLuong();
    void TBTienCanHo();
    void NhaPhoGiaTriMax();
    void LietKeThang122024();
};