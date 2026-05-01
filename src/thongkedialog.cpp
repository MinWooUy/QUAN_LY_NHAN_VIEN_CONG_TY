#include "thongkedialog.h"
#include "ui_thongkedialog.h"
#include <QLocale>

ThongKeDialog::ThongKeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ThongKeDialog)
{
    ui->setupUi(this);

    // Cài đặt cấu hình mặc định cho bảng thống kê
    ui->tableThongKe->setColumnCount(2);
    ui->tableThongKe->setHorizontalHeaderLabels({"Mã Phòng Ban", "Tổng Lương Cần Trả"});

    // Căn đều các cột và ẩn cột số thứ tự bên trái cho gọn
    ui->tableThongKe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableThongKe->verticalHeader()->setVisible(false);
}

ThongKeDialog::~ThongKeDialog()
{
    delete ui;
}

void ThongKeDialog::setDuLieu(double tongQuyLuong, std::map<std::string, double> thongKePB)
{
    //Cấu hình định dạng tiền tệ VNĐ
    QLocale vnLocale(QLocale::Vietnamese, QLocale::Vietnam);

    QString strTong = vnLocale.toCurrencyString(tongQuyLuong, "VNĐ");
    ui->lblTongQuyLuong->setText("Tổng quỹ lương toàn công ty: " + strTong);

    ui->tableThongKe->setRowCount(0); // Xóa rác cũ trước khi đổ
    int row = 0;

    for (auto const& pair : thongKePB) {
        ui->tableThongKe->insertRow(row);

        // Cột 0: Mã Phòng Ban (Lấy từ Key của Map)
        QString maPB = QString::fromStdString(pair.first);
        QTableWidgetItem* itemMaPB = new QTableWidgetItem(maPB);
        itemMaPB->setTextAlignment(Qt::AlignCenter); // Căn giữa
        ui->tableThongKe->setItem(row, 0, itemMaPB);

        // Cột 1: Tiền lương của phòng ban đó (Lấy từ Value của Map)
        QString luongPB = vnLocale.toCurrencyString(pair.second, "VNĐ");
        QTableWidgetItem* itemLuong = new QTableWidgetItem(luongPB);
        itemLuong->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // Căn phải cho số tiền
        ui->tableThongKe->setItem(row, 1, itemLuong);

        row++;
    }
}
