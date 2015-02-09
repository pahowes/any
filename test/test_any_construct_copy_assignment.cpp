#include <string>
#include <any.hpp>

int main() {
    try {
      type::any a(std::string("test"));
      type::any b = a;
      b = a;
      if (&a != &b && a.as<char*>() == b.as<char*>() && strcmp(b.as<char*>(), "test") == 0) {
        return 0;
      }
      return -1;
    }
    catch(...) {
      return -1;
    }
}

