#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class NhanVien{
protected:
	static int siSoNhanVien;
    string maNhanVien;
    string hoTen;
    string ngaySinh;
    string gioiTinh;
    string soDienThoai;
    string email;
    string diaChi;
    string chucVu;
    string ngayVaoLam;
    string maPhongBan;

public:
    NhanVien();

    NhanVien(
        string maNhanVien,
        string hoTen,
        string ngaySinh,
        string gioiTinh,
        string soDienThoai,
        string email,
        string diaChi,
        string chucVu,
        string ngayVaoLam,
        string maPhongBan
    );
	// Getter
    string getMaNhanVien() const;
    string getHoTen() const;
    string getNgaySinh() const;
    string getGioiTinh() const;
    string getSoDienThoai() const;
    string getEmail() const;
    string getDiaChi() const;
    string getChucVu() const;
    string getNgayVaoLam() const;
    string getMaPhongBan() const;
    string getOption(int selec);
    static int getSiSo();
	// Setter
	void setMaNhanVien(const string& maNhanVien);	
    void setHoTen(const string& hoTen);
    void setNgaySinh(const string& ngaySinh);
    void setGioiTinh(const string& gioiTinh);
    void setSoDienThoai(const string& soDienThoai);
    void setEmail(const string& email);
    void setDiaChi(const string& diaChi);
    void setChucVu(const string& chucVu);
    void setNgayVaoLam(const string& ngayVaoLam);
    void setMaPhongBan(string ma);
    
    // Function
    static void tangSiSo();
    static void giamSiSo();
    static void resetSiSo();
};

#endif
