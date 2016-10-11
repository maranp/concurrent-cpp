/*
 * chello.cpp
 *
 *  Created on: 07-Oct-2016
 *      Author: maran
 */

//#include "chello.h"
#include <thread>
#include <iostream>

//chello::chello() {
//	// TODO Auto-generated constructor stub
//
//}
//
//chello::~chello() {
//	// TODO Auto-generated destructor stub
//}

void hello() {
  std::cout << "hello concurrent world\n";
}

int main() {
  std::thread t(hello);
  std::cout << "number of hardware threads" << std::thread::hardware_concurrency() << std::endl;
  //hello();
  t.join();
}
