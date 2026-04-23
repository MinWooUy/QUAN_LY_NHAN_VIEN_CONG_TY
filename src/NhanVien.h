#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include "LichLamViec.h"
using namespace std;

class NhanVien: public LichLamViec {
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
    void capNhatThongTin();

    string getMaNhanVien() const;
    string getHoTen() const;
    string getNgaySinh() const;
    string getGioiTinh() const;
    string getSoDienThoai() const;
    string getEmail() const;
    string getDiaChi() const;
    string getChucVu() const;
    string getNgayVaoLam() const;
    string getMaPhongBan() const;

    void setHoTen(const string& hoTen);
    void setNgaySinh(const string& ngaySinh);
    void setGioiTinh(const string& gioiTinh);
    void setSoDienThoai(const string& soDienThoai);
    void setEmail(const string& email);
    void setDiaChi(const string& diaChi);
    void setChucVu(const string& chucVu);
    void setNgayVaoLam(const string& ngayVaoLam);
    void setMaPhongBan(string ma);
};

#endif