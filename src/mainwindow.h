#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QuanLyCongTy.h"
#include <QMainWindow>
#include <QList>
#include <QDate>

class QLineEdit;
class QLabel;
class QTableWidget;
class QComboBox;
class QSpinBox;
class QDateEdit;
class QDoubleSpinBox;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void taiDanhSachNhanVien();
    void taiDanhSachPhongBan();
    void themNhanVien();
    void xoaNhanVien();
    void suaNhanVien();
    void sapXepTangTheoMa();
    void sapXepTangTheoTen();
    void sapXepTangTheoNgaySinh();
    void sapXepTangTheoNgayVaoLam();
    void sapXepGiamTheoMa();
    void sapXepGiamTheoTen();
    void sapXepGiamTheoNgaySinh();
    void sapXepGiamTheoNgayVaoLam();
    void on_lineEdit_textChanged(const QString &arg1);

    // Phòng ban
    void hienThiNhanVienTheoPhong(QString maPB);
    void capNhatLaiBang();
    void themPhongBan();
    void xoaPhongBan();
    void boNhiemTruongPhong();

    void on_btnThongKeLuong_clicked();

    void on_pushButton_clicked();

    void on_btnThongTinNhom_clicked();

    // Chấm công
    void hienThiChamCong();
    void xuLyCheckIn();
    void xuLyCheckOut();
    void lamMoiChamCong();

    // Ngày làm việc
    void hienThiNgayLamViec();
    void capNhatThongKeNgayLamViec();
    void timKiemThongKeNhanVienNgayLamViec();
    void capNhatCongThuCong();
    void ghiNhanNgayNghi();
    void lamMoiFormNgayNghi();

private:
    Ui::MainWindow *ui;
    QuanLyCongTy *congTy;
    PhongBan* phongBanHienTai = nullptr;

    struct BanGhiChamCong {
        QString maChamCong;
        QString maNhanVien;
        QString hoTen;
        QDate ngay;
        QString gioVao;
        QString gioRa;
        QString trangThai;
        double soGio;
    };

    QList<BanGhiChamCong> dsChamCong;

    struct BanGhiNgayNghi {
        QString maNhanVien;
        QString hoTen;
        QDate ngay;
        QString trangThai;
        QString lyDo;
    };

    QList<BanGhiNgayNghi> dsNgayNghi;
    int demMaChamCong = 1;
    QLineEdit *txtMaNhanVienChamCong = nullptr;
    QLineEdit *txtThongTinChamCong = nullptr;
    QLabel *lblTrangThaiChamCong = nullptr;
    QTableWidget *tableChamCong = nullptr;

    QWidget *pageNgayLamViec = nullptr;
    QTableWidget *tableNgayLamViec = nullptr;
    QTableWidget *tableChiTietNgayNghi = nullptr;
    QComboBox *comboThangNgayLamViec = nullptr;
    QSpinBox *spinNamNgayLamViec = nullptr;
    QLineEdit *txtMaNhanVienNghi = nullptr;
    QLabel *lblThongTinNhanVienNgayLamViec = nullptr;
    QLabel *lblChiTietNgayLamViec = nullptr;
    QDateEdit *dateSuaCongThuCong = nullptr;
    QDoubleSpinBox *spinSoGioSuaCong = nullptr;
    QLineEdit *txtGhiChuSuaCong = nullptr;
    QDateEdit *dateNgayNghi = nullptr;
    QComboBox *comboTrangThaiNghi = nullptr;
    QLineEdit *txtLyDoNghi = nullptr;
    QLabel *lblTongQuanNgayLamViec = nullptr;

    void HienThiDanhSachNhanVienLenBang(vector<NhanVien*>dsNhanVien);
    void taoGiaoDienChamCong();
    void capNhatBangChamCong();
    int timBanGhiChamCongTrongNgay(const QString &maNhanVien) const;

    void taoGiaoDienNgayLamViec();
    int soNgayLamViecChuanTrongThang(int thang, int nam) const;
    bool laNgayLamViec(const QDate &ngay) const;
    QDate ngayCuoiThongKeTrongThang(int thang, int nam) const;
    int timBanGhiChamCongTheoNgay(const QString &maNhanVien, const QDate &ngay) const;
    QString layLyDoNghiTrongThang(const QString &maNV, int thang, int nam) const;
};
#endif // MAINWINDOW_H
