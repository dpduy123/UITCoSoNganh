#include <iostream>
#include <cmath>

using namespace std;
class SoPhuc{
   private:
    double thuc, ao;
   public:
    double getthuc(){
        return thuc;
    }
    double getao(){
        return ao;
    }
    void setthuc(double phanthuc){
        phanthuc = thuc;
    }
    void setao(double phanao){
        phanao = ao;
    }
    void Input(){
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }
    void Output(){
        cout << thuc;
        if(ao >= 0) cout << "+" << ao << "i\n";
        else cout << ao <<"i\n";
    }
    void Sum(SoPhuc b){
        thuc = thuc + b.thuc;
        ao = ao + b.ao;
        Output();
    }
};
int main()
{
    SoPhuc a,b;
    cout << "Nhap so phuc dau tien: \n";
    a.Input();
    cout << "Nhap so phuc thu hai: \n";
    b.Input();
    cout << "n1= ";
    a.Output();
    cout << "n2= ";
    b.Output();
    cout <<"Tong hai so phuc= ";
    a.Sum(b);
    return 0;
}
