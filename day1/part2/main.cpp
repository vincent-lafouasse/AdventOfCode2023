#include <array>
#include <fstream>
#include <iostream>
#include <optional>

#include <cctype>
#include <cstdint>
#include <cstdlib>

#define INPUT "input.txt"
#define ERROR 1

const std::array<const char*, 9> WORD_DIGITS = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

std::optional<short> get_digit(const char* s)
{
    if (isdigit(*s))
        return *s - '0';
    for (size_t i = 1; i < 10; i++)
    {
        const char* digit = WORD_DIGITS.at(i - 1);
        if (!strncmp(s, digit, strlen(digit)))
        {
            return i;
        }
    }
    return {};
}

const char* digit_to_word(short n)
{
    return WORD_DIGITS.at(n - 1);
}

std::optional<short> get_first(const std::string& s)
{
    std::optional<short> digit;
    const char* s__ = s.c_str();

    for (size_t i = 0; i < s.length(); i++)
    {
        digit = get_digit(s__ + i);
        if (digit)
            return digit;
    }
    return {};
}

std::optional<char> get_last(const std::string& s)
{
    std::optional<short> digit;
    const char* s__ = s.c_str();

    for (int i = s.length() - 1; i >= 0; i--)
    {
        digit = get_digit(s__ + i);
        if (digit)
            return digit;
    }
    return {};
}

short opt_char_to_int(std::optional<char> c);

int main()
{
    std::ifstream infile{INPUT};

    std::optional<short> first_digit;
    std::optional<short> last_digit;

    uint64_t sum{};

    std::string line;
    while (infile >> line)
    {
        first_digit = get_first(line);
        last_digit = get_last(line);
        if (!first_digit)
            return ERROR;

        short n = 10 * *first_digit + *last_digit;

        std::cout << line << '\n';
        std::cout << *first_digit << '\t' << *last_digit << '\t' << n << '\n';

        sum += n;
    }

    std::cout << sum;
}
