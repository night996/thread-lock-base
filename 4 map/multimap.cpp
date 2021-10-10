#include<map>
#include<iostream>
#include<functional>
#include <string>
using namespace std;
int main()
{//一、 通过调用 multimap 类模板的默认构造函数，可以创建一个空的 multimap 容器
	multimap<string, int> mm;
	
//二、声明多重映射的迭代器
	multimap<string, int>::iterator mm_iter;

//三、插入数据
	//1、使用pair<type,type>(a,b)构建键值对对象
	mm.insert(pair<string, int>("IF2012", 3500));
	mm.insert(pair<string, int>("IF2012", 3600));
	//2、使用make_pair(a,b)构建键值对对象
	mm.insert(make_pair("IF2101", 3800));
	//3、使用map<type,type>::value_type(a,b)标志
	mm.insert(map<string, int>::value_type("IF2103", 4200));
	//不能使用下标法插入数据
	//mm["IF2000"] = 2050;

	//一、创建多重映射,通过调用 multimap 类模板的拷贝（复制）构造函数，也可以初始化新的 multimap 容器。
	multimap<string, int> mm1(mm);


	//一、创建多重映射,3用迭代器的范围来初始化
	multimap<string, int>::iterator b_iter = mm.begin();
	multimap<string, int>::iterator e_iter = mm.begin();
	e_iter++;
	e_iter++;
	e_iter++;
	//e_iter++;
	multimap<string, int> mm2(b_iter,e_iter);

	//一、创建多重映射,4用迭代器的范围,并指定排序准则
	multimap<string, int,greater<string>> mm3(b_iter, e_iter, greater<string>(),mm.get_allocator());

	multimap<string, int,greater<string>> mm4(b_iter, e_iter, greater<string>());
	//4、对应multimap，不可以用下标方式
	//mm["IF2106"] = 4500;

	//四、遍历
	cout << "multimap的初始内容，自动排序：" << endl;
	for (mm_iter = mm.begin(); mm_iter != mm.end(); mm_iter++)
	{
		//迭代器对应的键部分用iter->first,值部分用iter->second
		cout << mm_iter->first << " " << mm_iter->second << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	for (mm_iter = mm.begin(); mm_iter != mm.end(); mm_iter++)
	{
		//键部分用(*p).first,值部分(*p).second
		cout << (*mm_iter).first << " " << (*mm_iter).second << endl;
	}
	//五、元素查找
	//1、count，获取某个键的元素个数
	int qty = mm.count("IF2012");
	cout << "IF2012的个数为：" << qty << endl;
	//2、find，返回一个迭代器，该迭代器指向该健的第一个键值对元素
	mm_iter = mm.find("IF2012");
	//遍历打印
	for (int i = 0; i < qty; i++)
	{
		cout << "IF2012对应的数值：" << (*mm_iter).second << endl;
		mm_iter++;
	}
	//六、删除erase
	/*iterator erase(
		const_iterator Where
	);
	iterator erase(
		const_iterator First,
		const_iterator Last
	);
	size_type erase(
		const key_type & Key
	);*/
	//1、用键删除
	mm.erase("IF2012");
	mm.insert(make_pair("IF2010", 2800));
	mm.insert(make_pair("IF2008", 2600));
	//2、迭代器位置删除
	multimap<string, int>::iterator iter0=mm.begin();
	//mm.erase(iter);
	multimap<string, int>::iterator iter1 = mm.begin();
	iter1++;
	mm.erase(iter0,++iter1);

	cout << "删除元素" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "删除后multimap的内容" << endl;
	for (mm_iter = mm.begin(); mm_iter != mm.end(); mm_iter++)
	{
		//迭代器对应的值用->
		cout << mm_iter->first << " " << mm_iter->second << endl;
	}
	getchar();
	return 0;
}