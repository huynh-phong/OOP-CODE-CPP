#ifndef CTIME_H
#define CTIME_H
#include <iostream>
using namespace std;

class CTime{
    private:
    int gio,phut,giay;
    void ChuanHoa();

    public:
    CTime(int h=0,int m=0, int s=0);

    friend istream& operator>>(istream& in,CTime& t);
    friend ostream& operator<<(ostream& out,const CTime& t);
 
    CTime operator+(int s) const;
    CTime operator-(int s) const;

    CTime operator++();
    CTime operator--();
};
#endif