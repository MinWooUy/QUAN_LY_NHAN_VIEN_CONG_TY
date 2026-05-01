#include "BaoCaoThongKe.h"

BaoCaoThongKe::BaoCaoThongKe(QuanLyCongTy* cty){
    this->congTy = cty;
};

double BaoCaoThongKe::tinhTongQuyLuong(){
    if(congTy == nullptr) return 0.0;

    double tongQuyLuong = 0;
    vector<NhanVien*> dsNhanVien = congTy->getDsNhanVien();

    for(int i = 0; i < dsNhanVien.size(); i++){
        tongQuyLuong += dsNhanVien[i]->tinhLuong();
    }

    return tongQuyLuong;
}

// Thống kê quỹ lương cần trả cho từng phòng ban
map<string, double> BaoCaoThongKe::thongKePhongBan() {
    map<string, double> thongKe;

    if (congTy == nullptr) {
        return thongKe;
    }

    vector<NhanVien*> dsNV = congTy->getDsNhanVien();

    for (NhanVien* nv : dsNV) {
        string maPB = nv->getMaPhongBan();
        double luong = nv->tinhLuong();

        // Map trong C++:
        // Nếu maPB chưa có, nó tự tạo mới với giá trị 0 rồi cộng luong vào.
        // Nếu maPB đã có, nó tự động cộng dồn luong vào quỹ hiện tại.
        thongKe[maPB] += luong;
    }

    return thongKe;
}
