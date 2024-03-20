#include <iostream>
#include <string>
#include "dynamic_array.cpp"
#include "TwoWayList.cpp"

int main()
{
    TwoWayList <int> clasa; 
    for (int i = 0; i <= 10; i++)
    {
        clasa.push_back(i);
        //clasa.pop_back();
        //clasa.push_front(i);
        //clasa.pop_front();
    }
    clasa.pop_front();
    clasa.pop_front();
    clasa.print_TwoWayList();
    //clasa.print_array();
    std::cout << "hello" << std::endl;
    return 0;
}
