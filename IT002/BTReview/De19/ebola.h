#ifndef EBOLA_H
#define EBOLA_H

#include "virus.h"
class Ebola : public Virus {
public:
	Ebola(string ImmuneAbility, bool Vacxin) : Virus(ImmuneAbility,Vacxin) {
	this->AvgProb = 0.5;
	if (this->Symptom == "Trieu chung nang") {
		this->SymptomInfo = "Non mua, tieu chay va xuat huyet ca ngoai lan ben trong";
	}
	else if (this->Symptom == "Trieu chung nhe") {
		this->SymptomInfo = "Sot, dau hong, dau co va dau dau";
	}
	else {
		this->SymptomInfo = "Khong trieu chung";
	}
	}
};

#endif