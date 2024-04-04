#include<iostream>
using namespace std;

#define SIZE 8
int a[SIZE][SIZE] = { 0 };
int dd[] = {-2,-1,1,2,2,1,-1,-2 };
int dc[] = { 1,2,2,1,-1,-2,-2,-1 };
void XuatKetQua()
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0; j<SIZE;j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void nuocdi(int n, int vtDong, int vtCot)
{
	for(int i=0;i<8;i++)
	{
		int DongMoi = vtDong + dd[i];
		int CotMoi = vtCot + dc[i];
		if(DongMoi>=0&&DongMoi<SIZE&&CotMoi>=0&&CotMoi<SIZE&&a[DongMoi][CotMoi]==0)
		{
			a[DongMoi][CotMoi] = n;
			if(n==SIZE*SIZE)
			{
				XuatKetQua();
				char c;
				cout << "Nhap ki tu de dung: "; cin >> c;
			}
			else
			{
				nuocdi(n + 1, DongMoi, CotMoi);
				a[DongMoi][CotMoi] = 0;
			}
		}
	}
}
int main()
{
	a[0][0] = 1;
	nuocdi(2, 0, 0);
	system("pause");
}