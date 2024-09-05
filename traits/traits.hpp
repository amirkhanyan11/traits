
#ifndef __TRAITS___
#define __TRAITS___


#include <type_traits>
#include <iostream>


namespace og
{

using std::false_type, std::true_type;


template <class T, class U>
struct is_same : false_type {};

template <class T>
struct is_same<T, T> : true_type {};

template <typename T, typename U, typename... Ts>
struct is_all_same
{
	static constexpr bool value = is_same<T, U>::value || is_all_same<U, Ts...>::value;
};

template <typename T, typename U>
struct is_all_same<T, U>
{
	static constexpr bool value = is_same<T, U>::value;
};





template <typename T>
struct remove_const
{
	using type = T;
};

template <typename T>
struct remove_const<const T>
{
	using type = T;
};

template <typename T>
using remove_const_t = typename remove_const<T>::type;

template <typename T>
struct remove_volatile
{
	using type = T;
};

template <typename T>
struct remove_volatile<volatile T>
{
	using type = T;
};

template <typename T>
using remove_volatile_t = typename remove_volatile<T>::type;

template <typename T>
struct remove_cv
{
	using type = typename remove_const<typename remove_volatile<T>::type>::type;
};

template <typename T>
using remove_cv_t = typename remove_cv<T>::type;





template <typename T>
struct add_const
{
	using type = const T;
};

template <typename T>
using add_const_t = typename add_const<T>::type;


template <typename T>
struct add_volatile
{
	using type = volatile T;
};

template <typename T>
using add_volatile_t = typename add_volatile<T>::type;

template <typename T>
struct add_cv
{
	using type = typename add_const<typename add_volatile<T>::type>::type;
};

template <typename T>
using add_cv_t = typename add_cv<T>::type;




template <typename T>
struct is_lvalue_reference : false_type {};

template <typename T>
struct is_lvalue_reference<T&> : true_type {};

template <typename T>
using is_lvalue_reference_t = typename is_lvalue_reference<T>::type;


template <typename T>
struct is_rvalue_reference : false_type {};

template <typename T>
struct is_rvalue_reference<T&&> : true_type {};

template <typename T>
using is_rvalue_reference_t = typename is_rvalue_reference<T>::type;





template <typename T>
struct remove_reference
{
	using type = T;
};

template <typename T>
struct remove_reference<T&>
{
	using type = T;
};

template <typename T>
struct remove_reference<T&&>
{
	using type = T;
};

template <typename T>
using remove_reference_t = typename remove_reference<T>::type;


template <typename T>
struct add_lvalue_reference
{
	using type = T&;
};

template <typename T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

template <typename T>
struct add_rvalue_reference
{
	using type = T&&;
};

template <typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;




template <bool val, typename T, typename U>
struct conditional
{
	using type = T;
};


template <typename T, typename U>
struct conditional<false, T, U>
{
	using type = U;
};


template <bool val, typename T, typename U>
using conditional_t = typename conditional<val, T, U>::type;



template <typename T>
struct is_class : std::bool_constant<__is_class(T)> {};

template <typename T>
static constexpr bool is_class_v = is_class<T>::value;


template <bool val, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T>
{
	using type = T;
};





template <typename T>
concept integral = requires (T ob, T* ptr, void f(T)) 
{
    ptr + ob;
    static_cast<char>(ob);
    f(0);
};

template<typename T>
struct is_integral : false_type {};

template<integral T>
struct is_integral<T> : true_type {};


template<typename T>
static constexpr bool is_integral_v = is_integral<T>::value;




template <typename T>
concept polymorphic = requires (T* ptr)
{
	dynamic_cast<void*>(ptr);
};


template <typename T>
struct is_polymorphic : false_type {};

template <polymorphic T>
struct is_polymorphic<T> : true_type {};



template <typename T>
static constexpr bool is_polymorphic_v = is_polymorphic<T>::value;





template <typename T>
struct is_array : false_type {};

template <typename T>
struct is_array<T[]> : true_type {};

template <size_t N, typename T>
struct is_array<T[N]> : true_type {};

template <typename T>
static constexpr bool is_array_v = is_array<T>::value;








};








#endif // __TRAITS___
