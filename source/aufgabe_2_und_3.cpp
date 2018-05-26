#include <list>
#include <set>
#include <random>
#include <algorithm>
#include <iostream>

int main()
{
    std::list<unsigned int> list_;
    std::set<unsigned int> result_;

    //fill list
    std::cout<<"Random filled List: \n";
    for(int i = 0; i<100; i++)
    {   unsigned int random = rand()%100;
        list_.push_back(random);
        std::cout<<random<<", ";
    }
    std::cout<<"\n\nMissing numbers between 0-100:\n";

    for(int i = 0; i<100; i++)
    {
        if(std::find(list_.begin(), list_.end(), i)==list_.end()){
            result_.insert(i);
        }
    }

    for(auto const& element : result_)
    {
        std::cout<<element<<", ";
    }
    return 0;
}

