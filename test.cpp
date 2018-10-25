#include <iostream>
#include <vector>

int main()
{
    std::vector<int> *v = new std::vector<int>();
    v->push_back(1);

    std::cout << v->at(0) << "\n";
    


    return 1;
}