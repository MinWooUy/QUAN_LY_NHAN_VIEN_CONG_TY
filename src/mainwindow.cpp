#include "mainwindow.h"
#include "themnhanviendialog.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Khởi tạo dữ liệu lõi
    congTy = new QuanLyCongTy();

    // Đặt file .txt vào thư mục build của Qt (thư mục debug/release)
    congTy->DocDanhSachNhanVien("ThongTinNhanVien.txt");
    congTy->DocDanhSachPhongBan("ThongTinPhongBan.txt");
    congTy->PhanBoNhanVienVaoPhongBan();

    // Cho cột tự giãn đều
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Kết nối QAction với hàm xử lý
    connect(ui->actionNhanVien, &QAction::triggered, this, &MainWindow::taiDanhSachNhanVien);
    connect(ui->actionPhongBan, &QAction::triggered, this, &MainWindow::taiDanhSachPhongBan);
    connect(ui->actionThemNhanVien_2, &QAction::triggered, this, &MainWindow::themNhanVien);
    connect(ui->actionXoaNhanVien_2, &QAction::triggered, this, &MainWindow::xoaNhanVien);
    connect(ui->actionSuaNhanVien_2, &QAction::triggered, this, &MainWindow::suaNhanVien);
    connect(ui->actionTangDanMaNV, &QAction::triggered, this, &MainWindow::sapXepTangTheoMa);
    connect(ui->actionTangDanTenNV, &QAction::triggered, this, &MainWindow::sapXepTangTheoTen);
    connect(ui->actionTangDanNgaySinh, &QAction::triggered, this, &MainWindow::sapXepTangTheoNgaySinh);
    connect(ui->actionTangDanNgayVL, &QAction::triggered, this, &MainWindow::sapXepTangTheoNgayVaoLam);
    connect(ui->actionGiamDanMaNV, &QAction::triggered, this, &MainWindow::sapXepGiamTheoMa);
    connect(ui->actionGiamDanTenNV, &QAction::triggered, this, &MainWindow::sapXepGiamTheoTen);
    connect(ui->actionGiamDanNgaySinh, &QAction::triggered, this, &MainWindow::sapXepGiamTheoNgaySinh);
    connect(ui->actionGiamDanNgayVL, &QAction::triggered, this, &MainWindow::sapXepGiamTheoNgayVaoLam);
}

MainWindow::~MainWindow()
{
    delete congTy;  // Giải phóng bộ nhớ
    delete ui;
}

// Hiển thị lên bảng
void MainWindow::HienThiDanhSachNhanVienLenBang(vector<NhanVien*> ds){
    ui->tableWidget->setRowCount(0); // Xóa dữ liệu cũ

    // Setup cấu trúc bảng
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels({"Mã Nhân Viên", "Họ Tên", "Ngày Sinh", "Ngày Vào Làm",  "Mã Đơn vị", "Chức vụ", "Giới tính", "Số Điện Thoại"});

    for(int i = 0; i < ds.size(); i++){
        ui->tableWidget->insertRow(i);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(ds[i]->getMaNhanVien())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(ds[i]->getHoTen())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ds[i]->getNgaySinh())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(ds[i]->getNgayVaoLam())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(ds[i]->getMaPhongBan())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(ds[i]->getChucVu())));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(ds[i]->getGioiTinh())));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(ds[i]->getSoDienThoai())));
    }
}

// Hiển thị danh sách phòng ban
void MainWindow::HienThiDanhSachPhongBanLenBang(vector<PhongBan*> ds){
    ui->tableWidget->setRowCount(0); // Xóa dữ liệu cũ

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Mã Phòng Ban", "Tên Đơn Vị", "Trưởng Phòng"});

    for(int i = 0; i < ds.size(); i++){
        ui->tableWidget->insertRow(i);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(ds[i]->getMaPhongBan())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(ds[i]->getTenPhongBan())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ds[i]->getTruongPhong()->getHoTen())));
    }
}

// Xuất Danh Sách Nhân Viên
void MainWindow::taiDanhSachNhanVien()
{
    vector<NhanVien*>ds = congTy->getDsNhanVien();
    HienThiDanhSachNhanVienLenBang(ds);
}


