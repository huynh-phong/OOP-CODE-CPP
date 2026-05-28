#include "CDate.h"
#include <iostream>
#include <cmath>
using namespace std;


CDate::CDate(){
    ngay=1; thang=1; nam=2000;
}
CDate::CDate(int d, int m, int y){
    ngay=d; thang=m; nam=y;
}

bool CDate::KiemTraHopLe(){
    if(nam<1) return false;
    if(thang<1 || thang >12) return false;
    if(ngay<1 || ngay > SoNgayTrongThang(thang,nam))
    return false;
    return true;
}

bool CDate::NamNhuan(int y){
    return ((y%400==0) || (y%4==0 && y%100!=0));
}

int CDate::SoNgayTrongThang(int m, int y){
    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && NamNhuan(y))
    return 29;
    return days[m];
}

void CDate::nextday(){
    ngay++;
    if(ngay > SoNgayTrongThang(thang,nam)){
        ngay=1; 
        thang++;
        if(thang > 12){
        thang=1; 
        nam++;
        }
    }
}

void CDate::prevday(){
    ngay--;
    if(ngay < 1){
        thang--;
        if(thang < 1){
            nam--;
            thang=12;
        }
        ngay = SoNgayTrongThang(thang,nam);
    }
}

long long CDate::fullday(){
    long long TongNgay = 0;
    for(int y=1;y<nam;y++)
        TongNgay += NamNhuan(y)?366:365;
    for(int m=1;m<thang;m++)
        TongNgay += SoNgayTrongThang(m,nam);
    TongNgay += ngay;
    return TongNgay;
}

istream& operator>>(istream& in, CDate& d){

    bool check;

    do{
        in >> d.ngay >> d.thang >> d.nam;
        if(in.fail()){
            in.clear();
            in.ignore(1000,'\n');
            cout << "\nDu lieu khong hop le! Nhap lai: ";
            check = false;
            continue;
        }
        check = d.KiemTraHopLe();
        if(!check)
            cout << "\nNgay/Thang/Nam khong hop le! Nhap lai: ";
    }while(!check);

    return in;
}

ostream& operator<<(ostream& out,const CDate& d){
    out << d.ngay <<"/"<< d.thang <<"/"<< d.nam;
    return out;
}

CDate CDate::operator+(int days){
    CDate temp = *this;
    for(int i=0;i<days;i++)
        temp.nextday();
    return temp;
}

CDate CDate::operator-(int days){
    CDate temp = *this;
    for(int i=0;i<days;i++)
        temp.prevday();
    return temp;
}

int CDate::operator-(CDate other){
    return abs(fullday() - other.fullday());
}

CDate& CDate::operator++(){
    nextday();
    return *this;
}

CDate CDate::operator++(int){
    CDate temp=*this;
    nextday();
    return temp;
}

CDate& CDate::operator--(){
    prevday();
    return *this;
}

CDate CDate::operator--(int){
    CDate temp=*this;
    prevday();
    return temp;
}

