#include "hinhtru.h" 

HinhTru::HinhTru(double _r, double _h) : r(_r), h(_h) {}

double HinhTru::DienTich() {
    return 2 * 3.14 * r * (r + h);
}

double HinhTru::TheTich() {
    return 3.14 * r * r * h;
}

double HinhTru::TyLeRuou() {
    double V = 1;
    double res = 1;
    double l1 = 1.00 * V * 0.15 + V * 0.15 * 0.45;
    double l2 = 1.00 * V * 0.05 + (res - l1) * 0.20;
    double l3 = V * 1.00 / 33;
    double l4 = 0.03 * 0.80 * (res - l1 - l2 - l3);
    res = res - l1 - l2 - l3 - l4;
    return res;
}
double HinhTru::LuongRuou() {
    double V = this->TheTich();
    double res = V;
    double l1 = 1.00 * V * 0.15 + V * 0.15 * 0.45;
    double l2 = 1.00 * V * 0.05 + (res - l1) * 0.20;
    double l3 = V * 1.00 / 33;
    double l4 = 0.03 * 0.80 * (res - l1 - l2 - l3);
    res = res - l1 - l2 - l3 - l4;
    return res;
}