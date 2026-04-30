#include <iostream>
#include <cmath>
#include "cDaThuc.h"

using namespace std;

void cDaThuc::Nhap(){
    cout << "Nhap bac da thuc: ";
    cin >> bac;

    for(int i = bac; i >= 0; i--){
        cout << "Nhap he so bac " << i << ": ";
        cin >> heSo[i];
    }
}

void cDaThuc::Xuat(){
    bool first = true;

    for(int i = bac; i >= 0; i--){
        if(heSo[i] == 0) continue;

        if(!first && heSo[i] > 0)
            cout << " + ";

        if(heSo[i] < 0)
            cout << " - ";

        double absHeSo = abs(heSo[i]);

        if(absHeSo != 1 || i == 0)
            cout << absHeSo;

        if(i > 0){
            cout << "x";

            if(i > 1)
                cout << "^" << i;
        }

        first = false;
    }

    if(first)
        cout << "0";

    cout << endl;
}

double cDaThuc::TinhGiaTri(double x){
    double tong = 0;

    for(int i = 0; i <= bac; i++){
        tong += heSo[i] * pow(x, i);
    }

    return tong;
}

cDaThuc cDaThuc::Cong(cDaThuc dt){
    cDaThuc kq;

    kq.bac = max(bac, dt.bac);

    for(int i = 0; i <= kq.bac; i++){
        double hs1 = (i <= bac) ? heSo[i] : 0;
        double hs2 = (i <= dt.bac) ? dt.heSo[i] : 0;

        kq.heSo[i] = hs1 + hs2;
    }

    while(kq.bac > 0 && kq.heSo[kq.bac] == 0)
        kq.bac--;

    return kq;
}

cDaThuc cDaThuc::Tru(cDaThuc dt){
    cDaThuc kq;

    kq.bac = max(bac, dt.bac);

    for(int i = 0; i <= kq.bac; i++){
        double hs1 = (i <= bac) ? heSo[i] : 0;
        double hs2 = (i <= dt.bac) ? dt.heSo[i] : 0;

        kq.heSo[i] = hs1 - hs2;
    }

    while(kq.bac > 0 && kq.heSo[kq.bac] == 0)
        kq.bac--;

    return kq;
}