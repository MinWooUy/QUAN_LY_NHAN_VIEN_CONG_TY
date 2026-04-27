#include "NhanVien.h"
#include <iostream>
using namespace std;

int NhanVien::siSoNhanVien = 0;

int NhanVien::getSiSo(){
	return siSoNhanVien;
}

void NhanVien::tangSiSo(){
	siSoNhanVien++;
}

void NhanVien::giamSiSo(){
	siSoNhanVien--;
}

void NhanVien::resetSiSo(){
	siSoNhanVien = 0;
}

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

string NhanVien::getOption(int selec){
    switch(selec){
        case 0:
            return getMaNhanVien();
        case 1:
            return getHoTen();
        case 2:
            return getNgaySinh();
        case 3:
            return getNgayVaoLam();
        default: return "";
    }
}

void NhanVien::setMaNhanVien(const string& maNhanVien){
	this->maNhanVien = maNhanVien;
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
    this->maPhongBan = ma;
}


