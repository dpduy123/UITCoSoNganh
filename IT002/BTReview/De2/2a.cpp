#include <bits/stdc++.h> 

class cNgay {
private:
	int Ngay, Thang, Nam;
public: 
	cNgay() {}
	cNgay(int Ngay, int Thang, int Nam) : Ngay(Ngay), Thang(Thang), Nam(Nam) {}
	int SoSanh(const cNgay& a) {
	    if (Ngay == a.Ngay && Thang == a.Thang && Nam == a.Nam) return 0;
        if ()
    }
};

int main() {
    cNgay ngl; // ngl sé co giå tri ngåy 1 thång 1 näm 1
cNgay ng2(2017, 1, 7); // ng2 sé co giå tri ngåy 7 thång 1 näm 2017
cin>>ngl;
int kq = ng1.SoSanh(ng2);
if(kq = -1)
cout << "Ngay 1 truoc ngay 2" << endl;
else if (kq = o)
cout << "Ngay 1 va ngay 2 la cung 1 ngay" << endl;
else
cout << "Ngay 1 sau ngay 2" << endl;
    return 0;
}