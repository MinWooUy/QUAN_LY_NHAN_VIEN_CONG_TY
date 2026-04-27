#ifndef THEMNHANVIENDIALOG_H
#define THEMNHANVIENDIALOG_H

#include <QDialog>
#include "NhanVien.h"

namespace Ui {
class ThemNhanVienDialog;
}

class ThemNhanVienDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThemNhanVienDialog(QWidget *parent = nullptr);
    ~ThemNhanVienDialog();
    NhanVien* LayThongTinNhanVien();
    void setThongTinNhanVien(NhanVien* nv);
private:
    Ui::ThemNhanVienDialog *ui;
};

#endif // THEMNHANVIENDIALOG_H
