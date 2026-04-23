#include "Menu.h"

int main() {
    string file_path = "../data/nhan_vien_test.txt";

    Menu m;
    m.init(file_path);
    m.menu();
    return 0;
}