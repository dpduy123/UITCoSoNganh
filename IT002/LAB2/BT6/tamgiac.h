#include "diem.h"

class TamGiac{
private:
    Diem A, B, C;
public: 
    void Nhap() {
        double ax, ay, bx, by, cx, cy;
        cin >> ax >> ay;
        cin >> bx >> by;
        cin >> cx >> cy;
        A = Diem(ax, ay);
        B = Diem(bx, by);
        C = Diem(cx, cy);
    }
    void Xuat() {
       A.Xuat();
       B.Xuat();
       C.Xuat();
    }

    void TinhTien(double dx, double dy) {
        A.TinhTien(dx, dy);
        B.TinhTien(dx, dy);
        C.TinhTien(dx, dy);
    }
    void PhongTo(double x) {
        A.iHoanh = (double) A.iHoanh * x;
        A.iTung = (double) A.iTung * x;
        B.iHoanh = (double) B.iHoanh * x;
        B.iTung = (double) B.iTung * x;
        C.iHoanh = (double) C.iHoanh * x;
        C.iTung = (double) C.iTung * x;
    }
    void ThuNho(double x) {
        PhongTo (1.0 / x);
    }
    void Quay(double angle) {
        double rad = angle * M_PI / 180.0;
        double cosA = cos(rad);
        double sinA = sin(rad);
        double newHoanh, newTung;
        newHoanh = (int) A.iHoanh * cosA - A.iTung * sinA;
        newTung = (int) A.iHoanh * sinA + A.iTung * cosA;
        A = Diem(newHoanh, newTung);

        newHoanh = (int) B.iHoanh * cosA - B.iTung * sinA;
        newTung = (int) B.iHoanh * sinA + B.iTung * cosA;
        B = Diem(newHoanh, newTung);

        newHoanh = (int) C.iHoanh * cosA - C.iTung * sinA;
        newTung = (int) C.iHoanh * sinA + C.iTung * cosA;
        C = Diem(newHoanh, newTung);
    }
};