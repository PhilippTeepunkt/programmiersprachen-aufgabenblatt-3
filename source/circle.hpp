#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "color.hpp"
#include "vec2.hpp"
//#include "window.hpp"

#include <vector>
#include <string>
#include <iostream>

class Circle{
    
    private:

        float radius_;
        Vec2 center_;
        Color color_;
        std::string name_;

    public:

        Circle();
        Circle(Circle const& c);
        Circle(float radius);
        Circle(float radius,Color const& color);
        Circle(float radius,Vec2 const& center);
        Circle(float radius,Color const& color,std::string const& name);
        Circle(float radius,Vec2 const& center,Color const& color);
        Circle(float radius,Vec2 const& center,Color const& color, std::string name);

        float get_radius() const;
        Vec2 get_center() const;
        Color get_color() const;
        std::string get_name() const;

        float circumference() const;
        /*void draw(Window const& w) const;
        void draw(Window const& w, Color const& c) const;
        void draw(Window const& w,float r, float g, float b) const;*/

        bool is_inside(Vec2 const& v)const;
        std::ostream& print(std::ostream & outstream)const;
};
std::ostream& operator<<(std::ostream& outstream,Circle const& Circle);
bool operator <(Circle const& c1, Circle const& c2);
bool operator >(Circle const& c1, Circle const& c2);
bool operator ==(Circle const& c1, Circle const& c2);



struct circ_less{
    bool operator()(Circle const& c1, Circle const& c2)
    {
        if(c1.get_name().compare(c2.get_name())==0&&c1.get_name().size()!=0)
        {
            std::cout<<"Kreis mit dem Namen "<<c1.get_name()<<" wurde nicht hinzu gefügt, da bereits ein Kreis mit dem selben namen existiert!\n";
            return false;
        }
        if(c1.get_radius()<c2.get_radius())
        {
            return true;
        }
        else if(c1.get_radius()==c2.get_radius())
        {
            if(c1.get_center().x==c2.get_center().x)
            {
                return c1.get_center().y<c2.get_center().y;
            }
            
            else if(c1.get_center().x<c2.get_center().x)
            {
                return true;
            }
        }
        return false;
    }
};
#endif