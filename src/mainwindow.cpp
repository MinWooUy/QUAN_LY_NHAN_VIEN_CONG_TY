#include "mainwindow.h"
#include "themnhanviendialog.h"
#include "thongkedialog.h"
#include "phongbancard.h"
#include "BaoCaoThongKe.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QHeaderView>
#include <QDateTime>
#include <QTime>
#include <QStringList>
#include <QMenuBar>
#include <QAction>
#include <QAbstractItemView>
#include <QTableWidgetItem>
#include <QSet>
#include <QMap>
#include <QInputDialog>
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QLocale>
#include <QScrollArea>
#include <QAbstractItemView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    congTy = new QuanLyCongTy();

    // Đặt file .txt vào thư mục build của Qt (thư mục debug/release)
    congTy->DocDanhSachNhanVien("ThongTinNhanVien.txt");
    congTy->DocDanhSachPhongBan("ThongTinPhongBan.txt");
    congTy->PhanBoNhanVienVaoPhongBan();

    QStringList headers = {"STT","Mã Nhân Viên", "Họ Tên", "Ngày Sinh", "Ngày Vào Làm", "Mã Phòng Ban", "Chức Vụ", "Giới Tính", "SĐT", "Lương Tháng"};

    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Ẩn cột chỉ số mặc định của QTableWidget để dùng cột STT tự tạo
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(45);

    QHeaderView *header = ui->tableWidget->horizontalHeader();

    // Các cột có nội dung ngắn/cố định -> Ép co lại vừa khít
    header->setSectionResizeMode(0, QHeaderView::ResizeToContents); // STT
    header->setSectionResizeMode(1, QHeaderView::ResizeToContents); // Mã NV
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents); // Mã phòng
    header->setSectionResizeMode(7, QHeaderView::ResizeToContents); // Giới tính
    header->setSectionResizeMode(8, QHeaderView::ResizeToContents); // SĐT

    // Các cột trung bình -> Để tự động
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Họ tên
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents); // Ngày sinh
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents); // Ngày vào làm
    header->setSectionResizeMode(9, QHeaderView::ResizeToContents); // Lương tháng

    // Các cột dài (Họ tên, Chức vụ) -> Ưu tiên dãn rộng nhất
    // dùng Stretch cho cả hai để chúng tự chia nhau vùng trống còn lại
    header->setSectionResizeMode(6, QHeaderView::Stretch); // Chức Vụ

    // Khởi tạo giao diện
    taiDanhSachPhongBan();
    ui->lblSiSo->setText("Sỉ số Nhân Viên Công Ty: " + QString::number(NhanVien::getSiSo()));

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
    connect(ui->actionThemPhongBan, &QAction::triggered, this, &MainWindow::themPhongBan);
    connect(ui->actionXoaPhongBan, &QAction::triggered, this, &MainWindow::xoaPhongBan);
    connect(ui->actionBoNhiemTruongPhong, &QAction::triggered, this, &MainWindow::boNhiemTruongPhong);

    // Tạo thêm tab/menu Chấm công ở thanh menu trên cùng
    QAction *actionChamCong = new QAction("Chấm công", this);
    ui->menubar->addAction(actionChamCong);
    connect(actionChamCong, &QAction::triggered, this, &MainWindow::hienThiChamCong);

    // Tạo thêm tab/menu Ngày làm việc để thống kê lại dữ liệu chấm công trong tháng
    QAction *actionNgayLamViec = new QAction("Ngày làm việc", this);
    ui->menubar->addAction(actionNgayLamViec);
    connect(actionNgayLamViec, &QAction::triggered, this, &MainWindow::hienThiNgayLamViec);

    // Tạo trang chấm công và ngày làm việc bằng code để không ảnh hưởng các trang cũ trong file .ui
    taoGiaoDienChamCong();
    taoGiaoDienNgayLamViec();
}


MainWindow::~MainWindow()
{
    delete congTy;  // Giải phóng bộ nhớ
    delete ui;
}

// Hiển thị lên bảng
void MainWindow::HienThiDanhSachNhanVienLenBang(vector<NhanVien*> ds){
    ui->tableWidget->setRowCount(0); // Xóa dữ liệu cũ

    for(int i = 0; i < ds.size(); i++){
        ui->tableWidget->insertRow(i);

        QTableWidgetItem* itemSTT = new QTableWidgetItem(QString::number(i + 1));
        itemSTT->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 0, itemSTT);

        string chucVuHienThi = ds[i]->getChucVu();
        PhongBan* pb = congTy->timKiemPhongBan(ds[i]->getMaPhongBan());
        if (pb != nullptr && pb->getTruongPhong() == ds[i]) {
            chucVuHienThi += " (Trưởng phòng)"; // Nối thêm đuôi cực kỳ tự nhiên
        }
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(ds[i]->getMaNhanVien())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ds[i]->getHoTen())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(ds[i]->getNgaySinh())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(ds[i]->getNgayVaoLam())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(ds[i]->getMaPhongBan())));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(chucVuHienThi)));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(ds[i]->getGioiTinh())));
        ui->tableWidget->setItem(i, 8, new QTableWidgetItem(QString::fromStdString(ds[i]->getSoDienThoai())));

        double tienLuong = ds[i]->tinhLuong();
        // Định dạng số tiền kiểu Việt Nam (VD: 15.000.000 VNĐ)
        QLocale vnLocale(QLocale::Vietnamese, QLocale::Vietnam);
        QString luongChuoi = vnLocale.toCurrencyString(tienLuong, "VNĐ");

        // Ép chữ căn lề phải cho cột tiền tệ
        QTableWidgetItem* itemLuong = new QTableWidgetItem(luongChuoi);
        itemLuong->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        ui->tableWidget->setItem(i, 9, itemLuong);
    }
}

// Xuất Danh Sách Nhân Viên
void MainWindow::taiDanhSachNhanVien()
{
    ui->stackedWidget->setCurrentIndex(0);
    phongBanHienTai = nullptr;
    capNhatLaiBang();
}

void MainWindow::xoaNhanVien()
{
    int row = ui->tableWidget->currentRow(); // Lấy dòng đang click
    if (row < 0) {
        QMessageBox::warning(this, "Lỗi", "Vui lòng click chọn nhân viên trên bảng cần xóa!");
        return;
    }

    // Lấy mã nhân viên ở cột 0 của dòng được chọn
    QString maNV = ui->tableWidget->item(row, 1)->text();

    // Gọi hàm lõi để xóa
    congTy->XoaNhanVienKhoiDanhSachCongTy(maNV.toStdString());

    congTy->PhanBoNhanVienVaoPhongBan();
    capNhatLaiBang();

    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
    QMessageBox::information(this, "Thành công", "Đã xóa nhân viên " + maNV);
}

void MainWindow::hienThiNhanVienTheoPhong(QString maPB) {
    ui->stackedWidget->setCurrentIndex(0);
    phongBanHienTai = congTy->timKiemPhongBan(maPB.toStdString());
    capNhatLaiBang();
}

void MainWindow::capNhatLaiBang() {
    ui->lblSiSo->setText("Sỉ số Nhân Viên Công Ty: " + QString::number(NhanVien::getSiSo()));

    if (phongBanHienTai != nullptr) {
        HienThiDanhSachNhanVienLenBang(phongBanHienTai->getDsNhanVienTrongPhong());
    } else {
        HienThiDanhSachNhanVienLenBang(congTy->getDsNhanVien());
    }
    congTy->PhanBoNhanVienVaoPhongBan();
}

