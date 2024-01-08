#include<bits/stdc++.h>
using namespace std;
class DANHBA {
private:
    string hoten;
    string diachi;
    string sdt;
    string donvi;
    DANHBA* prev;
    DANHBA* next;

public:
    DANHBA() {
        hoten = "";
        diachi = "";
        sdt = "";
        donvi = "";
        prev = nullptr;
        next = nullptr;
    }

    DANHBA(string hoten, string diachi, string sdt, string donvi) {
        this->hoten = hoten;
        this->diachi = diachi;
        this->sdt = sdt;
        this->donvi = donvi;
        prev = nullptr;
        next = nullptr;
    }

    void xuat() {
        cout << "Name: " << hoten << endl;
        cout << "Address: " << diachi << endl;
        cout << "Number phone: " << sdt << endl;
        cout << "Untits: " << donvi << endl;
    }

    string getHoten() {
        return hoten;
    }

    string getSdt() {
        return sdt;
    }
    string getDonvi() {
        return donvi;
    }
    DANHBA* getPrev() {
        return prev;
    }
    DANHBA* getNext() {
        return next;
    }
    void setPrev(DANHBA* prevNode) {
        prev = prevNode;
    }
    void setNext(DANHBA* nextNode) {
        next = nextNode;
    }
};

class QUANLY {
private:
    DANHBA* first;
    DANHBA* last;

public:
    QUANLY() {
        first = nullptr;
        last = nullptr;
    }

    void them(DANHBA* danhba) {
        if (first == nullptr) {
            first = danhba;
            last = danhba;
        }
        else {
            last->setNext(danhba);
            danhba->setPrev(last);
            last = danhba;
        }
    }

    void xuat() {
        DANHBA* p = first;
        while (p != nullptr) {
            p->xuat();
            p = p->getNext();
        }
    }

    DANHBA* timKiem(string hoten) {
        DANHBA* p = first;
        while (p != nullptr) {
            if (p->getHoten() == hoten) {
                return p;
            }
            p = p->getNext();
        }

        return nullptr;
    }

    void xoa(string hoten) {
        DANHBA* p = first;
        DANHBA* q = nullptr;

        while (p != nullptr) {
            if (p->getHoten() == hoten) {
                if (p == first && p == last) {
                    delete p;
                    first = last = nullptr;
                }
                else if (p == first) {
                    first = first->getNext();
                    first->setPrev(nullptr);
                    delete p;
                }
                else if (p == last) {
                    q->setNext(nullptr);
                    last = q;
                    delete p;
                }
                else {
                    q->setNext(p->getNext());
                    p->getNext()->setPrev(q);
                    delete p;
                }
                break;
            }
            q = p;
            p = p->getNext();
        }
    }
};
int main() {
    QUANLY danhba;
    char c;
    while (true) {
        cout << "Enter name:";
        string hoten;
        cin >> hoten;
        cout << "Enter address: ";
        string diachi;
        cin >> diachi;
        cout << "Enter number phone: ";
        string sdt;
        cin >> sdt;
        cout << "Enter units: ";
        string donvi;
        cin >> donvi;
        DANHBA* danhba_moi = new DANHBA(hoten, diachi, sdt, donvi);
        danhba.them(danhba_moi);

        cout << "Continue entering (Y/N)? ";
        cin >> c;
        if (c != 'Y') {
            break;
        }
    }
    danhba.xuat();
    cout << "Enter the full name you want to search for: ";
    string hoten_tim;
    cin >> hoten_tim;
    DANHBA* danhba_tim = danhba.timKiem(hoten_tim);
    if (danhba_tim != nullptr) {
        cout << "The information of DANHBA subject's full name is: " << hoten_tim << ":" << endl;
        danhba_tim->xuat();
    }
    else {
        cout << "The person is not in your contacts." << endl;
    }
    cout << "Enter the full name you want to delete: ";
    string hoten_xoa;
    cin >> hoten_xoa;

    danhba.xoa(hoten_xoa);
    danhba.xuat();

    return 0;
}