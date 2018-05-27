#include <iostream>
#include <set>
#include <string>
#include <algorithm>

#include "circle.hpp"

int main()
{
    Circle circ1{200.0f,Vec2{400.0f,400.0f},Color{1.0f,0.0f,0.0f},"Herbert"};
    Circle circ2{150.0f,Vec2{400.0f,400.0f},Color{0.0f,1.0f,0.0f},"Jürgen"};
    Circle circ3{100.0f,Vec2{400.0f,400.0f},Color{0.0f,0.0f,1.0f},"Peter"};
    Circle circ4{100.0f,Vec2{300.0f,400.0f},Color{1.0f,1.0f,0.0f},"Peter"};

    std::set<Circle, circ_less> circs;
    circs.insert(circ1);
    circs.insert(circ2);
    circs.insert(circ3);
    circs.insert(circ4);

    std::cout<<"Type in name: \n";
    std::string search;
    std::cin >> search;

    for(auto it = circs.begin(); it!=circs.end();it++)
    {
        if((*it).get_name().compare(search)==0)
        {
            std::cout<<*it;
        }
    }

    return 0;
}
