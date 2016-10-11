/*
 * 2_2.cpp
 *
 *  Created on: 10-Oct-2016
 *      Author: maran
 */

#include <thread>
#include <iostream>

class background_task {
public:
	void operator() () {
		std::cout << "from operator" << std::endl;
	}
};

struct func {
	func(int &iref) : i(iref) {
		std::cout << "from func's c'tor" << std::endl;
	}
	void operator() () {
		std::cout << "from func's operator" << std::endl;
		for (int idx = 0; idx < 10000000; idx++) {
			increment(i);
		}
		std::cout << "func's operator complete" << std::endl;
	}

private:
	int &i;
	void increment(int &i) {
		++i;
	}
};

struct thread_guard {
	std::thread &t;

	thread_guard(std::thread &tref) : t(tref) {}
	thread_guard(const thread_guard &g) = delete;
	thread_guard & operator=(thread_guard &g) = delete;
	~thread_guard() {
		if (t.joinable()) {
			t.join();
		}
	}
};

int main() {
	int local_state = 0;

	func my_func{local_state};
	std::thread t4(my_func);

	thread_guard g(t4);

	//try {
		for (int idx = 0; idx < 10000000; idx++) {
			idx += idx * 2 - idx * 2;
		}
	//} catch(...) {
	//	t4.join();
	//	throw;
	//}
	//t4.join();
}


