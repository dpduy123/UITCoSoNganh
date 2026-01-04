#ifndef BUSINESS_H
#define BUSINESS_H

#include "roomclass.h"

class Business : public RoomClass{

public: 
    Business(int SoDem) : RoomClass(SoDem) {}
    int DoanhThuPhong() const override {
        return SoDem * 300000;
    }
};
#endif 