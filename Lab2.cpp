#include <iostream>
using namespace std;
#define MAX 50

int TinhTong(int n,int tong=0)
{
	if (n == 0)
		return tong;
	return TinhTong(n - 1, tong + n);
}
int TinhTongBP(int n, int tong =0)
{
	if (n == 0)
		return tong;
	return TinhTongBP(n - 1, tong + n*n);
}
int GiaiThua(int n, int gt=1)
{
	if (n == 1)
		return gt;
	return GiaiThua(n - 1, gt*n);
}
//int NhapMang1D(int *arr, int &n)
//{
//	cout << "Nhap so phan tu trong mang: ";
//	cin >> n;
//	while(n < 0||n>MAX)
//	{
//		cout << "Moi ban nhap lai so phan tu: ";
//		cin >> n;
//	}
//}
int Pascal(int i,int j)
{
	if (j == 0 || i == j)
		return 1;
	return Pascal(i - 1, j - 1) + Pascal(i - 1, j);
}
int main()
{
	cout << "Tong cac so: " << TinhTong(3) << endl;
	cout << "Tong cac so binh phuong: " << TinhTongBP(3) << endl;
	cout << "Giai thua la: " << GiaiThua(4) << endl;
	int h;
	cout << "Nhap chieu cao h: ";
	cin >> h;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout << Pascal(i, j) << "  ";
		}
		cout<<endl;
	}
	system("pause");
}