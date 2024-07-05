#include <iostream>
#include <string>
#define MAX 45
using namespace std;
struct SinhVien
{
	string MSSV;
	string HoVaTen;
	string DiaChi;
	int NamSinh;
	double DiemToan, DiemVan, DiemAnh;
	double DiemTrungBinh;
	string XepLoai;
};
struct DSSV
{
	SinhVien* ds;
	int n;
};
void Nhap1SV(SinhVien& sv)
{
	cout << "Nhap MSSV: ";
	getline(cin, sv.MSSV);
	cout << "Nhap ho va ten sinh vien: ";
	getline(cin, sv.HoVaTen);
	cout << "Nhap dia chi cua sinh vien: ";
	getline(cin, sv.DiaChi);
	cout << "Nhap nam sinh cua sinh vien: ";
	cin >> sv.NamSinh;
	cin.ignore(1);
	cout << "Nhap diem toan, van, anh cua sinh vien: ";
	cin >> sv.DiemToan >> sv.DiemVan >> sv.DiemAnh;
	sv.DiemTrungBinh=((sv.DiemToan + sv.DiemVan) * 2 + sv.DiemAnh) / 5;
	if (sv.DiemTrungBinh >= 8.0)
		sv.XepLoai = "Gioi";
	else if (sv.DiemTrungBinh >= 6.5)
		sv.XepLoai = "Kha";
	else if (sv.DiemTrungBinh >= 5.0)
		sv.XepLoai = "TB";
	else
		sv.XepLoai = "Duoi TB";
	cin.ignore(1);
}
void Xuat1SV(const SinhVien sv)
{
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Ho va ten cua sinh vien: " << sv.HoVaTen << endl;
	cout << "Dia chi cua sinh vien: " << sv.DiaChi << endl;
	cout << "Nam sinh cua sinh vien: " << sv.NamSinh << endl;
	cout << "Diem toan cua sinh vien: " << sv.DiemToan << endl;
	cout << "Diem van cua sinh vien: " << sv.DiemVan << endl;
	cout << "Diem anh cua sinh vien: " << sv.DiemAnh << endl;
	cout << "Sinh vien duoc xep loai: " << sv.XepLoai << endl;
}
void NhapDSSV(DSSV &dssv)
{
	do
	{
		cout << "Nhap so luong sinh vien: ";
		cin >> dssv.n;
		if (dssv.n < 0 || dssv.n >= 45)
			cout << "Nhap lai so sinh vien. \n";
	} while (dssv.n < 0 || dssv.n >= 45);
	dssv.ds = new SinhVien[dssv.n];
	cin.ignore();
	for(int i=0;i<dssv.n;i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
		Nhap1SV(dssv.ds[i]);
	}
}
int TinhDiemTrungBinh(const SinhVien sv)
{
	return ((sv.DiemToan + sv.DiemVan) * 2 + sv.DiemAnh) / 5;
}
void XuatDSSV(const DSSV dssv)
{
	for (int i=0;i<dssv.n;i++)
	{
		cout << "================ \n";
		cout << i + 1 << "." << endl;
		Xuat1SV(dssv.ds[i]);
		cout << "================ \n";
	}
}
void XuatSVDiemTB(const SinhVien sv)
{
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Ho va ten cua sinh vien: " << sv.HoVaTen << endl;
	cout << "Diem trung binh cua sinh vien la: " << sv.DiemTrungBinh << endl;
}
void XuatDSSV_DiemTB(const DSSV dssv)
{
	for (int i = 0; i < dssv.n; i++)
	{
		cout << endl;
		cout << "================ \n";
		cout << i + 1 << "." << endl;
		XuatSVDiemTB(dssv.ds[i]);
		cout << "================ \n";
	}
}
void TimKiemSV(const DSSV dssv, int x)
{
	if (x > 0 && x <= dssv.n)
	{
		Xuat1SV(dssv.ds[x - 1]);
	}
	else
	{
		cout << "Khong co thong tin sinh vien nay.\n";
	}
}
void HuyDSSV(DSSV &dssv)
{
	delete[]dssv.ds;
	dssv.ds = nullptr;
}
int main() 
{
	DSSV dssv1;
	int n;
	NhapDSSV(dssv1);
	cout << "Danh sach lop: " << endl;
	XuatDSSV(dssv1);
	cout << "Nhap so thu tu cua sinh vien ban muon tim kiem thong tin: ";
	cin >> n;
	TimKiemSV(dssv1, n);
	XuatDSSV_DiemTB(dssv1);
	XuatDSSV(dssv1);
	HuyDSSV(dssv1);
	system("pause");
	return 0;
}