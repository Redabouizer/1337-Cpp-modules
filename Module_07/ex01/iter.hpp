#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, std::size_t length, void (*func)(T &))
{
    if (array == NULL || func == NULL)
        return;
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void iter(T const *array, std::size_t length, void (*func)(T const &))
{
    if (array == NULL || func == NULL)
        return;
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif
