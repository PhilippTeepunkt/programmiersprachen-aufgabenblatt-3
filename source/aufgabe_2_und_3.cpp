#include <list>
#include <set>
#include <random>
#include <algorithm>
#include <iostream>

int main()
{
    //Aufgabe 3.3
    std::list<unsigned int> list_;
    std::set<unsigned int> result_;
    std::vector<unsigned int>random_vector(100);

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

    //Aufgabe 3.4
    //with the container map,
    //you could call the count operation, wich counts the element by the specific key
    std::cout<<"\n\n Frequency: \n";
    for(int i = 0; i<100; i++){
        if(!(std::find(result_.begin(),result_.end(),i)!=result_.end())){
            std::cout<<i<<": "<<std::count(list_.begin(),list_.end(),i)<<"\n";
        }
    }

    //Aufgabe 3.10
    std::copy(list_.begin(),list_.end(),random_vector.begin());

    return 0;
}

