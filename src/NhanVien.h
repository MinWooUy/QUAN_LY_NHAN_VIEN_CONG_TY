#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

class NhanVien {
private:
    string maNhanVien;
    string hoTen;
    string ngaySinh;
    string gioiTinh;
    string soDienThoai;
    string email;
    string diaChi;
    string chucVu;
    string ngayVaoLam;
    string maPhongBan;

public:
    NhanVien();

    NhanVien(
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
    );

    void nhapThongTin();
    void hienThiThongTin();

    string getMaPhongBan();
    void setMaPhongBan(string ma);
};

#endif