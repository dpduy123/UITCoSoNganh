#include "PhanSo.h"

//Constructor mac dinh
PhanSo::PhanSo() : iTu(0), iMau(1) {}

//Constructor voi tu va mau 
PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    RutGon();
}

//Toan tu +
PhanSo PhanSo::operator+(const PhanSo &a) {
    return PhanSo(iTu * a.iMau + a.iTu * iMau, iMau * a.iMau);
}

//Toan tu -
PhanSo PhanSo::operator-(const PhanSo &a) {
    return PhanSo(iTu * a.iMau - a.iTu * iMau, iMau * a.iMau);
}

//Toan tu *
PhanSo PhanSo::operator*(const PhanSo &a) {
    return PhanSo(iTu * a.iTu, iMau * a.iMau);
}

//Toan tu /
PhanSo PhanSo::operator/(const PhanSo &a) {
    return PhanSo(iTu * a.iMau, iMau * a.iTu);
}

//Toan tu == 
bool PhanSo::operator==(const PhanSo &a) {
    return (iTu == a.iTu && iMau == a.iMau);
}

//Toan tu != 
bool PhanSo::operator!=(const PhanSo &a) {
    return !(iTu == a.iTu && iMau == a.iMau);
}

//Toan tu >= 
bool PhanSo::operator>=(const PhanSo &a) {
    return iTu * a.iMau >= a.iTu * iMau;
}

//Toan tu >= 
bool PhanSo::operator<=(const PhanSo &a) {
    return iTu * a.iMau <= a.iTu * iMau;
}

//Toan tu > 
bool PhanSo::operator>(const PhanSo &a) {
    return iTu * a.iMau > a.iTu * iMau;
}

//Toan tu < 
bool PhanSo::operator<(const PhanSo &a) {
    return iTu * a.iMau < a.iTu * iMau;
}

istream& operator >> (istream& in, PhanSo &ps){
    cout << "Nhap tu so: ";
    in >> ps.iTu;
    cout << "Nhap mau so: ";
    in >> ps.iMau; 
    ps.RutGon();
    return in;
}

ostream& operator << (ostream& out, const PhanSo &ps) {
    out << ps.iTu << "/" << ps.iMau << "\n";
    return out;
}