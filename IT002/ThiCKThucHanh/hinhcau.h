#ifndef HINHCAU_H
#define HINHCAU_H

#include "chai.h"
class HinhCau : public Chai {
private: 
    double r;
public: 
    HinhCau(double _r);
    double DienTich() override;
    double TheTich() override;
    double TyLeRuou() override;
    double LuongRuou() override;
};

#endif 