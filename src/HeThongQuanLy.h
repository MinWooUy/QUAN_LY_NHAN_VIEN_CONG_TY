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
    int timViTriPhongBanTheoMa(const string& maPhongBan);
    bool tonTaiMaPhongBan(const string& maPhongBan);
    void themPhongBan(const PhongBan& pb);
    void hienThiDanhSachPhongBan();
    void hienThiPhongBanTheoMa(const string& maPhongBan);
    bool xoaPhongBanTheoMa(const string& maPhongBan);
    bool suaPhongBanTheoMa(const string& maPhongBan);
    PhongBan* layPhongBanTheoMa(const string& maPhongBan);
    const vector<PhongBan>& layDanhSachPhongBan() const;

    bool capNhatPhongBanTheoMa(
        const string& maPhongBan,
        const string& tenPhongBan,
        const string& truongPhong,
        int soLuongNhanVien
    );

    //-------------------------------------------------------------------//
    //                          OBJECT CHAMCONG
    //-------------------------------------------------------------------//
    int timViTriChamCongTheoMa(const string& maChamCong);
    bool tonTaiMaChamCong(const string& maChamCong);
    ChamCong* layChamCongTheoMa(const string& maChamCong);
    const vector<ChamCong>& layDanhSachChamCong() const;

    void themChamCong(const ChamCong& cc);
    void hienThiDanhSachChamCong();
    void hienThiChamCongTheoMa(const string& maChamCong);

    bool xoaChamCongTheoMa(const string& maChamCong);
    bool suaChamCongTheoMa(const string& maChamCong);

    bool capNhatChamCongTheoMa(
        const string& maChamCong,
        const string& maNhanVien,
        const string& ngayLamViec,
        const string& gioVao,
        const string& gioRa,
        const string& trangThaiChamCong,
        double soGioLam,
        const string& ghiChu
    );
    
    //-------------------------------------------------------------------//
    //                          OBJECT LICHLAMVIEC
    //-------------------------------------------------------------------//
    void themLichLamViec(const LichLamViec& llv);
    void hienThiDanhSachLichLamViec();
};

#endif