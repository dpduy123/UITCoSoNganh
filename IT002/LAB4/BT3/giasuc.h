#ifndef GIASUC_H
#define GIASUC_H

#include <bits/stdc++.h> 
using namespace std;

class GiaSuc{
protected:
    int SoLuong;
public: 
    GiaSuc(int SoLuong) : SoLuong(SoLuong) {}
    virtual ~GiaSuc() {} 
    virtual string Sound() const = 0;
    virtual int SoLuongSinh () const = 0;
    virtual int SoLuongSua() const = 0;

    int getSoLuong() const {
        return SoLuong;
    }

    void tangSoLuong(int them) {
        SoLuong += them;
    }
};
#endif