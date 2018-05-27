#define CATCH_CONFIG_RUNNER
#include<catch.hpp>
#include<vector>
#include<functional>
#include<algorithm>

bool is_even(int i)
{
    return i%2==0;
}

template<typename Container,typename Praedikat>
Container filter(Container const& container,Praedikat const& praedikat)
{
    Container resultContainer;
    for(auto it = container.begin();it!=container.end();it++)
    {
        if(praedikat(*it)){
            resultContainer.push_back(*it);
        }
    } 
    return resultContainer;
}

TEST_CASE("function Template","[template]")
{
    std::vector<int>v{1,2,3,4,5,6,7,8};
    std::vector<int>v2(8);
    v2 = filter(v,is_even);

    REQUIRE(std::all_of(v2.begin(),v2.end(),is_even));
}

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc,argv);
}
