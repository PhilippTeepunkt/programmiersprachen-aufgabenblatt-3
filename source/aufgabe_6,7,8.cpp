#define CATCH_CONFIG_RUNNER
#include "circle.hpp"
#include "catch.hpp"

#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}

TEST_CASE("tests_sortVec","[Aufgabe6]")
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

TEST_CASE("tests_sortVecLambda","[Aufgabe7]")
{
    std::vector<Circle>sorted_circles2;

    Circle circ5{100.0f,Vec2{400.0f,400.0f},Color{1.0f,0.0f,0.0f},"Herbert"};
    Circle circ6{250.0f,Vec2{400.0f,400.0f},Color{0.0f,1.0f,0.0f},"Jürgen"};
    Circle circ7{150.0f,Vec2{400.0f,400.0f},Color{0.0f,0.0f,1.0f},"Peter"};
    Circle circ8{75.0f,Vec2{300.0f,400.0f},Color{1.0f,1.0f,0.0f},"Hans"};

    sorted_circles2.push_back(circ5);
    sorted_circles2.push_back(circ6);
    sorted_circles2.push_back(circ7);
    sorted_circles2.push_back(circ8);

    std::sort(sorted_circles2.begin(),sorted_circles2.end(),[](Circle const& c1,Circle const& c2)->bool{return (c1.get_radius()<c2.get_radius());});

    REQUIRE(std::is_sorted(sorted_circles2.begin(),sorted_circles2.end()));
}

TEST_CASE("tests_sortVecFunktor","[Aufgabe8]")
{
    std::vector<Circle>sorted_circles3;

    Circle circ9{100.0f,Vec2{400.0f,400.0f},Color{1.0f,0.0f,0.0f},"Herbert"};
    Circle circ10{250.0f,Vec2{400.0f,400.0f},Color{0.0f,1.0f,0.0f},"Jürgen"};
    Circle circ11{150.0f,Vec2{400.0f,400.0f},Color{0.0f,0.0f,1.0f},"Peter"};
    Circle circ12{75.0f,Vec2{300.0f,400.0f},Color{1.0f,1.0f,0.0f},"Hans"};

    sorted_circles3.push_back(circ9);
    sorted_circles3.push_back(circ10);
    sorted_circles3.push_back(circ11);
    sorted_circles3.push_back(circ12);

    less<Circle> kleiner;
    std::sort(sorted_circles3.begin(),sorted_circles3.end(),kleiner);

    REQUIRE(std::is_sorted(sorted_circles3.begin(),sorted_circles3.end()));

}