#include "bo.h"
#include "cuu.h" 
#include "de.h"
#include "nongtrai.h"

signed main()
{
    srand(time(NULL));
    int soBo, soDe, soCuu;
    cout << "Nhap so luong bo: "; cin >> soBo;
    cout << "Nhap so luong cuu: "; cin >> soCuu;
    cout << "Nhap so luong de: "; cin >> soDe;
    NongTrai nt;
    nt.themGiaSuc(new Bo(soBo));
    nt.themGiaSuc(new Cuu(soCuu));
    nt.themGiaSuc(new De(soDe));

    cout << "Tieng keu cua gia suc khi doi: " << "\n";
    nt.tiengKeu();

    cout << "Thong ke sau mot lua sinh va cho sua: " << "\n";
    nt.thongKe();
    return 0;
}