#include <iostream>

bool luhnAlgorithm(long long int);

bool luhnAlgorithm(long long int ccNumber)
{
    int lastDigit = 0;
    int idx = 15;
    int total = 0;

    while (ccNumber != 0)
    {
        lastDigit = ccNumber % 10;
        if (idx % 2 == 0)
        {
            lastDigit = lastDigit * 2;
            if (lastDigit >= 10)
            {
                lastDigit = lastDigit - 9;
            }
            total = total + lastDigit;  
        }
        else
        {
            total = total + lastDigit;
        }
        // Removing last digit from ccNumber
        ccNumber = ccNumber / 10;
        idx--;
    }
    return total % 10 == 0;
}

int main()
{
    long long int valid = 4556737586899855;
    long long int invalid = 79927398710;

    std::cout << luhnAlgorithm(valid) << std::endl;
    std::cout << luhnAlgorithm(invalid) << std::endl;

    valid = 6011111111111117;
    invalid = 1234567890123456;

    std::cout << luhnAlgorithm(valid) << std::endl;
    std::cout << luhnAlgorithm(invalid) << std::endl;

    valid = 3530111333300000;
    invalid = 4111111111111110;

    std::cout << luhnAlgorithm(valid) << std::endl;
    std::cout << luhnAlgorithm(invalid) << std::endl;

    return 0; 

}