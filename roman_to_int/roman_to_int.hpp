// read each character of string
// check current char and char after it
// if current char is I, X or V
// branch descision tree to check the next char is one of the corresponding rule characters
// replace count with special character
// iterate pointer to next char and skip value, but check for end of list first

#include <iostream>

int roman_to_int(std::string s);
int roman_char_conversion(char roman_char);
