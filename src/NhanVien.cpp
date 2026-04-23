#include "NhanVien.h"
#include <iostream>
using namespace std;

NhanVien::NhanVien() {
    maNhanVien = "";
    hoTen = "";
    ngaySinh = "";
    gioiTinh = "";
    soDienThoai = "";
    email = "";
    diaChi = "";
    chucVu = "";
    ngayVaoLam = "";
    maPhongBan = "";
}

NhanVien::NhanVien(
    string maNhanVien,
    string hoTen,
    string ngaySinh,
    string gioiTinh,
    string soDienThoai,
    string email,
    string diaChi,
    string chucVu,
    string ngayVaoLam,
    string maPhongBan
) {
    this->maNhanVien = maNhanVien;
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->gioiTinh = gioiTinh;
    this->soDienThoai = soDienThoai;
    this->email = email;
    this->diaChi = diaChi;
    this->chucVu = chucVu;
    this->ngayVaoLam = ngayVaoLam;
    this->maPhongBan = maPhongBan;
}

void NhanVien::nhapThongTin() {
    cout << "Nhap ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);

    cout << "Nhap gioi tinh: ";
    getline(cin, gioiTinh);

    cout << "Nhap so dien thoai: ";
    getline(cin, soDienThoai);

    cout << "Nhap email: ";
    getline(cin, email);

    cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    cout << "Nhap chuc vu: ";
    getline(cin, chucVu);

    cout << "Nhap ngay vao lam: ";
    getline(cin, ngayVaoLam);

    cout << "Nhap ma phong ban: ";
    getline(cin, maPhongBan);
}

void NhanVien::hienThiThongTin() {
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Gioi tinh: " << gioiTinh << endl;
    cout << "So dien thoai: " << soDienThoai << endl;
    cout << "Email: " << email << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Chuc vu: " << chucVu << endl;
    cout << "Ngay vao lam: " << ngayVaoLam << endl;
    cout << "Ma phong ban: " << maPhongBan << endl;
}

string NhanVien::getMaPhongBan() {
    return maPhongBan;
}

void NhanVien::setMaPhongBan(string ma) {
    maPhongBan = ma;
}