#include <string.h>
#include <any.hpp>

int main() {
  try {
    type::any a("test");
    if(typeid(char const*) == a.type()) {
      return 0;
    }
    return -1;
  }
  catch(...) {
    return -1;
  }
}


