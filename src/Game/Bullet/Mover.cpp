#include "Mover.hpp"

Mover::Mover(double x0, double y0, double d0, double s0)
: x(x0), y(y0), d(d0), s(s0)
{
    style.setRadius(3);
    style.setFillColor(sf::Color::Magenta);
    style.setPosition(x, y);
}

void Mover::tick() 
{
    x += s * sin(d);
    y -= s * cos(d);
    style.setPosition(x, y);
}

void Mover::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(style, states);
}

Shot::Shot(double x, double y, double d, double s) : Mover(x, y, d, s)
{}

