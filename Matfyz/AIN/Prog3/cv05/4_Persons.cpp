#include "4_Persons.h"

//4. uloha
void Persons::increaseSizeOfPersons(int numberOfNewPersons) {
    if (numberOfNewPersons <= 0) {
        return;
    }

    Person *newArr = new Person[(numberOfRecs + numberOfNewPersons) * 2];
    for (int i = 0; i < numberOfRecs; i++) {
        newArr[i] = persons[i];
    }
    delete[] persons;
    persons = newArr;
    maximum = (numberOfRecs + numberOfNewPersons) * 2;
}

bool Persons::append(const std::string &list) {
    if (list.empty()) {
        return false;
    }

    int delimiters = 0;
    for (int i = 0; i < list.length(); i++) {
        if (list[i] == ';') {
            delimiters++;
        }
    }

    if (numberOfRecs+delimiters+1 > maximum) {
        increaseSizeOfPersons(delimiters+1);
    }

    Person personValidator;

    for (int i = 0; i < delimiters+1; i++) {
        if (personValidator.put(subString(list,i+1, ';')) == OK) {
            Person tmp;
            tmp.put(subString(list,i+1, ';'));
            persons[numberOfRecs] = tmp;
            numberOfRecs++;
        }
    }

    return true;
}

std::string Persons::get(int personNumber) const {
    if (personNumber > numberOfRecs) {
      return "";
    }

    return persons[personNumber-1].get();
}

Person Persons::getPerson(int personNumber) const {
    Person DUMMY_PERSON;
    if (personNumber > numberOfRecs) {
        return DUMMY_PERSON;
    }

    return persons[personNumber-1];
}

