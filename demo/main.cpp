#include <sharedptr.hpp>

int main() {
struct Klan{
  int a;
  int b;
};
Klan klan1 = {1,2};
Klan klan2 = {3,4};
SharedPtr<Klan> a(&klan1);
SharedPtr<Klan> b(&klan2);
SharedPtr<Klan> c(&klan2);
a.swapPtr(b);
std::cout << a.get() << std::endl;
std::cout << b.get() << std::endl;
std::cout << c.get() << std::endl;
}
//g