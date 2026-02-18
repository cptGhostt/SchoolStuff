#pragma once

#include <iostream>
#include "1_2_array.h"

template<typename T> class Queue {
    T emptyItem {};
    Array<T> array;
public:
    void push(const T &element);
    void push(const Queue<T> &queue);
    T &front() { return array[0]; };
    T pop();
    int size() const { return array.size(); };
};

template<typename T> void Queue<T>::push(const T &element) {
    array.append(element);
}

template<typename T> void Queue<T>::push(const Queue<T> &queue) {
    Queue<T> tmp;
    tmp = queue;

    for (int i = 0; i < tmp.size(); i++) {
        array.append(tmp.array[i]);
    }
}

template<typename T> T Queue<T>::pop() {
    if (size() == 0) {
        return emptyItem;
    }
    T item = array[0];
    array.remove(0);
    return item;
}
