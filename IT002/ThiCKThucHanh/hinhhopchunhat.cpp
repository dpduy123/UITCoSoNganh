#include "hinhhopchunhat.h" 

HinhHopChuNhat::HinhHopChuNhat(double _l, double _w, double _h) : l(_l), w(_w), h(_h) {}

double HinhHopChuNhat::DienTich() {
    return (2 * w + l * h + w * h);
}

double HinhHopChuNhat::TheTich() {
    return l * h * w;
}
double HinhHopChuNhat::TyLeRuou() {
    double V = 1;
    double res = V;
    double l1 = V * 0.40;
    double l2 = (res - l1) * 0.50;
    double l3 = l2 * 0.10;
    double l4 = V * 0.02;
    res = res - l1 - l2 - l3 - l4;
    return res;
}
double HinhHopChuNhat::LuongRuou() {
    double V = this->TheTich();
    double res = V;
    double l1 = V * 0.40;
    double l2 = (res - l1) * 0.50;
    double l3 = l2 * 0.10;
    double l4 = V * 0.02;
    res = res - l1 - l2 - l3 - l4;
    return res;
}