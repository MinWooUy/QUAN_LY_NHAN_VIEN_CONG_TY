#include "HeThongQuanLy.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

HeThongQuanLy::HeThongQuanLy() {
}

//------------------------------------------------------------//
//                        THONG TIN TONG QUAN                 //
//------------------------------------------------------------//

void HeThongQuanLy::hienThiThongTinTongQuan() {
    cout << "He thong da khoi tao thanh cong." << endl;
    cout << "So luong nhan vien: " << dsNhanVien.size() << endl;
    cout << "So luong phong ban: " << dsPhongBan.size() << endl;
    cout << "So luong cham cong: " << dsChamCong.size() << endl;
    cout << "So luong lich lam viec: " << dsLichLamViec.size() << endl;
    cout << "So luong don xin nghi: " << dsDonXinNghi.size() << endl;
    cout << "So luong quan ly: " << dsQuanLy.size() << endl;
    cout << "So luong bao cao cong: " << dsBaoCaoCong.size() << endl;
}

//------------------------------------------------------------//
//                         OBJECT NHANVIEN                    //
//------------------------------------------------------------//

int HeThongQuanLy::timViTriNhanVienTheoMa(const string& maNhanVien) {
    for (int i = 0; i < dsNhanVien.size(); i++) {
        if (dsNhanVien[i].getMaNhanVien() == maNhanVien) {
            return i;
        }
    }
    return -1;
}

bool HeThongQuanLy::tonTaiMaNhanVien(const string& maNhanVien) {
    return timViTriNhanVienTheoMa(maNhanVien) != -1;
}

void HeThongQuanLy::themNhanVien(const NhanVien& nv) {
    if (tonTaiMaNhanVien(nv.getMaNhanVien())) {
        cout << "Ma nhan vien da ton tai. Khong the them.\n";
        return;
    }

    dsNhanVien.push_back(nv);
}

void HeThongQuanLy::loadNhanVienTuFile(const string& tenFile) {
    ifstream file(tenFile);

    if (!file.is_open()) {
        cout << "Khong mo duoc file: " << tenFile << endl;
        return;
    }

    string line;
    int soLuongDaLoad = 0;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        if (line[0] == '#') {
            continue;
        }

        stringstream ss(line);
        vector<string> parts;
        string part;

        while (getline(ss, part, '|')) {
            parts.push_back(part);
        }

        if (parts.size() != 10) {
            continue;
        }

        NhanVien nv(
            parts[0],
            parts[1],
            parts[2],
            parts[3],
            parts[4],
            parts[5],
            parts[6],
            parts[7],
            parts[8],
            parts[9]
        );

        if (!tonTaiMaNhanVien(nv.getMaNhanVien())) {
            dsNhanVien.push_back(nv);
            soLuongDaLoad++;
        }
    }

    file.close();
    cout << "Da load " << soLuongDaLoad << " nhan vien tu file." << endl;
}

void HeThongQuanLy::hienThiDanhSachNhanVien() {
    if (dsNhanVien.empty()) {
        cout << "Danh sach nhan vien dang rong." << endl;
        return;
    }

    cout << "\n===== DANH SACH NHAN VIEN =====" << endl;
    for (int i = 0; i < dsNhanVien.size(); i++) {
        cout << "\nNhan vien thu " << i + 1 << ":" << endl;
        dsNhanVien[i].hienThiThongTin();
    }
}

void HeThongQuanLy::hienThiNhanVienTheoMa(const string& maNhanVien) {
    int viTri = timViTriNhanVienTheoMa(maNhanVien);

    if (viTri == -1) {
        cout << "Khong tim thay nhan vien co ma: " << maNhanVien << endl;
        return;
    }

    cout << "\nThong tin nhan vien tim duoc:\n";
    dsNhanVien[viTri].hienThiThongTin();
}

