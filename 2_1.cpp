/*
 * 2_1.cpp
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
	}

private:
	int &i;
	void increment(int &i) {
		++i;
	}
};

int main() {
	background_task f;
	std::thread t1{f};
	std::thread t2{background_task{}};

	std::thread t3([]() {
		std::cout << "from lambda expression" << std::endl;
	});

	t1.join();
	t2.join();
	t3.join();

	int local_state = 0;
	// send local variable as reference to func object.
	// func object of t4 refers to the local variable even after the
	// main thread has exited
	func my_func{local_state};
	std::thread t4(my_func);
	// since the thread is detached, local_state is referred in t4 though main
	// has gone out of scope. fix this by calling t4.join
	t4.join(); //t4.detach();
	// now, after t4.join, t4 is no longer associated with any thread
	// calling t4.joinable will return false
}


