#ifndef PHONGBAN_H
#define PHONGBAN_H

#include "NhanVien.h"

#include <string>
#include <vector>
using namespace std;

class PhongBan{
	private:
		static int soLuongPhongBan;
        string maPhongBan;
    	string tenPhongBan;
    	NhanVien* truongPhong;
    	vector<NhanVien*> dsNhanVienTrongPhong;
	public:
		PhongBan(string ma = "", string ten = "", NhanVien* tp = nullptr);
		
    	string getMaPhongBan() const;
    	string getTenPhongBan() const;
    	NhanVien* getTruongPhong() const;
        vector<NhanVien*> getDsNhanVienTrongPhong() const;
        int getSoLuongNhanVien();

    	void setTenPhongBan(const string& tenPhongBan);
    	void setTruongPhong(NhanVien* truongPhong);
		
		static void tangSoLuongPB();
		static void giamSoLuongPB();
		
		void themNhanVienVaoPhongBan(NhanVien* nv);
		
		void xoaTungPhongBan();
        void xoaNhanVienPhongBan(NhanVien* nv);
        void xoaDanhSachNhanVienTrongPhong();
};

#endif
