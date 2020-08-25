#include<iostream>

int main()
{
    int number[6]{100,40,32,78,12,9};

    for (int i=0;i<6;i++)
    {
        std::cout << number[i] << "/t";
    }
    
    std::cout <<"vaya";
    std::cin.get();
    return 0;
}