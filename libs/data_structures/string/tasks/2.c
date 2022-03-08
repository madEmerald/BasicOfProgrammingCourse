#include "../string_.h"

#define ASSERT_STRING(expected, got) assertString(expected , got , __FILE__ , __FUNCTION__ , __LINE__)

void removeAdjacentEqualLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *beginSource = s;
    char *destination = s;
    while (beginSource != endSource) {
        if (*beginSource != *(beginSource + 1)) {
            *destination = *beginSource;
            destination++;
        }
        beginSource++;
    }
    *destination = *endSource;
    destination++;
    *destination = '\0';
}

void test_removeAdjacentEqualLetters_emptyString() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("", s);
}

void test_removeAdjacentEqualLetters_singleLetterAtBegin() {
    char s[] = "122234444";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("1234", s);
}

void test_removeAdjacentEqualLetters_singleLetterAtEnd() {
    char s[] = "11112333334";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("1234", s);
}

int main() {
    test_removeAdjacentEqualLetters_emptyString();
    test_removeAdjacentEqualLetters_singleLetterAtBegin();
    test_removeAdjacentEqualLetters_singleLetterAtEnd();

    return 1;
}
