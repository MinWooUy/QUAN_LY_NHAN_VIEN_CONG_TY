#include "themnhanviendialog.h"
#include "ui_themnhanviendialog.h"

ThemNhanVienDialog::ThemNhanVienDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ThemNhanVienDialog)
{
    ui->setupUi(this);
}

ThemNhanVienDialog::~ThemNhanVienDialog()
{
    delete ui;
}

NhanVien* ThemNhanVienDialog::LayThongTinNhanVien(){
    std::string maNhanVien = ui->txtMaNhanVien->text().toStdString();
    std::string tenNhanVien = ui->txtTenNhanVien->text().toStdString();
    std::string ngaySinh = ui->txtNgaySinh->text().toStdString();
    std::string gioiTinh = ui->txtGioiTinh->text().toStdString();
    std::string soDienThoai = ui->txtSoDienThoai->text().toStdString();
    std::string email = ui->txtEmail->text().toStdString();
    std::string diaChi = ui->txtDiaChi->text().toStdString();
    std::string chucVu = ui->txtChucVu->text().toStdString();
    std::string ngayVaoLam = ui->txtNgayVaoLam->text().toStdString();
    std::string maPhongBan = ui->txtMaPhongBan->text().toStdString();

    NhanVien* NVmoi = new NhanVien(maNhanVien, tenNhanVien, ngaySinh, gioiTinh, soDienThoai, email, diaChi, chucVu, ngayVaoLam, maPhongBan);
    return NVmoi;
}

void ThemNhanVienDialog::setThongTinNhanVien(NhanVien* nv) {
    if (!nv) return;

    // Điền dữ liệu từ object vào các ô QLineEdit trên UI
    ui->txtMaNhanVien->setText(QString::fromStdString(nv->getMaNhanVien()));
    ui->txtTenNhanVien->setText(QString::fromStdString(nv->getHoTen()));
    ui->txtNgaySinh->setText(QString::fromStdString(nv->getNgaySinh()));
    ui->txtGioiTinh->setText(QString::fromStdString(nv->getGioiTinh()));
    ui->txtSoDienThoai->setText(QString::fromStdString(nv->getSoDienThoai()));
    ui->txtEmail->setText(QString::fromStdString(nv->getEmail()));
    ui->txtDiaChi->setText(QString::fromStdString(nv->getDiaChi()));
    ui->txtChucVu->setText(QString::fromStdString(nv->getChucVu()));
    ui->txtNgayVaoLam->setText(QString::fromStdString(nv->getNgayVaoLam()));
    ui->txtMaPhongBan->setText(QString::fromStdString(nv->getMaPhongBan()));

    // Khi sửa, thường ta sẽ khóa không cho sửa Mã Nhân Viên
    // ui->txtMaNhanVien->setEnabled(false);
}
