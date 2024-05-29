#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;	
void NhapMang(int *&arr,int &n)
{
	do
	{
		cout << "Moi ban nhap so phan tu: ";
		cin >> n;
		if (n < 0 || n>50)
			cout << "Moi ban nhap lai so phan tu: ";
	} while (n < 0 || n>50);
	arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cout << "a[" << i << "]=";
		cin >> arr[i];
	}
}
void XuatMang(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << "\t";
	}
}
void writeArrayToFile(const vector<int>& arr) {
    const string filename = "output.txt"; 
    ofstream outFile(filename); 
    if (outFile.is_open())
    {
        for (const int& num : arr)
        {
            outFile << num << endl;
        }
        outFile.close();
    }
    else 
    {
       cout << "Unable to open file for writing!" << endl;
    }
}

void readArrayFromFile(vector<int>& arr) {
    const string filename = "1.txt"; 
    ifstream inFile(filename); 
    if (inFile.is_open()) { 
        int num;
        while (inFile >> num) { 
            arr.push_back(num); 
        }
        inFile.close(); 
    }
    else {
       cout<< "Unable to open file for reading!" << endl; 
    }
}
int main()
{
	vector<int>a;
    readArrayFromFile(a);
    cout << "Array read from file successfully. Contents are:" << endl;
    for (const int& num : a) 
    {
        cout << num << " ";
    }
    cout << endl;
    writeArrayToFile(a);
    system("pause");
    return 0;
}