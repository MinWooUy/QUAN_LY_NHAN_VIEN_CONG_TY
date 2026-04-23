#ifndef BAOCAOCONG_H
#define BAOCAOCONG_H

#include <string>
using namespace std;

class BaoCaoCong {
private:
    string maBaoCao;
    int thang;
    int nam;
    string maNhanVien;
    int tongSoNgayLam;
    int soNgayNghi;
    int soLanDiTre;
    double soGioTangCa;

public:
    BaoCaoCong();

    BaoCaoCong(
        const string& maBaoCao,
        int thang,
        int nam,
        const string& maNhanVien,
        int tongSoNgayLam,
        int soNgayNghi,
        int soLanDiTre,
        double soGioTangCa
    );

    void nhapThongTin();
    void hienThiThongTin() const;
    void capNhatThongTin();

    string getMaBaoCao() const;
    int getThang() const;
    int getNam() const;
    string getMaNhanVien() const;
    int getTongSoNgayLam() const;
    int getSoNgayNghi() const;
    int getSoLanDiTre() const;
    double getSoGioTangCa() const;

    void setThang(int thang);
    void setNam(int nam);
    void setMaNhanVien(const string& maNhanVien);
    void setTongSoNgayLam(int tongSoNgayLam);
    void setSoNgayNghi(int soNgayNghi);
    void setSoLanDiTre(int soLanDiTre);
    void setSoGioTangCa(double soGioTangCa);
};

#endif