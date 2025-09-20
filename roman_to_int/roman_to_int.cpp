#include <iostream>
#include "roman_to_int.hpp"

int roman_char_conversion(char roman_char)
{
    if (roman_char == 'I')
        return 1;
    else if (roman_char == 'V')
        return 5;
    else if (roman_char == 'X')
        return 10;
    else if (roman_char == 'L')
        return 50;
    else if (roman_char == 'C')
        return 100;
    else if (roman_char == 'D')
        return 500;
    else if (roman_char == 'M')
        return 1000;
    else
        return -1; // error code
}

int roman_to_int(std::string s)
{
    int length = s.length();
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == 'I' && (i + 1) < length)
        {
            if (s[i + 1] == 'V' || s[i + 1] == 'X')
            {
                total = total - 1;
            }
            else
            {
                total = total + roman_char_conversion(s[i]);
            }
        }
        else if (s[i] == 'X' && (i + 1) < length)
        {
            if (s[i + 1] == 'L' || s[i + 1] == 'C')
            {
                total = total - 10;
            }
            else
            {
                total = total + roman_char_conversion(s[i]);
            }
        }
        else if ((s[i] == 'C' && (i + 1) < length))
        {
            if (s[i + 1] == 'D' || s[i + 1] == 'M')
            {
                total = total - 100;
            }
            else
            {
                total = total + roman_char_conversion(s[i]);
            }
        }
        else
        {
            total = total + roman_char_conversion(s[i]);
        }
    }

    return total;
}

int main()
{
    std::string s = "MCMXCIV";
    int result = roman_to_int(s);
    std::cout << "Roman numeral: " << s << ", Integer: " << result << std::endl;
    return 0;
}