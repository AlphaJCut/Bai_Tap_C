#include <iostream>
#include <string>
using namespace std;
struct NhanVien
{
	string Ma_nv;
	string HovaTen;
	int Namvaolam, Namsinh;
};
void Nhap1NhanVien(NhanVien &nv)
{
	cout << "Nhap ma nhan vien: ";
	getline(cin, nv.Ma_nv);
	cout << "Nhap ho va ten nhan vien: ";
	getline(cin, nv.HovaTen);
	cout << "Nhap nam vao lam: ";
	cin >> nv.Namvaolam;
	cin.ignore(1);
	cout << "Nhap nam sinh cua sinh vien: ";
	cin >> nv.Namsinh;
	cin.ignore(1);
}
int TinhTuoi(int namsinh)
{
	int NamHienTai = 2024;
	if ((NamHienTai - namsinh) < 0)
		return -1;
	else return NamHienTai - namsinh;
}
int ThamNien(int namvaoLam)
{
	int NamHienTai = 2024;
	if ((NamHienTai - namvaoLam) < 0)
		return -1;
	else return NamHienTai - namvaoLam;

}
void Xuat1NhanVien(const NhanVien nv)
{
	cout << "============ \n";
	cout << "Ma nhan vien: " << nv.Ma_nv << endl;
	cout << "Ho va ten cua nhan vien la: " << nv.HovaTen << endl;
	cout << "Nam vao lam cua nhan vien la: " << nv.Namvaolam << endl;
	cout << "Nam sinh cua nhan vien la: " << nv.Namsinh << endl;
	if (ThamNien(nv.Namvaolam) < 0)
		cout << "Ban da nhap sai thong tin. " << endl;
	else cout << "Tham nien cua nhan vien: " << ThamNien(nv.Namvaolam) << endl;
	if (TinhTuoi(nv.Namsinh) < 0)
		cout << "Ban da nhap sai thong tin. " << endl;
	else cout << "Tuoi cua nhan vien: " << TinhTuoi(nv.Namsinh) << endl;
	cout << "============ \n";
}

int main()
{
	NhanVien nv1;
	Nhap1NhanVien(nv1);
	Xuat1NhanVien(nv1);
	system("pause");
	return 0;
}