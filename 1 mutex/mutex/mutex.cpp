#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
mutex mtx;
int cnt = 20;

void t1(void)
{
	mtx.lock();
	cout << "in t1..." << endl;
	while (cnt >= 0)
	{
		cout << "cnt is " << cnt << endl;
		cnt--;
	}
	mtx.unlock();
}

void t2(void)
{
	mtx.lock();
	cout << "in t2..." << endl;
	if (cnt <= 0)
	{
		cout << "cnt<=0" << endl;
		cnt = 15;
	}
	while (cnt >= 0)
	{
		cout << "cnt is " << cnt << endl;
		cnt--;
	}
	mtx.unlock();
}

int main()
{
	thread a(t1);
	thread b(t2);
	a.join();
	b.join();
	//a.detach();
	//b.detach();
	getchar();
	return 0;
}