#ifndef QUANLY_H
#define QUANLY_H

#include "nhanvien.h"

class QuanLy : public NhanVien{
private: 
    double TyLeThuong;
public:
    QuanLy() {}
    QuanLy(string MaSo, string Ten, double Luong, double TyLeThuong) : NhanVien(MaSo, Ten, Luong), TyLeThuong(TyLeThuong) {}
    double TienThuong() const override {
        return TyLeThuong * Luong;
    }
    void Xuat() const override{ 
        cout << "Đay la thong tin cua Quan Ly" << "\n";
        NhanVien::Xuat();
        //cout << "Ty le thuong: " << TyLeThuong << "\n";
        cout << "Tien thuong: " << TienThuong() << "\n";
        cout << "---------------------------" << "\n";
    }
};
#endif 