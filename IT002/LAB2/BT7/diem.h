#include <bits/stdc++.h> 

using namespace std;

class Diem{
private:

public:
    double iHoanh; // hoanh do 
    double iTung; // tung do
    // Ham khoi tao mac dinh
    Diem() : iHoanh(0), iTung(0) {};

    // Ham khoi tao voi tham so 
    Diem(double _iHoanh, double _iTung) : iHoanh(_iHoanh), iTung(_iTung) {}
    
    // Ham khoi tao voi sao chep 
    Diem(const Diem &x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

    // Phuong thuc Xuat
    void Xuat(int t) {
        cout << "Diem "<< t << "(" << iHoanh << ", " << iTung << ")" << "\n";
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

    void TinhTien(double dx, double dy) {
        iHoanh += dx;
        iTung += dy;
    }
};