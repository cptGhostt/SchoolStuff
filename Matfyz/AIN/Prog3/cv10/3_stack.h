#pragma once

#include <iostream>
#include "1_2_array.h"

template<typename T> class Stack {
  T emptyItem {};
  Array<T> array;
 public:
  bool empty() const;
  void push(const T &element);
  void push(const Stack<T> &stack);
  T pop();
};

template<typename T> bool Stack<T>::empty() const {
    if (array.size() == 0) {
        return true;
    }
    return false;
};

template<typename T> void Stack<T>::push(const T &element) {
    array.append(element);
}

template<typename T> void Stack<T>::push(const Stack<T> &stack) {
    Stack<T> tmp;
    tmp = stack;

    for (int i = 0; i < tmp.array.size(); i++) {
        array.append(tmp.array[i]);
    }
}

template<typename T> T Stack<T>::pop() {
    if (array.size() == 0) {
        return emptyItem;
    }

    T item = array[array.size() - 1];
    array.remove(array.size() - 1);

    return item;
}
