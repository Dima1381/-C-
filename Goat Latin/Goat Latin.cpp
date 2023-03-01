#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string toGoatLatin(string sentence) 
{
    int len_sentence = sentence.length();
    if (len_sentence == 0)
        return "";

    static const string is_vowel = "aAeEiIoOuU";

    stringstream ss(sentence);
    string word;

    string res = "";
    res.reserve(len_sentence * 2);
    int index_add_a = 1;

    while (ss >> word)
    {
        if (is_vowel.find(word[0]) != string::npos) {
            word += "ma";
        }
        else
        {
            char first_letter = word[0];
            word.erase(word.begin());
            word += first_letter;
            word += "ma";
        }

        word.insert(word.length(), index_add_a, 'a');

        res += word;
        res += ' ';

        index_add_a++;
    }

    res.erase(res.length() - 1, 1);
    return res;
}

int main()
{
    string sentence = "I speak Goat Latin";
    
    string res = toGoatLatin(sentence);

    return 0;
}
