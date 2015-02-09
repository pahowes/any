# ANY

Variant type for C++

This is similar to [Boost.Any](http://www.boost.org/doc/libs/release/doc/html/any.html) in that any
type can be encapsulated and retrieved, but this implementation does not have any dependencies which
keeps the footprint much smaller than Boost.Any.

# Building

The `any` variant type is distributed only as a header. There is nothing to compile in this
repository other than tests which also illustrate how to use `any`.

## Dependencies

* [CMake](http://www.cmake.org) 2.8.12 or newer
* C compiler. The following have been tested:
  * [llvm](http://llvm.org) 3.5 or newer
  * [gcc](http://gcc.gnu.org) 4.8.2 or newer
  * [Visual Studio 2013 Update 4](http://www.visualstudio.com)

All tests have passed on OS X 10.0, Ubuntu 14.04.1, Ubuntu 14.10, and Fedora 21.

## Instructions

I highly recommend building outside of the source tree so that build products do not pollute the
repository. The simplest way to accomplish this is to create a sub-directory named "build" as
follows:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

# Examples

Construct from a machine type:

    type::any a = 3.14159;
    std::cout << "a = " << a.as<double>() << std::endl;

Construct from a constant array (e.g. C-style string):

    type::any a = "string";
    std::cout << "a = " << a.as<char const*>() << std::endl;

Construct from an object reference

    type::any a = std::string("string");
    std::cout << "a = " << a.as<std::string>() << std::endl;

Construct from an object pointer:

    struct obj {
      char const* str() { return "string"; }
    };

    obj* o = new obj();
    type::any a = o;
    std::cout << "a = " << a.as<obj*>()->str() << std::endl;
    delete o;

# TODO List

1. Add type check to type::any::as method.
2. Add more tests.

# Contributing

1.  Fork it
2.  Create a feature branch (`git checkout -b new-feature`)
3.  Commit changes (`git commit -am "Added new feature xyz"`)
4.  Push the branch (`git push origin new-feature`)
5.  Create a new pull request.

# Maintainers

* Paul Howes (http://github.com/PaulHowes/)

# License

`type::any` variant type copyright 2015 Paul Howes and is licensed under the Apache License.
