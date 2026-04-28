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

    NhanVien* NVmoi = nullptr;

    // Phân loại class con dựa trên chức vụ người dùng vừa nhập trên UI
    if (chucVu.find("kinh doanh") != string::npos) {
        NhanVienKinhDoanh* kd = new NhanVienKinhDoanh();
        kd->setDoanhSo(0); // Khởi tạo mặc định dữ liệu riêng là 0
        NVmoi = kd;
    }
    else if (chucVu.find("Quản lý") != string::npos || chucVu.find("Trưởng") != string::npos) {
        QuanLy* ql = new QuanLy();
        ql->setHeSo(1.0); // Khởi tạo mặc định hệ số là 1.0
        NVmoi = ql;
    }
    else if (chucVu.find("Kỹ thuật") != string::npos || chucVu.find("Lập trình") != string::npos || chucVu.find("vi mạch") != string::npos) {
        NhanVienKyThuat* kt = new NhanVienKyThuat();
        kt->setHeSo(1.0);
        NVmoi = kt;
    }
    else if (chucVu.find("vận hành") != string::npos || chucVu.find("kho") != string::npos) {
        NhanVienLaoDong* ld = new NhanVienLaoDong();
        ld->setSoNgayCong(0);
        NVmoi = ld;
    }
    else {
        // Mặc định là nhân viên văn phòng
        NhanVienVanPhong* vp = new NhanVienVanPhong();
        vp->setSoNgayCong(0);
        NVmoi = vp;
    }

    if (NVmoi != nullptr) {
        NVmoi->setMaNhanVien(maNhanVien);
        NVmoi->setHoTen(tenNhanVien);
        NVmoi->setNgaySinh(ngaySinh);
        NVmoi->setGioiTinh(gioiTinh);
        NVmoi->setSoDienThoai(soDienThoai);
        NVmoi->setEmail(email);
        NVmoi->setDiaChi(diaChi);
        NVmoi->setChucVu(chucVu);
        NVmoi->setNgayVaoLam(ngayVaoLam);
        NVmoi->setMaPhongBan(maPhongBan);
    }
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
