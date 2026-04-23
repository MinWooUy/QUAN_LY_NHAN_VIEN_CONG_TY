#include "BaoCaoCong.h"
#include <iostream>
using namespace std;

BaoCaoCong::BaoCaoCong() {
    maBaoCao = "";
    thang = 0;
    nam = 0;
    maNhanVien = "";
    tongSoNgayLam = 0;
    soNgayNghi = 0;
    soLanDiTre = 0;
    soGioTangCa = 0;
}

BaoCaoCong::BaoCaoCong(
    const string& maBaoCao,
    int thang,
    int nam,
    const string& maNhanVien,
    int tongSoNgayLam,
    int soNgayNghi,
    int soLanDiTre,
    double soGioTangCa
) {
    this->maBaoCao = maBaoCao;
    this->thang = thang;
    this->nam = nam;
    this->maNhanVien = maNhanVien;
    this->tongSoNgayLam = tongSoNgayLam;
    this->soNgayNghi = soNgayNghi;
    this->soLanDiTre = soLanDiTre;
    this->soGioTangCa = soGioTangCa;
}

void BaoCaoCong::nhapThongTin() {
    cout << "Nhap ma bao cao: ";
    getline(cin, maBaoCao);

    cout << "Nhap thang: ";
    cin >> thang;

    cout << "Nhap nam: ";
    cin >> nam;
    cin.ignore();

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Nhap tong so ngay lam: ";
    cin >> tongSoNgayLam;

    cout << "Nhap so ngay nghi: ";
    cin >> soNgayNghi;

    cout << "Nhap so lan di tre: ";
    cin >> soLanDiTre;

    cout << "Nhap so gio tang ca: ";
    cin >> soGioTangCa;
    cin.ignore();
}

void BaoCaoCong::hienThiThongTin() const {
    cout << "Ma bao cao: " << maBaoCao << endl;
    cout << "Thang: " << thang << endl;
    cout << "Nam: " << nam << endl;
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Tong so ngay lam: " << tongSoNgayLam << endl;
    cout << "So ngay nghi: " << soNgayNghi << endl;
    cout << "So lan di tre: " << soLanDiTre << endl;
    cout << "So gio tang ca: " << soGioTangCa << endl;
}

void BaoCaoCong::capNhatThongTin() {
    cout << "Cap nhat thang: ";
    cin >> thang;

    cout << "Cap nhat nam: ";
    cin >> nam;
    cin.ignore();

    cout << "Cap nhat ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Cap nhat tong so ngay lam: ";
    cin >> tongSoNgayLam;

    cout << "Cap nhat so ngay nghi: ";
    cin >> soNgayNghi;

    cout << "Cap nhat so lan di tre: ";
    cin >> soLanDiTre;

    cout << "Cap nhat so gio tang ca: ";
    cin >> soGioTangCa;
    cin.ignore();
}

string BaoCaoCong::getMaBaoCao() const {
    return maBaoCao;
}

int BaoCaoCong::getThang() const {
    return thang;
}

int BaoCaoCong::getNam() const {
    return nam;
}

string BaoCaoCong::getMaNhanVien() const {
    return maNhanVien;
}

int BaoCaoCong::getTongSoNgayLam() const {
    return tongSoNgayLam;
}

int BaoCaoCong::getSoNgayNghi() const {
    return soNgayNghi;
}

int BaoCaoCong::getSoLanDiTre() const {
    return soLanDiTre;
}

double BaoCaoCong::getSoGioTangCa() const {
    return soGioTangCa;
}

void BaoCaoCong::setThang(int thang) {
    this->thang = thang;
}

void BaoCaoCong::setNam(int nam) {
    this->nam = nam;
}

void BaoCaoCong::setMaNhanVien(const string& maNhanVien) {
    this->maNhanVien = maNhanVien;
}

void BaoCaoCong::setTongSoNgayLam(int tongSoNgayLam) {
    this->tongSoNgayLam = tongSoNgayLam;
}

void BaoCaoCong::setSoNgayNghi(int soNgayNghi) {
    this->soNgayNghi = soNgayNghi;
}

void BaoCaoCong::setSoLanDiTre(int soLanDiTre) {
    this->soLanDiTre = soLanDiTre;
}

void BaoCaoCong::setSoGioTangCa(double soGioTangCa) {
    this->soGioTangCa = soGioTangCa;
}