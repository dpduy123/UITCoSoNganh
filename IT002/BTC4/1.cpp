#include <bits/stdc++.h> 

using namespace std;

class cArray{
private:
	int n;
	vector <int> a;
public: 

	cArray() {

	}
	void Nhap()
	{
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i++) 
			cin >> a[i];
	}

	void Xuat() {
		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
	}

	void CreateRandom() {
		for (int i = 0; i < n; i++) 
			a[i] = rand() % 1000000;
	}

	int SoLanXuatHien(int x) {
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			cnt += (a[i] == x);
		return cnt;
	}

	bool TangDan() {
		for (int i = 1; i < n; i++) 
		{
			if (a[i] < a[i - 1]) return false;
		}
		return true;
	}

	int MinLe() {
		int res = 100000000;
		for (int i = 0; i < n; i++) 
		{
			if (a[i] % 2 == 1) res = min(res, a[i]);
		}
		if (res == 100000000) res = -1;
		return res;
	}

	void SapXep() {
		sort(a.begin(), a.end());
	}
};

signed main()
{
	cArray c;
	c.Nhap();
	c.Xuat();
	cout << "\n";
	c.CreateRandom();
	c.Xuat();
	cout << "\n";
	cout << c.SoLanXuatHien(5) << "\n";
	if (c.TangDan()) {cout << "Mảng tăng dần" << "\n";} else {cout << "Mảng không tăng dần" << "\n";}
	cout << c.MinLe() << "\n";

	c.SapXep();
	c.Xuat();
	return 0;
}