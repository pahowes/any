#include <string.h>
#include <any.hpp>

struct obj {
  obj(char const* s) : str(s) { }
  char const* str;
};

int main() {
  try {
    obj o("test");
    type::any a;
    a = o;
    if(strcmp(a.as<obj>().str, "test") == 0) {
      return 0;
    }
    return -1;
  }
  catch(...) {
    return -1;
  }
}


