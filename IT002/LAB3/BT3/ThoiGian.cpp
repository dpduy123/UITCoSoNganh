#include "ThoiGian.h"

//Constructor mac dinh
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {};

//Constructor voi Gio Phut Giay
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {};

//Phuong Thuc TinhGiay 
int ThoiGian::TinhGiay() const {
    return (iGiay + iGio * 3600 + iPhut * 60);
}
void ThoiGian::TinhLaiGio(int Giay)
{
    iGio = Giay / 3600;
    Giay %= 3600;
    iPhut = Giay / 60;
    Giay %= 60;
    iGiay = Giay;
}
//Toan tu + giay
ThoiGian ThoiGian::operator+ (int Giay) {
    int TongGiay = TinhGiay() + Giay;
    ThoiGian res;
    res.TinhLaiGio(TongGiay);
    return res;
}

//Toan tu - giay
ThoiGian ThoiGian::operator- (int Giay) {
    int TongGiay = TinhGiay() - Giay;
    ThoiGian res;
    res.TinhLaiGio(TongGiay);
    return res;
}

// Toan tu + ThoiGian
ThoiGian ThoiGian::operator+ (const ThoiGian &a) {
    int TongGiay = TinhGiay() + a.TinhGiay();
    ThoiGian res;
    res.TinhLaiGio(TongGiay);
    return res;
}

// Toan tu - ThoiGian
ThoiGian ThoiGian::operator- (const ThoiGian &a) {
    int TongGiay = TinhGiay() - a.TinhGiay();
    ThoiGian res;
    res.TinhLaiGio(TongGiay);
    return res;
}

//Toan tu ++
ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

//Toan tu --
ThoiGian& ThoiGian::operator--() {
    *this = *this - 1;
    return *this;
}

//Cac toan tu so sanh
bool ThoiGian::operator== (const ThoiGian &a) {
    return TinhGiay() == a.TinhGiay();
}
bool ThoiGian::operator!= (const ThoiGian &a) {
    return TinhGiay() != a.TinhGiay();
}
bool ThoiGian::operator>= (const ThoiGian &a) {
    return TinhGiay() >= a.TinhGiay();
}
bool ThoiGian::operator<= (const ThoiGian &a) {
    return TinhGiay() <= a.TinhGiay();
}
bool ThoiGian::operator> (const ThoiGian &a) {
    return TinhGiay() > a.TinhGiay();
}
bool ThoiGian::operator< (const ThoiGian &a) {
    return TinhGiay() < a.TinhGiay();
}

//Cac toan tu nhap xuat
istream& operator >> (istream& in, ThoiGian &a) {
    cout << "Nhap so Gio: ";
    in >> a.iGio;
    cout << "Nhap so Phut: ";
    in >> a.iPhut;
    cout << "Nhap so Giay: ";
    in >> a.iGiay;
    a.TinhLaiGio(a.TinhGiay());
    return in; 
}

ostream& operator << (ostream& out, const ThoiGian &a) {
    out << a.iGio << " Gio " << a.iPhut << " Phut " << a.iGiay << " Giay " << "\n";
    return out;
}