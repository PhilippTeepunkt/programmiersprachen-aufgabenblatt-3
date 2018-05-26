#include <list>
#include <set>
#include <random>
#include <algorithm>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::list<unsigned int> list_;
    std::set<unsigned int> result_;

    //fill list
    for(int i = 0; i<100; i++)
    {
        list_.push_back(rand()%100);
    }

    for(int i = 0; i<100; i++)
    {
        if(std::find(list_.begin(), list_.end(), i)==list_.end()){
            result_.insert(i);
        }
    }

    for(auto const& element : result_)
    {
        std::cout<<element;
    }
    return 0;
}

