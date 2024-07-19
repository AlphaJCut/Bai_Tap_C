#include<iostream>
#define MAX 100
using namespace std;
void NhapDS(int arr[],int &n)
{
	do
	{
		cout << "Nhap so phan tu cho danh sach: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Moi ban nhap lai.";
	} while (n <= 0 || n > MAX);
	for (int i = 0; i<n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> arr[i];
	}
}
void XuatDS(int arr[], int &n)
{
	cout << "Cac gia tri cua danh sach: ";
	for (int i = 0; i<n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int TimPhanTu(int arr[],int n,int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
			return i + 1;
	}
	return -1;
}
void ThemPhanTuVaoDS(int arr[],int &n,int vitri,int x)
{
	if (vitri >= 0 && vitri <= n)
	{
		for(int i=n;i>vitri;i--)
		arr[i] = arr[i - 1];
			arr[vitri] = x;
			n++;
	}
}
void XoaPhanTuDS(int arr[],int&n, int vitri)
{
	if(vitri>=0&&vitri<=n)
	{
		for (int i = vitri; i < n - 1; i++)
			arr[i] = arr[i+1];
		n--;
	}
}
int main()
{
	int arr[MAX]; int n; int x;
	NhapDS(arr, n);
	XuatDS(arr, n);
	cout << "Nhap gia tri ban muon tim kiem: ";
	cin >> x;
	int vitri = TimPhanTu(arr, n, x);
	if(vitri!=-1)
	{
		cout << "So can tim nam tai vi tri thu " << vitri << endl;
	}
	else
	{
		cout << "Khong tim thay so ban nhap." << endl;
	}
	cout << "Nhap gia tri ban muon them vao danh sach: ";
	int gt; cin >> gt;
	cout << "Nhap vi tri tri ban muon them vao danh sach: ";
	int vtgt; cin >> vtgt;
	ThemPhanTuVaoDS(arr, n, vtgt, gt);
	XuatDS(arr, n);
	cout << "Nhap vi tri tri ban muon xoa trong danh sach: ";
	int xoa; cin >> xoa;
	XoaPhanTuDS(arr, n, vitri);
	XuatDS(arr, n);
	system("pause");
	return 0;
}