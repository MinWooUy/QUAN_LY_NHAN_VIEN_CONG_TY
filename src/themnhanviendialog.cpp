#include "themnhanviendialog.h"
#include "ui_themnhanviendialog.h"

ThemNhanVienDialog::ThemNhanVienDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ThemNhanVienDialog)
{
    ui->setupUi(this);
    ui->cbbChucVu->addItem("Kinh Doanh");
    ui->cbbChucVu->addItem("Quản Lý");
    ui->cbbChucVu->addItem("Kỹ Thuật");
    ui->cbbChucVu->addItem("Vận Hành");
    ui->cbbChucVu->addItem("Văn Phòng");
}

ThemNhanVienDialog::~ThemNhanVienDialog()
{
    delete ui;
}

NhanVien* ThemNhanVienDialog::LayThongTinNhanVien() {
    // 1. Chuyển các thông tin cơ bản sang chuẩn std::string
    string maNhanVien = ui->txtMaNhanVien->text().toStdString();
    string tenNhanVien = ui->txtTenNhanVien->text().toStdString();
    string ngaySinh = ui->txtNgaySinh->text().toStdString();
    string gioiTinh = ui->txtGioiTinh->text().toStdString();
    string soDienThoai = ui->txtSoDienThoai->text().toStdString();
    string email = ui->txtEmail->text().toStdString();
    string diaChi = ui->txtDiaChi->text().toStdString();
    string congViecCuThe = ui->txtCongViec->text().toStdString();
    string ngayVaoLam = ui->txtNgayVaoLam->text().toStdString();
    string maPhongBan = ui->txtMaPhongBan->text().toStdString();

    // 2. Lấy chức vụ chuẩn từ ComboBox
    QString chucVu = ui->cbbChucVu->currentText();

    NhanVien* NVmoi = nullptr;

    // 3. ĐA HÌNH (Polymorphism): So sánh bằng tuyệt đối, code chạy cực nhanh và an toàn
    if (chucVu == "Kinh Doanh") {
        NhanVienKinhDoanh* kd = new NhanVienKinhDoanh();
        kd->setDoanhSo(0);
        NVmoi = kd;
    }
    else if (chucVu == "Quản Lý" || chucVu == "Trưởng Phòng") {
        QuanLy* ql = new QuanLy();
        ql->setHeSo(1.0);
        NVmoi = ql;
    }
    else if (chucVu == "Kỹ Thuật") {
        NhanVienKyThuat* kt = new NhanVienKyThuat();
        kt->setHeSo(1.0);
        NVmoi = kt;
    }
    else if (chucVu == "Vận Hành") {
        NhanVienLaoDong* ld = new NhanVienLaoDong();
        ld->setSoNgayCong(0);
        NVmoi = ld;
    }
    else {
        // Mặc định (Văn phòng, Hành chính...)
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
        NVmoi->setNgayVaoLam(ngayVaoLam);
        NVmoi->setMaPhongBan(maPhongBan);

        NVmoi->setChucVu(congViecCuThe);
    }

    return NVmoi;
}

void ThemNhanVienDialog::setThongTinNhanVien(NhanVien* nv) {
    if (!nv) return;

    this->setWindowTitle("Cập nhật thông tin nhân viên");
    ui->lblTieuDe->setText("CẬP NHẬT THÔNG TIN");
    ui->txtMaNhanVien->setReadOnly(true); // Không cho sửa mã nhân viên
    ui->txtMaNhanVien->setStyleSheet("background-color: #e2e8f0; color: #64748b; border: 1px solid #cbd5e1;");

    // Điền dữ liệu từ object vào các ô QLineEdit trên UI
    ui->txtMaNhanVien->setText(QString::fromStdString(nv->getMaNhanVien()));
    ui->txtTenNhanVien->setText(QString::fromStdString(nv->getHoTen()));
    ui->txtNgaySinh->setText(QString::fromStdString(nv->getNgaySinh()));
    ui->txtGioiTinh->setText(QString::fromStdString(nv->getGioiTinh()));
    ui->txtSoDienThoai->setText(QString::fromStdString(nv->getSoDienThoai()));
    ui->txtEmail->setText(QString::fromStdString(nv->getEmail()));
    ui->txtDiaChi->setText(QString::fromStdString(nv->getDiaChi()));
    ui->txtCongViec->setText(QString::fromStdString(nv->getChucVu()));
    ui->txtNgayVaoLam->setText(QString::fromStdString(nv->getNgayVaoLam()));
    ui->txtMaPhongBan->setText(QString::fromStdString(nv->getMaPhongBan()));
}
