#ifndef CDAGIAC_H
#define CDAGIAC_H

class DIEM{
    public: 
    double x,y;
    void Nhap();
    void Xuat();
};
class DAGIAC{
    private:
    int n;
    DIEM nDiem[100];

    public:
    void Nhap();
    void Xuat();

    bool KiemTraHopLe();

    void KiemTraLoaiDaGiac();
    void ChuVi();
    void DienTich();
    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongTo(double k);
    void ThuNho(double k);
};
#endif