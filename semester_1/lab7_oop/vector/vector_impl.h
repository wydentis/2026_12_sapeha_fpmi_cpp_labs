#pragma once

#include <initializer_list>
#include <cstddef>
#include <stdexcept>
#include <iostream>

class Vector {
public:
    Vector();
    Vector(size_t size);
    Vector(const std::initializer_list<int>& list);
    Vector(const Vector& other);

    Vector& operator=(const Vector& other);

    ~Vector();

    void Swap(Vector& other);

    int& operator[](std::size_t idx);
    const int& operator[](std::size_t idx) const;

    int& At(std::size_t idx);
    const int& At(std::size_t idx) const;

    size_t Size() const;
    size_t Capacity() const;

    void PushBack(int val);
    int PopBack();
    void Clear();
    void Reserve(size_t capacity);

    friend std::ostream& operator<<(std::ostream& out, const Vector& v);

private:
    int* memory_;
    size_t size_;
    size_t capacity_;
};
