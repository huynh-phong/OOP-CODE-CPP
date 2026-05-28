#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    SoPhuc(double t = 0, double a = 0);

    friend istream& operator>>(istream& in, SoPhuc& sp);
    friend ostream& operator<<(ostream& out, const SoPhuc& sp);

    SoPhuc operator+(const SoPhuc& other) const;
    SoPhuc operator-(const SoPhuc& other) const;
    SoPhuc operator*(const SoPhuc& other) const;
    SoPhuc operator/(const SoPhuc& other) const;

    bool operator==(const SoPhuc& other) const;
    bool operator!=(const SoPhuc& other) const;
};

#endif