void MainWindow::taiDanhSachPhongBan()
{
    ui->stackedWidget->setCurrentIndex(1);

    if(ui->scrollPhongBan->widget()){
        delete ui->scrollPhongBan->widget();
    }

    QWidget* containerWidget = new QWidget();
    containerWidget->setObjectName("scrollAreaWidgetContents"); // Để khớp với QSS ở trên
    QGridLayout* gridLayout = new QGridLayout(containerWidget);

    // Khoảng cách giữa các thẻ
    gridLayout->setSpacing(8);
    gridLayout->setContentsMargins(8, 8, 8, 8);

    vector<PhongBan*> ds = congTy->getDsPhongBan();
    int soCot = 3;

    for(int i = 0; i < ds.size(); i++){
        PhongBanCard* card = new PhongBanCard();
        card->setData(ds[i]);

        int row = i/soCot;
        int col = i%soCot;
        gridLayout->addWidget(card, row, col);
        connect(card, &PhongBanCard::xemChiTietClicked, this, &MainWindow::hienThiNhanVienTheoPhong);
    }

    gridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    // Nhét container chứa các thẻ vào ScrollArea
    ui->scrollPhongBan->setWidget(containerWidget);
    ui->scrollPhongBan->setWidgetResizable(true);
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
        taiDanhSachPhongBan();

        capNhatLaiBang();
    }

    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
    congTy->LuuDanhSachPhongBan("ThongTinPhongBanMoi.csv");
}

