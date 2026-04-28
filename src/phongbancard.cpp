#include "phongbancard.h"
#include "ui_phongbancard.h"

PhongBanCard::PhongBanCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PhongBanCard)
{
    ui->setupUi(this);
}

PhongBanCard::~PhongBanCard()
{
    delete ui;
}

void PhongBanCard::setData(PhongBan* pb){
    if(!pb) return;

    mMaPhongBan = QString::fromStdString(pb->getMaPhongBan());
    ui->lblTenPhong->setText(QString::fromStdString(pb->getTenPhongBan()));
    ui->lblMaPhong->setText(mMaPhongBan);

    // Kiểm tra có trưởng phòng không
    NhanVien* tp = pb->getTruongPhong();
    if(tp != nullptr){
        ui->lblTruongPhong->setText(QString::fromStdString(pb->getTruongPhong()->getHoTen()));
    }else{
        ui->lblTruongPhong->setText("Chưa bổ nhiệm");
    }

    // Lấy sỉ số
    int siso = pb->getDsNhanVienTrongPhong().size();
    ui->lblSiSo->setText(QString::number(siso) + " nhân viên");
}



void PhongBanCard::on_btnChiTiet_clicked()
{
    // Phát tín hiệu ra ngoài, mang theo mã phòng ban
    emit xemChiTietClicked(mMaPhongBan);
}
