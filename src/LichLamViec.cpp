#include "LichLamViec.h"
#include <iostream>
using namespace std;

LichLamViec::LichLamViec() {
    maLichLam = "";
    maNhanVien = "";
    ngayLamViec = "";
    caLam = "";
    gioBatDau = "";
    gioKetThuc = "";
    viTriLamViec = "";
}

void LichLamViec::nhapThongTin() {
    cout << "Nhap ma lich lam: ";
    getline(cin, maLichLam);

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Nhap ngay lam viec: ";
    getline(cin, ngayLamViec);

    cout << "Nhap ca lam: ";
    getline(cin, caLam);

    cout << "Nhap gio bat dau: ";
    getline(cin, gioBatDau);

    cout << "Nhap gio ket thuc: ";
    getline(cin, gioKetThuc);

    cout << "Nhap vi tri lam viec: ";
    getline(cin, viTriLamViec);
}

void LichLamViec::hienThiThongTin() {
    cout << "Ma lich lam: " << maLichLam << endl;
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Ngay lam viec: " << ngayLamViec << endl;
    cout << "Ca lam: " << caLam << endl;
    cout << "Gio bat dau: " << gioBatDau << endl;
    cout << "Gio ket thuc: " << gioKetThuc << endl;
    cout << "Vi tri lam viec: " << viTriLamViec << endl;
}