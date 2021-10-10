#include<map>
#include<iostream>
#include<functional>
#include <string>
using namespace std;
int main()
{//һ�� ͨ������ multimap ��ģ���Ĭ�Ϲ��캯�������Դ���һ���յ� multimap ����
	multimap<string, int> mm;
	
//������������ӳ��ĵ�����
	multimap<string, int>::iterator mm_iter;

//������������
	//1��ʹ��pair<type,type>(a,b)������ֵ�Զ���
	mm.insert(pair<string, int>("IF2012", 3500));
	mm.insert(pair<string, int>("IF2012", 3600));
	//2��ʹ��make_pair(a,b)������ֵ�Զ���
	mm.insert(make_pair("IF2101", 3800));
	//3��ʹ��map<type,type>::value_type(a,b)��־
	mm.insert(map<string, int>::value_type("IF2103", 4200));
	//����ʹ���±귨��������
	//mm["IF2000"] = 2050;

	//һ����������ӳ��,ͨ������ multimap ��ģ��Ŀ��������ƣ����캯����Ҳ���Գ�ʼ���µ� multimap ������
	multimap<string, int> mm1(mm);


	//һ����������ӳ��,3�õ������ķ�Χ����ʼ��
	multimap<string, int>::iterator b_iter = mm.begin();
	multimap<string, int>::iterator e_iter = mm.begin();
	e_iter++;
	e_iter++;
	e_iter++;
	//e_iter++;
	multimap<string, int> mm2(b_iter,e_iter);

	//һ����������ӳ��,4�õ������ķ�Χ,��ָ������׼��
	multimap<string, int,greater<string>> mm3(b_iter, e_iter, greater<string>(),mm.get_allocator());

	multimap<string, int,greater<string>> mm4(b_iter, e_iter, greater<string>());
	//4����Ӧmultimap�����������±귽ʽ
	//mm["IF2106"] = 4500;

	//�ġ�����
	cout << "multimap�ĳ�ʼ���ݣ��Զ�����" << endl;
	for (mm_iter = mm.begin(); mm_iter != mm.end(); mm_iter++)
	{
		//��������Ӧ�ļ�������iter->first,ֵ������iter->second
		cout << mm_iter->first << " " << mm_iter->second << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	for (mm_iter = mm.begin(); mm_iter != mm.end(); mm_iter++)
	{
		//��������(*p).first,ֵ����(*p).second
		cout << (*mm_iter).first << " " << (*mm_iter).second << endl;
	}
	//�塢Ԫ�ز���
	//1��count����ȡĳ������Ԫ�ظ���
	int qty = mm.count("IF2012");
	cout << "IF2012�ĸ���Ϊ��" << qty << endl;
	//2��find������һ�����������õ�����ָ��ý��ĵ�һ����ֵ��Ԫ��
	mm_iter = mm.find("IF2012");
	//������ӡ
	for (int i = 0; i < qty; i++)
	{
		cout << "IF2012��Ӧ����ֵ��" << (*mm_iter).second << endl;
		mm_iter++;
	}
	//����ɾ��erase
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
	//1���ü�ɾ��
	mm.erase("IF2012");
	mm.insert(make_pair("IF2010", 2800));
	mm.insert(make_pair("IF2008", 2600));
	//2��������λ��ɾ��
	multimap<string, int>::iterator iter0=mm.begin();
	//mm.erase(iter);
	multimap<string, int>::iterator iter1 = mm.begin();
	iter1++;
	mm.erase(iter0,++iter1);

	cout << "ɾ��Ԫ��" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "ɾ����multimap������" << endl;
	for (mm_iter = mm.begin(); mm_iter != mm.end(); mm_iter++)
	{
		//��������Ӧ��ֵ��->
		cout << mm_iter->first << " " << mm_iter->second << endl;
	}
	getchar();
	return 0;
}