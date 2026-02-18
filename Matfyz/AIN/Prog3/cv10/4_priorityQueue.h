#pragma once

#include <iostream>
#include "1_2_array.h"
#include "3_queue.h"

template<typename T> bool lesser(T x, T y) {
    return x <= y;
}

template<typename T> bool bigger(T x, T y) {
    return x >= y;
}

template<typename T> bool fifo(T x, T y) {
    return false;
}

template<typename T> bool lifo(T x, T y) {
    return true;
}

template<typename T> class PriorityQueue {
    T emptyItem {};
    Array<T> array;
    bool (*order)(T x, T y) = lesser<T>;
public:
    void setOrder(bool (*order)(T x, T y));
    void push(const T &element);
    void push(const PriorityQueue<T> &queue);
    T &front() { return array[0]; };
    T pop();
    int size() const { return array.size(); };
    std::string list();
};

template<typename T>
void PriorityQueue<T>::setOrder(bool (*ordering)(T, T)) {
    order = ordering;
}

template<typename T> void PriorityQueue<T>::push(const T &element) {
    for (int i = 0; i < array.size(); i++) {
        if (order(element, array[i])) {
            array.insert(element, i);
            return;
        }
    }
    array.append(element);
}

template<typename T> T PriorityQueue<T>::pop() {
    if (array.size() == 0) {
        return emptyItem;
    }

    T tmp;
    if (order(array[0], array[1])) {
        tmp = array[0];
        array.remove(0);
    } else {
        tmp = array[array.size() - 1];
        array.remove(array.size() - 1);
    }
    return tmp;
}

template<typename T> void PriorityQueue<T>::push(const PriorityQueue<T> &queue) {
    PriorityQueue<T> tmp;
    tmp = queue;

    for (int i = 0; i < tmp.array.size(); i++) {
        push(tmp.array[i]);
    }
}

template<typename T> std::string PriorityQueue<T>::list() {
    if (array.size() == 0) {
        return "";
    }
    std::ostringstream os;
    os << array[0];
    for (int i = 1; i < array.size(); i++) {
        os << "," << array[i];
    }
    return os.str();
}
