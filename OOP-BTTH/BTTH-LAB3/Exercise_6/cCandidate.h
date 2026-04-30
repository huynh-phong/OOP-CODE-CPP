#ifndef CCANDIDATE_H
#define CCANDIDATE_H

#include <string>

class cCandidate{
private:
    std::string ma;
    std::string ten;
    std::string ngaySinh;

    double diemToan;
    double diemVan;
    double diemAnh;

public:
    void Nhap();
    void Xuat();

    double TongDiem();
};

class cListCandidate{
private:
    int n;
    cCandidate ds[100];

public:
    void Nhap();
    void Xuat();

    void XuatLonHon15();
    cCandidate TongDiemCaoNhat();

    void SapXepGiamDan();
};

#endif