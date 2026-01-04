#include <bits/stdc++.h> 

using namespace std;

class Diem{
private:
    double iHoanh; // hoanh do 
    double iTung; // tung do
public:
    // Ham khoi tao mac dinh
    Diem() : iHoanh(0), iTung(0) {};

    // Ham khoi tao voi tham so 
    Diem(double _iHoanh, double _iTung) : iHoanh(_iHoanh), iTung(_iTung) {}
    
    // Ham khoi tao voi sao chep 
    Diem(const Diem &x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

    // Phuong thuc Xuat
    void Nhap() {
        cin >> iHoanh >> iTung;
    }
    void Xuat() {
        cout << "(" << iHoanh << ", " << iTung << ")" << "\n";
    }

    void NhanDoi() {
        iHoanh = iHoanh * 2;
        iTung = iTung * 2;
    }
    double GetHoanhDo() {
        return iHoanh;
    }
    double GetTungDo (){
        return iTung;
    } 

    void SetHoanhDo(double Hoanh) {
        iHoanh = Hoanh;
    }

    void SetTungDo(double Tung) {
        iTung = Tung;
    }

    void TinhTienX(double dx) {
        iHoanh += dx;
    }
    void TinhTienY(double dy) {
        iTung += dy;
    }
};