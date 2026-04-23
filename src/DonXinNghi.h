#ifndef DONXINNGHI_H
#define DONXINNGHI_H

#include <string>
using namespace std;

class DonXinNghi {
private:
    string maDonNghi;
    string maNhanVien;
    string loaiNghi;
    string ngayBatDau;
    string ngayKetThuc;
    string lyDo;
    string trangThaiDuyet;
    string nguoiDuyet;

public:
    DonXinNghi();

    DonXinNghi(
        const string& maDonNghi,
        const string& maNhanVien,
        const string& loaiNghi,
        const string& ngayBatDau,
        const string& ngayKetThuc,
        const string& lyDo,
        const string& trangThaiDuyet,
        const string& nguoiDuyet
    );

    void nhapThongTin();
    void hienThiThongTin() const;
    void capNhatThongTin();

    string getMaDonNghi() const;
    string getMaNhanVien() const;
    string getLoaiNghi() const;
    string getNgayBatDau() const;
    string getNgayKetThuc() const;
    string getLyDo() const;
    string getTrangThaiDuyet() const;
    string getNguoiDuyet() const;

    void setMaNhanVien(const string& maNhanVien);
    void setLoaiNghi(const string& loaiNghi);
    void setNgayBatDau(const string& ngayBatDau);
    void setNgayKetThuc(const string& ngayKetThuc);
    void setLyDo(const string& lyDo);
    void setTrangThaiDuyet(const string& trangThaiDuyet);
    void setNguoiDuyet(const string& nguoiDuyet);
};

#endif