#pragma once
#include <iostream>
#include <cmath>
#include <math.h>
#include <time.h>
#include <cstdlib>

#define MAX 100
#define MAXROW 100
#define MAXCOL 50
using namespace std;

int RNG(int minN, int maxN);
//M?ng 1 chi?u//
void Nhap_Mang_1D(int* arr, int& Size); 
void Xuat_Mang_1D(int* arr, int& Size);
int* TimKiem(int* arr, int Size, int& x);
//M?ng 2 chi?u//
void nhapMang2D(int a[MAXROW][MAXCOL], int& r, int& c);
void xuatMang2D(const int a[MAXROW][MAXCOL], int r, int c);
void nhapHangCot(int& r, int& c);
int RNG(int minN, int maxN)
{
	return minN + rand() % (maxN + 1 - minN);
}
void Nhap_Mang_1D(int *arr, int& Size, int &A, int &B)
{
	cout << "Moi ban nhap so A trong doan ban muon so Random: ";
	cin >> A;
	cout << "Moi ban nhap so B trong doan ban muon so Random: ";
	cin >> B;
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
		r = RNG(A,B);
		*(arr+i) = r;
	}
}
void Xuat_Mang_1D(int* arr, int &Size)
{
	cout << "Cac so trong mang la: ";
	for (int i = 0; i < Size; i++)
		cout << " " << arr[i];
	cout << endl;
}
void nhapMang2D(int arr[MAXROW][MAXCOL], int& r, int& c)
{
	nhapHangCot(r, c);
	for (int i = 0; i < r; i++) 
	{
		cout << "Nhap dong thu " << i + 1 << ": ";
		for(int j=0;j<c;j++)
		{
			cin >> arr[i][j];
		}
	}
}
void xuatMang2D(const int arr[MAXROW][MAXCOL], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j] << " ";
		}
	}
}
void nhapHangCot(int& r, int& c)
{
	do
	{
		cout << "Nhap so hang:"; cin >> r;
		cout << "Nhap so cot: "; cin >> c;
		if (r <= 0 || r > MAXROW || c <= 0 || c > MAXCOL)
			cout << "Moi ban nhap lai: ";
	} while (r <= 0 || r > MAXROW || c <= 0 || c > MAXCOL);
}
 

