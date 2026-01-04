#ifndef NONGTRAI_H
#define NONGTRAI_H

#include "giasuc.h"

class NongTrai{
private: 
    vector <GiaSuc*> Cattle;
public: 
    ~NongTrai() {
        for (GiaSuc* gs : Cattle) {
            delete gs;
        }
    }
    void themGiaSuc(GiaSuc* gs) {
        Cattle.push_back(gs);
    }

    void tiengKeu() const {
        for (const GiaSuc* gs : Cattle) {
            cout << gs->Sound() << endl;
        }
    }

    void thongKe() {
        int tongSoLuong = 0;
        int tongSua = 0;

        for (GiaSuc* gs : Cattle) {
            int soLuongMoi = 0;
            int sua = 0;

            // Thống kê từng loại gia súc
            for (int i = 0; i < gs->getSoLuong(); ++i) {
                soLuongMoi += gs->SoLuongSinh();
                sua += gs->SoLuongSua();
            }

            gs->tangSoLuong(soLuongMoi);
            tongSoLuong += gs->getSoLuong();
            tongSua += sua;

            cout << "Loại gia súc: " << gs->Sound() << endl;
            cout << "Số lượng mới sinh: " << soLuongMoi << endl;
            cout << "Tổng sữa: " << sua << " lít" << endl;
        }

        cout << "\nTổng số lượng gia súc: " << tongSoLuong << endl;
        cout << "Tổng lượng sữa thu được: " << tongSua << " lít" << endl;
    }
};
#endif