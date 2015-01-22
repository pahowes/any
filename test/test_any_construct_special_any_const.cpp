#include <any.hpp>

int main() {
  try {
    type::any a(3.14159);
    type::any b(a);
    if(b.as<double>() == 3.14159) {
      return 0;
    }
    return -1;
  }
  catch(...) {
    return -1;
  }
}