void MainWindow::suaNhanVien(){
    int row = ui->tableWidget->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "Thông báo", "Vui lòng chọn nhân viên cần sửa");
        return;
    }

    string maNhanVien = ui->tableWidget->item(row, 1)->text().toStdString();

    NhanVien* nvCanSua = congTy->timNhanVienTheoMaNV(maNhanVien);

    if(nvCanSua){
        ThemNhanVienDialog dialog(this);
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

            capNhatLaiBang();
            QMessageBox::information(this, "Thành công", "Đã cập nhật thông tin nhân viên!");
        }
    }
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::sapXepTangTheoMa(){
    congTy->sapXepNhanVien(0, true);
    capNhatLaiBang();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::sapXepTangTheoTen(){
    congTy->sapXepNhanVien(1, true);
    capNhatLaiBang();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::sapXepTangTheoNgaySinh(){
    congTy->sapXepNhanVien(2, true);
    capNhatLaiBang();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::sapXepTangTheoNgayVaoLam(){
    congTy->sapXepNhanVien(3, true);
    capNhatLaiBang();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::sapXepGiamTheoMa(){
    congTy->sapXepNhanVien(0, false);
    capNhatLaiBang();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::sapXepGiamTheoTen(){
    congTy->sapXepNhanVien(1, false);
    capNhatLaiBang();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::sapXepGiamTheoNgaySinh(){
    congTy->sapXepNhanVien(2, false);
    capNhatLaiBang();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::sapXepGiamTheoNgayVaoLam(){
    congTy->sapXepNhanVien(3, false);
    capNhatLaiBang();
    congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    // Lấy từ khóa người dùng gõ
    string keyword = arg1.toStdString();
    vector<NhanVien*> ketQuaLoc = congTy->timKiemNhanVien(keyword);
    HienThiDanhSachNhanVienLenBang(ketQuaLoc);
}


void MainWindow::on_btnThongKeLuong_clicked()
{
    BaoCaoThongKe baoCao(congTy);
    ThongKeDialog dialog(this);
    dialog.setDuLieu(baoCao.tinhTongQuyLuong(), baoCao.thongKePhongBan());
    dialog.exec();
}

void MainWindow::themPhongBan() {
    taiDanhSachPhongBan();
    // Hỏi người dùng nhập Mã Phòng Ban
    bool ok;
    QString maPB = QInputDialog::getText(this, "Thêm Phòng Ban", "Nhập Mã Phòng Ban mới:", QLineEdit::Normal, "", &ok);
    if (!ok || maPB.trimmed().isEmpty()) return;

    // Kiểm tra trùng mã
    if (congTy->kiemTraTrungMaPhongBan(maPB.trimmed().toStdString())) {
        QMessageBox::warning(this, "Lỗi", "Mã phòng ban này đã tồn tại!");
        return;
    }

    // Hỏi người dùng nhập Tên Phòng Ban
    QString tenPB = QInputDialog::getText(this, "Thêm Phòng Ban", "Nhập Tên Phòng Ban:", QLineEdit::Normal, "", &ok);
    if (!ok || tenPB.trimmed().isEmpty()) return;

    // Tạo đối tượng và thêm vào Model
    PhongBan* pbMoi = new PhongBan(maPB.trimmed().toStdString(), tenPB.trimmed().toStdString(), nullptr);
    if (congTy->ThemPhongBanMoi(pbMoi)) {
        // Lưu ra file và Load lại UI
        congTy->LuuDanhSachPhongBan("ThongTinPhongBanMoi.csv");
        taiDanhSachPhongBan();
        QMessageBox::information(this, "Thành công", "Đã thêm phòng ban mới!");
    }
}

void MainWindow::xoaPhongBan() {
    QStringList danhSachPB;
    for (PhongBan* pb : congTy->getDsPhongBan()) {
        // Hiển thị dạng "PB001 - Phòng Kinh Doanh"
        danhSachPB << QString::fromStdString(pb->getMaPhongBan() + " - " + pb->getTenPhongBan());
    }

    if (danhSachPB.isEmpty()) {
        QMessageBox::warning(this, "Trống", "Không có phòng ban nào để xóa!");
        return;
    }

    bool ok;
    QString luaChon = QInputDialog::getItem(this, "Xóa Phòng Ban", "Chọn phòng ban cần xóa:", danhSachPB, 0, false, &ok);

    if (ok && !luaChon.isEmpty()) {
        // Cắt lấy đoạn mã PB ở phía trước (ví dụ: cắt "PB001" từ "PB001 - Phòng Kinh Doanh")
        string maCanXoa = luaChon.split(" - ").first().toStdString();

        // Xác nhận lần cuối
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Xác nhận", "Bạn có chắc chắn muốn xóa phòng " + QString::fromStdString(maCanXoa) + "?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) return;

        int ketQua = congTy->kiemTraPhongBan(maCanXoa);

        if (ketQua == 1) {
            congTy->LuuDanhSachPhongBan("ThongTinPhongBanMoi.csv");
            taiDanhSachPhongBan();
            QMessageBox::information(this, "Thành công", "Đã xóa phòng ban!");
        } else if (ketQua == -1) {
            // Lỗi quy tắc vẹn toàn dữ liệu
            QMessageBox::critical(this, "Không thể xóa", "Phòng ban này đang chứa nhân viên!\nVui lòng chuyển hết nhân viên sang phòng khác trước khi xóa.");
        } else {
            QMessageBox::warning(this, "Lỗi", "Không tìm thấy phòng ban!");
        }
    }
}

void MainWindow::boNhiemTruongPhong()
{
    // Kiểm tra xem người dùng đã chọn nhân viên trên bảng chưa
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Thông báo", "Vui lòng click chọn một nhân viên trên bảng để bổ nhiệm!");
        return;
    }

    QString maNV = ui->tableWidget->item(row, 1)->text();
    NhanVien* nvDuocChon = congTy->timNhanVienTheoMaNV(maNV.toStdString());

    if (!nvDuocChon) return;

    // Tìm xem nhân viên này đang ở phòng ban nào
    string maPB = nvDuocChon->getMaPhongBan();
    PhongBan* pb = congTy->timKiemPhongBan(maPB);

    if (!pb) {
        QMessageBox::warning(this, "Lỗi", "Nhân viên này chưa được phân bổ vào phòng ban hợp lệ!");
        return;
    }

    // Xác nhận
    QString cauHoi = "Bạn có chắc muốn bổ nhiệm nhân viên <b>" + QString::fromStdString(nvDuocChon->getHoTen()) +
                     "</b> làm Trưởng phòng <b>" + QString::fromStdString(pb->getTenPhongBan()) + "</b> không?";

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Xác nhận bổ nhiệm", cauHoi, QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Cập nhật con trỏ Trưởng phòng cho class PhongBan
        pb->setTruongPhong(nvDuocChon);

        // (Tùy chọn) Cập nhật lại chữ "Chức vụ" của nhân viên để hiển thị lên bảng cho ngầu
        // nvDuocChon->setChucVu("Trưởng phòng");

        // --- LƯU TRỮ VÀ CẬP NHẬT UI ---

        // Lưu lại file Phòng ban (vì có trưởng phòng mới)
        congTy->LuuDanhSachPhongBan("ThongTinPhongBanMoi.csv");
        // Lưu lại file Nhân viên (vì chức vụ đã đổi thành Trưởng phòng)
        congTy->LuuDanhSachNhanVien("DanhSachNhanVienMoi.csv");

        // Cập nhật lại giao diện bảng để thấy sự thay đổi
        capNhatLaiBang();

        QMessageBox::information(this, "Thành công", "Đã bổ nhiệm Trưởng phòng thành công!");
    }
}

void MainWindow::on_pushButton_clicked()
{
    congTy->XoaDanhSachNhanVien();
    congTy->XoaDanhSachPhongBan();
    // Đặt file .txt vào thư mục build của Qt (thư mục debug/release)
    congTy->DocDanhSachNhanVien("ThongTinNhanVien.txt");
    congTy->DocDanhSachPhongBan("ThongTinPhongBan.txt");
    congTy->PhanBoNhanVienVaoPhongBan();
    taiDanhSachNhanVien();
}


void MainWindow::on_btnThongTinNhom_clicked()
{
    QString info =  "<b>Trường Đại học Khoa học Tự nhiên, ĐHQG-HCM</b><br>"
                   "<b>ĐỒ ÁN QUẢN LÝ NHÂN VIÊN</b><br><br>"
                   "<b>Nhóm thực hiện:</b> Nhóm 22<br>"
                   "- 23207064 - Bùi Gia Huy<br>"
                   "- 23207065 - Nguyễn Thanh Huy<br>"
                   "- 23207053 - Bùi Quang Hiếu<br>"
                   "- 23207081 - Nguyễn Thế Lực<br>";

    QMessageBox::about(this, "Thông tin nhóm", info);
}


void MainWindow::taoGiaoDienChamCong()
{
    QWidget *pageChamCong = new QWidget();
    pageChamCong->setObjectName("pageChamCong");
    pageChamCong->setStyleSheet(R"(
        QWidget#pageChamCong {
            background-color: #f4f7f6;
            font-family: "Segoe UI";
            color: #2c3e50;
        }
        QFrame#frameChamCongNhanh {
            background-color: #2c3e50;
            border-radius: 12px;
        }
        QLabel#lblTieuDeChamCongNhanh {
            color: #ffffff;
            font-size: 20px;
            font-weight: bold;
        }
        QLabel#lblChamCongField {
            color: #ffffff;
            font-size: 13px;
            font-weight: bold;
        }
        QLineEdit#txtMaNhanVienChamCong,
        QLineEdit#txtThongTinChamCong {
            background-color: #ffffff;
            color: #1e293b;
            border: 1px solid #cbd5e1;
            border-radius: 8px;
            padding: 9px 12px;
            font-size: 13px;
        }
        QLabel#lblTrangThaiChamCong {
            background-color: #edf4ff;
            color: #2563eb;
            border-radius: 7px;
            padding: 10px 12px;
            font-size: 13px;
        }
        QLabel#lblHuongDanChamCong {
            color: #ecf0f1;
            font-size: 12px;
            line-height: 150%;
        }
        QPushButton#btnCheckInChamCong {
            background-color: #27ae60;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px 18px;
            font-weight: bold;
        }
        QPushButton#btnCheckInChamCong:hover { background-color: #2ecc71; }
        QPushButton#btnCheckOutChamCong {
            background-color: #ff7a2f;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px 18px;
            font-weight: bold;
        }
        QPushButton#btnCheckOutChamCong:hover { background-color: #ff8f50; }
        QPushButton#btnLamMoiChamCong {
            background-color: #64748b;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px 18px;
            font-weight: bold;
        }
        QPushButton#btnLamMoiChamCong:hover { background-color: #77869b; }
        QLabel#lblDanhSachChamCong {
            color: #2c3e50;
            font-size: 20px;
            font-weight: bold;
        }
        QTableWidget#tableChamCong {
            background-color: #ffffff;
            alternate-background-color: #f8fafc;
            color: #1e293b;
            border: 1px solid #cbd5e1;
            gridline-color: #e2e8f0;
            selection-background-color: #3498db;
            selection-color: #ffffff;
        }
    )");

    QHBoxLayout *mainLayout = new QHBoxLayout(pageChamCong);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(18);

    QFrame *leftFrame = new QFrame(pageChamCong);
    leftFrame->setObjectName("frameChamCongNhanh");
    leftFrame->setFixedWidth(320);

    QVBoxLayout *leftLayout = new QVBoxLayout(leftFrame);
    leftLayout->setContentsMargins(18, 18, 18, 18);
    leftLayout->setSpacing(12);

    QLabel *lblTitle = new QLabel("Chấm công nhanh", leftFrame);
    lblTitle->setObjectName("lblTieuDeChamCongNhanh");
    leftLayout->addWidget(lblTitle);

    QLabel *lblMaNV = new QLabel("Mã nhân viên", leftFrame);
    lblMaNV->setObjectName("lblChamCongField");
    leftLayout->addWidget(lblMaNV);

    txtMaNhanVienChamCong = new QLineEdit(leftFrame);
    txtMaNhanVienChamCong->setObjectName("txtMaNhanVienChamCong");
    txtMaNhanVienChamCong->setPlaceholderText("Nhập / quét mã nhân viên");
    leftLayout->addWidget(txtMaNhanVienChamCong);

    QLabel *lblThongTin = new QLabel("Thông tin", leftFrame);
    lblThongTin->setObjectName("lblChamCongField");
    leftLayout->addWidget(lblThongTin);

    txtThongTinChamCong = new QLineEdit(leftFrame);
    txtThongTinChamCong->setObjectName("txtThongTinChamCong");
    txtThongTinChamCong->setReadOnly(true);
    txtThongTinChamCong->setText("Nhập mã nhân viên để bắt đầu.");
    leftLayout->addWidget(txtThongTinChamCong);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(10);

    QPushButton *btnCheckIn = new QPushButton("Check-in", leftFrame);
    btnCheckIn->setObjectName("btnCheckInChamCong");
    QPushButton *btnCheckOut = new QPushButton("Check-out", leftFrame);
    btnCheckOut->setObjectName("btnCheckOutChamCong");
    QPushButton *btnLamMoi = new QPushButton("Làm mới", leftFrame);
    btnLamMoi->setObjectName("btnLamMoiChamCong");

    buttonLayout->addWidget(btnCheckIn);
    buttonLayout->addWidget(btnCheckOut);
    buttonLayout->addWidget(btnLamMoi);
    leftLayout->addLayout(buttonLayout);

    QLabel *lblTrangThaiTitle = new QLabel("Trạng thái", leftFrame);
    lblTrangThaiTitle->setObjectName("lblChamCongField");
    leftLayout->addWidget(lblTrangThaiTitle);

    lblTrangThaiChamCong = new QLabel("Sẵn sàng check-in / check-out.", leftFrame);
    lblTrangThaiChamCong->setObjectName("lblTrangThaiChamCong");
    lblTrangThaiChamCong->setWordWrap(true);
    leftLayout->addWidget(lblTrangThaiChamCong);

    QLabel *lblHuongDan = new QLabel(
        "- Nhập mã nhân viên để mô phỏng quét thẻ / vân tay\n"
        "- Check-in: tạo bản ghi mới tự động\n"
        "- Check-out: đóng chu kỳ làm việc trong ngày\n"
        "- Mã chấm công được sinh tự động, không nhập tay",
        leftFrame);
    lblHuongDan->setObjectName("lblHuongDanChamCong");
    lblHuongDan->setWordWrap(true);
    leftLayout->addWidget(lblHuongDan);
    leftLayout->addStretch();

    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->setContentsMargins(0, 0, 0, 0);
    rightLayout->setSpacing(12);

    QLabel *lblDanhSach = new QLabel("Danh sách chấm công", pageChamCong);
    lblDanhSach->setObjectName("lblDanhSachChamCong");
    rightLayout->addWidget(lblDanhSach);

    tableChamCong = new QTableWidget(pageChamCong);
    tableChamCong->setObjectName("tableChamCong");
    tableChamCong->setColumnCount(9);
    tableChamCong->setHorizontalHeaderLabels({"STT", "Mã CC", "Mã NV", "Họ tên", "Ngày", "Giờ vào", "Giờ ra", "Trạng thái", "Số giờ"});
    tableChamCong->verticalHeader()->setVisible(false);
    tableChamCong->setAlternatingRowColors(true);
    tableChamCong->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableChamCong->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableChamCong->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableChamCong->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tableChamCong->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tableChamCong->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    tableChamCong->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    tableChamCong->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    tableChamCong->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    tableChamCong->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    tableChamCong->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
    rightLayout->addWidget(tableChamCong);

    mainLayout->addWidget(leftFrame);
    mainLayout->addLayout(rightLayout, 1);

    ui->stackedWidget->addWidget(pageChamCong);

    connect(btnCheckIn, &QPushButton::clicked, this, &MainWindow::xuLyCheckIn);
    connect(btnCheckOut, &QPushButton::clicked, this, &MainWindow::xuLyCheckOut);
    connect(btnLamMoi, &QPushButton::clicked, this, &MainWindow::lamMoiChamCong);
    connect(txtMaNhanVienChamCong, &QLineEdit::returnPressed, this, &MainWindow::xuLyCheckIn);

    capNhatBangChamCong();
}

