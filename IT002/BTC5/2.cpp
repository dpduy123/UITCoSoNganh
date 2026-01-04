#include <bits/stdc++.h> 
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
class PhanSo
{
private:
	int Tu, Mau;
public:
	PhanSo() : Tu(0), Mau(1) {}
	PhanSo(int _Tu, int _Mau) {
		Tu = _Tu;
		Mau = _Mau;
	}
	PhanSo (const PhanSo &n) {
		Tu = n.Tu;
		Mau = n.Mau;
	}
	int getTu() {return Tu;}
	int getMau() {return Mau;}
	void Nhap() {
		cin >> Tu >> Mau;
	}

	void Xuat() {
		cout << Tu << "/" << Mau;
	}

	bool operator > (PhanSo a) {
		return Tu * a.Mau > Mau * a.Tu;
	}
	PhanSo RutGon() {
		return PhanSo(Tu / gcd(Tu, Mau), Mau / gcd(Tu, Mau));
	}
	PhanSo operator+(const PhanSo &x) {
		return PhanSo(Tu * x.Mau + Mau * x.Tu, Mau * x.Mau).RutGon();
	}
	PhanSo operator-(const PhanSo &x) {
		return PhanSo(Tu * x.Mau - Mau * x.Tu, Mau * x.Mau).RutGon();
	}
};

class DSPhanSo{
private:
	int n; 
	vector <PhanSo> a;
public:
	DSPhanSo() {};

	void Nhap()
	{
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i++) 
		{
			a[i].Nhap();
		}
	}
	PhanSo Tong()
	{
		PhanSo res;
		for (int i = 0; i < n; i++) 
			res = res + a[i];
		return res;
	}
	PhanSo Max()
	{
		PhanSo res;
		for (int i = 0; i < n; i++) 
			if (a[i] > res) res = a[i];
		return res;		
	}

};
signed main() 
{
	DSPhanSo d;
	d.Nhap();
	cout << "Tong cac phan so la "; d.Tong().Xuat(); cout << "\n";
	cout << "Phan so lon nhat la "; d.Max().Xuat(); 
	return 0;
}