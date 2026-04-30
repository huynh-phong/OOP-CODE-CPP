#ifndef CDSPHANSO_H
#define CDSPHANSO_H

class PHANSO{
public:
    int tu, mau;

    void Nhap();
    void Xuat();
    void RutGon();
};

class DSPHANSO{
private:
    int n;
    PHANSO ds[100];

public:
    void Nhap();
    void Xuat();

    PHANSO Tong();
    PHANSO LonNhat();
    PHANSO NhoNhat();
    PHANSO TuNguyenToLonNhat();

    void SapXepTangDan();
    void SapXepGiamDan();
};

#endif