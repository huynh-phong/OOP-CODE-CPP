#include <iostream>
#include "cArray.h"

using namespace std;

int main(){
    cArray arr;

    cout << "TAO MANG NGAU NHIEN\n";
    arr.TaoMangNgauNhien();

    cout << "\nMang vua tao:\n";
    arr.Xuat();

    int x;
    cout << "\nNhap gia tri can dem: ";
    cin >> x;

    cout << "So lan xuat hien cua " << x << ": "
         << arr.DemX(x) << endl;

    if(arr.KiemTraTangDan())
        cout << "Mang tang dan.\n";
    else
        cout << "Mang khong tang dan.\n";

    int minLe = arr.TimLeNhoNhat();
    if(minLe != -1)
        cout << "So le nho nhat: " << minLe << endl;
    else
        cout << "Khong co so le trong mang.\n";

    int maxNT = arr.TimSoNguyenToLonNhat();
    if(maxNT != -1)
        cout << "So nguyen to lon nhat: " << maxNT << endl;
    else
        cout << "Khong co so nguyen to trong mang.\n";

    arr.SapXepTangDan();
    cout << "\nMang sau khi sap xep tang dan:\n";
    arr.Xuat();

    arr.SapXepGiamDan();
    cout << "\nMang sau khi sap xep giam dan:\n";
    arr.Xuat();

    return 0;
}