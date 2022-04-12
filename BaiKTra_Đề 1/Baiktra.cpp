
//1. (2 điểm) Xây dựng lớp phương tiện giao thông PTGT với những thuộc tính sau : Mã phương tiện, Hãng sản xuất, ngày xuất xưởng,
//  giá chưa thuế là các thuộc tính.Trong lớp có định nghĩa các hàm công cộng sau :
//-Hàm khởi tạo với các tham số có giá trị ngầm định.
//- Hàm hủy.
//- Hàm nhập dữ liệu cho một phương tiện giao thông.
//- Hàm in các thông tin của một phương tiện giao thông.

//2. (3 điểm) Xây dựng lớp máy bay MAYBAY kế thừa từ lớp PTGT, lớp MAYBAY bổ sung thêm thuộc tính : đường bay, số chỗ ngồi, 
// nơi đăng ký kinh doanh và lớp này gồm các hàm thành phần :
//-Hàm khởi tạo với các tham số có giá trị ngầm định.
//- Hàm hủy.
//- Tái định nghĩa toán tử nhập “ >> ”
//- Hàm tính giá thành sau thuế.Biết giá sau thuế = giá chưa thuế + giá chưa thuế * 8 %
//-Tái định nghĩa toán tử < để so sánh số ghế của máy bay với một số nguyên.
//	- Tái định nghĩa toán tử xuất “ << ”.



#include<iostream>
using namespace std;


class ptgt {
private:
	char ma[20];
	char ten[30];
	char ngay[30];
	float gia;
public:
	ptgt() {
		this->ma[0] = '\0';
		this->ten[0] ='\0';
		this->ngay[0] = '\0';
		this->gia = 0;

	}
	
	void nhap() {
		cout << "Nhap ma: "; cin.getline(ma, 20);
		cout << "\nNhap hang xan xuat: "; cin.getline(ten, 30);
		cout << "\nNhap ngay xuat xuong: "; cin.getline(ngay, 30);
		cout << "\nNhap gia thue: "; cin >> gia;
	}
	void xuat() {
		cout << "\nMa phuong tien: " << ma << endl;
		cout << "\nHang san xuat: " << ten << endl;
		cout << "\nNgay xuat xuong: " << ngay << endl;
		cout << "Gia thue: " << gia << endl;
	}
	int getgia() {
		gia +=(float) gia * (8 / 100);
		cout << "Gia sau the: " << gia;
	}
	~ptgt(){};

};
	class maybay: public ptgt{
private:
	int scn;
	char duongbay[20];
	char noidk[20];
	
	
public:
	void nhap() {
		ptgt::nhap();
	}
	
	friend istream& operator >>(istream& is, maybay& a) {
	
		cout << "\nNhap So cho ngoi: "; is >> a.scn;
		cout << "\nNhap duong bay: "; is.getline(a.duongbay, 20);
		cout << "\nNoi dang ki kinh doanh: "; is.getline(a.noidk, 20);
	
	}
	void xuat() {
		ptgt::xuat();
	}

	friend ostream& operator <<(ostream& os, maybay& a) {

		os << "\nNhap So cho ngoi: " << a.scn;
		os << "\nNhap duong bay: " << a.duongbay;
		os << "\nNoi dang ki kinh doanh: " << a.noidk;

	}
	
	

	
	
	

};
int main() {
	int n;
	cout << "nhap so luong phuong tien: "; cin >> n;
	ptgt a[1000];
	cin.ignore();
	cout << "\nNhap phuong tien: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Nhap phuong tien thu: " << i + 1 << endl;
		a[i].nhap();
		cin.ignore();

	}
	cout << "\nXuat Phuong tien====" << endl;
	for (int i = 0; i < n; i++) {
		cout << "-Phuong tien thu: " << i + 1 << endl;
		a[i].xuat();

	}
	return 0;

}