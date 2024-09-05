#ifndef __FOLD_TPP__
#define __FOLD_TPP__

#include <optional>
#include <ranges>

namespace og
{


template <typename InuptIt, class T, class F>
constexpr auto fold_left(InuptIt first, InuptIt last, T init, F f)
{
    if (first == last)
        return std::move(init); 

    auto val = f(init, *first);

    ++first;

    for (; first != last; ++first)
    {
        val = f(val, *first);
    }

    return std::move(val);
}


template <InputRange range, class T, class F>
constexpr auto fold_left(range&& R, T init, F f)
{
    return fold_left(R.begin(), R.end(), init, f);
}


template <typename InuptIt, class F>
constexpr auto fold_left_first(InuptIt first, InuptIt last, F f)
{

    if (first == last)
        throw std::logic_error("ba"); 

    auto val = f(*(first), *(first + 1));

    ++first;

    if (first == last)
        return val;

    ++first;    

    for (; first != last; ++first)
    {
        val = f(val, *first);
    }

    return std::move(val);
}


template <InputRange range, class F>
constexpr auto fold_left_first(range&& R, F f)
{
    return fold_left_first(R.begin(), R.end(), f);
}


template <typename BiDirIt, class T, class F>
constexpr auto fold_right(BiDirIt first, BiDirIt last, T init, F f)
{
    if (first == last)
        return std::move(init);
    
    --last;

    auto val = f(init, *last);

    if (first == last)
        return std::move(val);

    --last;

    for (; last != first; --last)
    {
        val = f(val, *last);
    }

    return f(val, *first);   
}




template <InputRange range, class T, class F>
constexpr auto fold_right(range&& R, T init, F f)
{
    return fold_right(R.begin(), R.end(), init, f);
}

}






#endif // __FOLD_TPP__