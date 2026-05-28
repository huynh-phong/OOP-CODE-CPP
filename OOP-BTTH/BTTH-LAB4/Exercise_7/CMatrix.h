#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
using namespace std;

class CMatrix {
private:
    int dong, cot;
    float** a;

public:
    CMatrix();
    CMatrix(int dong, int cot);
    CMatrix(const CMatrix& mt);
    ~CMatrix();

    void Nhap();
    void Xuat() const;

    CMatrix operator+(const CMatrix& mt) const;
    CMatrix operator-(const CMatrix& mt) const;

    CMatrix operator*(const CMatrix& mt) const;

    float* NhanVector(float v[]) const;

    friend istream& operator>>(istream& in, CMatrix& mt);
    friend ostream& operator<<(ostream& out, const CMatrix& mt);
};

#endif