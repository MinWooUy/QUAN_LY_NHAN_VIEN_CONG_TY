#include <iostream>
#include "PhongBan.h"
using namespace std;

int main() {
    PhongBan pb1;
    PhongBan pb2("PB001", "Hanh chinh - Nhan su", "Nguyen Van A", 5);

    cout << "===== TEST NHAP THONG TIN PHONG BAN =====\n";
    pb1.nhapThongTin();

    cout << "\n===== THONG TIN PHONG BAN VUA NHAP =====\n";
    pb1.hienThiThongTin();

    cout << "\n===== THONG TIN PHONG BAN KHOI TAO SAN =====\n";
    pb2.hienThiThongTin();

    cout << "\n===== TEST GETTER =====\n";
    cout << "Ma phong ban: " << pb2.getMaPhongBan() << endl;
    cout << "Ten phong ban: " << pb2.getTenPhongBan() << endl;
    cout << "Truong phong: " << pb2.getTruongPhong() << endl;
    cout << "So luong nhan vien: " << pb2.getSoLuongNhanVien() << endl;

    cout << "\n===== TEST SETTER =====\n";
    pb2.setTenPhongBan("Ke toan - Tai chinh");
    pb2.setTruongPhong("Tran Thi B");
    pb2.setSoLuongNhanVien(8);
    pb2.hienThiThongTin();

    cout << "\n===== TEST CAP NHAT THONG TIN =====\n";
    pb2.capNhatThongTin();

    cout << "\n===== THONG TIN PHONG BAN SAU KHI CAP NHAT =====\n";
    pb2.hienThiThongTin();

    return 0;
}