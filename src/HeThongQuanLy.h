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
    void hienThiThongTinTongQuan();

    //-------------------------------------------------------------------//
    //                          OBJECT NHANVIEN
    //-------------------------------------------------------------------//
    int timViTriNhanVienTheoMa(const string& maNhanVien);
    bool tonTaiMaNhanVien(const string& maNhanVien);
    NhanVien* layNhanVienTheoMa(const string& maNhanVien);
    const vector<NhanVien>& layDanhSachNhanVien() const;
    void themNhanVien(const NhanVien& nv);
    void loadNhanVienTuFile(const string& tenFile);
    void hienThiDanhSachNhanVien();
    void hienThiNhanVienTheoMa(const string& maNhanVien);
    bool xoaNhanVienTheoMa(const string& maNhanVien);
    bool suaNhanVienTheoMa(const string& maNhanVien);

    bool capNhatNhanVienTheoMa(
        const string& maNhanVien,
        const string& hoTen,
        const string& ngaySinh,
        const string& gioiTinh,
        const string& soDienThoai,
        const string& email,
        const string& diaChi,
        const string& chucVu,
        const string& ngayVaoLam,
        const string& maPhongBan
    );
    //-------------------------------------------------------------------//
    //                          OBJECT PHONGBAN
    //-------------------------------------------------------------------//
    void themPhongBan(const PhongBan& pb);
    void hienThiDanhSachPhongBan();

    //-------------------------------------------------------------------//
    //                          OBJECT CHAMCONG
    //-------------------------------------------------------------------//
    void themChamCong(const ChamCong& cc);
    void hienThiDanhSachChamCong();

    //-------------------------------------------------------------------//
    //                          OBJECT LICHLAMVIEC
    //-------------------------------------------------------------------//
    void themLichLamViec(const LichLamViec& llv);
    void hienThiDanhSachLichLamViec();
};

#endif