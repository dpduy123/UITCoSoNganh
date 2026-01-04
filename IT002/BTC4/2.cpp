#include <bits/stdc++.h> 

using namespace std;

int prime(int n) 
{
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) 
		if (n % i == 0) return 0;
	return 1;
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
	int getTu() {return Tu;}
	int getMau() {return Mau;}
	void Nhap() {
		cin >> Tu >> Mau;
	}

	void Xuat() {
		cout << Tu << "/" << Mau;
	}

	void Rand()
	{
		Tu = rand() % 1000000;
		Mau = rand() % 1000000;
	}

	bool cmp(PhanSo a) {
		return Tu * a.Mau < Mau * a.Tu;
	}
};
class arrPhanSo{
private:
	int n;
	vector <PhanSo> a;
public:
	arrPhanSo() {};

	void Nhap() {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i++) 
			a[i].Nhap();
	}

	void Xuat()
	{
		for (int i = 0; i < n; i++) 
			a[i].Xuat();
	}

	void Random() {
		for (int i = 0; i < n; i++) 
			a[i].Rand();
	}

	PhanSo findMax() {
		PhanSo res;
		for (int i = 0; i < n; i++) 
		{
			if (res.cmp(a[i])) res = a[i];
		}
		return res;
	}

	int tunt()
	{
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			if (prime(a[i].getTu())) cnt++;
		return cnt; 
	}

	void SapXep() {
		
	}
};

signed main()
{
	
	return 0;
}