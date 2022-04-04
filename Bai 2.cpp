//Câu 2: Xây d?ng l?p giáo viên GV g?m các thu?c tính h? tên ht(ki?u char[30]),
//tu?i t(ki?u s? nguyên), b?ng c?p cao nh?t du?c dào t?o bc(ki?u char[15]), chuyên ngành(ki?u char[20]),
//b?c luong bl(ki?u float) là các thu?c tính riêng.Trong l?p có d?nh nghia các hàm công c?ng sau :
//-Hàm toán t? nh?p >> di v?i cin d? nh?p d? li?u cho các thông tin trên c?a 1 giáo viên
//- Hàm toán t? xu?t << di v?i cout d? xu?t các thông tin trên c?a giáo viên ra màn hình
//- Hàm tính ti?n luong co b?n lcb bi?t r?ng lcb = bl * 610
//- Hàm toán t? “ == ”so sánh 2 GV, 2 giáo viên b?ng nhau n?u có b?ng c?p cao nh?t gi?ng nhau
//Vi?t chuong trình nh?p vào n(n nguyên duong nh?p t? bàn phím) giáo viên.In ra màn hình :
//-Danh sách giáo viên s?p x?p theo b?ng c?p.
#include<iostream>
#include<iomanip>
using namespace std;

class giaovien {
private:
	char ht[30];
	char cn[20];
	char bc[15];
	int tuoi;
	float bl;
	float  lcb;
	int bac;

public:
	friend istream& operator >>(istream& nhap, giaovien& a) {
		nhap.ignore();
		cout << "Nhap ho ten: "; nhap.getline(a.ht, 30);
		cout << "\nNhap chuyen nganh: "; nhap.getline(a.cn, 20);
		cout << "\nNhap bang cap: "; nhap.getline(a.bc, 15);
		cout << "\nNhap bac luong: "; nhap >> a.bl;
		cout << "\nNhap tuoi: "; nhap >> a.tuoi;

		//	a.lcb = a.bl * 610;
		return nhap;
	}

	void tt() {


		lcb = bl * 610;

		cout << lcb << endl;
	}
	friend ostream& operator<<(ostream& xuat, giaovien a) {
		xuat << "- Ho ten: " << a.ht << endl;
		xuat << "-Chuyen nganh: " << a.cn << endl;
		xuat << "-Bang cap: " << a.bc << endl;
		xuat << "-Bac luong: " << a.bl << endl;
		xuat << "-Luong co ban: " << a.lcb << endl;

		return xuat;
	}





	

		
	friend void xuat(giaovien a[],int n) {
		for (int i = 0; i < n; i++) {
			cout << "- Ho ten: " << a[i].ht << endl
				<< "Tuoi: " << a[i].tuoi << endl
				<< "-Bang cap: " << a[i].bc << endl
				<< "-Bac luong: " << a[i].bl << endl
				<< "-Luong co ban: " << a[i].lcb << endl;
		}

	}



};


int main() {
	int n;
	cout << "Nhap so luong giao vien: "; cin >> n;
	giaovien a[100];



	for (int i = 0; i < n; i++) {


		cin >> a[i];
		cout << "\nLuong co ban: "; a[i].tt();

	}
	cout << "\n========XUAT THONG TIN===========" << endl;
	for (int i = 0; i < n; i++) {
		cout << "\n thong tin giao vien thu " << i + 1 << endl;
		cout << a[i];

	}
	cout << "\n========Sap xep =====" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].lcb > a[j].lcb) {
				giaovien tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}
for (int i = 0; i < n; i++) {
	cout << a[i];
}


	system("pause");
	return 0;
}