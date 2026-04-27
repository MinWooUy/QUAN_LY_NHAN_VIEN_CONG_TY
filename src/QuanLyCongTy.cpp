#include "QuanLyCongTy.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


// Lay Danh Sach Nhan Vien Hien Tai
vector<NhanVien*> QuanLyCongTy::getDsNhanVien(){
    return dsNhanVien;
}

vector<PhongBan*> QuanLyCongTy::getDsPhongBan(){
    return dsPhongBan;
}

// Tim Nhan Vien Theo Ma Nhan Vien
NhanVien* QuanLyCongTy::timNhanVienTheoMaNV(string ma){
    for(int i = 0; i < dsNhanVien.size(); i++){
        if(dsNhanVien[i]->getMaNhanVien() == ma){
            return dsNhanVien[i];
        }
    }
    return nullptr;
}

// Phuong Thuc Xoa Danh Sach Cu [Phong Ban]
void QuanLyCongTy::XoaDanhSachPhongBan(){
    for(int i = 0; i < dsPhongBan.size(); i++){
        delete dsPhongBan[i];
    }
    dsPhongBan.clear();
}

void QuanLyCongTy::DocDanhSachPhongBan(string file){
    ifstream MyReadFile(file);
    if(!MyReadFile.is_open())
    {
        cout << "Khong mo duoc FILE Phong Ban!" << endl;
        return;
    }

    string myText;
    while(getline(MyReadFile, myText)){
        if(myText.empty()) continue;

        stringstream ss(myText);
        string maPB, tenPB, maTP;

        getline(ss, maPB, '|');
        getline(ss, tenPB, '|');
        getline(ss, maTP, '|');

        // Tim Truong Phong Theo Ma
        NhanVien* tp = timNhanVienTheoMaNV(maTP);

        // Tao Phong Ban
        PhongBan* pb = new PhongBan(maPB, tenPB, tp);

        // Them vao Danh Sach Phong Ban
        dsPhongBan.push_back(pb);
        PhongBan::tangSoLuongPB();
    }
    MyReadFile.close();
}

// Phuong Thuc Xoa Danh Sach Cu [Nhan Vien]
void QuanLyCongTy::XoaDanhSachNhanVien(){
    for(int i = 0; i < dsPhongBan.size(); i++){
        dsPhongBan[i]->xoaTungPhongBan();
    }

    for(int i = 0; i < dsNhanVien.size(); i++){
        if(dsNhanVien[i] != nullptr)
            delete dsNhanVien[i];
    }
    dsNhanVien.clear();
    NhanVien::resetSiSo();
    cout << "Da xoa toan bo danh sach nhan vien!" << endl;
}

void QuanLyCongTy::DocDanhSachNhanVien(string file){
    ifstream MyReadFile(file);
    if(!MyReadFile.is_open())
    {
        cout << "Khong mo duoc FILE Nhan Vien!" << endl;
        return;
    }

    string myText;
    while(getline(MyReadFile, myText)){
        if(myText.empty()) continue;

        stringstream ss(myText);
        string maNV, ten, nSinh, gTinh, sdt, mail, dc, cVu, nLam, maPB;

        getline(ss, maNV, '|');
        getline(ss, ten, '|');
        getline(ss, nSinh, '|');
        getline(ss, gTinh, '|');
        getline(ss, sdt, '|');
        getline(ss, mail, '|');
        getline(ss, dc, '|');
        getline(ss, cVu, '|');
        getline(ss, nLam, '|');
        getline(ss, maPB);

        NhanVien* nv = new NhanVien(maNV, ten, nSinh, gTinh, sdt, mail, dc, cVu, nLam, maPB);

        dsNhanVien.push_back(nv);
        NhanVien::tangSiSo();
    }
    MyReadFile.close();
}

void QuanLyCongTy::PhanBoNhanVienVaoPhongBan(){
    for(int i = 0 ; i < dsPhongBan.size(); i++){
        for(int j = 0; j < dsNhanVien.size(); j++)
            dsPhongBan[i]->themNhanVienVaoPhongBan(dsNhanVien[j]);
    }
}

void QuanLyCongTy::ThemNhanVienVaoPhongBan(NhanVien* nv){
    for(int i = 0; i < dsPhongBan.size(); i++){
        dsPhongBan[i]->themNhanVienVaoPhongBan(nv);
    }
}

void QuanLyCongTy::ThemNhanVienVaoDanhSachCongTy(NhanVien* nv) {
    if(nv != nullptr){
        dsNhanVien.push_back(nv);
        NhanVien::tangSiSo();
    }
}

