#ifndef MENU_H
#define MENU_H

#include "NhanVien.h"
#include "PhongBan.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Menu{
	protected:
		vector<NhanVien*> dsNhanVien;
		vector<PhongBan*> dsPhongBan;
	public:
		// Phuong Thuc Huy
		~Menu(){
			XoaDanhSachNhanVien();
			
			XoaDanhSachPhongBan();
		}
		
		NhanVien* timNhanVienTheoMaNV(string ma);
		vector<NhanVien*> getDsNhanVien();
		
		void XoaDanhSachNhanVien();
		void DocDanhSachNhanVien(string file);
		
		void XoaDanhSachPhongBan();
		void DocDanhSachPhongBan(string file);
		
		void XuatDanhSachNhanVienCongTy();
		void XuatDanhSachDonViCongTy();
		
		void PhanBoNhanVienVaoPhongBan();
		void XuatThongTinNhanVienMoiDonVi();
		
		// Them/Xoa
		NhanVien* ThemNhanVienVaoDanhSachCongTy();
		void XoaNhanVienKhoiDanhSachCongTy(string ma);
		void ThemNhanVienVaoPhongBan(NhanVien* nv);
		
		// Thay doi thong tin
        // void ThayDoiThongTinNhanVien(NhanVien* nv);
		
		void run();
		friend ostream& operator<<(ostream& os, Menu& m);
};

#endif
