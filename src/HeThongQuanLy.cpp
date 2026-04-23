#include "HeThongQuanLy.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

HeThongQuanLy::HeThongQuanLy() {
    
 ghiCSVTuTXT("../data/nhan_vien_test.txt", "../data/nhan_vien.csv");

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
    if (tonTaiMaPhongBan(pb.getMaPhongBan())) {
        cout << "Ma phong ban da ton tai. Khong the them.\n";
        return;
    }

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

bool HeThongQuanLy::tonTaiMaPhongBan(const string& maPhongBan) {
    return timViTriPhongBanTheoMa(maPhongBan) != -1;
}

int HeThongQuanLy::timViTriPhongBanTheoMa(const string& maPhongBan) {
    for (int i = 0; i < dsPhongBan.size(); i++) {
        if (dsPhongBan[i].getMaPhongBan() == maPhongBan) {
            return i;
        }
    }
    return -1;
}

void HeThongQuanLy::hienThiPhongBanTheoMa(const string& maPhongBan) {
    int viTri = timViTriPhongBanTheoMa(maPhongBan);

    if (viTri == -1) {
        cout << "Khong tim thay phong ban co ma: " << maPhongBan << endl;
        return;
    }

    cout << "\nThong tin phong ban tim duoc:\n";
    dsPhongBan[viTri].hienThiThongTin();
}

bool HeThongQuanLy::xoaPhongBanTheoMa(const string& maPhongBan) {
    int viTri = timViTriPhongBanTheoMa(maPhongBan);

    if (viTri == -1) {
        return false;
    }

    dsPhongBan.erase(dsPhongBan.begin() + viTri);
    return true;
}

bool HeThongQuanLy::suaPhongBanTheoMa(const string& maPhongBan) {
    int viTri = timViTriPhongBanTheoMa(maPhongBan);

    if (viTri == -1) {
        return false;
    }

    dsPhongBan[viTri].capNhatThongTin();
    return true;
}

PhongBan* HeThongQuanLy::layPhongBanTheoMa(const string& maPhongBan) {
    int viTri = timViTriPhongBanTheoMa(maPhongBan);

    if (viTri == -1) {
        return nullptr;
    }

    return &dsPhongBan[viTri];
}

const vector<PhongBan>& HeThongQuanLy::layDanhSachPhongBan() const {
    return dsPhongBan;
}

bool HeThongQuanLy::capNhatPhongBanTheoMa(
    const string& maPhongBan,
    const string& tenPhongBan,
    const string& truongPhong,
    int soLuongNhanVien
) {
    PhongBan* pb = layPhongBanTheoMa(maPhongBan);

    if (pb == nullptr) {
        return false;
    }

    pb->setTenPhongBan(tenPhongBan);
    pb->setTruongPhong(truongPhong);
    pb->setSoLuongNhanVien(soLuongNhanVien);

    return true;
}

//------------------------------------------------------------//
//                         OBJECT CHAMCONG                    //
//------------------------------------------------------------//

int HeThongQuanLy::timViTriChamCongTheoMa(const string& maChamCong) {
    for (int i = 0; i < dsChamCong.size(); i++) {
        if (dsChamCong[i].getMaChamCong() == maChamCong) {
            return i;
        }
    }
    return -1;
}

bool HeThongQuanLy::tonTaiMaChamCong(const string& maChamCong) {
    return timViTriChamCongTheoMa(maChamCong) != -1;
}

ChamCong* HeThongQuanLy::layChamCongTheoMa(const string& maChamCong) {
    int viTri = timViTriChamCongTheoMa(maChamCong);

    if (viTri == -1) {
        return nullptr;
    }

    return &dsChamCong[viTri];
}

const vector<ChamCong>& HeThongQuanLy::layDanhSachChamCong() const {
    return dsChamCong;
}

void HeThongQuanLy::themChamCong(const ChamCong& cc) {
    if (tonTaiMaChamCong(cc.getMaChamCong())) {
        cout << "Ma cham cong da ton tai. Khong the them.\n";
        return;
    }

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

void HeThongQuanLy::hienThiChamCongTheoMa(const string& maChamCong) {
    int viTri = timViTriChamCongTheoMa(maChamCong);

    if (viTri == -1) {
        cout << "Khong tim thay cham cong co ma: " << maChamCong << endl;
        return;
    }

    cout << "\nThong tin cham cong tim duoc:\n";
    dsChamCong[viTri].hienThiThongTin();
}

bool HeThongQuanLy::xoaChamCongTheoMa(const string& maChamCong) {
    int viTri = timViTriChamCongTheoMa(maChamCong);

    if (viTri == -1) {
        return false;
    }

    dsChamCong.erase(dsChamCong.begin() + viTri);
    return true;
}

bool HeThongQuanLy::suaChamCongTheoMa(const string& maChamCong) {
    int viTri = timViTriChamCongTheoMa(maChamCong);

    if (viTri == -1) {
        return false;
    }

    dsChamCong[viTri].capNhatThongTin();
    return true;
}

bool HeThongQuanLy::capNhatChamCongTheoMa(
    const string& maChamCong,
    const string& maNhanVien,
    const string& ngayLamViec,
    const string& gioVao,
    const string& gioRa,
    const string& trangThaiChamCong,
    double soGioLam,
    const string& ghiChu
) {
    ChamCong* cc = layChamCongTheoMa(maChamCong);

    if (cc == nullptr) {
        return false;
    }

    cc->setMaNhanVien(maNhanVien);
    cc->setNgayLamViec(ngayLamViec);
    cc->setGioVao(gioVao);
    cc->setGioRa(gioRa);
    cc->setTrangThaiChamCong(trangThaiChamCong);
    cc->setSoGioLam(soGioLam);
    cc->setGhiChu(ghiChu);

    return true;
}

//------------------------------------------------------------//
//                      OBJECT DONXINNGHI                     //
//------------------------------------------------------------//

int HeThongQuanLy::timViTriDonXinNghiTheoMa(const string& maDonNghi) {
    for (int i = 0; i < dsDonXinNghi.size(); i++) {
        if (dsDonXinNghi[i].getMaDonNghi() == maDonNghi) {
            return i;
        }
    }
    return -1;
}

bool HeThongQuanLy::tonTaiMaDonXinNghi(const string& maDonNghi) {
    return timViTriDonXinNghiTheoMa(maDonNghi) != -1;
}

DonXinNghi* HeThongQuanLy::layDonXinNghiTheoMa(const string& maDonNghi) {
    int viTri = timViTriDonXinNghiTheoMa(maDonNghi);

    if (viTri == -1) {
        return nullptr;
    }

    return &dsDonXinNghi[viTri];
}

const vector<DonXinNghi>& HeThongQuanLy::layDanhSachDonXinNghi() const {
    return dsDonXinNghi;
}

void HeThongQuanLy::themDonXinNghi(const DonXinNghi& dxn) {
    if (tonTaiMaDonXinNghi(dxn.getMaDonNghi())) {
        cout << "Ma don xin nghi da ton tai. Khong the them.\n";
        return;
    }

    dsDonXinNghi.push_back(dxn);
}

void HeThongQuanLy::hienThiDanhSachDonXinNghi() {
    if (dsDonXinNghi.empty()) {
        cout << "Danh sach don xin nghi dang rong." << endl;
        return;
    }

    cout << "\n===== DANH SACH DON XIN NGHI =====" << endl;
    for (int i = 0; i < dsDonXinNghi.size(); i++) {
        cout << "\nDon xin nghi thu " << i + 1 << ":" << endl;
        dsDonXinNghi[i].hienThiThongTin();
    }
}

void HeThongQuanLy::hienThiDonXinNghiTheoMa(const string& maDonNghi) {
    int viTri = timViTriDonXinNghiTheoMa(maDonNghi);

    if (viTri == -1) {
        cout << "Khong tim thay don xin nghi co ma: " << maDonNghi << endl;
        return;
    }

    cout << "\nThong tin don xin nghi tim duoc:\n";
    dsDonXinNghi[viTri].hienThiThongTin();
}

bool HeThongQuanLy::xoaDonXinNghiTheoMa(const string& maDonNghi) {
    int viTri = timViTriDonXinNghiTheoMa(maDonNghi);

    if (viTri == -1) {
        return false;
    }

    dsDonXinNghi.erase(dsDonXinNghi.begin() + viTri);
    return true;
}

bool HeThongQuanLy::suaDonXinNghiTheoMa(const string& maDonNghi) {
    int viTri = timViTriDonXinNghiTheoMa(maDonNghi);

    if (viTri == -1) {
        return false;
    }

    dsDonXinNghi[viTri].capNhatThongTin();
    return true;
}

bool HeThongQuanLy::capNhatDonXinNghiTheoMa(
    const string& maDonNghi,
    const string& maNhanVien,
    const string& loaiNghi,
    const string& ngayBatDau,
    const string& ngayKetThuc,
    const string& lyDo,
    const string& trangThaiDuyet,
    const string& nguoiDuyet
) {
    DonXinNghi* dxn = layDonXinNghiTheoMa(maDonNghi);

    if (dxn == nullptr) {
        return false;
    }

    dxn->setMaNhanVien(maNhanVien);
    dxn->setLoaiNghi(loaiNghi);
    dxn->setNgayBatDau(ngayBatDau);
    dxn->setNgayKetThuc(ngayKetThuc);
    dxn->setLyDo(lyDo);
    dxn->setTrangThaiDuyet(trangThaiDuyet);
    dxn->setNguoiDuyet(nguoiDuyet);

    return true;
}