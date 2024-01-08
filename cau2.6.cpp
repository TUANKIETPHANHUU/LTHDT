
#include<iostream>
using namespace std;

class dathuc {
    private:
        int *heso;  
        int bac;    
    public:
        dathuc(int n = 0) {
            bac = n;
            heso = new int[n+1];
        }
        dathuc(const dathuc &dt) {
            bac = dt.bac;
            heso = new int[bac+1];
            for(int i = 0; i <= bac; i++) {
                heso[i] = dt.heso[i];
            }
        }
        ~dathuc() {
            delete[] heso;
        }
        void nhap() {
            cout<<"Nhap bac cua da thuc: ";
            cin>>bac;
            heso = new int[bac+1];
            for(int i = 0; i <= bac; i++) {
                cout<<"Nhap he so thu "<<i<<": ";
                cin>>heso[i];
            }
        }
        void xuat() {
            for(int i = bac; i >= 0; i--) {
                if(heso[i]) {
                    cout<<heso[i]<<"x^"<<i;
                    if(i) cout<<" + ";
                }
            }
            cout<<endl;
        }
        int operator[](int i) {
            if(i >= 0 && i <= bac) {
                return heso[i];
            }
            return 0;
        }
        dathuc operator+(const dathuc &dt) {
            int max_bac = (bac < dt.bac) ? dt.bac : bac;
            dathuc kq(max_bac);
            for(int i = 0; i <= max_bac; i++) {
                kq.heso[i] = (*this)[i] + dt[i];
            }
            return kq;
        }
        
};

int main() {
    dathuc a, b;
    a.nhap();
    b.nhap();
    dathuc c = a+b;
    a.xuat();
    b.xuat();
    c.xuat();
    cout<<c[2]<<endl;
    return 0;
}