#include "diem.h"

class DaGiac{
private:
    int n;
    vector <Diem> Dinh;
public: 
    void Nhap() {
        cout << "Nhập số đỉnh của đa giác: ";
        cin >> n;
        Dinh.resize(n);
        for (int i = 0; i < n; i++) 
        {
            cout << "Nhập tọa độ đỉnh thứ " << i + 1 << "\n";
            cin >> Dinh[i].iHoanh >> Dinh[i].iTung;
        }
    }
    void Xuat() {
       cout << "Đa giác có " << n << " đỉnh:" << "\n";
       for (int i = 1; i <= n; i++) 
       {
            Dinh[i - 1].Xuat(i);
       }
    }

    void TinhTien(double dx, double dy) {
        for (int i = 0; i < n; i++) 
            Dinh[i].TinhTien(dx, dy);
    }
    void PhongTo(double x) {
        for (int i = 0; i < n; i++) {
            Dinh[i].iHoanh = Dinh[i].iHoanh * x;
            Dinh[i].iTung = Dinh[i].iTung * x;
        }
    }
    void ThuNho(double x) {
        PhongTo (1.0 / x);
    }
    void Quay(double angle) {
        double rad = angle * M_PI / 180.0;
        double cosA = cos(rad);
        double sinA = sin(rad);

        for (int i = 0; i < n; i++) {
            Dinh[i].iHoanh = (int) Dinh[i].iHoanh * cosA - Dinh[i].iTung * sinA;
            Dinh[i].iTung = (int) Dinh[i].iHoanh * sinA + Dinh[i].iTung * cosA;
        }
        
    }
};