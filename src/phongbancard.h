#ifndef PHONGBANCARD_H
#define PHONGBANCARD_H

#include <QWidget>
#include "PhongBan.h"

namespace Ui {
class PhongBanCard;
}

class PhongBanCard : public QWidget
{
    Q_OBJECT

public:
    explicit PhongBanCard(QWidget *parent = nullptr);
    ~PhongBanCard();

    void setData(PhongBan* pb);
signals: // Tín hiệu tự tạo để báo cho MainWindow biết thẻ nào vừa bị click
    void xemChiTietClicked(QString maPhongBan);

private slots:
    void on_btnChiTiet_clicked();

private:
    Ui::PhongBanCard *ui;
    QString mMaPhongBan; // Lưu mã phòng để truyền ra ngoai
};

#endif // PHONGBANCARD_H
