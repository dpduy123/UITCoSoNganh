#ifndef PREMIUM_H
#define PREMIUM_H

#include "roomclass.h"

class Premium : public RoomClass {
private: 
    int PhiDichVu;
public:
    Premium(int SoDem, int PhiDichVu) : RoomClass(SoDem), PhiDichVu(PhiDichVu) {}
    int DoanhThuPhong() const override {
        return SoDem * 500000 + PhiDichVu;
    }
};

#endif 