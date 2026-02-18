#pragma once

#include "2_numberOfCharacters.h"

const int MINIMAL_LENGTH = 8;

enum PasswordStrength {EMPTY_PASSWORD, VERY_WEAK_PASSWORD, WEAK_PASSWORD,
                       STRONG_PASSWORD, VERY_STRONG_PASSWORD, NOT_ALLOWED_PASSWORD};

PasswordStrength passwordStrength(const char password[]);

const PasswordStrength DUMMY_PASSWORD_STRENGTH = EMPTY_PASSWORD;