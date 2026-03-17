#include <iostream>
using namespace std;

void Input(int &d, int &m, int &y)
{
    cout << "Nhập Ngày: ";
    cin >> d;
    cout << "Nhập Tháng: ";
    cin >> m;
    cout << "Nhập Năm: ";
    cin >> y;
}
int True(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
        return 0;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return 0;
    if (m == 2)
    {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if ((isLeap && d > 29) || (!isLeap && d > 28))
            return 0;
    }
    return 1;
}
int NamNhuan(int y)
{
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 29 : 28;
}
int main()
{
    int d, m, y;
    Input(d, m, y);
    while (!True(d, m, y) || abs(y - 2026) > 150)
    {
        if(!True(d, m, y))
            cout << "Ngày không hợp lệ! Nhập lại!\n";
        if(abs(y - 2026) > 150)
            cout << "Năm phải cách năm 2026 không quá 150 năm. Nhập lại!\n";
        Input(d, m, y);
    }
    if (m == 2)
    {
        if (d == NamNhuan(y))
            cout << "Ngày tiếp theo là: 1/" << m+1 << "/" << y;
        else
            cout << "Ngày tiếp theo là: " << d+1 << "/" << m << "/" << y;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 30)
        cout << "Ngày tiếp theo là: 1/" << m+1 << "/" << y;
    else if (m == 12 && d == 31)
        cout << "Ngày tiếp theo là: 1/1/" << y+1;
    else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) && d == 31)
        cout << "Ngày tiếp theo là: 1/" << m+1 << "/" << y;
    else
        cout << "Ngày tiếp theo là: " << d+1 << "/" << m << "/" << y;

    return 0;
}