#include "CTime.h"
#include <iostream>
using namespace std;

CTime::CTime(int h,int m, int s){
    gio=h; phut=m; giay=s;
    ChuanHoa();
}

void CTime::ChuanHoa(){
    int tonggiay = gio*3600 + phut*60 + giay;
    gio = (tonggiay/3600)%24;
    phut = (tonggiay%3600)/60;
    giay = ((tonggiay%3600)%60);
}

istream& operator>>(istream& in,CTime& t){
    cout<<"\nNhap gio phut giay (khong am): ";
    in >> t.gio >> t.phut >> t.giay;
    t.ChuanHoa();
    return in;
}

ostream& operator<<(ostream& out,const CTime& t){
    if (t.gio < 10) out << "0";
    out << t.gio << ":";
    if (t.phut < 10) out << "0";
    out << t.phut << ":";
    if (t.giay < 10) out << "0";
    out << t.giay;

    return out;

}

CTime CTime::operator+(int s) const{
    int tonggiay = gio*3600 + phut*60 + giay;
    tonggiay+=s;
    return CTime(0,0,tonggiay);
}

CTime CTime::operator-(int s) const{
    int tonggiay = gio*3600 + phut*60 + giay;
    tonggiay-=s;
    return CTime(0,0,tonggiay);
}

CTime CTime::operator++(){
    *this = *this + 1;
    return *this;
}

CTime CTime::operator--(){
    *this = *this - 1;
    return *this;
}