/*
 * 2_3.cpp
 *
 *  Created on: 11-Oct-2016
 *      Author: maran
 */

#include <thread>
#include <iostream>

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

int main() {
	int local_state = 0;

	func my_func{local_state};

	auto delete_thread = [](std::thread *t) {
		if (t->joinable()) {
			std::cout << "new threadid " << std::this_thread::get_id() << std::endl;
			std::cout << "new threadid " << t->get_id() << std::endl;
			t->join();
			std::cout << "joined in closure\n";
			delete t;
		}
	};
	std::unique_ptr<std::thread, decltype(delete_thread)>
		tptr(new std::thread(my_func), delete_thread);

	std::cout << "main threadid:" << std::this_thread::get_id() << std::endl;

	for (int idx = 0; idx < 10000000; idx++) {
		idx += idx * 2 - idx * 2;
	}
}
