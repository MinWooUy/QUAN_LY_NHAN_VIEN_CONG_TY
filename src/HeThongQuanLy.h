#ifndef HETHONGQUANLY_H
#define HETHONGQUANLY_H

#include <vector>
#include "NhanVien.h"
#include "PhongBan.h"
#include "ChamCong.h"
#include "LichLamViec.h"
#include "DonXinNghi.h"
#include "QuanLy.h"
#include "BaoCaoCong.h"
using namespace std;

class HeThongQuanLy {
private:
    vector<NhanVien> dsNhanVien;
    vector<PhongBan> dsPhongBan;
    vector<ChamCong> dsChamCong;
    vector<LichLamViec> dsLichLamViec;
    vector<DonXinNghi> dsDonXinNghi;
    vector<QuanLy> dsQuanLy;
    vector<BaoCaoCong> dsBaoCaoCong;

public:
    HeThongQuanLy();

    void themNhanVien(const NhanVien& nv);
    void themPhongBan(const PhongBan& pb);

    void loadNhanVienTuFile(const string& tenFile);

    void hienThiThongTinTongQuan();
    void hienThiDanhSachNhanVien();
    void hienThiDanhSachPhongBan();
};

#endif