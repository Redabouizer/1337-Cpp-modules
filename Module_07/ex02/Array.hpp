#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
public:
    Array() : _size(0), _data(NULL)
    {
    }

    explicit Array(unsigned int n) : _size(n), _data(NULL)
    {
        if (_size > 0)
        {
            _data = new T[_size];
        }
    }

    Array(Array const &other) : _size(0), _data(NULL)
    {
        *this = other;
    }

    ~Array()
    {
        delete[] _data;
    }

    Array &operator=(Array const &other)
    {
        if (this != &other)
        {
            T *newData = NULL;
            if (other._size > 0)
            {
                newData = new T[other._size];
                for (unsigned int i = 0; i < other._size; ++i)
                    newData[i] = other._data[i];
            }

            delete[] _data;

            _size = other._size;
            _data = newData;
        }
        return *this;
    }

    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Array index out of bounds");
        return _data[index];
    }

    T const &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Array index out of bounds");
        return _data[index];
    }

    unsigned int size() const
    {
        return _size;
    }

private:
    unsigned int _size;
    T *_data;
};

#endif
