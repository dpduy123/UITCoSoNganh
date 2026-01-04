#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <bits/stdc++.h> 

using namespace std;

class NhanVien{
protected:
    string MaSo, Ten;
    double Luong;
public:
    NhanVien() {} 
    NhanVien(string MaSo, string Ten, double Luong) : MaSo(MaSo), Ten(Ten), Luong(Luong) {}
    virtual ~NhanVien() {}
    virtual double TienThuong() const = 0;
    virtual void Xuat() const {
        cout << "Nhan Vien: " << Ten << "\n";
        cout << "MaSo: " << MaSo << "\n";
        cout << "Luong co ban: " << fixed << setprecision(2) << Luong << "\n";
    }
};
#endif