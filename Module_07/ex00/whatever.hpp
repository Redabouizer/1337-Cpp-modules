#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &lhs, T &rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

template <typename T>
T const &min(T const &lhs, T const &rhs)
{
    return (rhs <= lhs) ? rhs : lhs;
}

template <typename T>
T const &max(T const &lhs, T const &rhs)
{
    return (rhs >= lhs) ? rhs : lhs;
}

#endif
