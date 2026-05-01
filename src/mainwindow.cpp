#include "mainwindow.h"
#include "themnhanviendialog.h"
#include "thongkedialog.h"
#include "phongbancard.h"
#include "BaoCaoThongKe.h"
#include <QGridLayout>
#include <QInputDialog>
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QLocale>

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

