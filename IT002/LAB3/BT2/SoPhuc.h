#include <bits/stdc++.h> 

using namespace std;

class SoPhuc{
private:
    int dThuc, dAo;
public:
    SoPhuc();
    SoPhuc(int thuc, int ao);
    SoPhuc operator+(const SoPhuc &a);
    SoPhuc operator-(const SoPhuc &a);
    SoPhuc operator*(const SoPhuc &a);
    SoPhuc operator/(const SoPhuc &a);
    bool operator==(const SoPhuc &a);
    bool operator!=(const SoPhuc &a);
    friend istream& operator >> (istream& in, SoPhuc &sp);
    friend ostream& operator << (ostream& out, const SoPhuc &sp);
};