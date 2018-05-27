#define CATCH_CONFIG_RUNNER
#include "circle.hpp"
#include "catch.hpp"

#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}

TEST_CASE("tests_sortVec","[CircleVec]")
{
    std::vector<Circle>sorted_circles;

    Circle circ1{100.0f,Vec2{400.0f,400.0f},Color{1.0f,0.0f,0.0f},"Herbert"};
    Circle circ2{250.0f,Vec2{400.0f,400.0f},Color{0.0f,1.0f,0.0f},"Jürgen"};
    Circle circ3{150.0f,Vec2{400.0f,400.0f},Color{0.0f,0.0f,1.0f},"Peter"};
    Circle circ4{75.0f,Vec2{300.0f,400.0f},Color{1.0f,1.0f,0.0f},"Hans"};

    sorted_circles.push_back(circ1);
    sorted_circles.push_back(circ2);
    sorted_circles.push_back(circ3);
    sorted_circles.push_back(circ4);

    std::sort(sorted_circles.begin(),sorted_circles.end());

    REQUIRE(std::is_sorted(sorted_circles.begin(),sorted_circles.end()));
}