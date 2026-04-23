#ifndef BAOCAOCONG_H
#define BAOCAOCONG_H

#include <string>
using namespace std;

class BaoCaoCong {
private:
    string maBaoCao;
    int thang;
    int nam;
    string maNhanVien;
    int tongSoNgayLam;
    int soNgayNghi;
    int soLanDiTre;
    double soGioTangCa;

public:
    BaoCaoCong();
    void nhapThongTin();
    void hienThiThongTin();
};

#endif