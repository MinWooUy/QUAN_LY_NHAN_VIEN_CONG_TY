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

ChamCong::ChamCong(
    const string& maChamCong,
    const string& maNhanVien,
    const string& ngayLamViec,
    const string& gioVao,
    const string& gioRa,
    const string& trangThaiChamCong,
    double soGioLam,
    const string& ghiChu
) {
    this->maChamCong = maChamCong;
    this->maNhanVien = maNhanVien;
    this->ngayLamViec = ngayLamViec;
    this->gioVao = gioVao;
    this->gioRa = gioRa;
    this->trangThaiChamCong = trangThaiChamCong;
    this->soGioLam = soGioLam;
    this->ghiChu = ghiChu;
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

void ChamCong::hienThiThongTin() const {
    cout << "Ma cham cong: " << maChamCong << endl;
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Ngay lam viec: " << ngayLamViec << endl;
    cout << "Gio vao: " << gioVao << endl;
    cout << "Gio ra: " << gioRa << endl;
    cout << "Trang thai cham cong: " << trangThaiChamCong << endl;
    cout << "So gio lam: " << soGioLam << endl;
    cout << "Ghi chu: " << ghiChu << endl;
}

void ChamCong::capNhatThongTin() {
    cout << "Cap nhat ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Cap nhat ngay lam viec: ";
    getline(cin, ngayLamViec);

    cout << "Cap nhat gio vao: ";
    getline(cin, gioVao);

    cout << "Cap nhat gio ra: ";
    getline(cin, gioRa);

    cout << "Cap nhat trang thai cham cong: ";
    getline(cin, trangThaiChamCong);

    cout << "Cap nhat so gio lam: ";
    cin >> soGioLam;
    cin.ignore();

    cout << "Cap nhat ghi chu: ";
    getline(cin, ghiChu);
}

string ChamCong::getMaChamCong() const {
    return maChamCong;
}

string ChamCong::getMaNhanVien() const {
    return maNhanVien;
}

string ChamCong::getNgayLamViec() const {
    return ngayLamViec;
}

string ChamCong::getGioVao() const {
    return gioVao;
}

string ChamCong::getGioRa() const {
    return gioRa;
}

string ChamCong::getTrangThaiChamCong() const {
    return trangThaiChamCong;
}

double ChamCong::getSoGioLam() const {
    return soGioLam;
}

string ChamCong::getGhiChu() const {
    return ghiChu;
}

void ChamCong::setMaNhanVien(const string& maNhanVien) {
    this->maNhanVien = maNhanVien;
}

void ChamCong::setNgayLamViec(const string& ngayLamViec) {
    this->ngayLamViec = ngayLamViec;
}

void ChamCong::setGioVao(const string& gioVao) {
    this->gioVao = gioVao;
}

void ChamCong::setGioRa(const string& gioRa) {
    this->gioRa = gioRa;
}

void ChamCong::setTrangThaiChamCong(const string& trangThaiChamCong) {
    this->trangThaiChamCong = trangThaiChamCong;
}

void ChamCong::setSoGioLam(double soGioLam) {
    this->soGioLam = soGioLam;
}

void ChamCong::setGhiChu(const string& ghiChu) {
    this->ghiChu = ghiChu;
}