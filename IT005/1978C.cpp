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
const int N = 1e6 + 6;

int n, a[N], k;
int x, y;
void input()
{
	cin >> n >> k;
}

void solve()
{
	if (k == 0) 
	{
		cout << "Yes" << "\n";
		for (int i = 1; i <= n; i++) 
			cout << i << " "; cout << "\n";
		return;
	}
	if (k % 2 == 1) {
		cout << "No" << "\n";
		return;
	}
	int sum = 0;
	int m = n - 1;
	while (m > 0) 
	{
		sum += m * 2;
		m -= 2;
	}
	if (k > sum) {cout << "No" << "\n"; return;}
	for (int i = 1; i <= n; i++) 
	{
		a[i] = i;
	}
	

	cout << "Yes" << "\n";
	for (int i = 1; i <= n; i++) 
		cout << a[i] << " "; cout << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) 
	{
		input();
		solve();
	}
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
