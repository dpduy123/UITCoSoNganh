#include <bits/stdc++.h> 

#define int long long 
#define pii pair <int,int> 
#define st first 
#define nd second 
#define vi vector <int> 
#define vpii vector <pii> 
#define pb push_back 
#define lb lower_bound 
#define ub upper_bound 
#define FILE ""
#define trii pair <pii, int> 
using namespace std;

const int oo = 1e18;
const int base = 311;
const int mod = 998244353;
const int N = 333;

struct Phanso{
	int tu, mau;
	bool operator> (const Phanso &a) {
		return tu * a.mau > mau * a.tu;
	}
};

int gcd(int a, int b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
Phanso Rutgon(Phanso a) 
{
	Phanso c = a;
	c.tu = a.tu / gcd(a.tu, a.mau);
	c.mau = a.mau / gcd(a.tu, a.mau);
	if (c.mau < 0) {
		c.tu *= -1;
		c.mau *= -1;
	}
	return c;

}
Phanso Cong(Phanso a, Phanso b) 
{
	Phanso c;
	c.mau = a.mau * b.mau;
	c.tu = a.mau * b.tu + b.mau * a.tu;
	return Rutgon(c);
}
Phanso Tru(Phanso a, Phanso b) 
{
	Phanso c;
	c.mau = a.mau * b.mau;
	c.tu = -a.mau * b.tu + b.mau * a.tu;
	return Rutgon(c);
}
Phanso Nhan(Phanso a, Phanso b) 
{
	Phanso c;
	c.mau = a.mau * b.mau;
	c.tu = a.tu * b.tu;
	return Rutgon(c);
}
Phanso Chia(Phanso a, Phanso b) 
{
	Phanso c;
	c.mau = a.mau * b.tu;
	c.tu = b.mau * a.tu;
	return Rutgon(c);
}
int n;
string frac;
Phanso maxx, sum, cur;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	maxx.tu = -oo;
	maxx.mau = 1;
	sum.tu = 0;
	sum.mau = 1;
	while (true) 
	{
		cout << "Nhap phan so (hoac nhap exit de ket thuc)";
		cin >> frac;
		if (frac == "exit") break;
		int tut, maut;
		char slash;
		stringstream ss(frac);
		if (ss >> tut >> slash >> maut) {
			cur.tu = tut;
			cur.mau = maut;
			if (cur > maxx) maxx = cur;
			sum = Cong(sum, cur);
		} else {
			cout << "Vui long nhap phan so hop le\n";
		}

	}
	cout << "Tong cua day phan so tren la: " << sum.tu << '/' << sum.mau << "\n";
	cout << "Phan so lon nhat la: " << maxx.tu << '/' << maxx.mau << "\n";
	return 0;
}
/*
From Benq: 
	int overflow?
	array bounds?
	Special Cases (n = 1?)
	Do something instead of nothing and stay organized 
	WRITE STUFF DOWN 
	DON'T GET STUCK ON ONE APPROACH 
*/