void MainWindow::xoaNhanVien()
{
    int row = ui->tableWidget->currentRow(); // Lấy dòng đang click
    if (row < 0) {
        QMessageBox::warning(this, "Lỗi", "Vui lòng click chọn nhân viên trên bảng cần xóa!");
        return;
    }

    // Lấy mã nhân viên ở cột 0 của dòng được chọn
    QString maNV = ui->tableWidget->item(row, 0)->text();

    // Gọi hàm lõi để xóa
    congTy->XoaNhanVienKhoiDanhSachCongTy(maNV.toStdString());

    // Load lại bảng
    taiDanhSachNhanVien();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.txt");
    QMessageBox::information(this, "Thành công", "Đã xóa nhân viên " + maNV);
}


void MainWindow::taiDanhSachPhongBan()
{
    vector<PhongBan*> ds = congTy->getDsPhongBan();
    HienThiDanhSachPhongBanLenBang(ds);
}


void MainWindow::themNhanVien()
{
    ThemNhanVienDialog dialog(this);

    // Nếu người dùng điền Form và bấm OK
    if(dialog.exec() == QDialog::Accepted){
        NhanVien* NVmoi = dialog.LayThongTinNhanVien();

        if(NVmoi->getMaNhanVien().empty() || NVmoi->getHoTen().empty() || NVmoi->getMaPhongBan().empty()){
            QMessageBox::warning(this, "Lỗi", "Mã, Tên nhân viên và Mã Phòng Ban không được để trống");
            delete NVmoi;
            return;
        }

        congTy->ThemNhanVienVaoDanhSachCongTy(NVmoi);
        congTy->ThemNhanVienVaoPhongBan(NVmoi);

        taiDanhSachNhanVien();
    }

    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.txt");
}

void MainWindow::suaNhanVien(){
    int row = ui->tableWidget->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "Thông báo", "Vui lòng chọn nhân viên cần sửa");
        return;
    }

    string maNhanVien = ui->tableWidget->item(row, 0)->text().toStdString();

    NhanVien* nvCanSua = congTy->timNhanVienTheoMaNV(maNhanVien);

    if(nvCanSua){
        ThemNhanVienDialog dialog(this);
        dialog.setWindowTitle("Cập nhật thông tin nhân viên");
        dialog.setThongTinNhanVien(nvCanSua);

        if(dialog.exec() == QDialog::Accepted){
            NhanVien* NVmoi = dialog.LayThongTinNhanVien();

            nvCanSua->setMaNhanVien(NVmoi->getMaNhanVien());
            nvCanSua->setHoTen(NVmoi->getHoTen());
            nvCanSua->setNgaySinh(NVmoi->getNgaySinh());
            nvCanSua->setGioiTinh(NVmoi->getGioiTinh());
            nvCanSua->setSoDienThoai(NVmoi->getSoDienThoai());
            nvCanSua->setEmail(NVmoi->getEmail());
            nvCanSua->setDiaChi(NVmoi->getDiaChi());
            nvCanSua->setChucVu(NVmoi->getChucVu());
            nvCanSua->setNgayVaoLam(NVmoi->getNgayVaoLam());
            nvCanSua->setMaPhongBan(NVmoi->getMaPhongBan());

            delete NVmoi;

            taiDanhSachNhanVien();
            QMessageBox::information(this, "Thành công", "Đã cập nhật thông tin nhân viên!");
        }
    }

    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.txt");
}

void MainWindow::sapXepTangTheoMa(){
    congTy->sapXepNhanVien(0, true);
    taiDanhSachNhanVien();
}

void MainWindow::sapXepTangTheoTen(){
    congTy->sapXepNhanVien(1, true);
    taiDanhSachNhanVien();
}

void MainWindow::sapXepTangTheoNgaySinh(){
    congTy->sapXepNhanVien(2, true);
    taiDanhSachNhanVien();
}

void MainWindow::sapXepTangTheoNgayVaoLam(){
    congTy->sapXepNhanVien(3, true);
    taiDanhSachNhanVien();
}

void MainWindow::sapXepGiamTheoMa(){
    congTy->sapXepNhanVien(0, false);
    taiDanhSachNhanVien();
}

void MainWindow::sapXepGiamTheoTen(){
    congTy->sapXepNhanVien(1, false);
    taiDanhSachNhanVien();
}

void MainWindow::sapXepGiamTheoNgaySinh(){
    congTy->sapXepNhanVien(2, false);
    taiDanhSachNhanVien();
}

void MainWindow::sapXepGiamTheoNgayVaoLam(){
    congTy->sapXepNhanVien(3, false);
    taiDanhSachNhanVien();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    // Lấy từ khóa người dùng gõ
    string keyword = arg1.toStdString();
    vector<NhanVien*> ketQuaLoc = congTy->timKiemNhanVien(keyword);
    HienThiDanhSachNhanVienLenBang(ketQuaLoc);
}