void MainWindow::hienThiChamCong()
{
    ui->stackedWidget->setCurrentWidget(tableChamCong->parentWidget());
    if (txtMaNhanVienChamCong) {
        txtMaNhanVienChamCong->setFocus();
    }
}

int MainWindow::timBanGhiChamCongTrongNgay(const QString &maNhanVien) const
{
    QDate homNay = QDate::currentDate();
    for (int i = dsChamCong.size() - 1; i >= 0; --i) {
        const BanGhiChamCong &cc = dsChamCong[i];
        if (cc.maNhanVien == maNhanVien && cc.ngay == homNay) {
            return i;
        }
    }
    return -1;
}

void MainWindow::xuLyCheckIn()
{
    QString maNV = txtMaNhanVienChamCong->text().trimmed();
    if (maNV.isEmpty()) {
        lblTrangThaiChamCong->setText("Vui lòng nhập mã nhân viên trước khi check-in.");
        return;
    }

    NhanVien *nv = congTy->timNhanVienTheoMaNV(maNV.toStdString());
    if (!nv) {
        txtThongTinChamCong->setText("Không tìm thấy nhân viên có mã " + maNV);
        lblTrangThaiChamCong->setText("Check-in thất bại: mã nhân viên không tồn tại.");
        return;
    }

    int viTri = timBanGhiChamCongTrongNgay(maNV);
    if (viTri >= 0 && dsChamCong[viTri].gioRa.isEmpty()) {
        lblTrangThaiChamCong->setText("Nhân viên này đã check-in hôm nay, chưa check-out.");
        return;
    }

    QDateTime now = QDateTime::currentDateTime();
    BanGhiChamCong cc;
    cc.maChamCong = QString("CC%1_%2").arg(now.date().toString("yyyyMMdd")).arg(demMaChamCong++, 3, 10, QChar('0'));
    cc.maNhanVien = maNV;
    cc.hoTen = QString::fromStdString(nv->getHoTen());
    cc.ngay = now.date();
    cc.gioVao = now.time().toString("HH:mm");
    cc.gioRa = "";
    cc.trangThai = "Đang làm";
    cc.soGio = 0.0;
    dsChamCong.append(cc);

    txtThongTinChamCong->setText(cc.hoTen + " - " + cc.maNhanVien);
    lblTrangThaiChamCong->setText("Check-in thành công lúc " + cc.gioVao + ".");
    capNhatBangChamCong();
}

void MainWindow::xuLyCheckOut()
{
    QString maNV = txtMaNhanVienChamCong->text().trimmed();
    if (maNV.isEmpty()) {
        lblTrangThaiChamCong->setText("Vui lòng nhập mã nhân viên trước khi check-out.");
        return;
    }

    int viTri = timBanGhiChamCongTrongNgay(maNV);
    if (viTri < 0 || !dsChamCong[viTri].gioRa.isEmpty()) {
        lblTrangThaiChamCong->setText("Chưa có bản ghi check-in đang mở cho nhân viên này trong hôm nay.");
        return;
    }

    QTime gioRa = QTime::currentTime();
    QTime gioVao = QTime::fromString(dsChamCong[viTri].gioVao, "HH:mm");
    int soGiay = gioVao.secsTo(gioRa);
    if (soGiay < 0) soGiay = 0;

    dsChamCong[viTri].gioRa = gioRa.toString("HH:mm");
    dsChamCong[viTri].soGio = soGiay / 3600.0;
    dsChamCong[viTri].trangThai = "Hoàn tất";

    txtThongTinChamCong->setText(dsChamCong[viTri].hoTen + " - " + dsChamCong[viTri].maNhanVien);
    lblTrangThaiChamCong->setText("Check-out thành công lúc " + dsChamCong[viTri].gioRa + ".");
    capNhatBangChamCong();
}

void MainWindow::lamMoiChamCong()
{
    txtMaNhanVienChamCong->clear();
    txtThongTinChamCong->setText("Nhập mã nhân viên để bắt đầu.");
    lblTrangThaiChamCong->setText("Sẵn sàng check-in / check-out.");
    txtMaNhanVienChamCong->setFocus();
}

void MainWindow::capNhatBangChamCong()
{
    if (!tableChamCong) return;

    tableChamCong->setRowCount(0);
    for (int i = 0; i < dsChamCong.size(); ++i) {
        const BanGhiChamCong &cc = dsChamCong[i];
        tableChamCong->insertRow(i);

        QStringList values = {
            QString::number(i + 1),
            cc.maChamCong,
            cc.maNhanVien,
            cc.hoTen,
            cc.ngay.toString("dd/MM/yyyy"),
            cc.gioVao,
            cc.gioRa.isEmpty() ? "--:--" : cc.gioRa,
            cc.trangThai,
            QString::number(cc.soGio, 'f', 2)
        };

        for (int col = 0; col < values.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(values[col]);
            if (col == 0 || col >= 4) {
                item->setTextAlignment(Qt::AlignCenter);
            }
            tableChamCong->setItem(i, col, item);
        }
    }

    // Nếu tab Ngày làm việc đã được tạo thì cập nhật lại thống kê sau mỗi lần chấm công.
    capNhatThongKeNgayLamViec();
}

