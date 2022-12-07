#include <iostream>
#include <bitset>

using namespace std;

string addBinary(string a, string b) 
{
    int Dec_a = bitset<32>(a).to_ulong();
    int Dec_b = bitset<32>(b).to_ulong();

    int Sum_Dec = Dec_a + Dec_b;

    bitset<14> Binary(Sum_Dec);

    string result = Binary.to_string();

    return result;
}

int main()
{
    string a = "11";
    string b = "1";

    addBinary(a, b);

    return 0;
} 