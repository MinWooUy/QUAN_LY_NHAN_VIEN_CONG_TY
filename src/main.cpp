#include <iostream>
#include "HeThongQuanLy.h"
using namespace std;

void menu(HeThongQuanLy heThong)
{
    int luaChon;

    do {
        cout << "\n========== MENU HE THONG ==========\n";
        cout << "1. Them phong ban\n";
        cout << "2. Them nhan vien\n";
        cout << "3. Hien thi danh sach phong ban\n";
        cout << "4. Hien thi danh sach nhan vien\n";
        cout << "5. Hien thi thong tin tong quan\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
            case 1: {
                PhongBan pb;
                cout << "\nNhap thong tin phong ban:\n";
                pb.nhapThongTin();
                heThong.themPhongBan(pb);
                cout << "Da them phong ban thanh cong.\n";
                break;
            }

            case 2: {
                NhanVien nv;
                cout << "\nNhap thong tin nhan vien:\n";
                nv.nhapThongTin();
                heThong.themNhanVien(nv);
                cout << "Da them nhan vien thanh cong.\n";
                break;
            }

            case 3:
                heThong.hienThiDanhSachPhongBan();
                break;

            case 4:
                heThong.hienThiDanhSachNhanVien();
                break;

            case 5:
                heThong.hienThiThongTinTongQuan();
                break;

            case 0:
                cout << "Dang thoat chuong trinh...\n";
                break;

            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }

    } while (luaChon != 0);
}

int main() {
    HeThongQuanLy heThong;

    heThong.loadNhanVienTuFile("nhan_vien_test.txt");

    cout << "\nThong tin tong quan he thong:\n";
    heThong.hienThiThongTinTongQuan();

    cout << "\nDanh sach nhan vien:\n";
    heThong.hienThiDanhSachNhanVien();

    return 0;
}