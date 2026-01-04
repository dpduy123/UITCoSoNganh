#ifndef VIRUS_H
#define VIRUS_H

#include <bits/stdc++.h>

using namespace std;

class Virus {
protected:
	string Symptom;
	double DeathProb;
	double AvgProb;
	string ImmuneAbility;
	string SymptomInfo;
	bool Vacxin;
public:
	Virus(string ImmuneAbility, bool Vacxin);
	void SetMienDich(int i);
	void InThongTin();
	double TinhXacSuatTuVong();
	string TrieuChung();
};

#endif 