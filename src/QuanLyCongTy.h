#ifndef QUANLYCONGTY_H
#define QUANLYCONGTY_H

#include "NhanVien.h"
#include "PhongBan.h"
#include <vector>
#include <string>

using namespace std;

class QuanLyCongTy {
protected:
    vector<NhanVien*> dsNhanVien;
    vector<PhongBan*> dsPhongBan;
public:
    // Phuong Thuc Huy
    ~QuanLyCongTy(){
        XoaDanhSachNhanVien();

        XoaDanhSachPhongBan();
    }

    NhanVien* timNhanVienTheoMaNV(string ma);
    vector<NhanVien*> getDsNhanVien();
    vector<PhongBan*> getDsPhongBan();

    void XoaDanhSachNhanVien();
    void DocDanhSachNhanVien(string file);

    void XoaDanhSachPhongBan();
    void DocDanhSachPhongBan(string file);

    void XuatDanhSachNhanVienCongTy();
    void XuatDanhSachDonViCongTy();

    void PhanBoNhanVienVaoPhongBan();
    void XuatThongTinNhanVienMoiDonVi();

    // Them/Xoa
    void ThemNhanVienVaoDanhSachCongTy(NhanVien* nv);
    void XoaNhanVienKhoiDanhSachCongTy(string ma);
    void ThemNhanVienVaoPhongBan(NhanVien* nv);

    // Tìm kiếm
    vector<NhanVien*> timKiemNhanVien(string keyword);

    // Sắp xếp
    void sapXepNhanVien(int selec, bool isAscending);
    void sapXepPhongBan(int selec);
    // void sapXepNhanVienTheoLuong();

    // Ghi File
    void LuuDanhSachNhanVien(string file);
};

#endif
