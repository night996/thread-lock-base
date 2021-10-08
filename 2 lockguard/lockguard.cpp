#include<mutex>
#include<iostream>
using namespace std;

int cnt = 20;
mutex m;//1������һ��������m
void t1()
{
	lock_guard<mutex> lockGuard(m);//2������,����һ��lock_guard �����߳̽����Զ�����
	while (cnt > 0)
	{

		if (cnt > 0)
		{
			--cnt;
			cout << cnt << endl;
		}

	}
}
void t2()
{
	lock_guard<mutex> lockGuard(m);

	cout << "execute in t2  " << endl;
	if (cnt <= 0)
	{
		cout << "cnt <=0 " << endl;
		cnt = 20;
	}

	while (cnt > 0)
	{

		if (cnt > 0)
		{
			--cnt;
			cout << cnt << endl;
		}

	}
}

int main()
{

	thread th1(t1);
	thread th2(t2);

	th1.join();
	th2.join();
	system("pause");
	return 0;
}