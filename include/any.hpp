/**
 * @file    any.hpp
 * @brief   A very simple variant for C++.
 */

#pragma once
#include <typeinfo>

/**
 * @namespace type
 */
namespace type {
  /**
   * @class any
   * @brief A very simple variant type for C++
   *
   * The Boost.any class is very feature complete, but also drags a large part of the Boost library
   * along with it. There is no easy way to separate that one concept without requiring a project
   * to depend on Boost itself.
   *
   * This class is an attempt to replicate most of the functionality of Boost.any in a self-
   * contained manner. There currently exist some limitations, such as not being able to create an
   * instance of type::any from another type::any instance. However this should work for most cases
   * where one would use Boost.any.
   */
  class any {
    public:
      /**
       * @brief Default constructor.
       */
      any() : _value(nullptr) { }

      /**
       * @brief Constructs and initializes a new type::any instance from an object reference.
       * @tparam    T     Value type.
       * @param[in] value Object that the type::any instance represents.
       */
      template<typename T> any(T& value)
        : _value(new erasure_impl<typename std::decay<T&>::type>(value)) { }

      /**
       * @brief Constructs and initializes a new type::any instance from a constant.
       * @tparam T Value type.
       * @param[in] value Constant that the type::any instance represents.
       */
      template<typename T> any(T const& value)
        : _value(new erasure_impl<typename std::decay<T const&>::type>(value)) { }

      /**
       * @brief Constructs and initializes a new type::any instance from an object pointer.
       * @tparam T Value type.
       * @param[in] value Object pointer that the type::any instance represents.
       */
      template<typename T> any(T* value)
        : _value(new erasure_impl<typename std::decay<T*>::type>(value)) { }

      /**
       * @brief Constructs and initializes a new type::any instance from an array or const pointer.
       * @tparam T Value type.
       * @param[in] value Array or pointer that the type::any instance represents.
       */
      template<typename T> any(T const* value)
        : _value(new erasure_impl<typename std::decay<T const*>::type>(value)) { }

      /**
       * @brief Object destructor.
       */
      ~any() { if(_value) delete _value; }

      /**
       * @brief Sets the value of the type::any instance from an object reference.
       * @tparam T Value type.
       * @param[in] value Object that the type::any instance represents.
       * @return Reference to the type::any instance.
       */
      template<typename T> any& operator=(T& value) {
        if(_value) delete _value;
        _value = new erasure_impl<typename std::decay<T&>::type>(value);
        return *this;
      }

      /**
       * @brief Sets the value of the type::any instance from a constant.
       * @tparam T Value type.
       * @param[in] value Constant that the type::any instance represents.
       * @return Reference to the type::any instance.
       */
      template<typename T> any& operator=(T const& value) {
        if(_value) delete _value;
        _value = new erasure_impl<typename std::decay<T const&>::type>(value);
        return *this;
      }

      /**
       * @brief Sets the value of the type::any instance from an object pointer.
       * @tparam T Value type.
       * @param[in] value Object pointer that the type::any instance represents.
       * @return Reference to the type::any instance.
       */
      template<typename T> any& operator=(T* value) {
        if(_value) delete _value;
        _value = new erasure_impl<typename std::decay<T*>::type>(value);
        return *this;
      }

      /**
       * @brief Sets the value of the type::any instance from an array or const pointer.
       * @tparam T Value type.
       * @param[in] value Array or const pointer that the type::any instance represents.
       * @return Reference to the type::any instance.
       */
      template<typename T> any& operator=(T const* value) {
        if(_value) delete _value;
        _value = new erasure_impl<typename std::decay<T const*>::type>(value);
        return *this;
      }

      /**
       * @brief Retrieves the value represented by the type::any object.
       * @tparam T Type to cast the represented value to.
       * @return Reference to the represented value.
       */
      template<typename T> T& as() const {
        return static_cast<erasure_impl<T>*>(_value)->value();
      }

      /**
       * @brief Retrieves the type of the value represented by the type::any object.
       * @return Reference to the std::type_info structure that describes the value type.
       */
      std::type_info const& type() const { return _value->type(); }

    private:

      struct erasure {
        virtual ~erasure() = 0;
        virtual std::type_info const& type() const = 0;
      };

      template<typename T> class erasure_impl : public erasure {
        public:
          erasure_impl(T value) : _value(value) { }
          virtual std::type_info const& type() const { return typeid(T); }
          T& value() { return _value; }
        private:
          T _value;
      };

      erasure* _value;
  };

  any::erasure::~erasure() { }
}
