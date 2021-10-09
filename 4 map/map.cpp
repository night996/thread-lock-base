#include <iostream>
#include <functional>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> m1;
	//��������
	//1��ʹ��pair<type,type>(a,b)������ֵ�Զ���
	m1.insert(pair<string, int>("FB001", 10));
	//2��ʹ��make_pair(a,b)������ֵ�Զ���
	m1.insert(make_pair<string, int>("FB002",20));
	//3��ʹ��map<type,type>::value_type(a,b)��־
	m1.insert(map<string, int>::value_type("FB003", 30));
	map<string, int>::iterator iter1;
	//4����Ӧmap�����������±귽ʽ��������
	m1["FB004"] = 50;
	m1["FB005"] = 40;
	//cout << "m1[FB001] is " << m1["FB001"] << endl;
	//��������
	map<string, int>m2(m1);
	map<string, int>m3(m1.begin(), m1.end());

	map<string, int, greater<string>> m4(m1.begin(), m1.end(), greater<string>());//��map�е�Ԫ�شӴ�С����
	//��������
	for (iter1 = m4.begin(); iter1 != m4.end(); iter1++)
	{
		//��������iterator->first,ֵ������iterator->second
		cout << iter1->first << " " << iter1->second << endl;
	}

	/*
	map<string, int, greater<int>> m5(m1.begin(), m1.end(), greater<int>());
	for (iter1 = m5.begin(); iter1 != m5.end(); iter1++)
	{
		cout << iter1->first << " " << iter1->second << endl;
	}*/
	//�ġ�find���ң����ص�����
	map<string, int>::iterator iter = m1.find("FB002");
	if (iter != m1.end())
	{
		cout << "find FB002  (*iter).second=" << (*iter).second << endl;
	}
	//����Ҳ����ͷ���m1.end(��
	map<string, int>::iterator iter2 = m1.find("FB000");
	if (iter2 != m1.end())
		cout << "find FB000 (*iter2).second = " << (*iter2).second << endl;
	//��������
	for (iter1 = m1.begin(); iter1 != m1.end(); iter1++)
	{
		//����"FB002" ��Ӧ����ֵ
		if ((*iter1).first == "FB002")
		{
			cout << "FB002 ��Ӧ����ֵ��:" << (*iter1).second << endl;
		}
	}
	//�±귨����
	cout << "FB002��Ӧ����ֵ��:" << m1["FB002"] << endl;
	getchar();
}