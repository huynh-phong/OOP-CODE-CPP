#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
protected:
    string maSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTB;

public:
    virtual ~SinhVien() {}

    virtual void Nhap();
    virtual void Xuat() const;
    virtual bool TotNghiep() const = 0;

    double GetDiemTB() const {
        return diemTB;
    }
};

class SVCaoDang : public SinhVien {
private:
    double diemTN;

public:
    void Nhap() override;
    void Xuat() const override;
    bool TotNghiep() const override;
};

class SVDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    void Nhap() override;
    void Xuat() const override;
    bool TotNghiep() const override;
};

class QuanLySV {
private:
    vector<SinhVien*> ds;

public:
    ~QuanLySV();

    void Nhap();
    void Xuat();

    void DSSVTotNghiep();
    void DSSVKhongTotNghiep();

    void SVDHDiemTBCaoNhat();
    void SVCDDiemTBCaoNhat();

    void DemKhongTotNghiep();
};