// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class TStack {
 private:
    T *arr;
    int head;

 public:
    TStack() :head(-1) {
       arr = new T[size];
    }
    void Push(T val) {
        if (IsFull())
            throw std::string("full");
        else
            arr[++head] = val;
    }
    const T& Pop() {
        if (IsEmpty())
            throw std::string("emp");
        else
            return arr[head--];

    }
    const T& Get() {
        if (IsEmpty())
            throw std::string("emp");
        else
            return arr[head];
    }
    bool IsFull() const {
        return head == size - 1;
    }
    bool IsEmpty() const {
        return head == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
