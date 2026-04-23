#include "QuanLy.h"
#include <iostream>
using namespace std;

QuanLy::QuanLy() {
    maQuanLy = "";
    hoTen = "";
    taiKhoan = "";
    matKhau = "";
    quyenHan = "";
}

QuanLy::QuanLy(
    const string& maQuanLy,
    const string& hoTen,
    const string& taiKhoan,
    const string& matKhau,
    const string& quyenHan
) {
    this->maQuanLy = maQuanLy;
    this->hoTen = hoTen;
    this->taiKhoan = taiKhoan;
    this->matKhau = matKhau;
    this->quyenHan = quyenHan;
}

void QuanLy::nhapThongTin() {
    cout << "Nhap ma quan ly: ";
    getline(cin, maQuanLy);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap tai khoan: ";
    getline(cin, taiKhoan);

    cout << "Nhap mat khau: ";
    getline(cin, matKhau);

    cout << "Nhap quyen han: ";
    getline(cin, quyenHan);
}

void QuanLy::hienThiThongTin() const {
    cout << "Ma quan ly: " << maQuanLy << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tai khoan: " << taiKhoan << endl;
    cout << "Mat khau: " << matKhau << endl;
    cout << "Quyen han: " << quyenHan << endl;
}

void QuanLy::capNhatThongTin() {
    cout << "Cap nhat ho ten: ";
    getline(cin, hoTen);

    cout << "Cap nhat tai khoan: ";
    getline(cin, taiKhoan);

    cout << "Cap nhat mat khau: ";
    getline(cin, matKhau);

    cout << "Cap nhat quyen han: ";
    getline(cin, quyenHan);
}

string QuanLy::getMaQuanLy() const {
    return maQuanLy;
}

string QuanLy::getHoTen() const {
    return hoTen;
}

string QuanLy::getTaiKhoan() const {
    return taiKhoan;
}

string QuanLy::getMatKhau() const {
    return matKhau;
}

string QuanLy::getQuyenHan() const {
    return quyenHan;
}

void QuanLy::setHoTen(const string& hoTen) {
    this->hoTen = hoTen;
}

void QuanLy::setTaiKhoan(const string& taiKhoan) {
    this->taiKhoan = taiKhoan;
}

void QuanLy::setMatKhau(const string& matKhau) {
    this->matKhau = matKhau;
}

void QuanLy::setQuyenHan(const string& quyenHan) {
    this->quyenHan = quyenHan;
}