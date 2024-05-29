#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
struct Date
{
	int day, month, year;
}; 
struct Lop
{
	char MaLop[5];
	char TenLop[9];
	string TenKhoa;
	int SoSV;
	Date NgThNam;
};
struct DSLop
{
	vector<Lop>Ds;
};
//Ham dung chung//
bool isNamNhuan(int nNam)
{
	if (nNam % 400 == 0 || nNam % 4 == 0 && nNam % 100 != 0)
		return true;
	return false;
}
int TinhSoNgay(int nThang,int nNam)
{
	int soNgay = 0;
	switch(nThang)
	{
	case 1:	case 3:	case 5:	case 7:	case 8:	case 10:	case 12:
	      soNgay = 31;
	      break;
	case 4: case 6: case 9: case 11:
		soNgay = 30;
		break;
	case 2:
		if (isNamNhuan(nNam) == true)
			soNgay = 29;
		else 
			soNgay = 28;
		break;
	}
	return soNgay;
}
bool KiemTraNgayHopLe(const Date ntn)
{
	if (ntn.year <= 0)
		return false;
	if (ntn.month < 0 || ntn.month >= 12)
		return false;
	if (ntn.day < 0 || ntn.day >= TinhSoNgay(ntn.month, ntn.year))
		return false;
	return true;
}
//Ham cua lop//
int Nhap1Lop(Lop *&l)
{
	cout << "Nhap ma lop:";
	cin >> l->MaLop;
	cin.ignore();
	cout << "Nhap ten lop: ";
	cin >> l->TenLop;
	cin.ignore();
	cout << "Nhap ten khoa: ";
	getline(cin, l->TenKhoa);
	cout << "Nhap so sinh vien: ";
	cin >> l->SoSV;
	Date NgayThNam;
	cout << "Nhap ngay khai giang: ";
	cin >> NgayThNam.day;
	cin.ignore(1);
	cin >> NgayThNam.month;
	cin.ignore(1);
	cin >> NgayThNam.year;
	cin.ignore(1);
	if(KiemTraNgayHopLe(NgayThNam)==true)
	{
		l->NgThNam=NgayThNam;
		return 1;
	}
	else
	{
		cout << "Ngay ban nhap khong hop le: ";
		return 0;
	}
}
void Xuat1lop(const Lop*l)
{
	cout << "=================\n";
	cout << "Ma lop: " << l->MaLop << endl;
	cout << "Ten lop: " << l->TenLop << endl;
	cout << "Ten khoa: " << l->TenKhoa << endl;
	cout << "So sinh vien: " << l->SoSV << endl;
	cout << "Ngay khai giang: " << l->NgThNam.day << "/" << l->NgThNam.month << "/" << l->NgThNam.year << endl;
	cout << "=================\n";
}
//Ham danh sach lop//
void NhapTuFile(DSLop &dsl,string filename)
{
	ifstream inFile(filename);
	if(inFile.is_open())
	{
		while(inFile.eof()==false)
		{
			Lop l;
			inFile.getline(l.MaLop, 5, '#');
			inFile.getline(l.TenLop, 9, '#');
			getline(inFile, l.TenKhoa, '#');
			inFile >> l.SoSV;
			inFile.ignore(1);
			Date ngay;
			inFile >> ngay.day;
			inFile.ignore(1);
			inFile >> ngay.month;
			inFile.ignore(1);
			inFile >> ngay.year;
			inFile.ignore(1);
			if(KiemTraNgayHopLe(ngay)==true)
			{
				l.NgThNam = ngay;
				dsl.Ds.push_back(l);
			}
			else
			{
				cout << "Ngay khong hop le. \n";
				break;
			}
		}
		inFile.close();
	}
}
int TinhSoLuongSV(const DSLop dsl,const string tenKhoa)
{
	int tong = 0;
	for(int i=0;i<dsl.Ds.size();i++)
	{
		if(dsl.Ds[i].TenKhoa==tenKhoa)
		{
			tong += dsl.Ds[i].SoSV;
		}
	}
	return tong;
}
int DemLop(const DSLop dsl,const string tenKhoa)
{
	int tong = 0;
	for(int i=0;i<dsl.Ds.size();i++)
	{
		if(dsl.Ds[i].TenKhoa==tenKhoa)
		{
			tong++;
		}
	}
	return tong;
}
void XuatDSLop(const DSLop dsl)
{
	for(int i=0;i<dsl.Ds.size();i++)
	{
		Xuat1lop(&dsl.Ds[i]);
	}
}
void Xoa1Lop(DSLop &dsl,char*MaLop)
{
	for(int i=0;i<dsl.Ds.size();i++)
	{
		if (strcmp(dsl.Ds[i].MaLop, MaLop) == 0)
		{
			dsl.Ds.erase(dsl.Ds.begin() + i);
			break;
		}
	}
}

int main()
{
	/*Lop* l1 = new Lop;
	if (Nhap1Lop(l1) == 1)
		Xuat1lop(l1);
	delete l1;*/
	DSLop ds;
	NhapTuFile(ds, "DSLop.txt");
	XuatDSLop(ds);
	Xoa1Lop(ds, (char*)"CB31");
	XuatDSLop(ds);
	int lop = DemLop(ds, "Khoa NN");
	cout << "Co " << lop << "lop thuoc khoa Ngoai Ngu." << endl;
	system("pause");
	return 1;

}