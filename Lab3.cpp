#include <iostream>
#include <cmath>
#include <math.h>
#include <time.h>
#include <cstdlib>
#define MAX 100
#define MAXROW 100
#define MAXCOL 50
using namespace std;


int random(int minN, int maxN);
void nhap(int* arr, int& Size);
int UCLN(int* a, int* b);
void bai3();
void bai4();
void xuatSoLe(int* arr, int& Size);
int* TimMax(int* arr, int Size);
void DaoNguoc(int* arr, int& Size);
int* TimKiem(int* arr, int Size, int &x);
void nhapMang2D(int a[MAXROW][MAXCOL], int& r, int& c);
void xuatMang2D(const int a[MAXROW][MAXCOL], int r, int c);
void nhapHangCot(int& r, int& c);
int** TaoMaTran(int h);
void GiaiPhongMaTran(int** matrix, int h);
void Pascal(int** matrix, int h);
void XuatPascal(int** matrix, int h);


int random(int minN, int maxN)
{
	return minN + rand() % (maxN + 1 - minN);
}
void nhap(int *arr, int& Size)
{
	cout << "Moi ban nhap so phan tu cho mang: ";
	cin >> Size;
	while (Size <= 0 || Size >= MAX)
	{
		cout << "Moi ban nhap lai so phan tu cho mang: ";
		cin >> Size;
	}
	srand((unsigned int)time(0));
	int r;
	for (int i = 0; i < Size; i++)
	{
		r = random(0, 100);
		*(arr+i) = r;
	}
}
void xuat(int* arr, int &Size)
{
	cout << "Cac so trong mang la: ";
	for (int i = 0; i < Size; i++)
		cout << " " << arr[i];
	cout << endl;
}
//Bai 3//
int UCLN(int *a, int *b)
{
	if (*b == 0) return *a;
	int d = *a % *b;
	return UCLN(b, &d);
}
void bai3()
{
	int* so_a = new int;
	int* so_b = new int;
	cout << "Moi ban nhap so a: ";
	cin >> *so_a;
	cout << "Moi ban nhap so b: ";
	cin >> *so_b;
	int kq= UCLN(so_a, so_b);
	cout << "Uoc chung lon nhat cua hai so la: " << kq << endl;
	delete so_a;
	delete so_b;
}
//Bai 4//
void xuatSoLe(int *arr, int &Size)
{
	cout << "Cac so le trong mang la: ";
	for(int i=0;i<Size;i++)
	{
		if (*(arr + i) % 2 != 0)
			cout << " " << *(arr+i);
	}
	cout << endl;
}
int *TimMax(int *arr, int Size)
{
	if (Size <= 0 || arr == nullptr)
	return nullptr;

	int *Max = arr;
	for (int i=1;i<Size;i++)
	{
		if (*(arr + i) > *Max)
			Max = arr + i;
	}
	return Max;
}
void bai4()
{
	int arr[MAX]; int n;
	nhap(arr, n);
	xuat(arr, n);
	cout << endl;
	xuatSoLe(arr, n);
	int* GTLN;
	GTLN = TimMax(arr, n);
	if (GTLN == nullptr)
	{
		cout << "Khong co dia chi cua gia tri lon nhat. ";
	}
	else cout << "Dia chi cua gia tri lon nhat la: " << GTLN << endl;
}
//Bai 5//
int Fibonacci(int n)
{
	if (n < 0)
	{
		return -1;
	}
	else if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
void bai5()
{
	cout << "Moi ban nhap so thu may cua day Fibonacci de in ra: ";
	cout << endl;
	int n;
	cin >> n;
	cout << "Day so Fibonacci: ";
	for (int i = 0; i <n; i++)
		cout << " " << Fibonacci(i);
	cout << endl;
}
//Bai 6//
void DaoNguoc(int *arr, int &Size)
{
	int bien;
	int* start = arr;
	int* end = arr + Size - 1;
	while(start<end)
	{
		bien = *start;
		*start = *end;
		*end = bien;
		start++;
		end--;
	}
}
void bai6()
{
	int arr[MAX];
	int n;
	nhap(arr, n);
	xuat(arr, n);
	cout << endl;
	cout << "Day so sau khi dao nguoc ";
	DaoNguoc(arr, n);
	cout << endl;
	xuat(arr, n);
}
//Bai7//
int* TimKiem(int* arr, int Size, int &x)
{
	
	for(int i=0;i<Size;i++)
	{
		if (*(arr + i) == x)
			return (arr + 1);
	}
	return nullptr;
}
void bai7()
{
	int arr[MAX];
	int n; int x;
	nhap(arr, n);
	xuat(arr, n);
	cout << "Nhap gia tri x ban muon tim: ";
	cin >> x;
	cout << endl;
	int* vitri = TimKiem(arr, n, x);
	if(vitri!=nullptr)
	{
		cout << "So " << x << " ban can tim o vi tri " << vitri << endl;
	}
	else
	{
		cout << "So " << x << " ban can tim khong co trong mang. " << endl;
	}
}
//Bai8//
int** TaoMaTran(int h)
{
	int** MaTran = new int*[h];
	for (int i = 0; i < h; i++)
		MaTran[i] = new int[i + 1];
	return MaTran;
}
void GiaiPhongMaTran(int** MaTran, int h)
{
	for (int i = 0; i < h; i++)
	{
		delete[]MaTran[i];
	}
	delete[]MaTran;
}
void Pascal(int** matrix, int h)
{

}
void XuatPascal(int** matrix, int h);
void nhapHangCot(int& r, int& c) {
	do {
		cout << "Nhap so hang: "; cin >> r;
		cout << "Nhap so cot: "; cin >> c;
		if (r <= 0 || r > MAXROW || c <= 0 || c > MAXCOL)
			cout << "Nhap sai, nhap lai di!\n";
	} while (r <= 0 || r > MAXROW || c <= 0 || c > MAXCOL);
}

void nhapMang2D(int a[MAXROW][MAXCOL], int& r, int& c) {
	nhapHangCot(r, c);
	for (int i = 0; i < r; i++) {
		cout << "Nhap dong thu " << i + 1 << ": ";
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
}
void xuatMang2D(const int a[MAXROW][MAXCOL], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
int main()
{
	int x = 10, y = 20; int* p;
	int* a=new int;  int* b=new int;
	p = &x;
	*p = 80;
	int bai;
menu:
	cout << "Moi ban nhap so (1-15) hoac nhan 0 de dung lai.";
	cin >> bai;
	switch(bai)
	{
	case 0:
		break;
		return 0;
	case 1:
		cout << "Dia chi cua bien x" << &x << endl;
		cout << "Dia chi luu trong con tro p: " << p << endl;
		cout << "Gia tri cua bien ma p tro den: " << *p << endl;
		cout << "Gia tri cua bien x: " << x << endl;
		goto menu;
	case 3:
		bai3();
		goto menu;
	case 4:
		bai4();
		goto menu;
	case 5: 
		bai5();
		goto menu;
	case 6: 
		bai6();
		goto menu;
	case 7:
		bai7();
		goto menu;
	}
	system("pause");
}