void MainWindow::taoGiaoDienNgayLamViec()
{
    pageNgayLamViec = new QWidget();
    pageNgayLamViec->setObjectName("pageNgayLamViec");
    pageNgayLamViec->setStyleSheet(R"(
        QWidget#pageNgayLamViec {
            background-color: #f4f7f6;
            font-family: "Segoe UI";
            color: #2c3e50;
        }

        QScrollArea#scrollNgayLamViecLeft {
            background: transparent;
            border: none;
        }

        QScrollArea#scrollNgayLamViecLeft > QWidget > QWidget {
            background: transparent;
        }

        QFrame#frameNgayLamViec {
            background-color: #2c3e50;
            border-radius: 12px;
        }

        QLabel#lblTieuDeNgayLamViec {
            color: #2563eb;
            font-size: 22px;
            font-weight: bold;
        }

        QLabel#lblNgayLamViecField {
            color: #2563eb;
            font-size: 13px;
            font-weight: bold;
            margin-top: 4px;
        }

        QLabel#lblHuongDanNgayLamViec {
            color: #2563eb;
            font-size: 12px;
            line-height: 150%;
        }

        QLabel#lblThongTinNhanVienNgayLamViec {
            background-color: #34495e;
            color: #ffffff;
            border-radius: 8px;
            padding: 10px;
            font-size: 13px;
            font-weight: bold;
        }

        QLineEdit#txtMaNhanVienNghi,
        QLineEdit#txtLyDoNghi,
        QLineEdit#txtGhiChuSuaCong,
        QComboBox#comboTrangThaiNghi,
        QComboBox#comboThangNgayLamViec,
        QSpinBox#spinNamNgayLamViec,
        QDoubleSpinBox#spinSoGioSuaCong,
        QDateEdit#dateSuaCongThuCong,
        QDateEdit#dateNgayNghi {
            background-color: #ffffff;
            color: #1e293b;
            border: 1px solid #cbd5e1;
            border-radius: 8px;
            padding: 6px 10px;
            font-size: 13px;
            min-height: 34px;
        }

        QComboBox#comboThangNgayLamViec QAbstractItemView,
        QComboBox#comboTrangThaiNghi QAbstractItemView {
            background-color: #ffffff;
            color: #1e293b;
            selection-background-color: #3498db;
            selection-color: #ffffff;
            outline: none;
            border: 1px solid #cbd5e1;
            padding: 4px;
        }

        QSpinBox::up-button,
        QSpinBox::down-button,
        QDoubleSpinBox::up-button,
        QDoubleSpinBox::down-button {
            width: 22px;
            background-color: #f8fafc;
            border-left: 1px solid #cbd5e1;
        }

        QPushButton#btnTimNhanVienNgayLamViec,
        QPushButton#btnCapNhatCongThuCong,
        QPushButton#btnGhiNhanNgayNghi {
            background-color: #27ae60;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            min-height: 36px;
            padding: 8px 14px;
            font-weight: bold;
        }

        QPushButton#btnTimNhanVienNgayLamViec:hover,
        QPushButton#btnCapNhatCongThuCong:hover,
        QPushButton#btnGhiNhanNgayNghi:hover {
            background-color: #2ecc71;
        }

        QPushButton#btnLamMoiNgayNghi {
            background-color: #64748b;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            min-height: 36px;
            padding: 8px 14px;
            font-weight: bold;
        }

        QPushButton#btnLamMoiNgayNghi:hover {
            background-color: #77869b;
        }

        QLabel#lblTieuDeBangNgayLamViec {
            color: #2c3e50;
            font-size: 20px;
            font-weight: bold;
        }

        QLabel#lblTongQuanNgayLamViec {
            background-color: #edf4ff;
            color: #2563eb;
            border-radius: 8px;
            padding: 12px 14px;
            font-size: 13px;
            font-weight: bold;
        }

        QLabel#lblChiTietNgayLamViec {
            background-color: #f8fafc;
            color: #334155;
            border: 1px solid #cbd5e1;
            border-radius: 8px;
            padding: 10px 12px;
            font-size: 13px;
        }

        QTableWidget#tableNgayLamViec,
        QTableWidget#tableChiTietNgayNghi {
            background-color: #ffffff;
            alternate-background-color: #f8fafc;
            color: #1e293b;
            border: 1px solid #cbd5e1;
            gridline-color: #e2e8f0;
            selection-background-color: #3498db;
            selection-color: #ffffff;
        }

        QHeaderView::section {
            background-color: #2c3e50;
            color: #ffffff;
            font-weight: bold;
            border: 1px solid #3498db;
            padding: 9px;
        }
    )");

    QHBoxLayout *mainLayout = new QHBoxLayout(pageNgayLamViec);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(18);

    // Bọc panel trái bằng QScrollArea để không bị che khi form nhiều dòng.
    QScrollArea *leftScroll = new QScrollArea(pageNgayLamViec);
    leftScroll->setObjectName("scrollNgayLamViecLeft");
    leftScroll->setWidgetResizable(true);
    leftScroll->setFixedWidth(420);
    leftScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    leftScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QFrame *leftFrame = new QFrame();
    leftFrame->setObjectName("frameNgayLamViec");
    leftFrame->setMinimumWidth(390);

    QVBoxLayout *leftLayout = new QVBoxLayout(leftFrame);
    leftLayout->setContentsMargins(20, 20, 20, 20);
    leftLayout->setSpacing(9);

    QLabel *lblTitle = new QLabel("Ngày làm việc", leftFrame);
    lblTitle->setObjectName("lblTieuDeNgayLamViec");
    leftLayout->addWidget(lblTitle);

    QLabel *lblThang = new QLabel("Tháng / năm thống kê", leftFrame);
    lblThang->setObjectName("lblNgayLamViecField");
    leftLayout->addWidget(lblThang);

    QHBoxLayout *filterLayout = new QHBoxLayout();
    filterLayout->setSpacing(10);

    comboThangNgayLamViec = new QComboBox(leftFrame);
    comboThangNgayLamViec->setObjectName("comboThangNgayLamViec");
    comboThangNgayLamViec->setMinimumHeight(38);
    comboThangNgayLamViec->setMaxVisibleItems(12);

    for (int i = 1; i <= 12; ++i) {
        comboThangNgayLamViec->addItem("Tháng " + QString::number(i), i);
    }

    comboThangNgayLamViec->setCurrentIndex(QDate::currentDate().month() - 1);
    comboThangNgayLamViec->view()->setMinimumWidth(180);

    spinNamNgayLamViec = new QSpinBox(leftFrame);
    spinNamNgayLamViec->setObjectName("spinNamNgayLamViec");
    spinNamNgayLamViec->setRange(2020, 2100);
    spinNamNgayLamViec->setValue(QDate::currentDate().year());
    spinNamNgayLamViec->setMinimumHeight(38);

    filterLayout->addWidget(comboThangNgayLamViec, 3);
    filterLayout->addWidget(spinNamNgayLamViec, 2);
    leftLayout->addLayout(filterLayout);

    QLabel *lblMaNV = new QLabel("Tìm nhân viên bằng mã NV", leftFrame);
    lblMaNV->setObjectName("lblNgayLamViecField");
    leftLayout->addWidget(lblMaNV);

    txtMaNhanVienNghi = new QLineEdit(leftFrame);
    txtMaNhanVienNghi->setObjectName("txtMaNhanVienNghi");
    txtMaNhanVienNghi->setPlaceholderText("VD: NV001");
    txtMaNhanVienNghi->setMinimumHeight(38);
    leftLayout->addWidget(txtMaNhanVienNghi);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(10);

    QPushButton *btnTim = new QPushButton("Tìm thống kê", leftFrame);
    btnTim->setObjectName("btnTimNhanVienNgayLamViec");
    btnTim->setMinimumHeight(38);

    QPushButton *btnLamMoi = new QPushButton("Làm mới", leftFrame);
    btnLamMoi->setObjectName("btnLamMoiNgayNghi");
    btnLamMoi->setMinimumHeight(38);

    buttonLayout->addWidget(btnTim);
    buttonLayout->addWidget(btnLamMoi);
    leftLayout->addLayout(buttonLayout);

    lblThongTinNhanVienNgayLamViec = new QLabel("Nhập mã nhân viên để xem thống kê theo tháng.", leftFrame);
    lblThongTinNhanVienNgayLamViec->setObjectName("lblThongTinNhanVienNgayLamViec");
    lblThongTinNhanVienNgayLamViec->setWordWrap(true);
    leftLayout->addWidget(lblThongTinNhanVienNgayLamViec);

    QLabel *lblSuaCong = new QLabel("Sửa công thủ công", leftFrame);
    lblSuaCong->setObjectName("lblNgayLamViecField");
    leftLayout->addWidget(lblSuaCong);

    dateSuaCongThuCong = new QDateEdit(QDate::currentDate(), leftFrame);
    dateSuaCongThuCong->setObjectName("dateSuaCongThuCong");
    dateSuaCongThuCong->setCalendarPopup(true);
    dateSuaCongThuCong->setDisplayFormat("dd/MM/yyyy");
    dateSuaCongThuCong->setMinimumHeight(38);
    leftLayout->addWidget(dateSuaCongThuCong);

    spinSoGioSuaCong = new QDoubleSpinBox(leftFrame);
    spinSoGioSuaCong->setObjectName("spinSoGioSuaCong");
    spinSoGioSuaCong->setRange(0.0, 24.0);
    spinSoGioSuaCong->setDecimals(2);
    spinSoGioSuaCong->setSingleStep(0.5);
    spinSoGioSuaCong->setValue(8.0);
    spinSoGioSuaCong->setSuffix(" giờ");
    spinSoGioSuaCong->setMinimumHeight(38);
    leftLayout->addWidget(spinSoGioSuaCong);

    txtGhiChuSuaCong = new QLineEdit(leftFrame);
    txtGhiChuSuaCong->setObjectName("txtGhiChuSuaCong");
    txtGhiChuSuaCong->setPlaceholderText("VD: Quên chấm công, có xác nhận");
    txtGhiChuSuaCong->setMinimumHeight(38);
    leftLayout->addWidget(txtGhiChuSuaCong);

    QPushButton *btnCapNhatCong = new QPushButton("Cập nhật công thủ công", leftFrame);
    btnCapNhatCong->setObjectName("btnCapNhatCongThuCong");
    btnCapNhatCong->setMinimumHeight(38);
    leftLayout->addWidget(btnCapNhatCong);

    QLabel *lblNgay = new QLabel("Khai báo ngày nghỉ", leftFrame);
    lblNgay->setObjectName("lblNgayLamViecField");
    leftLayout->addWidget(lblNgay);

    dateNgayNghi = new QDateEdit(QDate::currentDate(), leftFrame);
    dateNgayNghi->setObjectName("dateNgayNghi");
    dateNgayNghi->setCalendarPopup(true);
    dateNgayNghi->setDisplayFormat("dd/MM/yyyy");
    dateNgayNghi->setMinimumHeight(38);
    leftLayout->addWidget(dateNgayNghi);

    comboTrangThaiNghi = new QComboBox(leftFrame);
    comboTrangThaiNghi->setObjectName("comboTrangThaiNghi");
    comboTrangThaiNghi->addItems(QStringList() << "Nghỉ có phép" << "Nghỉ không phép");
    comboTrangThaiNghi->setMinimumHeight(38);
    comboTrangThaiNghi->view()->setMinimumWidth(220);
    leftLayout->addWidget(comboTrangThaiNghi);

    txtLyDoNghi = new QLineEdit(leftFrame);
    txtLyDoNghi->setObjectName("txtLyDoNghi");
    txtLyDoNghi->setPlaceholderText("Lý do nghỉ");
    txtLyDoNghi->setMinimumHeight(38);
    leftLayout->addWidget(txtLyDoNghi);

    QPushButton *btnGhiNhan = new QPushButton("Ghi nhận nghỉ", leftFrame);
    btnGhiNhan->setObjectName("btnGhiNhanNgayNghi");
    btnGhiNhan->setMinimumHeight(38);
    leftLayout->addWidget(btnGhiNhan);

    QLabel *lblHuongDan = new QLabel(
        "- Thống kê chỉ hiển thị cho mã nhân viên đang tìm\n"
        "- Ngày chuẩn tính từ đầu tháng đến hiện tại\n"
        "- Làm việc từ thứ 2 đến thứ 7, nghỉ Chủ nhật\n"
        "- Sửa công thủ công dùng cho trường hợp đi làm nhưng quên chấm công",
        leftFrame);
    lblHuongDan->setObjectName("lblHuongDanNgayLamViec");
    lblHuongDan->setWordWrap(true);
    leftLayout->addWidget(lblHuongDan);

    leftLayout->addStretch();

    leftScroll->setWidget(leftFrame);

    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->setContentsMargins(0, 0, 0, 0);
    rightLayout->setSpacing(12);

    QLabel *lblBang = new QLabel("Thống kê ngày làm việc theo nhân viên", pageNgayLamViec);
    lblBang->setObjectName("lblTieuDeBangNgayLamViec");
    rightLayout->addWidget(lblBang);

    lblTongQuanNgayLamViec = new QLabel("Chưa chọn nhân viên.", pageNgayLamViec);
    lblTongQuanNgayLamViec->setObjectName("lblTongQuanNgayLamViec");
    lblTongQuanNgayLamViec->setWordWrap(true);
    rightLayout->addWidget(lblTongQuanNgayLamViec);

    lblChiTietNgayLamViec = new QLabel(
        "Sau khi nhập mã nhân viên, bảng bên dưới sẽ hiển thị từng ngày làm việc trong tháng.",
        pageNgayLamViec);
    lblChiTietNgayLamViec->setObjectName("lblChiTietNgayLamViec");
    lblChiTietNgayLamViec->setWordWrap(true);
    rightLayout->addWidget(lblChiTietNgayLamViec);

    tableNgayLamViec = new QTableWidget(pageNgayLamViec);
    tableNgayLamViec->setObjectName("tableNgayLamViec");
    tableNgayLamViec->setColumnCount(7);
    tableNgayLamViec->setHorizontalHeaderLabels({
        "STT", "Ngày", "Thứ", "Giờ vào", "Giờ ra", "Số giờ", "Trạng thái / Ghi chú"
    });
    tableNgayLamViec->verticalHeader()->setVisible(false);
    tableNgayLamViec->setAlternatingRowColors(true);
    tableNgayLamViec->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableNgayLamViec->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableNgayLamViec->horizontalHeader()->setStretchLastSection(true);
    tableNgayLamViec->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableNgayLamViec->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tableNgayLamViec->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tableNgayLamViec->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    tableNgayLamViec->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    tableNgayLamViec->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    tableNgayLamViec->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
    tableNgayLamViec->setMinimumHeight(310);
    rightLayout->addWidget(tableNgayLamViec, 3);

    QLabel *lblChiTiet = new QLabel("Ngày nghỉ / lý do của nhân viên", pageNgayLamViec);
    lblChiTiet->setObjectName("lblTieuDeBangNgayLamViec");
    rightLayout->addWidget(lblChiTiet);

    tableChiTietNgayNghi = new QTableWidget(pageNgayLamViec);
    tableChiTietNgayNghi->setObjectName("tableChiTietNgayNghi");
    tableChiTietNgayNghi->setColumnCount(5);
    tableChiTietNgayNghi->setHorizontalHeaderLabels({
        "STT", "Ngày", "Thứ", "Trạng thái", "Lý do"
    });
    tableChiTietNgayNghi->verticalHeader()->setVisible(false);
    tableChiTietNgayNghi->setAlternatingRowColors(true);
    tableChiTietNgayNghi->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableChiTietNgayNghi->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableChiTietNgayNghi->horizontalHeader()->setStretchLastSection(true);
    tableChiTietNgayNghi->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableChiTietNgayNghi->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tableChiTietNgayNghi->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tableChiTietNgayNghi->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    tableChiTietNgayNghi->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    tableChiTietNgayNghi->setMinimumHeight(140);
    rightLayout->addWidget(tableChiTietNgayNghi, 1);

    mainLayout->addWidget(leftScroll);
    mainLayout->addLayout(rightLayout, 1);

    ui->stackedWidget->addWidget(pageNgayLamViec);

    connect(btnTim, &QPushButton::clicked, this, &MainWindow::timKiemThongKeNhanVienNgayLamViec);
    connect(btnCapNhatCong, &QPushButton::clicked, this, &MainWindow::capNhatCongThuCong);
    connect(btnGhiNhan, &QPushButton::clicked, this, &MainWindow::ghiNhanNgayNghi);
    connect(btnLamMoi, &QPushButton::clicked, this, &MainWindow::lamMoiFormNgayNghi);
    connect(txtMaNhanVienNghi, &QLineEdit::returnPressed, this, &MainWindow::timKiemThongKeNhanVienNgayLamViec);

    connect(comboThangNgayLamViec, SIGNAL(currentIndexChanged(int)),
            this, SLOT(capNhatThongKeNgayLamViec()));

    connect(spinNamNgayLamViec, SIGNAL(valueChanged(int)),
            this, SLOT(capNhatThongKeNgayLamViec()));

    capNhatThongKeNgayLamViec();
}

