#include <iostream>
#include <string>
#include <limits>
#include "HeThongQuanLy.h"

using namespace std;

int nhapLuaChon() {
    int x;
    cout << "Nhap lua chon: ";
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Vui long nhap so nguyen hop le: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

void tamDung() {
    cout << "\nNhan Enter de tiep tuc...";
    cin.get();
}

void menuNhanVien(HeThongQuanLy& heThong) {
    int chon;
    do {
        cout << "\n================ OBJECT NHANVIEN ================\n";
        cout << "1. Them nhan vien\n";
        cout << "2. Hien thi danh sach nhan vien\n";
        cout << "3. Hien thi nhan vien theo ma\n";
        cout << "4. Sua nhan vien theo ma (console)\n";
        cout << "5. Xoa nhan vien theo ma\n";
        cout << "6. Load nhan vien tu file test\n";
        cout << "0. Quay lai\n";

        chon = nhapLuaChon();

        switch (chon) {
            case 1: {
                NhanVien nv;
                nv.nhapThongTin();
                heThong.themNhanVien(nv);
                break;
            }
            case 2:
                heThong.hienThiDanhSachNhanVien();
                break;
            case 3: {
                string ma;
                cout << "Nhap ma nhan vien: ";
                getline(cin, ma);
                heThong.hienThiNhanVienTheoMa(ma);
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma nhan vien can sua: ";
                getline(cin, ma);
                if (heThong.suaNhanVienTheoMa(ma)) {
                    cout << "Sua nhan vien thanh cong.\n";
                } else {
                    cout << "Khong tim thay nhan vien.\n";
                }
                break;
            }
            case 5: {
                string ma;
                cout << "Nhap ma nhan vien can xoa: ";
                getline(cin, ma);
                if (heThong.xoaNhanVienTheoMa(ma)) {
                    cout << "Xoa nhan vien thanh cong.\n";
                } else {
                    cout << "Khong tim thay nhan vien.\n";
                }
                break;
            }
            case 6:
                heThong.loadNhanVienTuFile("../data/nhan_vien_test.txt");
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }

        if (chon != 0) tamDung();

    } while (chon != 0);
}

void menuPhongBan(HeThongQuanLy& heThong) {
    int chon;
    do {
        cout << "\n================ OBJECT PHONGBAN ================\n";
        cout << "1. Them phong ban\n";
        cout << "2. Hien thi danh sach phong ban\n";
        cout << "3. Hien thi phong ban theo ma\n";
        cout << "4. Sua phong ban theo ma (console)\n";
        cout << "5. Xoa phong ban theo ma\n";
        cout << "0. Quay lai\n";

        chon = nhapLuaChon();

        switch (chon) {
            case 1: {
                PhongBan pb;
                pb.nhapThongTin();
                heThong.themPhongBan(pb);
                break;
            }
            case 2:
                heThong.hienThiDanhSachPhongBan();
                break;
            case 3: {
                string ma;
                cout << "Nhap ma phong ban: ";
                getline(cin, ma);
                heThong.hienThiPhongBanTheoMa(ma);
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma phong ban can sua: ";
                getline(cin, ma);
                if (heThong.suaPhongBanTheoMa(ma)) {
                    cout << "Sua phong ban thanh cong.\n";
                } else {
                    cout << "Khong tim thay phong ban.\n";
                }
                break;
            }
            case 5: {
                string ma;
                cout << "Nhap ma phong ban can xoa: ";
                getline(cin, ma);
                if (heThong.xoaPhongBanTheoMa(ma)) {
                    cout << "Xoa phong ban thanh cong.\n";
                } else {
                    cout << "Khong tim thay phong ban.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }

        if (chon != 0) tamDung();

    } while (chon != 0);
}

void menuChamCong(HeThongQuanLy& heThong) {
    int chon;
    do {
        cout << "\n================ OBJECT CHAMCONG ================\n";
        cout << "1. Them cham cong\n";
        cout << "2. Hien thi danh sach cham cong\n";
        cout << "3. Hien thi cham cong theo ma\n";
        cout << "4. Sua cham cong theo ma (console)\n";
        cout << "5. Xoa cham cong theo ma\n";
        cout << "0. Quay lai\n";

        chon = nhapLuaChon();

        switch (chon) {
            case 1: {
                ChamCong cc;
                cc.nhapThongTin();
                heThong.themChamCong(cc);
                break;
            }
            case 2:
                heThong.hienThiDanhSachChamCong();
                break;
            case 3: {
                string ma;
                cout << "Nhap ma cham cong: ";
                getline(cin, ma);
                heThong.hienThiChamCongTheoMa(ma);
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma cham cong can sua: ";
                getline(cin, ma);
                if (heThong.suaChamCongTheoMa(ma)) {
                    cout << "Sua cham cong thanh cong.\n";
                } else {
                    cout << "Khong tim thay cham cong.\n";
                }
                break;
            }
            case 5: {
                string ma;
                cout << "Nhap ma cham cong can xoa: ";
                getline(cin, ma);
                if (heThong.xoaChamCongTheoMa(ma)) {
                    cout << "Xoa cham cong thanh cong.\n";
                } else {
                    cout << "Khong tim thay cham cong.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }

        if (chon != 0) tamDung();

    } while (chon != 0);
}

void menuLichLamViec(HeThongQuanLy& heThong) {
    int chon;
    do {
        cout << "\n============== OBJECT LICHLAMVIEC ===============\n";
        cout << "1. Them lich lam viec\n";
        cout << "2. Hien thi danh sach lich lam viec\n";
        cout << "3. Hien thi lich lam viec theo ma\n";
        cout << "4. Sua lich lam viec theo ma (console)\n";
        cout << "5. Xoa lich lam viec theo ma\n";
        cout << "0. Quay lai\n";

        chon = nhapLuaChon();

        switch (chon) {
            case 1: {
                LichLamViec llv;
                llv.nhapThongTin();
                heThong.themLichLamViec(llv);
                break;
            }
            case 2:
                heThong.hienThiDanhSachLichLamViec();
                break;
            case 3: {
                string ma;
                cout << "Nhap ma lich lam: ";
                getline(cin, ma);
                heThong.hienThiLichLamViecTheoMa(ma);
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma lich lam can sua: ";
                getline(cin, ma);
                if (heThong.suaLichLamViecTheoMa(ma)) {
                    cout << "Sua lich lam viec thanh cong.\n";
                } else {
                    cout << "Khong tim thay lich lam viec.\n";
                }
                break;
            }
            case 5: {
                string ma;
                cout << "Nhap ma lich lam can xoa: ";
                getline(cin, ma);
                if (heThong.xoaLichLamViecTheoMa(ma)) {
                    cout << "Xoa lich lam viec thanh cong.\n";
                } else {
                    cout << "Khong tim thay lich lam viec.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }

        if (chon != 0) tamDung();

    } while (chon != 0);
}

void menuDonXinNghi(HeThongQuanLy& heThong) {
    int chon;
    do {
        cout << "\n============== OBJECT DONXINNGHI ================\n";
        cout << "1. Them don xin nghi\n";
        cout << "2. Hien thi danh sach don xin nghi\n";
        cout << "3. Hien thi don xin nghi theo ma\n";
        cout << "4. Sua don xin nghi theo ma (console)\n";
        cout << "5. Xoa don xin nghi theo ma\n";
        cout << "0. Quay lai\n";

        chon = nhapLuaChon();

        switch (chon) {
            case 1: {
                DonXinNghi dxn;
                dxn.nhapThongTin();
                heThong.themDonXinNghi(dxn);
                break;
            }
            case 2:
                heThong.hienThiDanhSachDonXinNghi();
                break;
            case 3: {
                string ma;
                cout << "Nhap ma don xin nghi: ";
                getline(cin, ma);
                heThong.hienThiDonXinNghiTheoMa(ma);
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma don xin nghi can sua: ";
                getline(cin, ma);
                if (heThong.suaDonXinNghiTheoMa(ma)) {
                    cout << "Sua don xin nghi thanh cong.\n";
                } else {
                    cout << "Khong tim thay don xin nghi.\n";
                }
                break;
            }
            case 5: {
                string ma;
                cout << "Nhap ma don xin nghi can xoa: ";
                getline(cin, ma);
                if (heThong.xoaDonXinNghiTheoMa(ma)) {
                    cout << "Xoa don xin nghi thanh cong.\n";
                } else {
                    cout << "Khong tim thay don xin nghi.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }

        if (chon != 0) tamDung();

    } while (chon != 0);
}

void menuQuanLy(HeThongQuanLy& heThong) {
    int chon;
    do {
        cout << "\n================ OBJECT QUANLY ==================\n";
        cout << "1. Them quan ly\n";
        cout << "2. Hien thi danh sach quan ly\n";
        cout << "3. Hien thi quan ly theo ma\n";
        cout << "4. Sua quan ly theo ma (console)\n";
        cout << "5. Xoa quan ly theo ma\n";
        cout << "0. Quay lai\n";

        chon = nhapLuaChon();

        switch (chon) {
            case 1: {
                QuanLy ql;
                ql.nhapThongTin();
                heThong.themQuanLy(ql);
                break;
            }
            case 2:
                heThong.hienThiDanhSachQuanLy();
                break;
            case 3: {
                string ma;
                cout << "Nhap ma quan ly: ";
                getline(cin, ma);
                heThong.hienThiQuanLyTheoMa(ma);
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma quan ly can sua: ";
                getline(cin, ma);
                if (heThong.suaQuanLyTheoMa(ma)) {
                    cout << "Sua quan ly thanh cong.\n";
                } else {
                    cout << "Khong tim thay quan ly.\n";
                }
                break;
            }
            case 5: {
                string ma;
                cout << "Nhap ma quan ly can xoa: ";
                getline(cin, ma);
                if (heThong.xoaQuanLyTheoMa(ma)) {
                    cout << "Xoa quan ly thanh cong.\n";
                } else {
                    cout << "Khong tim thay quan ly.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }

        if (chon != 0) tamDung();

    } while (chon != 0);
}

void menuBaoCaoCong(HeThongQuanLy& heThong) {
    int chon;
    do {
        cout << "\n=============== OBJECT BAOCAOCONG ===============\n";
        cout << "1. Them bao cao cong\n";
        cout << "2. Hien thi danh sach bao cao cong\n";
        cout << "3. Hien thi bao cao cong theo ma\n";
        cout << "4. Sua bao cao cong theo ma (console)\n";
        cout << "5. Xoa bao cao cong theo ma\n";
        cout << "0. Quay lai\n";

        chon = nhapLuaChon();

        switch (chon) {
            case 1: {
                BaoCaoCong bcc;
                bcc.nhapThongTin();
                heThong.themBaoCaoCong(bcc);
                break;
            }
            case 2:
                heThong.hienThiDanhSachBaoCaoCong();
                break;
            case 3: {
                string ma;
                cout << "Nhap ma bao cao cong: ";
                getline(cin, ma);
                heThong.hienThiBaoCaoCongTheoMa(ma);
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma bao cao cong can sua: ";
                getline(cin, ma);
                if (heThong.suaBaoCaoCongTheoMa(ma)) {
                    cout << "Sua bao cao cong thanh cong.\n";
                } else {
                    cout << "Khong tim thay bao cao cong.\n";
                }
                break;
            }
            case 5: {
                string ma;
                cout << "Nhap ma bao cao cong can xoa: ";
                getline(cin, ma);
                if (heThong.xoaBaoCaoCongTheoMa(ma)) {
                    cout << "Xoa bao cao cong thanh cong.\n";
                } else {
                    cout << "Khong tim thay bao cao cong.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }

        if (chon != 0) tamDung();

    } while (chon != 0);
}

int main() {
    HeThongQuanLy heThong;
    int chon;

    do {
        cout << "\n================ MENU TONG HE THONG ================\n";
        cout << "1. Thong tin tong quan\n";
        cout << "2. Menu NhanVien\n";
        cout << "3. Menu PhongBan\n";
        cout << "4. Menu ChamCong\n";
        cout << "5. Menu LichLamViec\n";
        cout << "6. Menu DonXinNghi\n";
        cout << "7. Menu QuanLy\n";
        cout << "8. Menu BaoCaoCong\n";
        cout << "9. Load nhanh nhan vien tu file test\n";
        cout << "0. Thoat\n";

        chon = nhapLuaChon();

        switch (chon) {
            case 1:
                heThong.hienThiThongTinTongQuan();
                tamDung();
                break;
            case 2:
                menuNhanVien(heThong);
                break;
            case 3:
                menuPhongBan(heThong);
                break;
            case 4:
                menuChamCong(heThong);
                break;
            case 5:
                menuLichLamViec(heThong);
                break;
            case 6:
                menuDonXinNghi(heThong);
                break;
            case 7:
                menuQuanLy(heThong);
                break;
            case 8:
                menuBaoCaoCong(heThong);
                break;
            case 9:
                heThong.loadNhanVienTuFile("nhan_vien_test.txt");
                tamDung();
                break;
            case 0:
                cout << "Dang thoat chuong trinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                tamDung();
        }

    } while (chon != 0);

    return 0;
}