#ifndef CARRAY_H
#define CARRAY_H

class cArray{
private:
    int n;
    int a[100];

public:
    void TaoMangNgauNhien();
    void Xuat();

    int DemX(int x);
    bool KiemTraTangDan();

    int TimLeNhoNhat();
    int TimSoNguyenToLonNhat();

    void SapXepTangDan();
    void SapXepGiamDan();
};

#endif