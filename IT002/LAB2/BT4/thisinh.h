#include <bits/stdc++.h>

using namespace std;

class ThiSinh{
private: 
    string Ten, MSSV;
    int iNgay, iThang, iNam;
    double fToan, fVan, fAnh;
public:
    void Nhap() {
        cin.ignore();
        cout << "Nhập tên thí sinh: " << "\n";
        getline(cin, Ten);

        cout << "Nhập MSSV: " << "\n";
        cin >> MSSV;

        cout << "Nhập ngày tháng năm sinh: {dd mm yyyy}" << "\n";
        cin >> iNgay >> iThang >> iNam;

        cout << "Nhập lần lượt điểm Toán Văn Anh: " << "\n";
        cin >> fToan >> fVan >> fAnh;

        cin.ignore();
    }   
    void Xuat() {
        cout << "Tên thí sinh: " << Ten << "\n";
        cout << "MSSV: " << MSSV << "\n";
        cout << "Ngày sinh: " << iNgay << "/" << iThang << "/" << iNam << "\n";
        cout << "Điểm Toán Văn Anh: " << fToan << " " << fVan << " " << fAnh << "\n";
    }
    int Tong() {
        return fToan + fVan + fAnh;
    }
};