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
    PhongBan(string ma, string ten, string truong, int soLuong);

    void nhapThongTin();
    void hienThiThongTin();

    string getMaPhongBan();
    string getTenPhongBan();
};

#endif