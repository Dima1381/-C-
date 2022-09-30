#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

char* word_reverse(char* word)
{
    if (*word != 0)
    {
        int temp;
        int len = strlen(word);
        for (int i = 0; i < len / 2; i++)
        {
            temp = word[i];
            word[i] = word[len - i - 1];
            word[len - i - 1] = temp;
        }
    }
    return word;
}

int size_max_word(char* str, char* non_str)// функція пошуку довжини найбільшого слова
{
    int size = 0;
    int length = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        for (int j = i; str[j] != 0; j++)
        {
            if (strchr(non_str, str[j]) == NULL)
            {
                length++;
            }
            else
            {
                break;
            }
        }
        if (length > size)
        {
            size = length;
            i += (length - 1);
        }
        length = 0;
    }

    return size;
}

char* foo(char* str)
{
    char* res_array = (char*)calloc(sizeof(char), strlen(str) + 1);
    char non_str[] = " .!*,_?;:\n\t";

    int size = size_max_word(str, non_str);

    char* word = (char*)calloc(sizeof(char), size + 1);

    int index_word = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        while (i < strlen(str))
        {
            if (strchr(non_str, str[i]) != NULL)
            {
                break;
            }
            else
            {
                word[index_word] = str[i];
                index_word++;
                i++;
            }
        }
        if (index_word != 0)
        {
            word[index_word] = '\0';
            char* new_rev_word = word_reverse(word);
            strcat(res_array, new_rev_word);
            strcat(res_array, " ");

            index_word = 0;
        }
    }
    free(word);
    return res_array;
}

int main()
{
    char str[] = "12387654567    112456!, 7898765 - 11*";

    char* result_str = foo(str);

    cout << result_str;
    free(result_str);

    return 0;
}
