#include "EXCEPTIONS.h"

REPEAT_DEL::REPEAT_DEL(const char* str) {
    error = str;
}

void REPEAT_DEL::GetInfo() const {
    printf("%s", error);
    return;
}

REPEAT_ADD::REPEAT_ADD(const char* str) {
    error = str;
}

void REPEAT_ADD::GetInfo() const {
    printf("%s", error);
    return;
}

BAD_VALUE::BAD_VALUE(const char* str) {
    error = str;
}

void BAD_VALUE::GetInfo() const {
    printf("%s", error);
    return;
}
