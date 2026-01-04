#include "SoPhuc.h" 

//Constructor mac dinh
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

//Constructor voi phan thuc va phan ao 
SoPhuc::SoPhuc(int thuc, int ao) : dThuc(thuc), dAo(ao) {}

//Toan tu +
SoPhuc SoPhuc::operator+ (const SoPhuc &a) {
    return SoPhuc(dThuc + a.dThuc, dAo + a.dAo);
}

//Toan tu -
SoPhuc SoPhuc::operator- (const SoPhuc &a) {
    return SoPhuc(dThuc - a.dThuc, dAo - a.dAo);
}

//Toan tu * 
SoPhuc SoPhuc::operator* (const SoPhuc &a) {
    return SoPhuc(dThuc * a.dThuc - dAo * a.dAo, dThuc * a.dAo + a.dThuc * dAo);
}

//Toan tu /
SoPhuc SoPhuc::operator/ (const SoPhuc &a) {
    return SoPhuc((dThuc * a.dThuc + dAo * a.dAo) / (a.dThuc * a.dThuc + a.dAo * a.dAo), (a.dThuc * dAo - dThuc * a.dAo) / (a.dThuc * a.dThuc + a.dAo * a.dAo));
}

//Toan tu == 
bool SoPhuc::operator== (const SoPhuc &a) {
    return (dThuc == a.dThuc && dAo == a.dAo);
}

//Toan tu != 
bool SoPhuc::operator!= (const SoPhuc &a) {
    return !(a.dThuc * a.dThuc == a.dAo * a.dAo);
}

//Toan tu >>
istream& operator >> (istream& in, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    in >> sp.dThuc;
    cout << "Nhap phan ao: ";
    in >> sp.dAo;
    return in;
}
//Toan tu <<
ostream& operator << (ostream& out, const SoPhuc& sp) {
    out << sp.dThuc << " + " << sp.dAo << 'i' << "\n";
    return out; 
}