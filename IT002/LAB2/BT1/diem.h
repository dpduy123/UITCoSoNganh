#include <bits/stdc++.h> 

using namespace std;

class Diem{
private:
    int iHoanh; // hoanh do 
    int iTung; // tung do
public:
    // Ham khoi tao mac dinh
    Diem() : iHoanh(0), iTung(0) {};

    // Ham khoi tao voi tham so 
    Diem(int _iHoanh, int _iTung) : iHoanh(_iHoanh), iTung(_iTung) {}
    
    // Ham khoi tao voi sao chep 
    Diem(const Diem &x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

    // Phuong thuc Nhap 
    void Nhap() {
        cout << "Nhap toa do cua diem: {x y}" << "\n";
        cin >> iHoanh >> iTung;
    }
    // Phuong thuc Xuat
    void Xuat() {
        cout << "Diem(" << iHoanh << ", " << iTung << ")" << "\n";
    }

    int GetHoanhDo() {
        return iHoanh;
    }
    int GetTungDo (){
        return iTung;
    } 

    void SetHoanhDo(int Hoanh) {
        iHoanh = Hoanh;
    }

    void SetTungDo(int Tung) {
        iTung = Tung;
    }

    void TinhTien(int dx, int dy) {
        iHoanh += dx;
        iTung += dy;
    }
};