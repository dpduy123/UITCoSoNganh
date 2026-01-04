#include "hinhcau.h" 

HinhCau::HinhCau(double _r) : r(_r) {}

double HinhCau::DienTich() {
    return 4 * 3.14 * r * r;
}

double HinhCau::TheTich() {
    return 3.14 * 4 * r * r * r / 3;
}
double HinhCau::TyLeRuou() {
    double V = 1;
    double res = V;
    double l1 = V * 0.18;
    double l2 = (res - l1) * 0.50 * 0.25;
    double l3 = 0.12 * V; //
    double l4 = V * 0.025;
    double l5 = (res - l1 - l2 - l3 - l4) * 0.06 * 0.80;
    res = res - l1 - l2 - l3 - l4 - l5;
    return res;
}

double HinhCau::LuongRuou() {
    double V = this->TheTich();
    double res = V;
    double l1 = V * 0.18;
    double l2 = (res - l1) * 0.50 * 0.25;
    double l3 = 0.12 * V; //
    double l4 = V * 0.025;
    double l5 = (res - l1 - l2 - l3 - l4) * 0.06 * 0.80;
    res = res - l1 - l2 - l3 - l4 - l5;
    return res;
}