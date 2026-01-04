#ifndef KYSU_H
#define KYSU_H

#include "nhanvien.h"

class KySu : public NhanVien{
private:
    int SoGioLamThem;
public:
    KySu() {}
    KySu(string MaSo, string Ten, double Luong, int SoGioLamThem) : NhanVien(MaSo, Ten, Luong), SoGioLamThem(SoGioLamThem) {}
    double TienThuong() const override {
        return (double) 100000.0 * SoGioLamThem;
    }
    void Xuat() const override{
        cout << "Đay la thong tin cua Ky Su" << "\n";
        NhanVien::Xuat();
        //cout << "So gio lam them: " << SoGioLamThem << "\n";
        cout << "Tien Thuong: " << TienThuong() << "\n";
        cout << "---------------------------" << "\n";
    }
};
#endif 