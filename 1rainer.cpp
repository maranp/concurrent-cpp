/*
 * 1rainer.cpp
 *
 *  Created on: 17-Oct-2016
 *      Author: maran
 */




/*
 * 2_2.cpp
 *
 *  Created on: 11-Oct-2016
 *      Author: maran
 */

#include <thread>
#include <iostream>
#include <boost/lambda/lambda.hpp>

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

//template <typename T1, typename T2>
//typename std::conditional<sizeof(T1) < sizeof(T2), T1, T2>::type gcd(T1 a, T2 b) {
//	static_assert(std::is_integral<T1>::value, " T should be an integral type");
//	static_assert(std::is_integral<T2>::value, " T should be an integral type");
//	if (b == 0)
//		return a;
//	return gcd(b, a % b);
//}

//template <typename T1, typename T2>
//typename std::common_type<T1, T2>::type gcd(T1 a, T2 b) {
//	static_assert(std::is_integral<T1>::value, " T should be an integral type");
//	static_assert(std::is_integral<T2>::value, " T should be an integral type");
//	if (b == 0)
//		return a;
//	return gcd(b, a % b);
//}

template <typename T,
typename std::enable_if<std::is_integral<T>::value, T>::type = 0>
T gcd(T a, T b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	std::cout << "gcd:" << gcd(10, 20) << std::endl;
//	std::cout << "gcd:" << gcd(10, 20L) << std::endl;
//	std::cout << "gcd:" << gcd(20LL, 10L) << std::endl;
	//auto res1 = gcd(20LL, 10L);
	//auto res2 = gcd(20, 10L);
	auto res3 = gcd(20, 10);
	//auto res = gcd(20.5, 10.5);
//	std::cout << "typeof result: " << typeid(res1).name() << std::endl;
//	std::cout << "typeof result: " << typeid(res2).name() << std::endl;
	std::cout << "typeof result: " << typeid(res3).name() << std::endl;
}


