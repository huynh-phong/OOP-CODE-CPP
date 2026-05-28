#ifndef CDATE_H
#define CDATE_H

#include <iostream>
#include <cmath>
using namespace std;

class CDate{
    private:
    int ngay, thang, nam;
    
    public:
    CDate();
    CDate(int d,int m,int y);

    friend istream& operator>>(istream& in,CDate& d);
    friend ostream& operator<<(ostream& out, const CDate& d);
    
    bool KiemTraHopLe();

    CDate operator+(int days);
    CDate operator-(int days);

    int operator-(CDate other);

    CDate& operator++(); //++d
    CDate& operator--();
    CDate operator++(int); //d++
    CDate operator--(int);

    bool NamNhuan(int y);
    int SoNgayTrongThang(int m,int y);

    void nextday();
    void prevday();

    long long fullday();
};
#endif