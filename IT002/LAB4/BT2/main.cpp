#include "deluxe.h"
#include "premium.h" 
#include "business.h"

signed main()
{
    Deluxe a(3, 150000, 50000);
    Deluxe b(2, 200000, 100000);
    Premium c(5, 100000);
    Premium d(3, 0);
    Business e(1);
    int dsDoanhThu[5];
    dsDoanhThu[0] = a.DoanhThuPhong();
    dsDoanhThu[1] = b.DoanhThuPhong();
    dsDoanhThu[2] = c.DoanhThuPhong();
    dsDoanhThu[3] = d.DoanhThuPhong();
    dsDoanhThu[4] = e.DoanhThuPhong();
    char room[5] = {'a', 'b', 'c', 'd', 'e'};
    int Max = 0;
    char Room;
    for (int i = 0; i < 5; i++) 
    {
        if (Max < dsDoanhThu[i]) {
            Max = dsDoanhThu[i];
            Room = room[i];
        }
        cout << "Doanh thu cua phong " << room[i] << " là " << dsDoanhThu[i] << "\n";
    }
    cout << "-------------------------------------" << "\n";
    cout << "Phong co doanh thu lon nhat la phong " << Room << "\n";
    cout << "Voi tong doanh thu la " << Max << "\n";
    return 0;
}