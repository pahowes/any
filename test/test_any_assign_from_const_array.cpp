#include <string.h>
#include <any.hpp>

int main() {
  try {
    type::any a;
    a = "test";
    if(strcmp(a.as<char*>(), "test") == 0) {
      return 0;
    }
    return -1;
  }
  catch(...) {
    return -1;
  }
}


