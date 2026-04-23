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

LichLamViec::LichLamViec(
    const string& maLichLam,
    const string& maNhanVien,
    const string& ngayLamViec,
    const string& caLam,
    const string& gioBatDau,
    const string& gioKetThuc,
    const string& viTriLamViec
) {
    this->maLichLam = maLichLam;
    this->maNhanVien = maNhanVien;
    this->ngayLamViec = ngayLamViec;
    this->caLam = caLam;
    this->gioBatDau = gioBatDau;
    this->gioKetThuc = gioKetThuc;
    this->viTriLamViec = viTriLamViec;
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

void LichLamViec::hienThiThongTin() const {
    cout << "Ma lich lam: " << maLichLam << endl;
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Ngay lam viec: " << ngayLamViec << endl;
    cout << "Ca lam: " << caLam << endl;
    cout << "Gio bat dau: " << gioBatDau << endl;
    cout << "Gio ket thuc: " << gioKetThuc << endl;
    cout << "Vi tri lam viec: " << viTriLamViec << endl;
}

void LichLamViec::capNhatThongTin() {
    cout << "Cap nhat ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Cap nhat ngay lam viec: ";
    getline(cin, ngayLamViec);

    cout << "Cap nhat ca lam: ";
    getline(cin, caLam);

    cout << "Cap nhat gio bat dau: ";
    getline(cin, gioBatDau);

    cout << "Cap nhat gio ket thuc: ";
    getline(cin, gioKetThuc);

    cout << "Cap nhat vi tri lam viec: ";
    getline(cin, viTriLamViec);
}

string LichLamViec::getMaLichLam() const {
    return maLichLam;
}

string LichLamViec::getMaNhanVien() const {
    return maNhanVien;
}

string LichLamViec::getNgayLamViec() const {
    return ngayLamViec;
}

string LichLamViec::getCaLam() const {
    return caLam;
}

string LichLamViec::getGioBatDau() const {
    return gioBatDau;
}

string LichLamViec::getGioKetThuc() const {
    return gioKetThuc;
}

string LichLamViec::getViTriLamViec() const {
    return viTriLamViec;
}

void LichLamViec::setMaNhanVien(const string& maNhanVien) {
    this->maNhanVien = maNhanVien;
}

void LichLamViec::setNgayLamViec(const string& ngayLamViec) {
    this->ngayLamViec = ngayLamViec;
}

void LichLamViec::setCaLam(const string& caLam) {
    this->caLam = caLam;
}

void LichLamViec::setGioBatDau(const string& gioBatDau) {
    this->gioBatDau = gioBatDau;
}

void LichLamViec::setGioKetThuc(const string& gioKetThuc) {
    this->gioKetThuc = gioKetThuc;
}

void LichLamViec::setViTriLamViec(const string& viTriLamViec) {
    this->viTriLamViec = viTriLamViec;
}