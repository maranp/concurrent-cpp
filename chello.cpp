/*
 * chello.cpp
 *
 *  Created on: 11-Oct-2016
 *      Author: maran
 */
#include <thread>
#include <iostream>

void hello() {
  std::cout << "hello concurrent world\n";
}

int main() {
  std::thread t(hello);
  std::cout << "number of hardware threads" << std::thread::hardware_concurrency() << std::endl;
  t.join();
}
