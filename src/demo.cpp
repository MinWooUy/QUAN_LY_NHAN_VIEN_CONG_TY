#include "LichLamViec.h"
#include "NhanVien.h"
#include <iostream>
using namespace std;

int main(){
    vector<LichLamViec> dsLich;
    LichLamViec l;
    l.loadLichLamViecTuFile("../data/taolich.txt", dsLich);

    for(int i = 0; i < dsLich.size(); i++){
        dsLich[i].hienThiThongTinLich();
    }
}