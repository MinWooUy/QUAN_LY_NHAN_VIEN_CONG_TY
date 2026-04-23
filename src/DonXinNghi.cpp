#include "DonXinNghi.h"
#include <iostream>
using namespace std;

DonXinNghi::DonXinNghi() {
    maDonNghi = "";
    maNhanVien = "";
    loaiNghi = "";
    ngayBatDau = "";
    ngayKetThuc = "";
    lyDo = "";
    trangThaiDuyet = "";
    nguoiDuyet = "";
}

DonXinNghi::DonXinNghi(
    const string& maDonNghi,
    const string& maNhanVien,
    const string& loaiNghi,
    const string& ngayBatDau,
    const string& ngayKetThuc,
    const string& lyDo,
    const string& trangThaiDuyet,
    const string& nguoiDuyet
) {
    this->maDonNghi = maDonNghi;
    this->maNhanVien = maNhanVien;
    this->loaiNghi = loaiNghi;
    this->ngayBatDau = ngayBatDau;
    this->ngayKetThuc = ngayKetThuc;
    this->lyDo = lyDo;
    this->trangThaiDuyet = trangThaiDuyet;
    this->nguoiDuyet = nguoiDuyet;
}

void DonXinNghi::nhapThongTin() {
    cout << "Nhap ma don nghi: ";
    getline(cin, maDonNghi);

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Nhap loai nghi: ";
    getline(cin, loaiNghi);

    cout << "Nhap ngay bat dau: ";
    getline(cin, ngayBatDau);

    cout << "Nhap ngay ket thuc: ";
    getline(cin, ngayKetThuc);

    cout << "Nhap ly do: ";
    getline(cin, lyDo);

    cout << "Nhap trang thai duyet: ";
    getline(cin, trangThaiDuyet);

    cout << "Nhap nguoi duyet: ";
    getline(cin, nguoiDuyet);
}

void DonXinNghi::hienThiThongTin() const {
    cout << "Ma don nghi: " << maDonNghi << endl;
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Loai nghi: " << loaiNghi << endl;
    cout << "Ngay bat dau: " << ngayBatDau << endl;
    cout << "Ngay ket thuc: " << ngayKetThuc << endl;
    cout << "Ly do: " << lyDo << endl;
    cout << "Trang thai duyet: " << trangThaiDuyet << endl;
    cout << "Nguoi duyet: " << nguoiDuyet << endl;
}

void DonXinNghi::capNhatThongTin() {
    cout << "Cap nhat ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Cap nhat loai nghi: ";
    getline(cin, loaiNghi);

    cout << "Cap nhat ngay bat dau: ";
    getline(cin, ngayBatDau);

    cout << "Cap nhat ngay ket thuc: ";
    getline(cin, ngayKetThuc);

    cout << "Cap nhat ly do: ";
    getline(cin, lyDo);

    cout << "Cap nhat trang thai duyet: ";
    getline(cin, trangThaiDuyet);

    cout << "Cap nhat nguoi duyet: ";
    getline(cin, nguoiDuyet);
}

string DonXinNghi::getMaDonNghi() const {
    return maDonNghi;
}

string DonXinNghi::getMaNhanVien() const {
    return maNhanVien;
}

string DonXinNghi::getLoaiNghi() const {
    return loaiNghi;
}

string DonXinNghi::getNgayBatDau() const {
    return ngayBatDau;
}

string DonXinNghi::getNgayKetThuc() const {
    return ngayKetThuc;
}

string DonXinNghi::getLyDo() const {
    return lyDo;
}

string DonXinNghi::getTrangThaiDuyet() const {
    return trangThaiDuyet;
}

string DonXinNghi::getNguoiDuyet() const {
    return nguoiDuyet;
}

void DonXinNghi::setMaNhanVien(const string& maNhanVien) {
    this->maNhanVien = maNhanVien;
}

void DonXinNghi::setLoaiNghi(const string& loaiNghi) {
    this->loaiNghi = loaiNghi;
}

void DonXinNghi::setNgayBatDau(const string& ngayBatDau) {
    this->ngayBatDau = ngayBatDau;
}

void DonXinNghi::setNgayKetThuc(const string& ngayKetThuc) {
    this->ngayKetThuc = ngayKetThuc;
}

void DonXinNghi::setLyDo(const string& lyDo) {
    this->lyDo = lyDo;
}

void DonXinNghi::setTrangThaiDuyet(const string& trangThaiDuyet) {
    this->trangThaiDuyet = trangThaiDuyet;
}

void DonXinNghi::setNguoiDuyet(const string& nguoiDuyet) {
    this->nguoiDuyet = nguoiDuyet;
}