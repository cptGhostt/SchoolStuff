#pragma once

#include <iostream>
#include <sstream>

const int MAX = 10;
const std::string NONEXISTING_ELEMENT = "Index out of scope";

template<typename T> class Array {
  T emptyItem {};
  T *myArray;
  int max {MAX};
  int numberOfElements;
 public:
  Array();
  ~Array();
  bool reserve(int newMax);
  bool append(const T &element);
  bool insert(const T &element, int index);
  std::string listOfItems(char delimiter);
  bool remove(int index);
  int size() const { return numberOfElements; };
  int maxSize() const { return max; };

  //2. ulohu
  T &operator[](int index);
  Array(const Array<T> &input);
  Array(Array<T> &&input);
  Array<T> &operator=(const Array<T> &input);
  Array<T> &operator=(Array<T> &&input);
  void operator+=(const Array<T> &input);
  void operator+=(Array<T> &&input);
};

const bool DUMMY_BOOL = false;
const int DUMMY_INT = 0;
const std::string DUMMY_STRING = "";

template<typename T> Array<T>::Array() {
    myArray = new T[MAX];
    numberOfElements = 0;
    max = MAX;
}

template<typename T> Array<T>::~Array() {
    delete[] myArray;
}

template<typename T> bool Array<T>::reserve(int newMax) {
    if (newMax <= max) {
        return false;
    }

    T *newArray = new T[newMax];
    for (int i = 0; i < numberOfElements; i++) {
        newArray[i] = myArray[i];
    }
    delete[] myArray;
    myArray = newArray;
    max = newMax;

    return true;
}

template<typename T> bool Array<T>::append(const T &element) {
    if (numberOfElements >= max) {
        reserve(max*2);
    }
    myArray[numberOfElements++] = element;
    return true;
}

template<typename T> bool Array<T>::insert(const T &element, int index) {
    if (index < 0) {
        return false;
    }

    if (index >= numberOfElements) {
        return append(element);
    }
    if (numberOfElements >= max) {
        reserve(max*2);
    }
    for (int i = numberOfElements-1; i >= index; i--) {
        myArray[i+1] = myArray[i];
    }

    myArray[index] = element;
    numberOfElements++;
    return true;
}

template<typename T> std::string Array<T>::listOfItems(char delimiter) {
    std::ostringstream os;
    if (numberOfElements > 0) {
        os << myArray[0];
    }
    for (int i = 1; i < numberOfElements; i++) {
        os << delimiter << myArray[i];
    }
    return os.str();
}

template<typename T> bool Array<T>::remove(int index) {
    if (index < 0 || index >= numberOfElements) {
        return false;
    }
    for (int i = index; i < numberOfElements-1; i++) {
        myArray[i] = myArray[i+1];
    }
    numberOfElements--;
    return true;
}

//2 uloha
template<typename T> T &Array<T>::operator[](int index) {
    if (index < 0 || index >= numberOfElements) {
        return emptyItem;
    }
    return myArray[index];
}

template<> inline std::string &Array<std::string>::operator[](int index) {
    emptyItem = NONEXISTING_ELEMENT;
    if (index < 0 || index >= numberOfElements) {
        return emptyItem;
    }
    return myArray[index];
}

template<typename T> Array<T>::Array(const Array<T> &input) {
    this = input;
}

template<typename T> Array<T>::Array(Array<T> &&input) {
    this = input;
}

template<typename T> Array<T> &Array<T>::operator=(const Array<T> &input) {
    max = input.maxSize();
    numberOfElements = input.numberOfElements;
    myArray = new T[max];
    for (int i = 0; i < numberOfElements; i++) {
        myArray[i] = input.myArray[i];
    }
    return *this;
}

template<typename T> Array<T> &Array<T>::operator=(Array<T> &&input) {
    numberOfElements = input.numberOfElements;
    input.numberOfElements = 0;
    myArray = input.myArray;
    input.myArray = nullptr;
    max = input.max;
    input.max = 0;
    return *this;
}

template<typename T> void Array<T>::operator+=(const Array<T> &input) {
    for (int i = 0; i < input.numberOfElements; i++) {
        append(input.myArray[i]);
    }
}

template<typename T> void Array<T>::operator+=(Array<T> &&input) {
    for (int i = 0; i < input.numberOfElements; i++) {
        append(input.myArray[i]);
    }
    input.numberOfElements = 0;
    input.max = 0;
    input.myArray = nullptr;
}
