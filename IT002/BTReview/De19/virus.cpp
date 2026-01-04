#include "virus.h"
#include "util.h"
Virus::Virus(string immuneAbility, bool vacxin) 
    : ImmuneAbility(immuneAbility), Vacxin(vacxin) {
    if (immuneAbility == "Cao") {
        SetMienDich(1);
    } else if (immuneAbility == "Trung Binh") {
        SetMienDich(2);
    } else {
        SetMienDich(3);
    }
}

void Virus::SetMienDich(int level) {
    double r1 = RandomDouble();
    double probabilityTable[3][4];

    // Chọn bảng xác suất dựa trên trạng thái vacxin
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            probabilityTable[i][j] = Vacxin ? bang2[i][j] : bang1[i][j];
        }
    }

    // Xác định triệu chứng và xác suất tử vong dựa trên bảng xác suất
    if (r1 <= probabilityTable[level - 1][0]) {
        Symptom = "Khong trieu chung";
        DeathProb = probabilityTable[level - 1][3];
    } else if (r1 <= probabilityTable[level - 1][1]) {
        Symptom = "Trieu chung nhe";
        DeathProb = probabilityTable[level - 1][3];
    } else {
        Symptom = "Trieu chung nang";
        DeathProb = probabilityTable[level - 1][3];
    }
}

string Virus::TrieuChung() {
    return Symptom;
}

void Virus::InThongTin() {
    if (Symptom != "Khong trieu chung") {
        cout << SymptomInfo << endl;
    }
}

double Virus::TinhXacSuatTuVong() {
    return DeathProb * AvgProb;
}
