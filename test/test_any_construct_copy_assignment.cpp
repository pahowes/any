#include <string>
#include <any.hpp>

int main() {
    try {
      type::any b;
      b = type::any(true);
      if (b.as<bool>()) {
        return 0;
      }
      return -1;
    }
    catch(...) {
      return -1;
    }
}

