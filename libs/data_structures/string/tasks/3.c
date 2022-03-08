#include "../string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

int isdigit(int ch) {
    return ch >= '0' && ch <= '9';
}

int isalpha(int ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void digitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer,
                                      word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

char *changeWords(char *s) {
    char *beginString = s;
    char *beginSearch = beginString;

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToEnd(word);

        beginSearch = word.end;
    }
    return beginSearch;
}

void test_changeWords_emptyString() {
    char s[] = "";
    changeWords(s);
    ASSERT_STRING("", s);
}

void test_changeWords_noDigits() {
    char s[] = "dewwwe fewf we ";
    changeWords(s);
    ASSERT_STRING("dewwwe fewf we ", s);
}

void test_changeWords_noLetters() {
    char s[] = "11112333334 111 33 44";
    changeWords(s);
    ASSERT_STRING("11112333334 111 33 44", s);
}

void test_changeWords_simpleTest() {
    char s[] = "44few44 31gfr eg4e";
    changeWords(s);
    ASSERT_STRING("few4444 gfr31 ege4", s);
}

int main() {
    test_changeWords_emptyString();
    test_changeWords_noDigits();
    test_changeWords_noLetters();
    test_changeWords_simpleTest();

    return 1;
}