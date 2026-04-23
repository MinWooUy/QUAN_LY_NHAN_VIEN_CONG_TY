#ifndef CHAMCONG_H
#define CHAMCONG_H

#include <string>
using namespace std;

class ChamCong {
private:
    string maChamCong;
    string maNhanVien;
    string ngayLamViec;
    string gioVao;
    string gioRa;
    string trangThaiChamCong;
    double soGioLam;
    string ghiChu;

public:
    ChamCong();

    ChamCong(
        const string& maChamCong,
        const string& maNhanVien,
        const string& ngayLamViec,
        const string& gioVao,
        const string& gioRa,
        const string& trangThaiChamCong,
        double soGioLam,
        const string& ghiChu
    );

    void nhapThongTin();
    void hienThiThongTin() const;
    void capNhatThongTin();

    string getMaChamCong() const;
    string getMaNhanVien() const;
    string getNgayLamViec() const;
    string getGioVao() const;
    string getGioRa() const;
    string getTrangThaiChamCong() const;
    double getSoGioLam() const;
    string getGhiChu() const;

    void setMaNhanVien(const string& maNhanVien);
    void setNgayLamViec(const string& ngayLamViec);
    void setGioVao(const string& gioVao);
    void setGioRa(const string& gioRa);
    void setTrangThaiChamCong(const string& trangThaiChamCong);
    void setSoGioLam(double soGioLam);
    void setGhiChu(const string& ghiChu);
};

#endif