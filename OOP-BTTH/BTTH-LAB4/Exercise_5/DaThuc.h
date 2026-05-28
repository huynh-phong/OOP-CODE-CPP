#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
using namespace std;

class DaThuc {
private:
    int bac;       
    float* heso;   

public:
    DaThuc();
    DaThuc(int bac);
    DaThuc(const DaThuc& dt);
    ~DaThuc();

    void Nhap();
    void Xuat() const;

    float TinhGiaTri(float x) const;

    DaThuc operator+(const DaThuc& dt) const;
    DaThuc operator-(const DaThuc& dt) const;

    friend istream& operator>>(istream& in, DaThuc& dt);
    friend ostream& operator<<(ostream& out, const DaThuc& dt);
};

#endif