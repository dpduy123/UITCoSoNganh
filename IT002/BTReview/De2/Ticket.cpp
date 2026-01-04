#include <bits/stdc++.h> 

using namespace std;

class Ve{
protected: 
    string MaVe, HoTen;
    int NamSinh, SoTroChoi;
public: 
    Ve() : MaVe(NULL), HoTen(NULL), NamSinh(0), SoTroChoi(0) {}
    Ve(string MaVe, string HoTen, int NamSinh, int SoTroChoi) : MaVe(MaVe), HoTen(HoTen), NamSinh(NamSinh), SoTroChoi(SoTroChoi) {}
    virtual ~Ve() {}
    virtual int GiaVe() {return 0;}
};

class VeTronGoi : public Ve{
public: 
    VeTronGoi(string MaVe, string HoTen, int NamSinh, int SoTroChoi) : Ve(MaVe, HoTen, NamSinh, SoTroChoi) {}
    int GiaVe()  override{
        return 200000;
    }
};

class VeTungPhan : public Ve{
public: 
    VeTungPhan(string MaVe, string HoTen, int NamSinh, int SoTroChoi) : Ve(MaVe, HoTen, NamSinh, SoTroChoi) {}
    int GiaVe()  override{
        return 70000 + 20000 * SoTroChoi;
    }
};

int n;
Ve* ds[1001];
int main()
{   
    cout << "Nhap so luong ve ";
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap thong tin ve:\n";
        string Ma, Ten;
        int Nam, Games, type;
        cout << "Nhap ma ve: " << "\n"; cin >> Ma;
        cout << "Nhap ho va ten: " << "\n"; cin >> Ten;
        cout << "Nhap nam sinh: " << "\n"; cin >> Nam;
        cout << "Nhap so tro choi da choi: " << "\n"; cin >> Games;
        cout << "Nhap loai ve: {0: ve tung phan, 1: ve tron goi}" << "\n"; cin >> type;
        if (type == 1) ds[i] = new VeTronGoi(Ma, Ten, Nam, Games);
        else {ds[i] = new VeTungPhan(Ma, Ten, Nam, Games); cnt++;}
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) 
        sum += ds[i]->GiaVe();
    cout << "Tong tien ve ma cong vien thu duoc la " << sum << "VND \n";

    cout << "Co " << cnt << " ve da ban la ve tung phan\n"; 
    return 0;
}