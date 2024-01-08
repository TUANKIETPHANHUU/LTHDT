
/*-----------------------------
Ten: Lap Trinh Huong Doi Tuong
Ma hoc phan: TIN3073
Time: 15h20
Date: 25/10/2023
Author: 22T1020183
-------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
class Person {
  protected:
    string Hodem, ten;
    int age;
  public:
    Person() = default;
    Person(string Hodem, string ten, int age) : Hodem(Hodem),ten(ten), age(age) {}
    void nhap(){
        cout << "Nhap Ho Ten:";
        getline(cin,Hodem);
        cout << "Nhap ten:";
        cin>>ten;
        cout << "Nhap age:";
        cin>>age;
        cin.ignore();
    }
    void xuat() const{
        cout << Hodem << " " << ten << ", " << age << " tuoi." << endl;
    }
    bool operator > (const Person& other) const{
        if (ten == other.ten) {
            return Hodem > other.Hodem;
        }
        return ten > other.ten;
    }
};

class Officer : public Person {
    protected:
        int maSo;
        double hesoluong, baohiem;
    public:
        Officer() = default;
        Officer(string Hodem, string ten, int age, int maSo, double hesoluong, double baohiem ):
        Person(Hodem,ten,age),maSo(maSo),hesoluong(hesoluong),baohiem(baohiem){}
        void nhap(){
            Person::nhap();
            cout << "Nhap ma so:";
            cin>>maSo;
            cout << "Nhap he so luong:";
            cin>>hesoluong;
            cout<<"Nhap so tien bao hiem:";
            cin>>baohiem;
            cin.ignore();
        }
        void xuat() const{
            Person::xuat();
            double luong = hesoluong * 1350000;
            cout << "Ma so:" << maSo << endl;
            cout << "Tien luong:" << luong << endl;
            cout << "Tien bao hiem:" << baohiem << endl;
            cout << "Tien thuc nhan:" << luong - baohiem << endl;
        }
        bool operator > (const Officer& other) const {
            return Person::operator>(other);
        }
        double gethesoluong() const {
            return hesoluong;
        }
        double getbaohiem() const {
            return baohiem;
        }
};
int main(){
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    cin.ignore();
    vector<Officer> officers(n);
    for (int i=0; i<n; i++){
        cout << "Nhap thong tin can bo thu " << i+1 << ": " << endl;
        officers[i].nhap();
    }
    sort(officers.begin(),officers.end(),greater<Officer>());
    cout << "Danh sach can bo sap xep theo thu tu tang dan cua ten va ho dem:" << endl;
    for (int i=0; i<n; i++){
        officers[i].xuat();
        cout << endl;
    }
    double maxThucNhan = 0.0;
    Officer maxOfficer;
    for (int i=0; i<n; i++){
        double luong = officers[i].gethesoluong() * 1350000;
        double thucnhan = luong - officers[i].getbaohiem();
        if(thucnhan > maxThucNhan){
            maxThucNhan = thucnhan;
            maxOfficer = officers[i];
        }
    }
    cout << "Nhan vien co tien thuc nhan cao nhat la: " << endl;
    maxOfficer.xuat();
    cout << endl;
    return 0;
}