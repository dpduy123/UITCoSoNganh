#ifndef ROOMCLASS_H
#define ROOMCLASS_H

#include <bits/stdc++.h> 

using namespace std;
class RoomClass{
protected:
    int SoDem;
public:
    RoomClass(int SoDem) : SoDem(SoDem) {}
    virtual ~RoomClass() {}
    virtual int DoanhThuPhong() const = 0;
};
#endif 