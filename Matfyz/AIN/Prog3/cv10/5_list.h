#pragma once

#include <iostream>
#include "1_2_array.h"

const int EMPTY_LIST = -1;
enum MoveCurrent {FIRST, LAST, NEXT, PREVIOUS};

template<typename T> class List {  
    T emptyItem {0};
    Array<T> array;
    int currentIndex = EMPTY_LIST;
 public:
  bool setCurrent(MoveCurrent move);
  void append(const T &element);
  void insert(const T &element);
  T deleteCurrent();
  T &head();
  T &tail();
  T &current();

  std::string listOfItems() { return array.listOfItems(','); };
  int size() const { return array.size(); };
};

template<typename T> bool List<T>::setCurrent(MoveCurrent move) {
    if (size() == 0) {
        return false;
    }
    if (move == LAST) {
        currentIndex = size() - 1;
    } else if (move == NEXT) {
        if (currentIndex == size() - 1) {
            return false;
        }
        currentIndex++;
    } else if (move == PREVIOUS) {
        if (currentIndex == 0) {
            return false;
        }
        currentIndex--;
    } else if (move == FIRST) {
        currentIndex = 0;
    }
    return true;
}

template<typename T> void List<T>::append(const T &element) {
    if (size() == 0) {
        currentIndex = 0;
    }
    array.append(element);
}

template<typename T> void List<T>::insert(const T &element) {
    if (size() == 0) {
        currentIndex = 0;
        array.append(element);
        return;
    }
    array.insert(element, currentIndex);
}

template<typename T> T List<T>::deleteCurrent() {
    if (size() == 0) {
        return emptyItem;
    }
    T item = array[currentIndex];
    array.remove(currentIndex);
    if (currentIndex >= size() - 1) {
        currentIndex = size() - 1;
    }
    return item;
}

template<typename T> T &List<T>::head() {
    return array[0];
}

template<typename T> T &List<T>::tail() {
    return array[size() - 1];
};

template<typename T> T &List<T>::current() {
    return array[currentIndex];
};

