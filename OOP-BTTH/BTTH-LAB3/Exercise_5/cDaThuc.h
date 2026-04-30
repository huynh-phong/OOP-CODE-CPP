#ifndef CDATHUC_H
#define CDATHUC_H

class cDaThuc{
private:
    int bac;
    double heSo[100];

public:
    void Nhap();
    void Xuat();

    double TinhGiaTri(double x);

    cDaThuc Cong(cDaThuc dt);
    cDaThuc Tru(cDaThuc dt);
};

#endif