void QuanLyCongTy::XoaNhanVienKhoiDanhSachCongTy(string maNV){
    NhanVien* nv = timNhanVienTheoMaNV(maNV);
    if(nv == nullptr){
        cout << "Khong ton tai nhan vien co ma: " << maNV;
        return;
    }

    for(int i = 0; i < dsPhongBan.size(); i++){
        if(dsPhongBan[i]->getMaPhongBan() == nv->getMaPhongBan()){
            dsPhongBan[i]->xoaNhanVienPhongBan(nv);
            break;
        }
    }

    for(int i = 0; i < dsNhanVien.size(); i++){
        if(nv == dsNhanVien[i]){
            dsNhanVien.erase(dsNhanVien.begin() + i);
            NhanVien::giamSiSo();
            break;
        }
    }

    cout << "Da xoa nhan vien " << maNV << " khoi he thong" << endl;
}

// Sắp xếp theo HEAP SORT
string formatDate(string dateStr){
    if(dateStr.empty()) return "";
    stringstream ss(dateStr);
    string d, m, y;

    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    if(d.length() == 1) d = "0" + d;
    if(m.length() == 1) m = "0" + m;

    return y + m + d; // YYYYMMDD (ngược lại để dễ sắp xếp)
}

void heapify(vector<NhanVien*>& dsNV, int l, int r, int selec, bool isAscending){
    int i = l, j = 2*i+1;
    while(j<=r){
        string valTarget = dsNV[i]->getOption(selec);
        string val1 = dsNV[j]->getOption(selec);

        if (selec == 2 || selec == 3) {
            valTarget = formatDate(valTarget);
            val1 = formatDate(val1);
        }

        if (j < r) {
            string val2 = dsNV[j+1]->getOption(selec);
            if (selec == 2 || selec == 3) val2 = formatDate(val2);

            // Nếu Max-Heap (tăng dần) thì rẽ nhánh tìm con lớn nhất
            if (isAscending && val1 < val2) j++;
            // Nếu Min-Heap (giảm dần) thì rẽ nhánh tìm con nhỏ nhất
            else if (!isAscending && val1 > val2) j++;
        }

        string valSelected = dsNV[j]->getOption(selec);
        if (selec == 2 || selec == 3) valSelected = formatDate(valSelected);

        if (isAscending) {
            if (valTarget >= valSelected) break; // Max-Heap
        } else {
            if (valTarget <= valSelected) break; // Min-Heap
        }

        // Nếu chưa thỏa mãn, hoán vị và tiếp tục
        swap(dsNV[i], dsNV[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void buildMaxHeap(vector<NhanVien*>& dsNV, int n, int selec, bool isAscending){
    int l = n/2-1;
    while(l>=0){
        heapify(dsNV,l,n-1, selec, isAscending);
        l--;
    }
}

void heapSort(vector<NhanVien*>& dsNV, int n, int selec, bool isAscending){
    int r = n-1;
    buildMaxHeap(dsNV, r, selec, isAscending);
    while(r > 0){
        swap(dsNV[0], dsNV[r]);
        r--;
        heapify(dsNV,0,r, selec, isAscending);
    }
}

void QuanLyCongTy::sapXepNhanVien(int selec, bool isAscending){
    if(dsNhanVien.empty()) return;
    heapSort(this->dsNhanVien, dsNhanVien.size(), selec, isAscending);
}

// Tìm kiếm
string toLowerStr(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

vector<NhanVien*> QuanLyCongTy::timKiemNhanVien(string keyword){
    vector<NhanVien*> ketQua;

    if(keyword.empty()) return dsNhanVien;

    for(int i = 0; i < dsNhanVien.size(); i++){
        string maNV = toLowerStr(dsNhanVien[i]->getMaNhanVien());
        string tenNV = toLowerStr(dsNhanVien[i]->getHoTen());

        if(maNV.find(keyword) != string::npos || tenNV.find(keyword) != string::npos)
            ketQua.push_back(dsNhanVien[i]);
    }
    return ketQua;
}

void QuanLyCongTy::LuuDanhSachNhanVien(string file){
    ofstream MyFile(file);
    if(MyFile.is_open()){
        for(int i = 0; i < dsNhanVien.size(); i++){

            MyFile << dsNhanVien[i]->getMaNhanVien() << "|"
                   << dsNhanVien[i]->getHoTen() << "|"
                   << dsNhanVien[i]->getNgaySinh() << "|"
                   << dsNhanVien[i]->getGioiTinh() << "|"
                   << dsNhanVien[i]->getSoDienThoai() << "|"
                   << dsNhanVien[i]->getEmail() << "|"
                   << dsNhanVien[i]->getDiaChi() << "|"
                   << dsNhanVien[i]->getChucVu() << "|"
                   << dsNhanVien[i]->getNgayVaoLam() << "|"
                   << dsNhanVien[i]->getMaPhongBan() << endl;
        }
        MyFile.close();
    }
}
