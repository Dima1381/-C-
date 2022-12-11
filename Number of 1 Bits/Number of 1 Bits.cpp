#include <iostream>


int reverseBits(uint32_t n) 
{
    int count = 0;

    for (int i = 31; i >= 0 ; i--)
    {
        if ((n >> i) &1)
        {
            count++;
        }
    }

    return count;
}


int main()
{
    uint32_t n = 15;

    int Reverse_Bits = reverseBits(n);

    return 0;
} 