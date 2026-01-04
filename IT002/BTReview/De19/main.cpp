#include "vatchu.h"
#include "hiv.h" 
#include "ebola.h"
#include "covid19.h"

using namespace std;

signed main() {
	srand(time(NULL));
	int n;
	cin >> n;
	vector <Vatchu*> vatchu;
	for (int i = 0; i < n; i++) {
		vatchu.push_back(new Vatchu("BenhNhan" + to_string(i), 0));
	}

	for (int i = 0; i < n; i++) {
		vatchu[i]->InThongTinVatChu();
	}

	cout << "-----------------------------" << endl;
	cout << "Nhiem benh lan 2\n";
	vector <Vatchu*> vatchu2;
	for (int i = 0; i < n; i++) {
		vatchu2.push_back(new Vatchu("BenhNhan" + to_string(i), 1));
	}
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		vector <string> Symptom = vatchu2[i]->TrieuChung();
		a += (Symptom[0] == "Trieu chung nang" || Symptom[1] == "Trieu chung nang" || Symptom[2] == "Trieu chung nang") ? 1 : 0;
		b += (vatchu2[i]->TuVong()) ? 1 : 0;
	}
	cout << "Sau khi tiem Vacxin!\n";
	cout << "Co " << a << " vat chu co trieu chung nang\n";
	cout << "Co " << b << " vat chu tu vong\n"; 

	cout << "\n";
}