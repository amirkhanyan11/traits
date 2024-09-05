#ifndef __FOLD_HPP__
#define __FOLD_HPP__

#include <concepts>

namespace og
{


template <typename T>
concept InputRange = requires(T ob)
{
    ob.begin();
    ob.end();
    // {ob.begin()} -> std::same_as<typename T::iterator>;
    // {ob.end()} -> std::same_as<typename T::iterator>;
};

template <typename InuptIt, class T, class F>
constexpr auto fold_left(InuptIt first, InuptIt last, T init, F f);

template <InputRange range, class T, class F>
constexpr auto fold_left(range&& R, T init, F f);


template <typename InuptIt, class F>
constexpr auto fold_left_first(InuptIt first, InuptIt last, F f);

template <InputRange range, class F>
constexpr auto fold_left_first(range&& R, F f);


}




#include "fold.tpp"




#endif // __FOLD_HPP__