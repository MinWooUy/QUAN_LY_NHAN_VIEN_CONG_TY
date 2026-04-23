#ifndef CHAMCONG_H
#define CHAMCONG_H

#include <string>
using namespace std;

class ChamCong {
private:
    string maChamCong;
    string maNhanVien;
    string ngayLamViec;
    string gioVao;
    string gioRa;
    string trangThaiChamCong;
    double soGioLam;
    string ghiChu;

public:
    ChamCong();
    void nhapThongTin();
    void hienThiThongTin();
};

#endif