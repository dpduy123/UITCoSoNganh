#ifndef COVID19_H
#define COVID19_H

#include "virus.h"

class Covid19 : public Virus {
public:
	Covid19(string ImmuneAbility, bool Vacxin) : Virus(ImmuneAbility,Vacxin) {
	this->AvgProb = 0.05;
	if (this->Symptom == "Trieu chung nang") {
		this->SymptomInfo = "Sot cao, ho khan, kho tho va dau dau du doi";
	}
	else if (this->Symptom == "Trieu chung nhe") {
		this->SymptomInfo = "Sot, ho, mat vi giac";
	}
	else {
		this->SymptomInfo = "Khong trieu chung";
	}
}
};

#endif