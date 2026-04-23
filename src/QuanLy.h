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

    QuanLy(
        const string& maQuanLy,
        const string& hoTen,
        const string& taiKhoan,
        const string& matKhau,
        const string& quyenHan
    );

    void nhapThongTin();
    void hienThiThongTin() const;
    void capNhatThongTin();

    string getMaQuanLy() const;
    string getHoTen() const;
    string getTaiKhoan() const;
    string getMatKhau() const;
    string getQuyenHan() const;

    void setHoTen(const string& hoTen);
    void setTaiKhoan(const string& taiKhoan);
    void setMatKhau(const string& matKhau);
    void setQuyenHan(const string& quyenHan);
};

#endif