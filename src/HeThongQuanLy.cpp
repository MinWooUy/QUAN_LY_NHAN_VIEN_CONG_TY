#include "HeThongQuanLy.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

HeThongQuanLy::HeThongQuanLy() {
}

void HeThongQuanLy::themNhanVien(const NhanVien& nv) {
    dsNhanVien.push_back(nv);
}

void HeThongQuanLy::themPhongBan(const PhongBan& pb) {
    dsPhongBan.push_back(pb);
}

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

        dsNhanVien.push_back(nv);
        soLuongDaLoad++;
    }

    file.close();
    cout << "Da load " << soLuongDaLoad << " nhan vien tu file." << endl;
}