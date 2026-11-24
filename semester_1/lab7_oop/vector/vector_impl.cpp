#include "vector_impl.h"

Vector::Vector() : memory_(nullptr), size_(0), capacity_(0) {
}

Vector::Vector(size_t size) : memory_(nullptr), size_(0), capacity_(0) {
    if (size > 0) {
        memory_ = new int[size];
        size_ = size;
        capacity_ = size;
    }

    for (std::size_t i = 0; i < size; ++i) {
        memory_[i] = 0;
    }
}

Vector::Vector(const std::initializer_list<int>& list)
    : memory_(nullptr), size_(list.size()), capacity_(list.size()) {
    if (list.size() > 0) {
        memory_ = new int[list.size()];
    }

    for (std::size_t i = 0; i < list.size(); ++i) {
        memory_[i] = *(list.begin() + i);
    }
}

Vector::Vector(const Vector& other)
    : memory_(nullptr), size_(other.Size()), capacity_(other.Capacity()) {
    if (other.Capacity() > 0) {
        memory_ = new int[other.Capacity()];
    }

    for (std::size_t i = 0; i < other.Size(); ++i) {
        memory_[i] = other[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] memory_;

    size_ = other.Size();
    capacity_ = other.Capacity();

    memory_ = new int[capacity_];

    for (std::size_t i = 0; i < size_; ++i) {
        memory_[i] = other[i];
    }

    return *this;
}

Vector::~Vector() {
    delete[] memory_;
}

void Vector::Swap(Vector& other) {
    int* tmp_memory = memory_;
    size_t tmp_size = size_;
    size_t tmp_capacity = capacity_;

    memory_ = other.memory_;
    size_ = other.Size();
    capacity_ = other.Capacity();

    other.memory_ = tmp_memory;
    other.size_ = tmp_size;
    other.capacity_ = tmp_capacity;
}

int& Vector::operator[](std::size_t idx) {
    return memory_[idx];
}

const int& Vector::operator[](std::size_t idx) const {
    return memory_[idx];
}

int& Vector::At(std::size_t idx) {
    if (idx >= size_) {
        throw std::out_of_range("index out of range");
    }

    return memory_[idx];
}

const int& Vector::At(std::size_t idx) const {
    if (idx >= size_) {
        throw std::out_of_range("index out of range");
    }

    return memory_[idx];
}

std::size_t Vector::Size() const {
    return size_;
}

std::size_t Vector::Capacity() const {
    return capacity_;
}

void Vector::PushBack(int val) {
    if (size_ == capacity_) {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        Reserve(new_capacity);
    }

    memory_[size_++] = val;
}

int Vector::PopBack() {
    if (size_ >= 1) {
        return memory_[--size_];
    }

    return 0;
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(size_t capacity) {
    if (capacity <= capacity_) {
        return;
    }

    capacity_ = capacity;
    int* new_memory = new int[capacity_];

    for (std::size_t i = 0; i < size_; ++i) {
        new_memory[i] = memory_[i];
    }

    delete[] memory_;

    memory_ = new_memory;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    out << '[';

    for (std::size_t i = 0; i < v.Size(); ++i) {
        out << v[i];

        if (i < v.Size() - 1) {
            out << ", ";
        }
    }

    out << ']';

    return out;
}
