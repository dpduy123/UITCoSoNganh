#include "diem.h"

class DaGiac{
private:
    int n;
    vector <Diem> Dinh;
public: 
    void Nhap() {
       // cout << "Nhập số đỉnh của đa giác: ";
        cin >> n;
        Dinh.resize(n);
        for (int i = 0; i < n; i++) 
        {
            //cout << "Nhập tọa độ đỉnh thứ " << i + 1 << "\n";
            cin >> Dinh[i].iHoanh >> Dinh[i].iTung;
        }
    }
    void Xuat() {
       cout << "Đa giác có " << n << " đỉnh:" << "\n";
       for (int i = 1; i <= n; i++) 
       {
            Dinh[i - 1].Xuat(i);
       }
    }

    void Quay(double angle) {
        double rad = angle * M_PI / 180.0;
        double cosA = cos(rad);
        double sinA = sin(rad);

        for (int i = 0; i < n; i++) {
            Dinh[i].iHoanh = (int) Dinh[i].iHoanh * cosA - Dinh[i].iTung * sinA;
            Dinh[i].iTung = (int) Dinh[i].iHoanh * sinA + Dinh[i].iTung * cosA;
        }
    }
    // Hàm tính diện tích đa giác
    double tinhDienTich() const {
        double dienTich = 0.0;
        int n = Dinh.size();
        
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n; // chỉ số điểm tiếp theo
            dienTich += Dinh[i].iHoanh * Dinh[j].iTung;
            dienTich -= Dinh[j].iHoanh * Dinh[i].iTung;
        }
        
        return std::fabs(dienTich) / 2.0; // Trả về diện tích tuyệt đối
    }
};