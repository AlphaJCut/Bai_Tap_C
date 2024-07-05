#include <iostream>
#include <cstring>
using namespace std;

struct NTN
{
	int ngay;
	int thang;
	int nam;
};
struct Sach
{
	char TenSach[21];
	char TenTacGia[21];
	NTN NgayXuatBan;
};
void NhapDSSach(Sach ds[],int& soluong)
{
	do
	{
		cout << "Nhap so luong sach: ";
		cin >> soluong;
		if (soluong > 50 || soluong < 0)
			cout << "Nhap lai. ";
	} while (soluong > 50 || soluong < 0);
	for (int i = 0; i < soLuongSach; ++i) {
		cout << "Nhap thong tin sach thu " << i + 1 << ":" << endl;
		cout << "Ten sach: ";
		cin.getline(danhSach[i].TenSach, 21);
		cout << "Ten tac gia: ";
		cin.getline(danhSach[i].TenTacGia, 21);
		cout << "Nhap ngay xuat ban (ngay thang nam cach nhau boi dau space): ";
		cin >> danhSach[i].NgayXuatBan.ngay >> danhSach[i].NgayXuatBan.thang >> danhSach[i].NgayXuatBan.nam;
		cin.ignore();
}