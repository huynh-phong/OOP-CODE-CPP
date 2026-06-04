#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class KhachHang {
protected:
    string tenKH;
    int soLuong;
    double donGia;

public:
    virtual ~KhachHang() {}

    virtual void Nhap(ifstream& in);
    virtual double TinhTien() const = 0;

    string GetTen() const {
        return tenKH;
    }
};

class KhachHangA : public KhachHang {
public:
    double TinhTien() const override;
};

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;

public:
    void Nhap(ifstream& in) override;
    double TinhTien() const override;
};

class KhachHangC : public KhachHang {
public:
    double TinhTien() const override;
};

class QuanLy {
private:
    vector<KhachHang*> ds;

public:
    ~QuanLy();

    void DocFile(string tenFile);
    void GhiFile(string tenFile);
};