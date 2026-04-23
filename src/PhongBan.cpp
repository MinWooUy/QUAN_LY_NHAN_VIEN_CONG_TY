#include "PhongBan.h"
#include <iostream>
using namespace std;

PhongBan::PhongBan() {
    maPhongBan = "";
    tenPhongBan = "";
    truongPhong = "";
    soLuongNhanVien = 0;
}

PhongBan::PhongBan(string ma, string ten, string truong, int soLuong) {
    maPhongBan = ma;
    tenPhongBan = ten;
    truongPhong = truong;
    soLuongNhanVien = soLuong;
}

void PhongBan::nhapThongTin() {
    cout << "Nhap ma phong ban: ";
    getline(cin, maPhongBan);

    cout << "Nhap ten phong ban: ";
    getline(cin, tenPhongBan);

    cout << "Nhap truong phong: ";
    getline(cin, truongPhong);

    cout << "Nhap so luong nhan vien: ";
    cin >> soLuongNhanVien;
    cin.ignore();
}

void PhongBan::hienThiThongTin() {
    cout << "Ma phong ban: " << maPhongBan << endl;
    cout << "Ten phong ban: " << tenPhongBan << endl;
    cout << "Truong phong: " << truongPhong << endl;
    cout << "So luong nhan vien: " << soLuongNhanVien << endl;
}

string PhongBan::getMaPhongBan() {
    return maPhongBan;
}

string PhongBan::getTenPhongBan() {
    return tenPhongBan;
}