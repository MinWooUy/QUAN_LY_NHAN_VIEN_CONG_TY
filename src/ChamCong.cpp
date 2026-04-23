#include "ChamCong.h"
#include <iostream>
using namespace std;

ChamCong::ChamCong() {
    maChamCong = "";
    maNhanVien = "";
    ngayLamViec = "";
    gioVao = "";
    gioRa = "";
    trangThaiChamCong = "";
    soGioLam = 0;
    ghiChu = "";
}

void ChamCong::nhapThongTin() {
    cout << "Nhap ma cham cong: ";
    getline(cin, maChamCong);

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Nhap ngay lam viec: ";
    getline(cin, ngayLamViec);

    cout << "Nhap gio vao: ";
    getline(cin, gioVao);

    cout << "Nhap gio ra: ";
    getline(cin, gioRa);

    cout << "Nhap trang thai cham cong: ";
    getline(cin, trangThaiChamCong);

    cout << "Nhap so gio lam: ";
    cin >> soGioLam;
    cin.ignore();

    cout << "Nhap ghi chu: ";
    getline(cin, ghiChu);
}

void ChamCong::hienThiThongTin() {
    cout << "Ma cham cong: " << maChamCong << endl;
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Ngay lam viec: " << ngayLamViec << endl;
    cout << "Gio vao: " << gioVao << endl;
    cout << "Gio ra: " << gioRa << endl;
    cout << "Trang thai cham cong: " << trangThaiChamCong << endl;
    cout << "So gio lam: " << soGioLam << endl;
    cout << "Ghi chu: " << ghiChu << endl;
}