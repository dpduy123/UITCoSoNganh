#ifndef CUU_H
#define CUU_H

#include "giasuc.h"

class Cuu : public GiaSuc{

public: 
    Cuu(int SoLuong) : GiaSuc(SoLuong) {}
    string Sound() const override {
        return "Cuuuuuuuuuuuuu";
    }
    int SoLuongSinh() const override {
        return rand() % 3 + 1;
    }
    int SoLuongSua() const override {
        return rand() % 6;
    }
};
#endif