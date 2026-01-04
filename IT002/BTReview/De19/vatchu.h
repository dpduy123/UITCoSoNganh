#ifndef VATCHU_H
#define VATCHU_H 

#include <bits/stdc++.h> 
#include "hiv.h"
#include "ebola.h"
#include "covid19.h"

using namespace std;

class Vatchu {
private:
	Virus* virus[3];
	string ID;
	double DeathProb;
	bool Vacxin;
	string ImmuneAbility;
	bool Death;
	vector<string> Symptom;
	string GenerateImmuneAbility() {
        int r = rand() % 3;
        if (r == 0) return "Cao";
        if (r == 1) return "Trung Binh";
        return "Thap";
    }
public:
	Vatchu(string ID, bool Vacxin);
	~Vatchu();
	void InThongTinVatChu();
	vector<string> TrieuChung();
	bool TuVong();
};

#endif