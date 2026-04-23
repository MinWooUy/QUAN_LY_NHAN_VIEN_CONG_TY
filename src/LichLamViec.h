#ifndef LICHLAMVIEC_H
#define LICHLAMVIEC_H

#include <string>
using namespace std;

class LichLamViec {
private:
    string maLichLam;
    string maNhanVien;
    string ngayLamViec;
    string caLam;
    string gioBatDau;
    string gioKetThuc;
    string viTriLamViec;

public:
    LichLamViec();

    LichLamViec(
        const string& maLichLam,
        const string& maNhanVien,
        const string& ngayLamViec,
        const string& caLam,
        const string& gioBatDau,
        const string& gioKetThuc,
        const string& viTriLamViec
    );

    void nhapThongTin();
    void hienThiThongTin() const;
    void capNhatThongTin();

    string getMaLichLam() const;
    string getMaNhanVien() const;
    string getNgayLamViec() const;
    string getCaLam() const;
    string getGioBatDau() const;
    string getGioKetThuc() const;
    string getViTriLamViec() const;

    void setMaNhanVien(const string& maNhanVien);
    void setNgayLamViec(const string& ngayLamViec);
    void setCaLam(const string& caLam);
    void setGioBatDau(const string& gioBatDau);
    void setGioKetThuc(const string& gioKetThuc);
    void setViTriLamViec(const string& viTriLamViec);
};

#endif