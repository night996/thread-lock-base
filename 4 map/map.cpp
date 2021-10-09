#include <iostream>
#include <functional>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> m1;
	//插入数据
	//1、使用pair<type,type>(a,b)构建键值对对象
	m1.insert(pair<string, int>("FB001", 10));
	//2、使用make_pair(a,b)构建键值对对象
	m1.insert(make_pair<string, int>("FB002",20));
	//3、使用map<type,type>::value_type(a,b)标志
	m1.insert(map<string, int>::value_type("FB003", 30));
	map<string, int>::iterator iter1;
	//4、对应map，还可以用下标方式插入数据
	m1["FB004"] = 50;
	m1["FB005"] = 40;
	//cout << "m1[FB001] is " << m1["FB001"] << endl;
	//拷贝构造
	map<string, int>m2(m1);
	map<string, int>m3(m1.begin(), m1.end());

	map<string, int, greater<string>> m4(m1.begin(), m1.end(), greater<string>());//让map中的元素从大到小排序
	//三、遍历
	for (iter1 = m4.begin(); iter1 != m4.end(); iter1++)
	{
		//键部分用iterator->first,值部分用iterator->second
		cout << iter1->first << " " << iter1->second << endl;
	}

	/*
	map<string, int, greater<int>> m5(m1.begin(), m1.end(), greater<int>());
	for (iter1 = m5.begin(); iter1 != m5.end(); iter1++)
	{
		cout << iter1->first << " " << iter1->second << endl;
	}*/
	//四、find查找，返回迭代器
	map<string, int>::iterator iter = m1.find("FB002");
	if (iter != m1.end())
	{
		cout << "find FB002  (*iter).second=" << (*iter).second << endl;
	}
	//如果找不到就返回m1.end(）
	map<string, int>::iterator iter2 = m1.find("FB000");
	if (iter2 != m1.end())
		cout << "find FB000 (*iter2).second = " << (*iter2).second << endl;
	//遍历查找
	for (iter1 = m1.begin(); iter1 != m1.end(); iter1++)
	{
		//查找"FB002" 对应的数值
		if ((*iter1).first == "FB002")
		{
			cout << "FB002 对应的数值是:" << (*iter1).second << endl;
		}
	}
	//下标法查找
	cout << "FB002对应的数值是:" << m1["FB002"] << endl;
	getchar();
}