#ifndef HINHHOPCHUNHAT_H
#define HINHHOPCHUNHAT_H

#include "chai.h"
class HinhHopChuNhat : public Chai {
private: 
    double l, w, h;
public: 
    HinhHopChuNhat(double _l, double _w, double _h);
    double DienTich() override;
    double TheTich() override;
    double TyLeRuou() override;
    double LuongRuou() override;
};

#endif 