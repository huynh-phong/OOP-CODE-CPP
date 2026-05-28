#include "CDate.h"
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    CDate d1,d2;

    cout<<"\nNhap Ngay/Thang/Nam thu nhat: ";
    cin>>d1;
    cout<<"\nNhap Ngay/Thang/Nam thu hai: ";
    cin>>d2;
    
    cout<<"\nNgay 1: "<<d1;
    cout<<"\nNgay 2: "<<d2;
    
    cout<<"\nKhoang cach giua 2 ngay la: "<<d1-d2<<" ngay";;

    cout<<"\nNgay 1 sau khi tang 10 ngay: "<<d1+10;
    cout<<"\nNgay 1 sau khi giam 5 ngay: "<<d1-5;

    ++d1;
    cout<<"\nNgay 1 sau khi ++d1: "<<d1;
    d2--;
    cout<<"\nNgay 2 sau khi d2--: "<<d2;

    double tiengoc, laixuat;
    CDate ngaygui, ngayrut;
    cout<<"\n\nNhap so tien gui ngan hang (vnd): ";
    cin>>tiengoc;
    cout<<"\nNhap lai xuat nam (%): ";
    cin>>laixuat;
    cout<<"\nNhap ngay gui: ";
    cin>>ngaygui;
    cout<<"\nNhap ngay rut: ";
    cin>>ngayrut;
    int songay = ngayrut - ngaygui;
    double tienlai = tiengoc * (laixuat/100) * songay/365;
    cout<<"\nTien lai la: "<<tienlai<<" vnd";

    return 0;
}