bool HeThongQuanLy::xoaNhanVienTheoMa(const string& maNhanVien) {
    int viTri = timViTriNhanVienTheoMa(maNhanVien);

    if (viTri == -1) {
        return false;
    }

    dsNhanVien.erase(dsNhanVien.begin() + viTri);
    return true;
}

bool HeThongQuanLy::suaNhanVienTheoMa(const string& maNhanVien) {
    int viTri = timViTriNhanVienTheoMa(maNhanVien);

    if (viTri == -1) {
        return false;
    }

    dsNhanVien[viTri].capNhatThongTin();
    return true;
}

NhanVien* HeThongQuanLy::layNhanVienTheoMa(const string& maNhanVien) {
    int viTri = timViTriNhanVienTheoMa(maNhanVien);

    if (viTri == -1) {
        return nullptr;
    }

    return &dsNhanVien[viTri];
}

const vector<NhanVien>& HeThongQuanLy::layDanhSachNhanVien() const {
    return dsNhanVien;
}

bool HeThongQuanLy::capNhatNhanVienTheoMa(
    const string& maNhanVien,
    const string& hoTen,
    const string& ngaySinh,
    const string& gioiTinh,
    const string& soDienThoai,
    const string& email,
    const string& diaChi,
    const string& chucVu,
    const string& ngayVaoLam,
    const string& maPhongBan
) {
    NhanVien* nv = layNhanVienTheoMa(maNhanVien);

    if (nv == nullptr) {
        return false;
    }

    nv->setHoTen(hoTen);
    nv->setNgaySinh(ngaySinh);
    nv->setGioiTinh(gioiTinh);
    nv->setSoDienThoai(soDienThoai);
    nv->setEmail(email);
    nv->setDiaChi(diaChi);
    nv->setChucVu(chucVu);
    nv->setNgayVaoLam(ngayVaoLam);
    nv->setMaPhongBan(maPhongBan);

    return true;
}

//------------------------------------------------------------//
//                         OBJECT PHONGBAN                    //
//------------------------------------------------------------//

void HeThongQuanLy::themPhongBan(const PhongBan& pb) {
    dsPhongBan.push_back(pb);
}

void HeThongQuanLy::hienThiDanhSachPhongBan() {
    if (dsPhongBan.empty()) {
        cout << "Danh sach phong ban dang rong." << endl;
        return;
    }

    cout << "\n===== DANH SACH PHONG BAN =====" << endl;
    for (int i = 0; i < dsPhongBan.size(); i++) {
        cout << "\nPhong ban thu " << i + 1 << ":" << endl;
        dsPhongBan[i].hienThiThongTin();
    }
}

//------------------------------------------------------------//
//                         OBJECT CHAMCONG                    //
//------------------------------------------------------------//

void HeThongQuanLy::themChamCong(const ChamCong& cc) {
    dsChamCong.push_back(cc);
}

void HeThongQuanLy::hienThiDanhSachChamCong() {
    if (dsChamCong.empty()) {
        cout << "Danh sach cham cong dang rong." << endl;
        return;
    }

    cout << "\n===== DANH SACH CHAM CONG =====" << endl;
    for (int i = 0; i < dsChamCong.size(); i++) {
        cout << "\nBan ghi cham cong thu " << i + 1 << ":" << endl;
        dsChamCong[i].hienThiThongTin();
    }
}

//------------------------------------------------------------//
//                       OBJECT LICHLAMVIEC                   //
//------------------------------------------------------------//

void HeThongQuanLy::themLichLamViec(const LichLamViec& llv) {
    dsLichLamViec.push_back(llv);
}

void HeThongQuanLy::hienThiDanhSachLichLamViec() {
    if (dsLichLamViec.empty()) {
        cout << "Danh sach lich lam viec dang rong." << endl;
        return;
    }

    cout << "\n===== DANH SACH LICH LAM VIEC =====" << endl;
    for (int i = 0; i < dsLichLamViec.size(); i++) {
        cout << "\nLich lam viec thu " << i + 1 << ":" << endl;
        dsLichLamViec[i].hienThiThongTin();
    }
}