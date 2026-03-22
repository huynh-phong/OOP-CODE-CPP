#include <iostream>
using namespace std; 

void Input(int &x, int &y)
{  
    cin >> x >> y;
}

int main()
{
    int a, b, c, d;
    cout << "Nhập phân số 1 (a b): ";
    Input(a,b);
    while(b==0)
    {
        cout << "Mẫu số không thể bằng 0. Nhập lại: ";
        Input(a,b);
    }
    cout << "Nhập phân số 2 (c d): ";
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
    if(a*d > b*c)
        cout << "Phân số lớn hơn là: " << a << "/" << b << endl;
    else if(a*d < b*c)
        cout << "Phân số lớn hơn là: " << c << "/" << d << endl;
    else
        cout << "Hai phân số bằng nhau!" << endl;

    return 0;
}