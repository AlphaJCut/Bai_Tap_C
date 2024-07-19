#include <iostream>
#include <string>
using namespace std;
struct VIDEO
{
	string TenPhim;
	string TheLoai;
	string TenDaoDien;
	int NamSanXuat;
};
struct DanhSachPhim
{
	VIDEO *ds;
	int n;
};
void Nhap1BoPhim(VIDEO&phim)
{
	cout << "Nhap ten bo phim: ";
	getline(cin, phim.TenPhim);
	cout << "Nhap the loai cua phim: ";
	getline(cin, phim.TheLoai);
	cout << "Nhap ten dao dien cua bo phim: ";
	getline(cin, phim.TenDaoDien);
	cout << "Nhap nam san xuat cua bo phim: ";
	cin >> phim.NamSanXuat;
	cin.ignore();
	cout << endl;
}
void NhapDSBoPhim(DanhSachPhim&dsphim)
{
	do
	{
		cout << "Nhap so luong bo phim: ";
		cin >> dsphim.n;
		if (dsphim.n <= 0 || dsphim.n >= 50)
			cout << "Moi ban nhap lai. ";
	} while (dsphim.n <= 0 || dsphim.n >= 50);
	dsphim.ds = new VIDEO[dsphim.n];
	cin.ignore();
	for  (int i=0;i<dsphim.n;i++)
	{
		cout << "Nhap thong tin bo phim thu " << i + 1 << endl;
		Nhap1BoPhim(dsphim.ds[i]);
	}
}
void Xuat1BoPhim(const VIDEO phim)
{
	cout << "Ten bo phim: " << phim.TenPhim << endl;
	cout << "The loai: " << phim.TheLoai << endl;
	cout << "Dao dien " << phim.TenDaoDien << endl;
	cout << "Nam san xuat: " << phim.NamSanXuat << endl;
}
void XuatDSBoPhim(const DanhSachPhim dsphim)
{
	for(int i=0;i<dsphim.n;i++)
	{
		cout << "================ \n";
		cout << i + 1 << "." << endl;
		Xuat1BoPhim(dsphim.ds[i]);
		cout << "================ \n";
	}
}
void XuatDSPhimDaoDien(const DanhSachPhim dsphim,string ten)
{
	bool found = false;
	for (int i = 0; i < dsphim.n; i++) {
		if (ten == dsphim.ds[i].TenDaoDien) {
			Xuat1BoPhim(dsphim.ds[i]);
			found = true;
		}
	}
	if (!found) {
		cout << "Khong tim thay bo phim nao cua dao dien " << ten << endl;
	}
}
void sapXepTheoNamSanXuat(VIDEO dsphim[], int n) 
{
	for (int i = 0; i < n - 1; ++i) 
	{
		for (int j = 0; j < n - i - 1; ++j) 
		{
			if (dsphim[j].NamSanXuat > dsphim[j + 1].NamSanXuat) 
			{
				VIDEO temp = dsphim[j];
				dsphim[j] = dsphim[j + 1];
				dsphim[j + 1] = temp;
			}
		}
	}
}
void HuyDSPhim(DanhSachPhim&dsphim)
{
	delete[]dsphim.ds;
	dsphim.ds = nullptr;

}
int main()
{
	DanhSachPhim ds1;
	NhapDSBoPhim(ds1);
	XuatDSBoPhim(ds1);
	/*cout << "Nhap ten dao dien ban muon tim: ";
	string DaoDien; getline(cin, DaoDien);
	XuatDSPhimDaoDien(ds1, DaoDien);*/
	sapXepTheoNamSanXuat(ds1.ds, ds1.n);
	cout << "Danh sach phim sau khi sap xep lai: " << endl;
	XuatDSBoPhim(ds1);
	HuyDSPhim(ds1);
	system("pause");
	return 0;
}