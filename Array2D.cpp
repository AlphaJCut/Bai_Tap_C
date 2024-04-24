#include <iostream>
using namespace std;

bool DK_Normal(int n)
{
	return true;
}
void NhapMang2D(int **&arr,int &r,int &c)
{
	do
	{
		cout << "Nhap dong: ";
		cin >> r;
		cout << "Nhap cot: ";
		cin >> c;
		if (r <= 0 || c <= 0)
			cout << "Moi ban nhap lai: ";
	} while (r <= 0 || c <= 0);
	arr = new int* [r];
	for(int i=0;i<r;i++)
	{
		arr[i] = new int[c];
	}
	if(arr!=NULL)
	{
		for(int i=0;i<r;i++)
		{
			for (int j = 0; j < c; j++)
			{
				arr[i][j] = rand() % 50 + 1;
			}
		}
	}
}
void XuatMang2D(int **arr,int r, int c,bool(*dieu_kien)(int))
{
	if(arr!=NULL)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if(dieu_kien(*(*arr+i)+j))
				cout << arr[i][j] << " \t";
			}
			cout << endl;
		}
	}
}

int *Tim_Vtri(int**arr,int r,int dong,int c)
{
	int Min = arr[dong][0];
	int* MinPtr = &arr[dong][0];
	for(int j=1;j<c;j++)
	{
		if(Min>arr[dong][j])
		{
			Min = arr[dong][j];
			MinPtr = &arr[dong][j];
		}
	}
	return MinPtr;
}
int TongCot(int **arr,int r,int c, int hang,int tong)
{
	if (r >= hang)
	{
		return tong;
	}
	tong += arr[r][c];
	return TongCot(arr, r+1,c , hang, tong);
}
bool SoNguyenTo(int n)
{
	if (n < 2)
		return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void SoNguyenTo(int**arr,int r, int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(SoNguyenTo(arr[i][j]))
			{
				cout << "So " << arr[i][j] << " la so nguyen to o hang " << i << " ,cot " << j << endl;
			}
		}
	}
}
int main()
{
	int** a = NULL; int r, c; int dong_tim; int cot;
	NhapMang2D(a, r, c);
	cout << "Mang 2 chieu duoc tao: " << endl;
	XuatMang2D(a, r, c,DK_Normal);
	do
	{
		cout << "Nhap dong ban muon lay so nho nhat tu 1 den " << r << ": ";
		cin >> dong_tim;
	}while (dong_tim<0 || dong_tim>r);
	dong_tim--;
	int* Vi_tri = Tim_Vtri(a, r, dong_tim, c);
	cout << "Vi tri so nho nhat la: " << Vi_tri << endl;
	do
	{
		cout << "Nhap cot ban muon tinh tong tu 1 den " << c << ": ";
		cin >> cot;
	} while (cot<0 || cot>c);

	int tong = TongCot(a, 0,cot-1,r, 0);
	cout << "Tong cac so cot " << cot << " la: " << tong << endl;
	SoNguyenTo(a, r, c);
	for(int i=0;i<r;i++)
	{
		delete[] a[i];
		a[i] = nullptr;
	}
	delete[]a;
	a = nullptr;
	system("pause");
}
