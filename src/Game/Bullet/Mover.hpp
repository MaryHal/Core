#ifndef _Mover_hpp_
#define _Mover_hpp_

#include <SFML/Graphics.hpp>

class Mover : public sf::Drawable, public sf::Transformable
{
    protected:
        sf::CircleShape style;

    public:
        Mover(double x, double y, double d, double s);
        ~Mover() {};

        void tick();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        double x, y;
        double d, s;
        bool dead;
};

class Shot : public Mover 
{
    public:
        Shot(double x, double y, double d, double s);
};

#endif // _Mover_hpp_
