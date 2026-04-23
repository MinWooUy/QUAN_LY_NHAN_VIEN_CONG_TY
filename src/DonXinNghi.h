#ifndef DONXINNGHI_H
#define DONXINNGHI_H

#include <string>
using namespace std;

class DonXinNghi {
private:
    string maDonNghi;
    string maNhanVien;
    string loaiNghi;
    string ngayBatDau;
    string ngayKetThuc;
    string lyDo;
    string trangThaiDuyet;
    string nguoiDuyet;

public:
    DonXinNghi();
    void nhapThongTin();
    void hienThiThongTin();
};

#endif