#include <iostream>
#include "HeThongQuanLy.h"
using namespace std;

int main() {
    HeThongQuanLy heThong;
    heThong.loadNhanVienTuFile("../data/nhan_vien_test.txt");

    NhanVien* nv = heThong.layNhanVienTheoMa("NV004");

    if (nv != nullptr) {
        cout << "Tim thay nhan vien:\n";
        cout << nv->getHoTen() << endl;
        cout << nv->getEmail() << endl;

        nv->setEmail("new_email@company.com");

        cout << "\nSau khi cap nhat email:\n";
        nv->hienThiThongTin();
    } else {
        cout << "Khong tim thay nhan vien.\n";
    }

    return 0;
}