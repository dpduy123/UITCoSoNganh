#include "diem.h"
class TamGiac{
private:
    Diem A, B, C;
public: 
    void Nhap() {
        double ax, ay, bx, by, cx, cy;
        cout << "Nhập tọa độ đỉnh A: ";
        cin >> ax >> ay;
        cout << "Nhập tọa độ đỉnh B: ";
        cin >> bx >> by;
        cout << "Nhập tọa độ đỉnh C: ";
        cin >> cx >> cy;
        A = Diem(ax, ay);
        B = Diem(bx, by);
        C = Diem(cx, cy);
    }
    void Xuat() {
       cout << "Tam giác có: " << "\n";
       A.Xuat('A');
       B.Xuat('B');
       C.Xuat('C');
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