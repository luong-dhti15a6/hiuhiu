//Câu 4: Xây dựng một lớp đối tượng các máy in, lớp gồm có các thành phần :
//-Các thuộc tính số hiệu và số l¬ượng trong kho.
//- Hàm nhapkho(int q) để nhập vào kho q đơn vị mặt hàng.
//- Hàm xuatkho(int q) để xuất ra khỏi kho q đơn vị mặt hàng.
//Xây dựng lớp máy in laser kế thừa từ lớp máy in và có thêm thuộc tính dpi
//Xây dựng lớp máy in màu kế thừa từ lớp máy in có thêm thuộc tính bảng màu.
//Xây dựng lớp máy in laser màu kế thừa từ lớp máy in laser và máy in màu.
//Viết chư¬ơng trình hư¬ớng đối tượng quản lý các loại máy in với các thủ tục : 
//nhập, xuất và in ra số lư¬ợng các loại có trong kho.

#include<iostream>
using namespace std;
 
class mayin {
private:
	int sl;
	char sohieu[20];
public:
 void nhap() {
			cout << "\nNhap so luong trong kho: "; cin >>sl;
			cin.ignore();				
			cout << "\nNhap so hieu: "; cin.getline(sohieu, 20);
		
 }

	 void xuat() {
			cout << "\nSo luong trong kho: " << sl<<endl;
			cout << "\nSo hieu: " << sohieu << endl;
	 }

	};
class mayinls : public mayin {
private:
	int dpi;
public:
	 void nhap() {

		mayin::nhap( );
		cout << "\nNhap chi so DPI: "; cin >> dpi;
			
	 }
	 
	void xuat() {	
	
		mayin::xuat();
		cout << "\nChi so DPI la: " << dpi << endl;
		
	}
	void nhapdpi() {
		 cout << "\nNhap chi so DPI: "; cin >> dpi;
	}

	void xuatdpi() {
	cout << "\nNhap chi so DPI: "<< dpi<<endl;
	}

};
class mayinmau :public mayin {
private:
	int bangmau;
public:
	void nhap() {
		mayin::nhap();
		cout << "\nNhap chi so mau: "; cin >> bangmau;
	}
	
	void xuat() {
		mayin::xuat();
		cout << "\nSo mau: " << bangmau << endl;
	}
	void nhapmau() {
		cout << "\nNhap chi so mau: "; cin >> bangmau;
	}
	void xuatmau() {
		cout << "\nNhap chi so mau: "<< bangmau<<endl;
	}
};
class mayinlsmau : public mayinls, public mayinmau {
public:
	void nhap() {
		mayin::nhap();
		mayinls::nhapdpi();
		mayinmau::nhapmau();
	}
	void xuat() {
		mayin::xuat();
		mayinls::xuatdpi();
		mayinmau::xuatmau();
	}
};

int main() {

	int n;
	cout << "Nhap so luong may in: "; cin >> n;
	cin.ignore();
	mayin a[100];
	for (int i= 0;i<n;i++){
		cout << "Nhap du lieu may in " << i + 1 << endl;
	a[i].nhap();
	
	}
	for (int i = 0; i < n; i++) {
		cout << "Xuat du lieu may in " << i + 1 << endl;
		a[i].xuat();
	}
	cout << "\n======May in laser====" << endl;
	mayinls b[100];
	int m;
	cout << "Nhap so luong may in laser: "; cin >> m;
	for (int i = 0; i < m; i++) {
		cout << "Nhap du lieu cho may in laser " << i + 1 << endl;
		b[i].nhap();
		
	}
	for (int i = 0; i < m; i++) {
		cout << "Xuat du lieu may in laser " << i + 1 << endl;
		b[i].xuat();
	}
	cout << "\n===========May in mau ============" << endl;
	mayinmau c[100];
	int l;
	cout << "\nNhap so luong may in mau: "; cin >> l;
	for (int i = 0; i < l; i++) {
		cout << "Nhap du lieu cho may in mau thu " << i + 1 << endl;
		c[i].nhap();
	}

	for (int i = 0; i < l; i++) {
		cout << "\nXuat du lieu cho may in mau thu " << i + 1 << endl;
		c[i].xuat();
	}
	cout << "\n============May in laser mau============" << endl;
	mayinlsmau d[100];
	int k;
	cout << "\nNhap so luong may in laser mau: "; cin >> k;
	for (int i = 0; i < k; i++) {
		cout << "Nhap du lieu cho may in laser mau thu " << i + 1 << endl;
		d[i].nhap();
	}
	for (int i = 0; i < k; i++) {
		cout << "xuat du lieu cho may in laser mau thu " << i + 1 << endl;
		d[i].xuat();
	}
	return 0;
}

