#ifndef DELUXE_H
#define DELUXE_H

#include "roomclass.h"

class Deluxe : public RoomClass {
private: 
    int PhiDichVu, PhiPhucVu;
public: 
    Deluxe(int SoDem, int PhiDichVu, int PhiPhucVu) : RoomClass(SoDem), PhiDichVu(PhiDichVu), PhiPhucVu(PhiPhucVu) {}
    int DoanhThuPhong() const override {
        return SoDem * 750000 + PhiDichVu + PhiPhucVu;
    }
};

#endif