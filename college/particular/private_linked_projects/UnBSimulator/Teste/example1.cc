#include <boost/thread.hpp>

void fun () {
  std::cout << "boo!" << std::endl;
}

int main () {
  boost::thread t (fun);
  t.join ();
}