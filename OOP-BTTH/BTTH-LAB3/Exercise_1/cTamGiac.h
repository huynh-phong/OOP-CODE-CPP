#ifndef CTAMGIAC_H
#define CTAMGIAC_H

class DIEM{
    public: 
    double x,y;
    void Nhap();
    void Xuat();
};
class TAMGIAC{
    private:
    DIEM A,B,C;

    public:
    void Nhap();
    void Xuat();

    bool KiemTraHopLe();

    void KiemTraLoaiTamGiac();
    void ChuVi();
    void DienTich();
    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongTo(double k);
    void ThuNho(double k);
};
#endif