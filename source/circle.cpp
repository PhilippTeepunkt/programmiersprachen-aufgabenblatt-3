#ifndef CIRCLE_CPP
#define CIRCLE_CPP
#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"
//#include "window.hpp"
#include <string>
#include <math.h>
#include <iostream>
#include <sstream>

Circle::Circle():

    radius_(1.0f),
    center_(Vec2{0.0f,0.0f}),
    color_(Color{0.0f}),
    name_{"no name"}
{};

Circle::Circle(Circle const& c):
    radius_{c.get_radius()},
    center_{c.get_center()},
    color_{c.get_color()},
    name_{c.get_name()}
{};

Circle::Circle(float radius):
    radius_{radius},
    center_{Vec2{0.0f,0.0f}},
    color_{Color{0.0f}},
    name_{"no name"}
{};

Circle::Circle(float radius, Color const& color):
    radius_{radius},
    center_{Vec2{0.0f,0.0f}},
    color_{color},
    name_{"no name"}
{};

Circle::Circle(float radius, Vec2 const& center):
    radius_{radius},
    center_{center},
    color_{Color{0.0f}},
    name_{"no name"}
{};

Circle::Circle(float radius,Color const& color,std::string const& name):
    radius_{radius},
    center_{Vec2{0.0f,0.0f}},
    color_{color},
    name_{name}
{}; 

Circle::Circle(float radius,Vec2 const& center, Color const& color):
    radius_{radius},
    center_{center},
    color_{color},
    name_{"no name"}
{};

Circle::Circle(float radius,Vec2 const& center, Color const& color,std::string name):
    radius_{radius},
    center_{center},
    color_{color},
    name_{name}
{};

float Circle::get_radius()const
{
    return radius_;
}

Vec2 Circle::get_center()const
{
    return center_;
}

Color Circle::get_color()const
{
    return color_;
}

float Circle::circumference()const
{
    return 2 * (float)M_PI * radius_;
}

std::string Circle::get_name()const
{
    return name_;
}

/*
void Circle::draw(Window const& w)const
{
    Vec2 start{};
    Vec2 end{};
    Color c{0.0f};
    c = get_color();
    
    for(int i =0; i<=360; i++)
    {
        start = {(float)sin((2*M_PI*i)/360)*get_radius()+center_.x,(float)cos((2*M_PI*i)/360)*get_radius()+center_.y};
        end = {(float)sin(((i+1)*2*M_PI)/360)*get_radius()+center_.x,(float)cos(((i+1)*2*M_PI)/360)*get_radius()+center_.y};
        w.draw_line(start.x,start.y,end.x,end.y,c.r_,c.g_,c.b_);
    }
}

void Circle::draw(Window const& w, Color const& c)const
{
    Vec2 start{};
    Vec2 end{};
    
    for(int i =0; i<=360; i++)
    {
        start = {(float)sin((2*M_PI*i)/360)*get_radius()+center_.x,(float)cos((2*M_PI*i)/360)*get_radius()+center_.y};
        end = {(float)sin(((i+1)*2*M_PI)/360)*get_radius()+center_.x,(float)cos(((i+1)*2*M_PI)/360)*get_radius()+center_.y};
        w.draw_line(start.x,start.y,end.x,end.y,c.r_,c.g_,c.b_);
    }
}

void Circle::draw(Window const& w, float r, float g, float b)const
{
    Vec2 start{};
    Vec2 end{};
    Color c{r,g,b};
    
    for(int i =0; i<=360; i++)
    {
        start = {(float)sin((2*M_PI*i)/360)*get_radius()+center_.x,(float)cos((2*M_PI*i)/360)*get_radius()+center_.y};
        end = {(float)sin(((i+1)*2*M_PI)/360)*get_radius()+center_.x,(float)cos(((i+1)*2*M_PI)/360)*get_radius()+center_.y};
        w.draw_line(start.x,start.y,end.x,end.y,c.r_,c.g_,c.b_);
    }
}
*/
bool Circle::is_inside(Vec2 const& vec)const
{
    if(length(vec-get_center())<=get_radius()){
        return true;
    }
    return false;
}

std::ostream& Circle::print(std::ostream & outstream)const
{
   outstream <<get_name()<<", "<<"(" << get_center().x << "," << get_center().y << ")" << ", " << get_radius()<<", "<<"("<<get_color().r_<<","<<get_color().g_<<","<<get_color().b_<<")\n";
    return outstream;
}

std::ostream& operator <<(std::ostream & outstream, Circle const& circle)
{
    return circle.print(outstream);
}

#endif