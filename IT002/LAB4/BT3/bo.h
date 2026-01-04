#ifndef BO_H
#define BO_H

#include "giasuc.h"

class Bo : public GiaSuc{

public: 
    Bo(int SoLuong) : GiaSuc(SoLuong) {}
    string Sound() const override {
        return "Boooooooooo";
    }

    int SoLuongSinh() const override {
        return rand() % 3 + 1;
    }
    int SoLuongSua() const override {
        return rand() % 21;
    }
};
#endif