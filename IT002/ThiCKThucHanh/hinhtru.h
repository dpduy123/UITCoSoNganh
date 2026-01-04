#ifndef HINHTRU_H
#define HINHTRU_H

#include "chai.h"
class HinhTru : public Chai {
private: 
    double r, h;
public: 
    HinhTru(double _r, double _h);
    double DienTich() override;
    double TheTich() override;
    double TyLeRuou() override;
    double LuongRuou() override;
};

#endif 