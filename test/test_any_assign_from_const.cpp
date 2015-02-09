#include <any.hpp>

int main() {
  try {
    type::any a;
    a = 3.14159;
    if(a.as<double>() == 3.14159) {
      return 0;
    }
    return -1;
  }
  catch(...) {
    return -1;
  }
}


