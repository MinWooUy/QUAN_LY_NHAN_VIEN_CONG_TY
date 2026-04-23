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

void QuanLy::hienThiThongTin() {
    cout << "Ma quan ly: " << maQuanLy << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tai khoan: " << taiKhoan << endl;
    cout << "Mat khau: " << matKhau << endl;
    cout << "Quyen han: " << quyenHan << endl;
}