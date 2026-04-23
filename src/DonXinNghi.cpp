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

void DonXinNghi::hienThiThongTin() {
    cout << "Ma don nghi: " << maDonNghi << endl;
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Loai nghi: " << loaiNghi << endl;
    cout << "Ngay bat dau: " << ngayBatDau << endl;
    cout << "Ngay ket thuc: " << ngayKetThuc << endl;
    cout << "Ly do: " << lyDo << endl;
    cout << "Trang thai duyet: " << trangThaiDuyet << endl;
    cout << "Nguoi duyet: " << nguoiDuyet << endl;
}