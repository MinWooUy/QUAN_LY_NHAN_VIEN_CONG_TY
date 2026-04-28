#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
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

    // Lương
    double luongCoBan = 5000000;

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

    virtual ~NhanVien(){} // Destructor ảo
    // Đa hình/ kế thừa
    virtual double tinhLuong() = 0; // Hàm thuần ảo
    virtual string getDuLieuRieng() = 0;
};

class NhanVienTheoNgayCong: public NhanVien{
protected:
    int soNgayCong;
public:
    void setSoNgayCong(int ngay){
        this->soNgayCong = ngay;
    }
    int getSoNgayCong(){return soNgayCong;}

    string getDuLieuRieng(){
        return to_string(soNgayCong);
    }
};

class NhanVienLaoDong: public NhanVienTheoNgayCong{
public:private:
    int phuCap = 500000; // Ăn trưa, đi lại
public:
    double tinhLuong(){
        return (luongCoBan /26.0) * soNgayCong + phuCap;
    }
};

class NhanVienVanPhong: public NhanVienTheoNgayCong{
private:
    int phuCap = 700000; // Ăn trưa, đi lại
public:
    double tinhLuong(){
        return (luongCoBan /26.0) * soNgayCong + phuCap;
    }
};

class NhanVienKinhDoanh: public NhanVien{
private:
    double doanhSo;
    double tiLeHoaHong = 0.05; // 5%
public:
    void setDoanhSo(double ds){
        doanhSo = ds;
    }
    int getDoanhSo(){return doanhSo;}

    string getDuLieuRieng() {
        return to_string((long long)doanhSo);
    }

    double tinhLuong(){
        return luongCoBan + (doanhSo * tiLeHoaHong);
    }
};

class NhanVienTheoHeSo:public NhanVien{
protected:
    double heSo;
public:
    void setHeSo(double heSo) { this->heSo = heSo; }
    string getDuLieuRieng(){
        return to_string(heSo);
    }
};

class NhanVienKyThuat:public NhanVienTheoHeSo{
private:
    int phuCap = 700000;
public:
    double tinhLuong(){
        return luongCoBan * heSo + phuCap;
    }
};

class QuanLy: public NhanVienTheoHeSo{
private:
    int phuCap = 1000000;
public:
    double tinhLuong(){
        return luongCoBan * heSo + phuCap;
    }
};

#endif
