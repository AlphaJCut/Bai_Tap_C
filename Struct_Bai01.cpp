#include <iostream>
#include<string>
using namespace std;

struct PhongBan
{
	string MaPhongBan;
	string TenPhongBan;
};
struct DSPB
{
	PhongBan *dspb;
	int n;
};
//Nhap 1 phong ban//
void Nhap1PhongBan(PhongBan &phban)
{
	cout << "Nhap ma phong ban: ";
	getline(cin, phban.MaPhongBan);
	cout << "Nhap ten phong ban: ";
	getline(cin, phban.TenPhongBan);
}
void Xuat1PhongBan(PhongBan phban)
{
	cout << "============ \n";
	cout << "Ma phong ban: " << phban.MaPhongBan << endl;
	cout << "Ten phong ban: " << phban.TenPhongBan << endl;
	cout << "============ \n";

}
void NhapDSPhongBan(DSPB &pb)
{
	do
	{
		cout << "Nhap so luong phong ban: ";
		cin >> pb.n;
		if (pb.n < 0 || pb.n >= 50)
			cout << "Nhap lai. \n";
	} while (pb.n < 0 || pb.n >= 50);
	pb.dspb = new PhongBan[pb.n];
	cin.ignore();
	for(int i=0;i<pb.n;i++)
	{
		cout << "Nhap thong tin phong ban thu " << i + 1 << ":" << endl;
		Nhap1PhongBan(pb.dspb[i]);
	}
}
void XuatDSPhongBan(const DSPB pb)
{
	for(int i=0;i<pb.n;i++)
	{
		Xuat1PhongBan(pb.dspb[i]);
	}
}
void HuyDSPB(DSPB& pb) {
	delete[]pb.dspb;
	pb.dspb = nullptr;
}
int main()
{
	DSPB pb;
	NhapDSPhongBan(pb);
	cout << "Danh sach cac phong ban ban vua nhap la: " << endl;
	XuatDSPhongBan(pb);
	HuyDSPB(pb);
}
