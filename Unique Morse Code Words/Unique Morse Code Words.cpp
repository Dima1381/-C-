#include <iostream>
#include <vector>
#include <unordered_map>

#define First_character_a 97

using namespace std;

int uniqueMorseRepresentations(const vector<string>& words, const vector<string>& full_code_words)
{
    unordered_map<string, int> unique_morse_code;

    int count_words = words.size();

    for (int i = 0; i < count_words; i++)
    {
        string temp_code_morse = "";

        for (int j = 0; j < words[i].size(); j++)
        {
            temp_code_morse += full_code_words[words[i][j] - First_character_a];
        }
        unique_morse_code[temp_code_morse]++;
    }

    return unique_morse_code.size();
}

int main()
{
    const vector<string> words = { "gin", "zen", "gig", "msg" };
    
    // For convenience, the full code for the 26 letters of the English alphabet is given below: a, b, c ...
    const vector<string> full_code_words{ ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

    int res = uniqueMorseRepresentations(words, full_code_words);
    return 0;
}
