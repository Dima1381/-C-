#include <iostream>


uint32_t reverseBits(uint32_t n) 
{
    uint32_t Rev_b = 0;

    for (int i = 0; i < 32; i++)
    {
        Rev_b = (Rev_b << 1) + (1 & n >> i);
    }

    return Rev_b;
}


int main()
{
    uint32_t n = 4294967293;

    uint32_t Reverse_Bits = reverseBits(n);

    return 0;
} 