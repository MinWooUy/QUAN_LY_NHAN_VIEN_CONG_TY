#include <iostream>
#include <vector>
#include "HeThongQuanLy.h"
using namespace std;

int main() {
    HeThongQuanLy heThong;

    ChamCong cc1("CC001", "NV001", "20/04/2026", "08:00", "17:00", "Dung gio", 8.0, "Khong co ghi chu");
    ChamCong cc2("CC002", "NV002", "20/04/2026", "08:15", "17:30", "Di tre", 8.25, "Den muon 15 phut");
    ChamCong cc3("CC001", "NV003", "21/04/2026", "08:00", "17:00", "Dung gio", 8.0, "Bi trung ma");

    heThong.themChamCong(cc1);
    heThong.themChamCong(cc2);
    heThong.themChamCong(cc3);

    cout << "\n===== DANH SACH BAN DAU =====\n";
    heThong.hienThiDanhSachChamCong();

    cout << "\n===== HIEN THI 1 BAN GHI THEO MA =====\n";
    heThong.hienThiChamCongTheoMa("CC002");

    cout << "\n===== CAP NHAT THEO KIEU GUI =====\n";
    bool capNhatOK = heThong.capNhatChamCongTheoMa(
        "CC002",
        "NV002",
        "21/04/2026",
        "08:05",
        "17:45",
        "Gan dung gio",
        8.5,
        "Da cap nhat"
    );

    if (capNhatOK) {
        cout << "Cap nhat cham cong CC002 thanh cong.\n";
    } else {
        cout << "Khong tim thay cham cong CC002 de cap nhat.\n";
    }

    heThong.hienThiChamCongTheoMa("CC002");

    cout << "\n===== XOA THEO MA =====\n";
    bool xoaOK = heThong.xoaChamCongTheoMa("CC001");

    if (xoaOK) {
        cout << "Xoa cham cong CC001 thanh cong.\n";
    } else {
        cout << "Khong tim thay cham cong CC001 de xoa.\n";
    }

    cout << "\n===== DANH SACH SAU CUNG =====\n";
    heThong.hienThiDanhSachChamCong();

    cout << "\n===== TEST LAY DANH SACH =====\n";
    const vector<ChamCong>& ds = heThong.layDanhSachChamCong();
    cout << "So luong cham cong hien tai: " << ds.size() << endl;

    return 0;
}