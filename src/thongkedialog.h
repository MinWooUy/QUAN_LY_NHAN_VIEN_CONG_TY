#ifndef THONGKEDIALOG_H
#define THONGKEDIALOG_H

#include <QDialog>
#include <map>
#include <string>

namespace Ui {
class ThongKeDialog;
}

class ThongKeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThongKeDialog(QWidget *parent = nullptr);
    ~ThongKeDialog();
    void setDuLieu(double tongQuyLuong, std::map<std::string, double> thongKePB);
private:
    Ui::ThongKeDialog *ui;
};

#endif // THONGKEDIALOG_H
