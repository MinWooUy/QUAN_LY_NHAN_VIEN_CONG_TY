#include "Menu.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

void inMenu(const Menu& m){
	cout << "0. Thoat!" << endl;
	cout << "1. Xuat Danh Sach Nhan Vien Cong Ty" << endl;
	cout << "2. Xuat Danh Sach Don Vi Cong Ty" << endl; 
	cout << "3. Xuat Thong Tin Nhan Vien Moi Don Vi" << endl;
	cout << "4. Them Nhan Vien Moi" << endl;
	cout << "5. Xoa Nhan Vien" << endl;
	cout << "6. Thay Doi Thong Tin Nhan Vien" << endl;
	cout << "Nhap lua chon: ";
}

// Lay Danh Sach Nhan Vien Hien Tai
vector<NhanVien*> Menu::getDsNhanVien(){
	return dsNhanVien;
}

// Tim Nhan Vien Theo Ma Nhan Vien
NhanVien* Menu::timNhanVienTheoMaNV(string ma){
	for(int i = 0; i < dsNhanVien.size(); i++){
		if(dsNhanVien[i]->getMaNhanVien() == ma){
			return dsNhanVien[i];
		}
	}		
	return nullptr;
}

// Phuong Thuc Xoa Danh Sach Cu [Phong Ban]
void Menu::XoaDanhSachPhongBan(){
	for(int i = 0; i < dsPhongBan.size(); i++){
		delete dsPhongBan[i];
	}
	dsPhongBan.clear();
}

void Menu::DocDanhSachPhongBan(string file){
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
void Menu::XoaDanhSachNhanVien(){
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

void Menu::DocDanhSachNhanVien(string file){
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
   		getline(ss, maPB, '|');

   		NhanVien* nv = new NhanVien(maNV, ten, nSinh, gTinh, sdt, mail, dc, cVu, nLam, maPB);

   		dsNhanVien.push_back(nv);
   		NhanVien::tangSiSo();
	}
	MyReadFile.close();
}

void Menu::XuatDanhSachNhanVienCongTy(){
	for(int i = 0; i < dsNhanVien.size(); i++){
		dsNhanVien[i]->hienThiThongTin();
	}
} 

void Menu::XuatDanhSachDonViCongTy(){
	cout << left << setw(20) << "Ma Don Vi" << left << setw(20) << "Ten Don Vi" << endl;
	for(int i = 0; i < dsPhongBan.size(); i++){
		dsPhongBan[i]->hienThiDanhSachPhongBan();
	}
	cout << endl;
}

void Menu::PhanBoNhanVienVaoPhongBan(){
	for(int i = 0 ; i < dsPhongBan.size(); i++){
		for(int j = 0; j < dsNhanVien.size(); j++)
			dsPhongBan[i]->themNhanVienVaoPhongBan(dsNhanVien[j]);
	}
}

void Menu::XuatThongTinNhanVienMoiDonVi(){
	for(int i = 0; i < dsPhongBan.size(); i++){
		dsPhongBan[i]->hienThiNhanVienTrongPB();
	}
}

void Menu::ThemNhanVienVaoPhongBan(NhanVien* nv){
	for(int i = 0; i < dsPhongBan.size(); i++){
		dsPhongBan[i]->themNhanVienVaoPhongBan(nv);
	}
}

NhanVien* Menu::ThemNhanVienVaoDanhSachCongTy(){
	NhanVien* nv = new NhanVien();
	nv->nhapThongTin();
	dsNhanVien.push_back(nv);
	return nv;
}

void Menu::XoaNhanVienKhoiDanhSachCongTy(string maNV){
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

void Menu::run(){
	int luaChon;
	// Doc File 1 Lan Duy Nhat Khi Bat Dau Chay
	DocDanhSachNhanVien("ThongTinNhanVien.txt");
	DocDanhSachPhongBan("ThongTinPhongBan.txt");
	PhanBoNhanVienVaoPhongBan();
	
	do{
		inMenu(*this);
		if(!(cin >> luaChon)){
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		cin.ignore();
				
		switch(luaChon){
			case 0: cout << "Ket Thuc Chuong Trinh!" << endl; break;
			case 1:{
				XuatDanhSachNhanVienCongTy();
				break;
			}
			case 2:{
				XuatDanhSachDonViCongTy();
				break;
			}
			case 3:{
				XuatThongTinNhanVienMoiDonVi();
				break;
			}
			case 4:{
				NhanVien* nv = ThemNhanVienVaoDanhSachCongTy();
				ThemNhanVienVaoPhongBan(nv);
				break;
			}
			case 5:{
				string maNV; cout << "Nhap ma nhan vien muon xoa: "; getline(cin, maNV);
				XoaNhanVienKhoiDanhSachCongTy(maNV);
				break;
			}
			default:{
				cout << "Chon Lai! Khong hop le." << endl;
				break;
			}
		}	
	}while(luaChon != 0);
}

// Khi dinh nghia ham Friend khong dung Menu::
ostream& operator<<(ostream &os, Menu& m){
	m.run();
	return os;
}
