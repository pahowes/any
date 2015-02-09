#include <string.h>
#include <any.hpp>

struct obj {
  obj(char const* s) : str(s) { }
  char const* str;
};

int main() {
  try {
    obj* o = new obj("test");
    type::any a(o);
    type::any b(a);
    if(strcmp(b.as<obj*>()->str, "test") == 0) {
      delete o;
      return 0;
    }
    return -1;
  }
  catch(...) {
    return -1;
  }
}



