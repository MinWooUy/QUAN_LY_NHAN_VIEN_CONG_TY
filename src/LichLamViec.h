#ifndef LICHLAMVIEC_H
#define LICHLAMVIEC_H

#include <string>
using namespace std;

class LichLamViec {
private:
    string maLichLam;
    string maNhanVien;
    string ngayLamViec;
    string caLam;
    string gioBatDau;
    string gioKetThuc;
    string viTriLamViec;

public:
    LichLamViec();
    void nhapThongTin();
    void hienThiThongTin();
};

#endif