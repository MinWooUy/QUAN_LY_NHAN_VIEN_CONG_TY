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
    //                       OBJECT LICHLAMVIEC
    //-------------------------------------------------------------------//
    int timViTriLichLamViecTheoMa(const string& maLichLam);
    bool tonTaiMaLichLamViec(const string& maLichLam);
    LichLamViec* layLichLamViecTheoMa(const string& maLichLam);
    const vector<LichLamViec>& layDanhSachLichLamViec() const;

    void themLichLamViec(const LichLamViec& llv);
    void hienThiDanhSachLichLamViec();
    void hienThiLichLamViecTheoMa(const string& maLichLam);

    bool xoaLichLamViecTheoMa(const string& maLichLam);
    bool suaLichLamViecTheoMa(const string& maLichLam);

    bool capNhatLichLamViecTheoMa(
        const string& maLichLam,
        const string& maNhanVien,
        const string& ngayLamViec,
        const string& caLam,
        const string& gioBatDau,
        const string& gioKetThuc,
        const string& viTriLamViec
    );

    //-------------------------------------------------------------------//
    //                         OBJECT DONXINNGHI
    //-------------------------------------------------------------------//
    int timViTriDonXinNghiTheoMa(const string& maDonNghi);
    bool tonTaiMaDonXinNghi(const string& maDonNghi);
    DonXinNghi* layDonXinNghiTheoMa(const string& maDonNghi);
    const vector<DonXinNghi>& layDanhSachDonXinNghi() const;

    void themDonXinNghi(const DonXinNghi& dxn);
    void hienThiDanhSachDonXinNghi();
    void hienThiDonXinNghiTheoMa(const string& maDonNghi);

    bool xoaDonXinNghiTheoMa(const string& maDonNghi);
    bool suaDonXinNghiTheoMa(const string& maDonNghi);

    bool capNhatDonXinNghiTheoMa(
        const string& maDonNghi,
        const string& maNhanVien,
        const string& loaiNghi,
        const string& ngayBatDau,
        const string& ngayKetThuc,
        const string& lyDo,
        const string& trangThaiDuyet,
        const string& nguoiDuyet
    );

    //-------------------------------------------------------------------//
    //                           OBJECT QUANLY
    //-------------------------------------------------------------------//
    int timViTriQuanLyTheoMa(const string& maQuanLy);
    bool tonTaiMaQuanLy(const string& maQuanLy);
    QuanLy* layQuanLyTheoMa(const string& maQuanLy);
    const vector<QuanLy>& layDanhSachQuanLy() const;

    void themQuanLy(const QuanLy& ql);
    void hienThiDanhSachQuanLy();
    void hienThiQuanLyTheoMa(const string& maQuanLy);

    bool xoaQuanLyTheoMa(const string& maQuanLy);
    bool suaQuanLyTheoMa(const string& maQuanLy);

    bool capNhatQuanLyTheoMa(
        const string& maQuanLy,
        const string& hoTen,
        const string& taiKhoan,
        const string& matKhau,
        const string& quyenHan
    );  

    //-------------------------------------------------------------------//
    //                         OBJECT BAOCAOCONG
    //-------------------------------------------------------------------//
    int timViTriBaoCaoCongTheoMa(const string& maBaoCao);
    bool tonTaiMaBaoCaoCong(const string& maBaoCao);
    BaoCaoCong* layBaoCaoCongTheoMa(const string& maBaoCao);
    const vector<BaoCaoCong>& layDanhSachBaoCaoCong() const;

    void themBaoCaoCong(const BaoCaoCong& bcc);
    void hienThiDanhSachBaoCaoCong();
    void hienThiBaoCaoCongTheoMa(const string& maBaoCao);

    bool xoaBaoCaoCongTheoMa(const string& maBaoCao);
    bool suaBaoCaoCongTheoMa(const string& maBaoCao);

    bool capNhatBaoCaoCongTheoMa(
        const string& maBaoCao,
        int thang,
        int nam,
        const string& maNhanVien,
        int tongSoNgayLam,
        int soNgayNghi,
        int soLanDiTre,
        double soGioTangCa
    );



};

#endif