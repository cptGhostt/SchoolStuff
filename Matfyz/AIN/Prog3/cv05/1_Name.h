#pragma once

#include "1_Element.h"

//1. uloha
class Name : public Element {
 public:
    ElementStatus put(const std::string &name) override;
};
