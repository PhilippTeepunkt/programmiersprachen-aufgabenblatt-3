#define CATCH_CONFIG_RUNNER
#include<catch.hpp>
#include<vector>
#include<algorithm>

#include"circle.hpp"

TEST_CASE("function Template","[template]")
{
    std::vector<Circle>circles;
    std::vector<Circle>circles2(3);

    circles.push_back(Circle{1.5f});
    circles.push_back(Circle{7.0f});
    circles.push_back(Circle{3.0f});
    circles.push_back(Circle{6.0f});
    circles.push_back(Circle{5.0f});

    std::copy_if(circles.begin(),circles.end(),circles2.begin(),[](Circle const& c){
        std::cout<<c.get_radius()<<"\n";
        return c.get_radius()>4.0f;});

    std::cout<<"-------------------\n";
    
    REQUIRE(std::all_of(circles2.begin(),circles2.end(),[](Circle const& c){
        std::cout<<c.get_radius()<<"\n";
        return c.get_radius()>3.0f;}));
}

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc,argv);
}