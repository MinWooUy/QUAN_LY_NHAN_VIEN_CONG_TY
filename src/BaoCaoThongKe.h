#ifndef BAOCAOTHONGKE_H
#define BAOCAOTHONGKE_H

#include "QuanLyCongTy.h"
#include <map>
using namespace std;
class BaoCaoThongKe{
private:
    QuanLyCongTy* congTy;
public:
    BaoCaoThongKe(QuanLyCongTy* cty);

    double tinhTongQuyLuong();
    map<string, double> thongKePhongBan();
};

#endif // BAOCAOTHONGKE_H
