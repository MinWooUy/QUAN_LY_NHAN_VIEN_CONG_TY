#ifndef QUANLY_H
#define QUANLY_H

#include <string>
using namespace std;

class QuanLy {
private:
    string maQuanLy;
    string hoTen;
    string taiKhoan;
    string matKhau;
    string quyenHan;

public:
    QuanLy();
    void nhapThongTin();
    void hienThiThongTin();
};

#endif