void MainWindow::hienThiNgayLamViec()
{
    if (!pageNgayLamViec) return;
    ui->stackedWidget->setCurrentWidget(pageNgayLamViec);
    capNhatThongKeNgayLamViec();
}

bool MainWindow::laNgayLamViec(const QDate &ngay) const
{
    return ngay.dayOfWeek() >= 1 && ngay.dayOfWeek() <= 6;
}

QDate MainWindow::ngayCuoiThongKeTrongThang(int thang, int nam) const
{
    QDate homNay = QDate::currentDate();
    QDate ngayDau(nam, thang, 1);
    if (!ngayDau.isValid()) return homNay;

    QDate ngayCuoi(nam, thang, ngayDau.daysInMonth());
    if (nam == homNay.year() && thang == homNay.month()) {
        return homNay;
    }
    if (QDate(nam, thang, 1) > homNay) {
        return QDate(nam, thang, 0); // tháng tương lai: chưa có ngày thống kê
    }
    return ngayCuoi;
}

int MainWindow::soNgayLamViecChuanTrongThang(int thang, int nam) const
{
    QDate ngayDau(nam, thang, 1);
    if (!ngayDau.isValid()) return 0;

    QDate ngayCuoi = ngayCuoiThongKeTrongThang(thang, nam);
    if (!ngayCuoi.isValid() || ngayCuoi < ngayDau) return 0;

    int dem = 0;
    for (QDate cur = ngayDau; cur <= ngayCuoi; cur = cur.addDays(1)) {
        if (laNgayLamViec(cur)) ++dem;
    }
    return dem;
}

