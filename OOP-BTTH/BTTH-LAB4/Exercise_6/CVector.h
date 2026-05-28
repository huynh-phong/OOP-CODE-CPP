#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
using namespace std;

class CVector {
private:
    int n;          
    float* a;       

public:
    CVector();
    CVector(int n);
    CVector(const CVector& v);
    ~CVector();

    void Nhap();
    void Xuat() const;

    float DoDai() const;

    CVector operator+(const CVector& v) const;
    CVector operator-(const CVector& v) const;
    float operator*(const CVector& v) const; // tích vô hướng

    friend istream& operator>>(istream& in, CVector& v);
    friend ostream& operator<<(ostream& out, const CVector& v);
};

#endif