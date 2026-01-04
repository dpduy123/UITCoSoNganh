#include "vatchu.h"
#include "virus.h"
#include "util.h"

Vatchu::Vatchu(string ID, bool Vacxin) {
	this->DeathProb = 0;
	this->ID = ID;
	this->Vacxin = Vacxin;
	ImmuneAbility = GenerateImmuneAbility();
	this->virus[0]= new Covid19(this->ImmuneAbility, this->Vacxin);
	this->virus[1]= new HIV(this->ImmuneAbility, this->Vacxin);
	this->virus[2]= new Ebola(this->ImmuneAbility, this->Vacxin);
	for (int i = 0; i < 3; i++) {
		this->Symptom.push_back(this->virus[i]->TrieuChung());
	}

	for (int i = 0; i < 3; i++){
		double r2 = RandomDouble();
		double xacsuat = this->virus[i]->TinhXacSuatTuVong();
		if (r2 <= xacsuat) {
			this->Death = true;
			break;
		}else {
			this->Death = false;
		}
	}
}

void Vatchu::InThongTinVatChu() {
	cout << "------------Thong tin------------" << endl;
	cout << "Ma so benh nhan: " << this->ID << endl;
	cout << "Kha nang mien dich: " << this->ImmuneAbility << endl;
	cout << "------------Trieu chung------------" << endl;
	for (int i = 0; i < 3; i++) {
		this->virus[i]->InThongTin();
	}
	if (this->Death) {
		cout << "Tu vong" << endl;
	}
	else {
		cout << "Khong tu vong" << endl;
	}
	cout << "---------------------------------" << endl;
}

vector<string> Vatchu::TrieuChung() {
	return this->Symptom;
}

bool Vatchu::TuVong() {
	return this->Death;
}

Vatchu::~Vatchu() {
	for (int i = 0; i < 3; i++) {
		delete this->virus[i];
	}
}