int MainWindow::timBanGhiChamCongTheoNgay(const QString &maNhanVien, const QDate &ngay) const
{
    for (int i = 0; i < dsChamCong.size(); ++i) {
        if (dsChamCong[i].maNhanVien == maNhanVien && dsChamCong[i].ngay == ngay) {
            return i;
        }
    }
    return -1;
}

QString MainWindow::layLyDoNghiTrongThang(const QString &maNV, int thang, int nam) const
{
    QStringList lyDo;
    for (const BanGhiNgayNghi &nghi : dsNgayNghi) {
        if (nghi.maNhanVien == maNV && nghi.ngay.month() == thang && nghi.ngay.year() == nam) {
            QString item = nghi.ngay.toString("dd/MM") + " - " + nghi.trangThai;
            if (!nghi.lyDo.trimmed().isEmpty()) {
                item += ": " + nghi.lyDo.trimmed();
            }
            lyDo << item;
        }
    }
    return lyDo.isEmpty() ? "--" : lyDo.join("; ");
}

void MainWindow::timKiemThongKeNhanVienNgayLamViec()
{
    capNhatThongKeNgayLamViec();
}

void MainWindow::capNhatCongThuCong()
{
    QString maNV = txtMaNhanVienNghi->text().trimmed();
    if (maNV.isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng nhập mã nhân viên cần sửa công.");
        return;
    }

    NhanVien *nv = congTy->timNhanVienTheoMaNV(maNV.toStdString());
    if (!nv) {
        QMessageBox::warning(this, "Không tìm thấy", "Không tìm thấy nhân viên có mã " + maNV + ".");
        return;
    }

    QDate ngay = dateSuaCongThuCong->date();
    if (!laNgayLamViec(ngay)) {
        QMessageBox::warning(this, "Ngày không hợp lệ", "Ngày được chọn là Chủ nhật. Ngày làm việc chính thức đang tính từ thứ 2 đến thứ 7.");
        return;
    }

    int thang = comboThangNgayLamViec->currentData().toInt();
    int nam = spinNamNgayLamViec->value();
    if (ngay.month() != thang || ngay.year() != nam) {
        QMessageBox::warning(this, "Sai tháng", "Ngày sửa công phải nằm trong tháng/năm đang thống kê.");
        return;
    }

    BanGhiChamCong cc;
    cc.maNhanVien = maNV;
    cc.hoTen = QString::fromStdString(nv->getHoTen());
    cc.ngay = ngay;
    cc.gioVao = "--";
    cc.gioRa = "--";
    cc.soGio = spinSoGioSuaCong->value();
    QString ghiChu = txtGhiChuSuaCong->text().trimmed();
    cc.trangThai = ghiChu.isEmpty() ? "Sửa thủ công" : "Sửa thủ công - " + ghiChu;

    int viTri = timBanGhiChamCongTheoNgay(maNV, ngay);
    if (viTri >= 0) {
        cc.maChamCong = dsChamCong[viTri].maChamCong;
        dsChamCong[viTri] = cc;
    } else {
        cc.maChamCong = "CC" + ngay.toString("yyyyMMdd") + "_MAN" + QString::number(demMaChamCong++).rightJustified(3, '0');
        dsChamCong.append(cc);
    }

    capNhatBangChamCong();
    capNhatThongKeNgayLamViec();
    QMessageBox::information(this, "Thành công", viTri >= 0 ? "Đã cập nhật công thủ công." : "Đã thêm công thủ công.");
}

void MainWindow::ghiNhanNgayNghi()
{
    QString maNV = txtMaNhanVienNghi->text().trimmed();
    if (maNV.isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng nhập mã nhân viên trước khi ghi nhận ngày nghỉ.");
        return;
    }

    NhanVien *nv = congTy->timNhanVienTheoMaNV(maNV.toStdString());
    if (!nv) {
        QMessageBox::warning(this, "Không tìm thấy", "Không tìm thấy nhân viên có mã " + maNV + ".");
        return;
    }

    QDate ngay = dateNgayNghi->date();
    if (!laNgayLamViec(ngay)) {
        QMessageBox::warning(this, "Ngày không hợp lệ", "Ngày được chọn là Chủ nhật. Ngày làm việc chính thức đang tính từ thứ 2 đến thứ 7.");
        return;
    }

    int thang = comboThangNgayLamViec->currentData().toInt();
    int nam = spinNamNgayLamViec->value();
    if (ngay.month() != thang || ngay.year() != nam) {
        QMessageBox::warning(this, "Sai tháng", "Ngày nghỉ phải nằm trong tháng/năm đang thống kê.");
        return;
    }

    BanGhiNgayNghi bg;
    bg.maNhanVien = maNV;
    bg.hoTen = QString::fromStdString(nv->getHoTen());
    bg.ngay = ngay;
    bg.trangThai = comboTrangThaiNghi->currentText();
    bg.lyDo = txtLyDoNghi->text().trimmed();
    if (bg.lyDo.isEmpty()) {
        bg.lyDo = bg.trangThai == "Nghỉ có phép" ? "Đã xin phép" : "Không có lý do";
    }

    bool daCapNhat = false;
    for (int i = 0; i < dsNgayNghi.size(); ++i) {
        if (dsNgayNghi[i].maNhanVien == maNV && dsNgayNghi[i].ngay == ngay) {
            dsNgayNghi[i] = bg;
            daCapNhat = true;
            break;
        }
    }
    if (!daCapNhat) {
        dsNgayNghi.append(bg);
    }

    capNhatThongKeNgayLamViec();
    QMessageBox::information(this, "Thành công", daCapNhat ? "Đã cập nhật ngày nghỉ." : "Đã ghi nhận ngày nghỉ.");
}

void MainWindow::lamMoiFormNgayNghi()
{
    txtMaNhanVienNghi->clear();
    txtLyDoNghi->clear();
    txtGhiChuSuaCong->clear();
    dateNgayNghi->setDate(QDate::currentDate());
    dateSuaCongThuCong->setDate(QDate::currentDate());
    spinSoGioSuaCong->setValue(8.0);
    comboTrangThaiNghi->setCurrentIndex(0);

    if (lblThongTinNhanVienNgayLamViec) {
        lblThongTinNhanVienNgayLamViec->setText("Nhập mã nhân viên để xem thống kê theo tháng.");
    }
    if (lblTongQuanNgayLamViec) {
        lblTongQuanNgayLamViec->setText("Chưa chọn nhân viên.");
    }
    if (lblChiTietNgayLamViec) {
        lblChiTietNgayLamViec->setText("Sau khi nhập mã nhân viên, bảng bên dưới sẽ hiển thị từng ngày làm việc trong tháng.");
    }
    if (tableNgayLamViec) tableNgayLamViec->setRowCount(0);
    if (tableChiTietNgayNghi) tableChiTietNgayNghi->setRowCount(0);
    txtMaNhanVienNghi->setFocus();
}

