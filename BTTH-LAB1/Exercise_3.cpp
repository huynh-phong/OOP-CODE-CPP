#include <iostream>
#include <cmath>
using namespace std; 

int Rutgon(int a, int b)
{
    if(b==0) return a;
    return Rutgon(b, a%b);
}

void Input(int &x, int &y)
{  
    cin >> x >> y;
}

void Xuat(int tu, int mau)
{
    cout << tu << "/" << mau << endl;
    int g = Rutgon(abs(tu), abs(mau));
    if(g > 1) 
    {
        tu /= g;
        mau /= g;
        if(mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
        cout << "Rút gọn: " << tu;
        if(mau != 1)
            cout << "/" << mau;
        cout << endl;
    }
}

int main()
{
    int a, b, c, d;
    cout << "Nhập phân số 1 có dạng là a/b lần lượt a b: ";
    Input(a,b);
    while(b==0)
    {
        cout << "Mẫu số không thể bằng 0. Nhập lại: ";
        Input(a,b);
    }
    cout << "Nhập phân số 2 có dạng là c/d lần lượt c d: ";
    Input(c,d);
    while(d==0)
    {
        cout << "Mẫu số không thể bằng 0. Nhập lại: ";
        Input(c,d);
    }
    if(b<0)
    {
        a=-a;
        b=-b;
    }
    if(d<0)
    {
        c=-c;
        d=-d;
    }
    cout << "Tổng của hai phân số là: ";
    Xuat(a*d + c*b , b*d);
    cout << "Hiệu của hai phân số là: ";
    Xuat(a*d - c*b , b*d);
    cout << "Tích của hai phân số là: ";
    Xuat(a*c , b*d);
    if(c==0)
    {
        cout << "Không thể chia cho phân số có tử số bằng 0!" << endl;
    }
    else
    {
        cout << "Thương của hai phân số là: ";
        Xuat(a*d , b*c);
    }

    return 0;
}