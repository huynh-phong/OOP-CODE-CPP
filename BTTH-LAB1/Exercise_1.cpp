#include <iostream>
using namespace std;
int ucln(int a, int b)
{
    if(b==0) return a;
    return ucln(b, a%b);
}
void Input(int &a, int &b)
{
    cout << "Nhap Tử: ";
    cin >> a;
    cout << "Nhap Mẫu: ";
    cin >> b;
}
int main()
{
    int a, b,c;
    Input(a, b);
    while(b==0)
    {
        cout << "Mẫu phải khác 0, vui lòng nhập lại!" << endl;
        Input(a, b);
    }
    c = ucln(abs(a), abs(b));
    a=a/c;
    b=b/c;
    if(b<0)
    {
        a=-a;
        b=-b;
    }
    if(b!=1)
    cout << "Phân số sau khi rút gọn: " << a << "/" << b << endl;
    else
    cout << "Phân số sau khi rút gọn: " << a << endl;
    return 0;
}