void MainWindow::capNhatThongKeNgayLamViec()
{
    if (!tableNgayLamViec || !tableChiTietNgayNghi) return;

    tableNgayLamViec->setRowCount(0);
    tableChiTietNgayNghi->setRowCount(0);

    int thang = comboThangNgayLamViec->currentData().toInt();
    int nam = spinNamNgayLamViec->value();
    int ngayChuan = soNgayLamViecChuanTrongThang(thang, nam);
    QDate ngayDau(nam, thang, 1);
    QDate ngayCuoi = ngayCuoiThongKeTrongThang(thang, nam);

    QString maNV = txtMaNhanVienNghi->text().trimmed();
    if (maNV.isEmpty()) {
        if (lblThongTinNhanVienNgayLamViec) {
            lblThongTinNhanVienNgayLamViec->setText("Nhập mã nhân viên để xem thống kê theo tháng.");
        }
        if (lblTongQuanNgayLamViec) {
            lblTongQuanNgayLamViec->setText(
                "Tháng " + QString::number(thang) + "/" + QString::number(nam) +
                " | Ngày làm việc chuẩn: " + QString::number(ngayChuan) +
                " | Chưa chọn nhân viên"
                );
        }
        if (lblChiTietNgayLamViec) {
            lblChiTietNgayLamViec->setText("Nhập mã nhân viên rồi bấm Tìm thống kê để xem chi tiết.");
        }
        return;
    }

    NhanVien *nv = congTy->timNhanVienTheoMaNV(maNV.toStdString());
    if (!nv) {
        if (lblThongTinNhanVienNgayLamViec) {
            lblThongTinNhanVienNgayLamViec->setText("Không tìm thấy nhân viên có mã: " + maNV);
        }
        if (lblTongQuanNgayLamViec) {
            lblTongQuanNgayLamViec->setText("Không có dữ liệu thống kê vì mã nhân viên không tồn tại.");
        }
        return;
    }

    QString hoTen = QString::fromStdString(nv->getHoTen());
    QString maPB = QString::fromStdString(nv->getMaPhongBan());
    QString chucVu = QString::fromStdString(nv->getChucVu());

    if (lblThongTinNhanVienNgayLamViec) {
        lblThongTinNhanVienNgayLamViec->setText(
            "Mã NV: " + maNV + "\n" +
            "Họ tên: " + hoTen + "\n" +
            "Phòng ban: " + maPB + "\n" +
            "Chức vụ: " + chucVu
            );
    }

    if (!ngayDau.isValid() || !ngayCuoi.isValid() || ngayCuoi < ngayDau) {
        lblTongQuanNgayLamViec->setText("Tháng được chọn chưa có ngày làm việc để thống kê.");
        return;
    }

    auto thuTrongTuan = [](const QDate &d) -> QString {
        switch (d.dayOfWeek()) {
        case 1: return "Thứ 2";
        case 2: return "Thứ 3";
        case 3: return "Thứ 4";
        case 4: return "Thứ 5";
        case 5: return "Thứ 6";
        case 6: return "Thứ 7";
        default: return "CN";
        }
    };

    QMap<QString, BanGhiChamCong> congTheoNgay;
    for (const BanGhiChamCong &cc : dsChamCong) {
        if (cc.maNhanVien == maNV && cc.ngay.month() == thang && cc.ngay.year() == nam && laNgayLamViec(cc.ngay)) {
            QString key = cc.ngay.toString("yyyyMMdd");
            if (congTheoNgay.contains(key)) {
                BanGhiChamCong old = congTheoNgay[key];
                old.soGio += cc.soGio;
                if (!cc.trangThai.trimmed().isEmpty()) old.trangThai += "; " + cc.trangThai;
                congTheoNgay[key] = old;
            } else {
                congTheoNgay[key] = cc;
            }
        }
    }

    QMap<QString, BanGhiNgayNghi> nghiTheoNgay;
    for (const BanGhiNgayNghi &nghi : dsNgayNghi) {
        if (nghi.maNhanVien == maNV && nghi.ngay.month() == thang && nghi.ngay.year() == nam && laNgayLamViec(nghi.ngay)) {
            nghiTheoNgay[nghi.ngay.toString("yyyyMMdd")] = nghi;
        }
    }

    int soNgayLam = 0;
    int soNghiPhep = 0;
    int soNghiKhongPhep = 0;
    double tongGioLam = 0.0;
    int row = 0;

    for (QDate cur = ngayDau; cur <= ngayCuoi; cur = cur.addDays(1)) {
        if (!laNgayLamViec(cur)) continue;

        QString key = cur.toString("yyyyMMdd");
        QString gioVao = "--";
        QString gioRa = "--";
        QString soGio = "0.00";
        QString trangThai = "Nghỉ không phép - Chưa có dữ liệu chấm công";

        if (congTheoNgay.contains(key)) {
            const BanGhiChamCong &cc = congTheoNgay[key];
            gioVao = cc.gioVao;
            gioRa = cc.gioRa;
            soGio = QString::number(cc.soGio, 'f', 2);
            trangThai = cc.trangThai.isEmpty() ? "Đã làm" : cc.trangThai;
            soNgayLam++;
            tongGioLam += cc.soGio;
        } else if (nghiTheoNgay.contains(key)) {
            const BanGhiNgayNghi &nghi = nghiTheoNgay[key];
            trangThai = nghi.trangThai;
            if (!nghi.lyDo.trimmed().isEmpty()) {
                trangThai += " - " + nghi.lyDo.trimmed();
            }
            if (nghi.trangThai == "Nghỉ có phép") soNghiPhep++;
            else soNghiKhongPhep++;
        } else {
            soNghiKhongPhep++;
        }

        tableNgayLamViec->insertRow(row);
        QStringList values = {
            QString::number(row + 1),
            cur.toString("dd/MM/yyyy"),
            thuTrongTuan(cur),
            gioVao,
            gioRa,
            soGio,
            trangThai
        };
        for (int col = 0; col < values.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(values[col]);
            if (col <= 5) item->setTextAlignment(Qt::AlignCenter);
            tableNgayLamViec->setItem(row, col, item);
        }
        ++row;
    }

    int soNgayCoThongTin = soNgayLam + soNghiPhep;
    QString danhGia = (soNgayCoThongTin >= ngayChuan && soNghiKhongPhep == 0) ? "Đủ công" : "Thiếu công";
    double gioTrungBinh = soNgayLam > 0 ? tongGioLam / soNgayLam : 0.0;

    lblTongQuanNgayLamViec->setText(
        "Tháng " + QString::number(thang) + "/" + QString::number(nam) +
        " | NV: " + maNV + " - " + hoTen +
        " | Ngày chuẩn: " + QString::number(ngayChuan) +
        " | Ngày làm: " + QString::number(soNgayLam) +
        " | Tổng giờ làm: " + QString::number(tongGioLam, 'f', 2) +
        " | TB/ngày: " + QString::number(gioTrungBinh, 'f', 2) +
        " | Nghỉ phép: " + QString::number(soNghiPhep) +
        " | Nghỉ không phép: " + QString::number(soNghiKhongPhep) +
        " | Đánh giá: " + danhGia
        );

    if (lblChiTietNgayLamViec) {
        lblChiTietNgayLamViec->setText(
            "Bảng chi tiết đang lấy dữ liệu chấm công từ tab Chấm công. "
            "Ngày nào chưa có chấm công hoặc chưa khai báo nghỉ sẽ được tính là nghỉ không phép."
            );
    }

    int rowNghi = 0;
    for (const BanGhiNgayNghi &nghi : dsNgayNghi) {
        if (nghi.maNhanVien != maNV || nghi.ngay.month() != thang || nghi.ngay.year() != nam) continue;

        tableChiTietNgayNghi->insertRow(rowNghi);
        QStringList values = {
            QString::number(rowNghi + 1),
            nghi.ngay.toString("dd/MM/yyyy"),
            thuTrongTuan(nghi.ngay),
            nghi.trangThai,
            nghi.lyDo
        };
        for (int col = 0; col < values.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(values[col]);
            if (col <= 3) item->setTextAlignment(Qt::AlignCenter);
            tableChiTietNgayNghi->setItem(rowNghi, col, item);
        }
        ++rowNghi;
    }
}
