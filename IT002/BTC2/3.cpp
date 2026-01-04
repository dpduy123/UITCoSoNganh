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
#define matrix vector <vi>
using namespace std;

const int oo = 1e18;
const int base = 311;
const int mod = 998244353;
const int N = 333;

int gcd(int a, int b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
matrix operator+(const matrix &a, const matrix &b) {
	matrix c;
	c.resize(a.size());
	for (int i = 0; i < a.size(); i++) 
	{
		c[i].resize(a[i].size());
		for (int j = 0; j < a[i].size(); j++) 
			c[i][j] = a[i][j] + b[i][j];
	}
	return c;
} 
matrix operator-(const matrix &a, const matrix &b) {
	matrix c;
	c.resize(a.size());
	for (int i = 0; i < a.size(); i++) 
	{
		c[i].resize(a[i].size());
		for (int j = 0; j < a[i].size(); j++) 
			c[i][j] = a[i][j] - b[i][j];
	}
	return c;
} 
matrix operator*(const matrix &a, const matrix &b) 
{
	matrix c;
	c.resize(a.size());
	for (int i = 0; i < a.size(); i++) 
	{
		c[i].resize(a[i].size());
		for (int j = 0; j < a[i].size(); j++) 
			for (int k = 0; k < b.size(); k++) 
				c[i][j] += a[i][k] * b[k][j];
	}
	return c;
}
void PrintMatrix(matrix a) 
{
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) 
			cout << a[i][j] << " "; cout << "\n";
	}
}
int n, m, x;
matrix a, b;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout << "Nhap so hang va cot cua ma tran" << "\n";
	cin >> n >> m;
	a.resize(n); b.resize(n);
	cout << "Nhap ma tran 1: " << "\n";
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> x; a[i].pb(x);
		}
	cout << "Nhap ma tran 2: " << "\n";
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> x; b[i].pb(x);
		}
	matrix Tong = a + b, Hieu = a - b, Tich = a * b;
	cout << "Tong 2 ma tran la: \n";PrintMatrix(Tong); cout << "\n";
	cout << "Hieu 2 ma tran la: \n";PrintMatrix(Hieu); cout << "\n";
	cout << "Tich 2 ma tran la: \n";PrintMatrix(Tich); cout << "\n";
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
