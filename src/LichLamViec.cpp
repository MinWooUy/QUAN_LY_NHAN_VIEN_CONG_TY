#include "LichLamViec.h"
#include <iostream>
#include <iomanip>
using namespace std;

LichLamViec::LichLamViec() {
    maLichLam = "";
    maNhanVien = "";
    ngayLamViec = "";
    caLam = "";
    gioBatDau = "";
    gioKetThuc = "";
    viTriLamViec = "";
}

LichLamViec::LichLamViec(
    const string& maLichLam,
    const string& maNhanVien,
    const string& ngayLamViec,
    const string& caLam,
    const string& gioBatDau,
    const string& gioKetThuc,
    const string& viTriLamViec
) {
    this->maLichLam = maLichLam;
    this->maNhanVien = maNhanVien;
    this->ngayLamViec = ngayLamViec;
    this->caLam = caLam;
    this->gioBatDau = gioBatDau;
    this->gioKetThuc = gioKetThuc;
    this->viTriLamViec = viTriLamViec;
}

#include <fstream>
#include <sstream>
#include <vector>

void LichLamViec::loadLichLamViecTuFile(const string& taolich, vector<LichLamViec>& dsLich) {
    ifstream file(taolich);

    if (!file.is_open()) {
        cout << "Khong mo duoc file: " << taolich << endl;
        return;
    }

    string line;
    int soLuongDaLoad = 0;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        vector<string> parts;
        string part;

        while (getline(ss, part, '|')) {
            parts.push_back(part);
        }

        if (parts.size() != 7) continue;

        LichLamViec lich;

        lich.setMaLichLam(parts[0]);      // nếu có mã lịch
        lich.setMaNhanVien(parts[1]);
        lich.setNgayLamViec(parts[2]);
        lich.setCaLam(parts[3]);
        lich.setGioBatDau(parts[4]);
        lich.setGioKetThuc(parts[5]);
        lich.setViTriLamViec(parts[6]);

        // nếu bạn có setMaLich thì thêm
        // lich.setMaLich(parts[0]);

        dsLich.push_back(lich);
        soLuongDaLoad++;
    }

    file.close();
    cout << "Da load " << soLuongDaLoad << " lich lam viec tu file." << endl;
}

void LichLamViec::hienThiThongTinLich() const {
    cout << maLichLam << " | "
         << maNhanVien << " | "
         << ngayLamViec << " | "
         << caLam << " | "
         << gioBatDau << " | "
         << gioKetThuc << " | "
         << viTriLamViec << endl;
}

void LichLamViec::capNhatThongTin() {
    cout << "Cap nhat ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Cap nhat ngay lam viec: ";
    getline(cin, ngayLamViec);

    cout << "Cap nhat ca lam: ";
    getline(cin, caLam);

    cout << "Cap nhat gio bat dau: ";
    getline(cin, gioBatDau);

    cout << "Cap nhat gio ket thuc: ";
    getline(cin, gioKetThuc);

    cout << "Cap nhat vi tri lam viec: ";
    getline(cin, viTriLamViec);
}

string LichLamViec::getMaLichLam() const {
    return maLichLam;
}

string LichLamViec::getMaNhanVien() const {
    return maNhanVien;
}

string LichLamViec::getNgayLamViec() const {
    return ngayLamViec;
}

string LichLamViec::getCaLam() const {
    return caLam;
}

string LichLamViec::getGioBatDau() const {
    return gioBatDau;
}

string LichLamViec::getGioKetThuc() const {
    return gioKetThuc;
}

string LichLamViec::getViTriLamViec() const {
    return viTriLamViec;
}

void LichLamViec::setMaLichLam(const string& maLichLam) {
    this->maLichLam = maLichLam;
}

void LichLamViec::setMaNhanVien(const string& maNhanVien) {
    this->maNhanVien = maNhanVien;
}

void LichLamViec::setNgayLamViec(const string& ngayLamViec) {
    this->ngayLamViec = ngayLamViec;
}

void LichLamViec::setCaLam(const string& caLam) {
    this->caLam = caLam;
}

void LichLamViec::setGioBatDau(const string& gioBatDau) {
    this->gioBatDau = gioBatDau;
}

void LichLamViec::setGioKetThuc(const string& gioKetThuc) {
    this->gioKetThuc = gioKetThuc;
}

void LichLamViec::setViTriLamViec(const string& viTriLamViec) {
    this->viTriLamViec = viTriLamViec;
}