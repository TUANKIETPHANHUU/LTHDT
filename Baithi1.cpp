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
class Printer {
public:
    string maSo;
    string tenMayIn;
    int soLuong;
    string ngayNhap;
    void nhapDuLieu(string maSo, string tenMayIn, int soLuong, string ngayNhap) {
        this->maSo = maSo;
        this->tenMayIn = tenMayIn;
        this->soLuong = soLuong;
        this->ngayNhap = ngayNhap;
    }
    void hienThiThongTin() const {
        cout << "Ma so: " << maSo << endl;
        cout << "Ten may in: " << tenMayIn << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Ngay nhap: " << ngayNhap << endl;
    }
    int getSoLuong() const {
        return soLuong;
    }
    bool operator>(const Printer& other) const {
        return ngayNhap > other.ngayNhap;
    }
};
class Laser : public Printer {
public:
    string doPhanGiai;
    void nhapDuLieu(string maSo, string tenMayIn, int soLuong, string ngayNhap, string doPhanGiai) {
        Printer::nhapDuLieu(maSo, tenMayIn, soLuong, ngayNhap);
        this->doPhanGiai = doPhanGiai;
    }
    void hienThiThongTin() const {
        Printer::hienThiThongTin();
        cout << "Do phan giai: " << doPhanGiai << endl;
    }
};
signed main() {
    system("color 2");
    vector<Laser> danhSachMayIn;
    int soLuongMayIn = 0;
    while (true) {
        Laser mayIn;
        string maSo, tenMayIn, ngayNhap, doPhanGiai;
        int soLuong;
        cout << "Nhap thong tin cho may in thu " << (soLuongMayIn+1) << ":" << endl;
        cout << "Ma so: ";
        cin >> maSo;
        cout << "Ten may in: ";
        cin.ignore();
        getline(cin, tenMayIn);
        cout << "So luong: ";
        cin >> soLuong;
        cout << "Ngay nhap (dd/mm/yyyy): ";
        cin.ignore();
        getline(cin, ngayNhap);
        cout << "Do phan giai: ";
        getline(cin, doPhanGiai);
        mayIn.nhapDuLieu(maSo, tenMayIn, soLuong, ngayNhap, doPhanGiai);
        danhSachMayIn.push_back(mayIn);
        soLuongMayIn++;
        char tiepTuc;
        cout << "Tiep tuc nhap  (y/n)? ";
        cin >> tiepTuc;
        if (tiepTuc != 'y' && tiepTuc != 'Y') {
            break;
        }
    }
    // Sap xep danh sach ngay nhap
    sort(danhSachMayIn.begin(), danhSachMayIn.end(), greater<Laser>());

    // Hien thi danh sach sap xep
    cout << "Danh sach may in da sap xep trong ngay nhap:" << endl;
    for (const Laser& mayIn : danhSachMayIn) {
        mayIn.hienThiThongTin();
    }
    // Hien thi may in co do phan giai la "600x600 dpi"
    cout << "May in co do phan giai  600x600 dpi:" << endl;
    for (const Laser& mayIn : danhSachMayIn) {
        if (mayIn.doPhanGiai == "600x600 dpi") {
            mayIn.hienThiThongTin();
        }
    }
    // Tim va hien thi may in co so luong lon nhat
    int maxSoLuong = -1;
    for (const Laser& mayIn : danhSachMayIn) {
        maxSoLuong = max(maxSoLuong, mayIn.getSoLuong());
    }
    cout << "May in co so luong lon nhat:" << endl;
    for (const Laser& mayIn : danhSachMayIn) {
        if (mayIn.getSoLuong() == maxSoLuong) {
            mayIn.hienThiThongTin();
        }
    } 
    cerr << "\nTime run: " << 1000*clock()/CLOCKS_PER_SEC << "ms";
    return 0;
}

