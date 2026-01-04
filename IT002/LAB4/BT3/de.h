#ifndef DE_H
#define DE_H

#include "giasuc.h"

class De : public GiaSuc{

public: 
    De(int SoLuong) : GiaSuc(SoLuong) {};
    string Sound() const override {
        return "Deeeeeeeeee";
    }
    int SoLuongSinh() const override {
        return rand() % 3 + 1;
    }
    int SoLuongSua() const override {
        return rand() % 11;
    }
};
#endif