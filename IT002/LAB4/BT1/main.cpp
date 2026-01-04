#include "quanly.h"
#include "kysu.h"

string ms, ten;
double luong, tlt;
int sogio;
QuanLy NhapQuanLy() {
    cout << "Nhap thong tin quan ly: " << "\n";
    cout << "MaSo: "; 
    cin >> ms;
    cout << "Ten: ";
    cin >> ten;
    cout << "Luong co ban: ";
    cin >> luong;
    cout << "Ty Le Thuong: ";
    cin >> tlt;
    QuanLy a(ms, ten, luong, tlt);
    return a;
}

KySu NhapKySu() {
    cout << "Nhap thong tin ky su: " << "\n";
    cout << "MaSo: "; 
    cin >> ms;
    cout << "Ten: ";
    cin >> ten;
    cout << "Luong co ban: ";
    cin >> luong;
    cout << "So gio lam them: ";
    cin >> sogio;
    KySu a(ms, ten, luong, sogio);
    return a;
}
signed main() {

    QuanLy a = NhapQuanLy();
    KySu b = NhapKySu();
    cout << "---------------------------" << "\n";
    a.Xuat();
    b.Xuat();    
    return 0;

}