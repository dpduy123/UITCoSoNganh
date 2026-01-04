#include "NgayThangNam.h"

//Constructor mac dinh
NgayThangNam::NgayThangNam() : iNgay(0), iThang(0), iNam(0) {};

//Constructor voi Gio Phut Ngay
NgayThangNam::NgayThangNam(int Ngay, int Thang, int Nam) : iNgay(Ngay), iThang(Thang), iNam(Nam) {};

//Ham tinh tong so ngay 
int NgayThangNam::TongNgay() const{
    int Ngay = iNgay + iNam * 365;
    for (int i = 1; i <= iThang - 1; i++) {
        Ngay += days[i];
    }
    return Ngay;
}
//Phuong Thuc TinhNgay 
void NgayThangNam::TinhNgay(int Ngay)  {
    iNam = Ngay / 365;
    Ngay %= 365;
    for (int i = 1; i <= 12; i++) {
        if (days[i] >= Ngay) {iThang = i; break;}
        else {
            Ngay -= days[i];
        }
    }    
    iNgay = Ngay;
    
}
//Toan tu + Ngay
NgayThangNam NgayThangNam::operator+ (int Ngay) {
    int sum = Ngay + TongNgay();
    NgayThangNam res;
    res.TinhNgay(sum);
    return res;
}   

//Toan tu - Ngay
NgayThangNam NgayThangNam::operator- (int Ngay) {
    int sum = TongNgay() - Ngay;
    NgayThangNam res;
    res.TinhNgay(sum);
    return res;
}

// Toan tu + NgayThangNam
NgayThangNam NgayThangNam::operator+ (const NgayThangNam &a) {
    int sum = TongNgay() + a.TongNgay();
    NgayThangNam res;
    res.TinhNgay(sum);
    return res;
}

// Toan tu - NgayThangNam
NgayThangNam NgayThangNam::operator- (const NgayThangNam &a) {
    int sum = TongNgay() - a.TongNgay();
    NgayThangNam res;
    res.TinhNgay(sum);
    return res;
}

//Toan tu ++
NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

//Toan tu --
NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

//Cac toan tu so sanh
bool NgayThangNam::operator== (const NgayThangNam &a) {
    return TongNgay() == a.TongNgay();
}
bool NgayThangNam::operator!= (const NgayThangNam &a) {
    return TongNgay() != a.TongNgay();
}
bool NgayThangNam::operator>= (const NgayThangNam &a) {
    return TongNgay() >= a.TongNgay();
}
bool NgayThangNam::operator<= (const NgayThangNam &a) {
    return TongNgay() <= a.TongNgay();
}
bool NgayThangNam::operator> (const NgayThangNam &a) {
    return TongNgay() > a.TongNgay();
}
bool NgayThangNam::operator< (const NgayThangNam &a) {
    return TongNgay() < a.TongNgay();
}

//Cac toan tu nhap xuat
istream& operator >> (istream& in, NgayThangNam &a) {
    cout << "Nhap Ngay: ";
    in >> a.iNgay;
    cout << "Nhap so Thang: ";
    in >> a.iThang;
    cout << "Nhap so Nam: ";
    in >> a.iNam;
    return in; 
}

ostream& operator << (ostream& out, const NgayThangNam &a) {
    out << "Ngay " << a.iNgay << " Thang " << a.iThang << " Nam " << a.iNam << "\n";
    return out;
}