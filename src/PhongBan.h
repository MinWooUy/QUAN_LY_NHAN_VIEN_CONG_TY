#ifndef PHONGBAN_H
#define PHONGBAN_H

#include <string>
using namespace std;

class PhongBan {
private:
    string maPhongBan;
    string tenPhongBan;
    string truongPhong;
    int soLuongNhanVien;

public:
    PhongBan();
    PhongBan(const string& ma, const string& ten, const string& truong, int soLuong);

    void nhapThongTin();
    void hienThiThongTin() const;
    void capNhatThongTin();

    string getMaPhongBan() const;
    string getTenPhongBan() const;
    string getTruongPhong() const;
    int getSoLuongNhanVien() const;

    void setTenPhongBan(const string& tenPhongBan);
    void setTruongPhong(const string& truongPhong);
    void setSoLuongNhanVien(int soLuongNhanVien);
};

#endif