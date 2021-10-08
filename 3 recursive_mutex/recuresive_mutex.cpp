#include <iostream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;
class X {
	recursive_mutex m;
	string shared;
public:
	void func1() {
		lock_guard<recursive_mutex> lx(m);
		shared = "fun1";
		cout << "in fun1 now shard is" << shared << endl;
	}
	void func2() {
		lock_guard<recursive_mutex> lx(m);
		shared = "fun2";
		cout << "in fun2 now shard is" << shared << endl;
		func1();
		cout << "back fun2 now shard is" << shared << endl;
	}
};
int main()
{
	X obj;
	thread t1(&X::func1,&obj);
	thread t2(&X::func2,&obj);
	t1.join();
	t2.join();
	getchar();
	return 0;
}