#include<mutex>
#include<iostream>
using namespace std;

int cnt = 20;
mutex m;//1、声明一个互斥锁m
void t1()
{
	lock_guard<mutex> lockGuard(m);//2、加锁,创建一个lock_guard 对象，线程结束自动解锁
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