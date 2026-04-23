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

void BaoCaoCong::hienThiThongTin() {
    cout << "Ma bao cao: " << maBaoCao << endl;
    cout << "Thang: " << thang << endl;
    cout << "Nam: " << nam << endl;
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Tong so ngay lam: " << tongSoNgayLam << endl;
    cout << "So ngay nghi: " << soNgayNghi << endl;
    cout << "So lan di tre: " << soLanDiTre << endl;
    cout << "So gio tang ca: " << soGioTangCa << endl;
}