#ifndef LICHLAMVIEC_H
#define LICHLAMVIEC_H

#include <string>
#include <vector>   // 🔥 thêm
using namespace std;

class LichLamViec {
protected:
    string maLichLam;
    string maNhanVien;
    string ngayLamViec;
    string caLam;
    string gioBatDau;
    string gioKetThuc;
    string viTriLamViec;

public:
    // ===== CONSTRUCTOR =====
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

    // ===== INPUT / OUTPUT =====
    void nhapThongTin();
    void hienThiThongTinLich() const;
    void capNhatThongTin();

    // ===== GET =====
    string getMaLichLam() const;
    string getMaNhanVien() const;
    string getNgayLamViec() const;
    string getCaLam() const;
    string getGioBatDau() const;
    string getGioKetThuc() const;
    string getViTriLamViec() const;

    // ===== SET =====
    void setMaLichLam(const string& maLichLam); // 🔥 thêm
    void setMaNhanVien(const string& maNhanVien);
    void setNgayLamViec(const string& ngayLamViec);
    void setCaLam(const string& caLam);
    void setGioBatDau(const string& gioBatDau);
    void setGioKetThuc(const string& gioKetThuc);
    void setViTriLamViec(const string& viTriLamViec);

    // ===== FILE =====
    static void loadLichLamViecTuFile(const string& tenFile, vector<LichLamViec>& ds);

    // ===== TIEN ICH =====
    static bool tonTaiMaLich(const vector<LichLamViec>& ds, const string& ma);
};

#endif