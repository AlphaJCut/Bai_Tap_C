//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#define SOMH 3
//Dinh Nghia//

struct SinhVien
{
	long long mssv;
	char HoVaTen[50];
	char MaLop[9];
	char NgaySinh[11];
	string QuaQuan;
	double DiemTB[SOMH];
};
struct DSSV
{
	SinhVien*ds;
	int n;
};
//Ham dung chung//
void Nhap1SV(SinhVien &sv)
{
	cout << "Nhap MSSV: ";
	cin >> sv.mssv;
	cin.ignore();
	cout << "Nhap ho va ten sinh vien: ";
	cin.getline(sv.HoVaTen,50);

	cout << "Nhap ma lop: ";
	cin >> sv.MaLop;
	cin.ignore(1);
	cout << "Nhap ngay sinh: ";
	cin >> sv.NgaySinh;
	cin.ignore(1);
	cout << "Nhap que quan: ";
	getline(cin, sv.QuaQuan);

}
void Xuat1SV(const SinhVien sv)
{
	cout << "=================\n";
	cout << "MSSV: " << sv.mssv << endl;
	cout << "Ho va ten sinh vien: " << sv.HoVaTen << endl;
	cout << "Ma lop sinh vien: " << sv.MaLop << endl;
	cout << "Ngay sinh cua sinh vien: " << sv.NgaySinh << endl;
	cout << "Que quan cua sinh vien: " << sv.QuaQuan << endl;
	cout << "=================\n";
}
void NhapDSSV(DSSV &mh)
{
	do
	{
		cout << "Nhap so luong sinh vien: ";
		cin >> mh.n;
		if (mh.n < 0 || mh.n >= 50)
			cout << "Moi ban nhap lai. " << endl;
	} while (mh.n <= 0 || mh.n >= 50);
	mh.ds = new SinhVien[mh.n];
	for(int i=0;i<mh.n;i++)
	{
		Nhap1SV(mh.ds[i]);
	}
}
void XuatDSSV(const DSSV mh)
{
	for(int i=0;i<mh.n;i++)
	{
		Xuat1SV(mh.ds[i]);
	}
}
int main()
{
	DSSV mh1;
	mh1.ds= NULL;
	mh1.n = 0;
	NhapDSSV(mh1);
	XuatDSSV(mh1);
	system("pause");
	return 0;
}