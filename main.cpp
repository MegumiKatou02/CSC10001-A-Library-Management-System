#include <iostream>

using namespace std;

void intro() {
	cout << "Phan mem quan ly thu vien." << endl;
	cout << "viet boi anh ching dep trai va em duy gai alime nup gam giuong." << endl;
}

int main_menu() {

	// hien thong tin lua chon len man hinh
	cout << "Nhap vao lua chon ma ban muon thuc hien:" << endl;
	cout << "     1. Quan ly doc gia" << endl;
	cout << "     2. Quan ly sach" << endl;
	cout << "     3. Lap phieu muon sach" << endl;
	cout << "     4. Lap phieu tra sach" << endl;
	cout << "     5. Thong ke" << endl;
	cout << "     6. Thoat" << endl;

	// xu ly lenh cua nguoi dung 
	int option;
	cin >> option;
	while (option < 1 || option > 6) {
		cout << "Lenh khong hop le, vui long nhap lai: ";
		cin >> option;
	}
	return option; 
}

void reader_management(int option) {

}

void quan_ly_sach(int option) {

	/*	b.Thêm sách
		c.Chỉnh sửa thông tin một quyển sách
		d.Xóa thông tin sách
		e.Tìm kiếm sách theo ISBN
		f.Tìm kiếm sách theo tên sác*/
}

void lap_phieu_mua_sach() {}

void lap_phieu_tra_sach() {}

void thong_ke() {}

int main() {
	intro();

	int option; // lua chon o main menu
	int choice;	// lua chon ben trong <(")

	while (option = main_menu()) {
		// system("cls");
		switch (option) {
		case 1: {
			cout << "Nhap vao lua chon ma ban muon thuc hien:" << endl;
			cout << "     1. Xem danh sach doc gia trong thu vien " << endl;
			cout << "     2. Chinh sua thong tin doc gia " << endl;
			cout << "     3. Xoa thong tin doc gia" << endl;
			cout << "     4. tim kiem doc gia theo CMND " << endl;
			cout << "     5. Tim kiem doc gia theo ho ten " << endl;
			cin >> choice;
			// system("cls");
			reader_management(option);
			break;
		}
		case 2: 
		{
			int choice;
			cout << "Nhap vao lua chon ma ban muon thuc hien:" << endl;
			cout << "     1. Them sach " << endl;
			cout << "     2. Xoa thong tin sach " << endl;
			cout << "     3. chinh sua thong tin sach" << endl;
			cout << "     4. tim kiem sach theo ISBN" << endl;
			cout << "     5. Tim kiem sach theo ten sach" << endl;
			cin >> choice;
			while (choice < 1 || choice > 6)
			{
				cout << "Vui long chon lua chon phu hop";
			}

		}
		case 3: lap_phieu_mua_sach();	break; // viet sau
		case 4: lap_phieu_tra_sach();	break; // viet sau
		case 5: thong_ke();				break; // viet sau
		case 6: return 0;
		default: break;

		}

		// nguoi dung co the chon tiep tuc cac thao tac khac hoac thoat chuong trinh
		char next;
		cout << "ban co muon thuc hien thao tac khac khong? (y/n):";
		cin >> next;
		while (toupper(next) != 'Y' && toupper(next) != 'N') {
			cout << "vui long nhap N hoac Y.";
			cin >> next;
		}
		if (toupper(next) == 'N')
			return 0;
	} 

	return 0;
}
