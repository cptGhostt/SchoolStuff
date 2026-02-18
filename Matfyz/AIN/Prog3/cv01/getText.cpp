#include <iostream>

std::string DUMMY_STRING = "Empty input";

std::string getText(const std::string &inputText) {
    return inputText.empty() ? DUMMY_STRING : inputText;
}
