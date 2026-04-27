#include "PhongBan.h"
using namespace std;

int PhongBan::soLuongNhanVienTrongPhong = 0;
int PhongBan::soLuongPhongBan = 0;

PhongBan::PhongBan(string ma, string ten, NhanVien* tp){
	this->maPhongBan = ma;
	this->tenPhongBan = ten;
	this->truongPhong = tp;
	tangSoLuongPB();
}

int PhongBan::getSoLuongNhanVien(){
	return soLuongNhanVienTrongPhong;
}

void PhongBan::tangSoLuongNV(){
	soLuongNhanVienTrongPhong++;
}

void PhongBan::giamSoLuongNV(){
	soLuongNhanVienTrongPhong--;
}

void PhongBan::tangSoLuongPB(){
	soLuongPhongBan++;
}

void PhongBan::giamSoLuongPB(){
	soLuongPhongBan--;
}

string PhongBan::getMaPhongBan() const {
    return maPhongBan;
}

string PhongBan::getTenPhongBan() const {
    return tenPhongBan;
}

NhanVien* PhongBan::getTruongPhong() const {
    return truongPhong;
}

void PhongBan::setTruongPhong(NhanVien* truongPhong) {
    this->truongPhong = truongPhong;
}

void PhongBan::themNhanVienVaoPhongBan(NhanVien* nv){
	if (nv == nullptr) return;
	
	if(this->maPhongBan == nv->getMaPhongBan()){
		dsNhanVienTrongPhong.push_back(nv);
		this->tangSoLuongNV();
	}	
}

void PhongBan::xoaTungPhongBan(){
	this->dsNhanVienTrongPhong.clear();
	this->truongPhong = nullptr;
	this->soLuongNhanVienTrongPhong = 0;
}

void PhongBan::xoaNhanVienPhongBan(NhanVien* nv){
	if(nv == nullptr) return;
	
	if(this->truongPhong == nv){
		this->truongPhong = nullptr;
	}
	
	for(int i = 0; i < dsNhanVienTrongPhong.size(); i++){
		if(nv == dsNhanVienTrongPhong[i]){
			dsNhanVienTrongPhong.erase(dsNhanVienTrongPhong.begin() + i);
			giamSoLuongNV();
			break;
		}
	}
}

vector<NhanVien*> PhongBan::getDsNhanVienTrongPhong() const { return dsNhanVienTrongPhong; }
