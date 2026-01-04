#include <bits/stdc++.h> 

using namespace std;

class SoPhuc{
private:
	double a, b;
public: 
	SoPhuc() {a = 0; b = 0;}
	SoPhuc(double _a, double _b) {
		a = _a;
		b = _b;
	}
	SoPhuc(const SoPhuc &x) {a = x.a; b = x.b;}

	SoPhuc operator+(const SoPhuc &x) {
		return SoPhuc(a + x.a, b + x.b);
	}

	SoPhuc operator-(const SoPhuc &x) {
		return SoPhuc(a - x.a, b - x.b);
	}

	SoPhuc operator* (const SoPhuc &x) {
		return SoPhuc(a * b - x.a * x.b, a * x.b + x.a * b);
	}

	SoPhuc operator/ (const SoPhuc &x) {
		return SoPhuc((a * b + x.a * x.b) / (b * b + x.b * x.b), (b * x.a - a * x.b) / (b * b + x.b * x.b));
	}
	SoPhuc operator== (const SoPhuc &x) {
		return a == x.a && b == x.b;
	}
	
};

signed main()
{

	return 0;
}