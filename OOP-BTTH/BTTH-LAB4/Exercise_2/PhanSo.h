#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PHANSO{
    private:
    int tu,mau;
    void RutGon();
    public:
    PHANSO(int t=0,int m=1);

    friend istream& operator>>(istream& in, PHANSO& ps);
    friend ostream& operator<<(ostream& out,const PHANSO& ps);

    PHANSO operator+(const PHANSO& other) const;
    PHANSO operator-(const PHANSO& other) const;
    PHANSO operator*(const PHANSO& other) const;
    PHANSO operator/(const PHANSO& other) const;

    bool operator==(const PHANSO& other) const;
    bool operator>(const PHANSO& other) const;
    bool operator<(const PHANSO& other) const;
};
#endif