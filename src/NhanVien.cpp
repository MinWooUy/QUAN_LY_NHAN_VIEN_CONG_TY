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

void NhanVien::capNhatThongTin() {
    cout << "Cap nhat ho ten: ";
    getline(cin, hoTen);

    cout << "Cap nhat ngay sinh: ";
    getline(cin, ngaySinh);

    cout << "Cap nhat gioi tinh: ";
    getline(cin, gioiTinh);

    cout << "Cap nhat so dien thoai: ";
    getline(cin, soDienThoai);

    cout << "Cap nhat email: ";
    getline(cin, email);

    cout << "Cap nhat dia chi: ";
    getline(cin, diaChi);

    cout << "Cap nhat chuc vu: ";
    getline(cin, chucVu);

    cout << "Cap nhat ngay vao lam: ";
    getline(cin, ngayVaoLam);

    cout << "Cap nhat ma phong ban: ";
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

string NhanVien::getMaNhanVien() const {
    return maNhanVien;
}

string NhanVien::getMaPhongBan() const {
    return maPhongBan;
}

string NhanVien::getHoTen() const {
    return hoTen;
}

string NhanVien::getNgaySinh() const {
    return ngaySinh;
}

string NhanVien::getGioiTinh() const {
    return gioiTinh;
}

string NhanVien::getSoDienThoai() const {
    return soDienThoai;
}

string NhanVien::getEmail() const {
    return email;
}

string NhanVien::getDiaChi() const {
    return diaChi;
}

string NhanVien::getChucVu() const {
    return chucVu;
}

string NhanVien::getNgayVaoLam() const {
    return ngayVaoLam;
}

void NhanVien::setHoTen(const string& hoTen) {
    this->hoTen = hoTen;
}

void NhanVien::setNgaySinh(const string& ngaySinh) {
    this->ngaySinh = ngaySinh;
}

void NhanVien::setGioiTinh(const string& gioiTinh) {
    this->gioiTinh = gioiTinh;
}

void NhanVien::setSoDienThoai(const string& soDienThoai) {
    this->soDienThoai = soDienThoai;
}

void NhanVien::setEmail(const string& email) {
    this->email = email;
}

void NhanVien::setDiaChi(const string& diaChi) {
    this->diaChi = diaChi;
}

void NhanVien::setChucVu(const string& chucVu) {
    this->chucVu = chucVu;
}

void NhanVien::setNgayVaoLam(const string& ngayVaoLam) {
    this->ngayVaoLam = ngayVaoLam;
}

void NhanVien::setMaPhongBan(string ma) {
    maPhongBan = ma;
}