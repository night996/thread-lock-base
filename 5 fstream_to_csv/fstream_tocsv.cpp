#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	string instID = "000001";
	double price = 3500;
	//ofstream fout("tocsv.csv", ios::app);

	ofstream fout;
	fout.open("tocsv.csv", ios::app);
	//fout << "��Լ����:" << instID.c_str() << ",�۸�:" << price << endl;
	//fout << "��Լ����:" << instID.c_str() << ",�۸�:" << price + 50 << endl;
	fout << "��Լ����:" << instID.c_str() << ",�۸�:" << price << endl;//����ö��Ÿ���
	fout.flush();
	fout << "��Լ����:" << instID.c_str() << ",�۸�:" << price + 50 << endl;
	fout.close();


	char buf[256];
	ifstream fin;

	fin.open("tocsv.csv", ios::in);
	cout << "------------reading from tocsv.csv" << endl;
	while (!fin.eof())
	{
		fin.getline(buf, 256, '\n');
		cout << buf << endl;
	}

	fin.close();
	return 0;
}