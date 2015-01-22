#include <string.h>
#include <any.hpp>

int main() {
  try {
    type::any a("test");
    type::any b(a);
    if(strcmp(b.as<char*>(), "test") == 0) {
      return 0;
    }
    return -1;
  }
  catch(...) {
    return -1;
  }
}


