#include <iostream>

using std::cout;
using std::endl;

char* intToString(int, int);
int stringToInt(char*, int);
bool strings_equal(char*, char*);

int NumDigits(int number)
{
    if (number == 0)
        return 1;

    int num_digits = 0;
    while (number != 0)
    {
        num_digits++;
        number /= 10;
    }

    return num_digits;
}

bool FindAndReplace(int &search, int find, int replace)
{
    int replace_copy = replace;
    if (find < 0 || replace < 0)
        return false;
    
    int num_digits_find = NumDigits(find);
    int num_digits_replace = NumDigits(replace);
    if (num_digits_find < num_digits_replace)
        return false;
    
    int num_digits_search = NumDigits(search);
    char* search_as_string = intToString(search, num_digits_search);

    char num_chars[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    int i = num_digits_search - 1;
    while (i >= 0)
    {
        replace = replace_copy;
        char* find_string = new char[num_digits_find + 1];
        find_string[num_digits_find] = '\0';
        
        int count = 0;
        while (count < num_digits_find)
        {
            if (num_digits_find > i + 1)
                break;
            find_string[num_digits_find - 1 - count] = search_as_string[i - count];

            count++;
        }
        if (strings_equal(find_string, intToString(find, num_digits_find)))
        {
            count = 0;
            while (count < num_digits_find)
            {
                search_as_string[i - count] = num_chars[replace % 10];
                count++;
                replace /= 10;
            }
            i -= num_digits_find;
        }
        else
            i--;
        delete [] find_string; find_string = nullptr;
    }
    
    search = search < 0 ? stringToInt(search_as_string, num_digits_search) * -1 : 
        stringToInt(search_as_string, num_digits_search);
    delete [] search_as_string; search_as_string = nullptr;
    return true;

}

char* intToString(int number, int num_digits)
{
    number = number < 0 ? number * -1 : number;
    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char* num_as_string = new char[num_digits + 1];
    num_as_string[num_digits] = '\0';

    for (int i = num_digits - 1; i >= 0; i--)
    {
        int digit = number % 10;
        num_as_string[i] = nums[digit];
        number /= 10;
    }    

    return num_as_string;
}

int stringToInt(char* num_as_string, int num_digits)
{
    int multiplier = 1;
    int number = 0;
    for (int i = num_digits - 1; i >= 0; i--)
    {
        int digit = num_as_string[i] - '0';
        number += digit * multiplier;
        multiplier *= 10;
    }

    return number;
}

bool strings_equal(char* string1, char* string2)
{
    int i = 0;
    while (*(string1 + i) != '\0' && *(string2 + i) != '\0')
    {
        if (string1[i] != string2[i])
            return false;
        i++;
    }

    return true;
}

