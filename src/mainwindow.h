#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QuanLyCongTy.h"
#include <QMainWindow>

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
private:
    Ui::MainWindow *ui;
    QuanLyCongTy *congTy;

    void HienThiDanhSachNhanVienLenBang(vector<NhanVien*>dsNhanVien);
};
#endif // MAINWINDOW_H
