// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    T arr[size];
    int head;
public:
    TStack() :head(-1) {}
    void Push(T val) {
        if (IsFull()) return;
        arr[++head] = val;
    }
    const T& Pop() {
        if (IsEmpty()) return NULL;
        return arr[head--];
    }
    const T& Get() { return arr[head]; }
    bool IsFull() const {
        return head == size - 1;
    }
    bool IsEmpty() const {
        return head == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
