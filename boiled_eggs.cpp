#include <iostream>
#include <cmath>

unsigned int cookingTime(unsigned int eggs)
{
    if (eggs == 0)
    {
        return 0;
    }
    return ceil(((eggs * 1.0) / 8)) * 5;
}

int main(void)
{
    int eggs = 5;
    std::cout << "result of " << eggs << " is : " << cookingTime(eggs) << std::endl;
}