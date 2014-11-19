#include "Player.hpp"

#include "../../Utils/Log.hpp"
#include "../../Math/Math.hpp"

Player::Player()
    : position(10.0f, 10.0f),
      velocity(0.0f, 0.0f),
      xMove(0),
      sprite(sf::Vector2f(16.0f, 16.0f))
{
    sprite.setFillColor(sf::Color::White);
    sprite.setPosition(position.x - 8.0f, position.y - 8.0f);
}

Player::~Player()
{
}

void Player::update(sf::Time dt)
{
    float timeStep = dt.asSeconds();

    sf::Vector2f gravityForce(0.0f, GRAVITY * timeStep);

    sf::Vector2f pushForce(HORI_VEL * xMove * timeStep, 0.0f);

    velocity += gravityForce;
    velocity.x *= DAMPING;

    if (xMove != 0)
    {
        velocity += pushForce;
    }

    // Clamp velocities
    velocity.x = Math::clamp(velocity.x, -HORI_VEL_CAP, HORI_VEL_CAP);
    velocity.y = Math::clamp(velocity.y, -50.0f, 15.0f);

    position += velocity;

    // For now, let's just clamp our position so we stay on screen.
    position.x = Math::clamp(position.x, 8.0f, 640.0f - 8.0f);
    position.y = Math::clamp(position.y, 8.0f, 480.0f - 8.0f);

    // Finally, we must move our sprite as the position members of this class
    // and the position member of an sf::Drawable are not the same.
    sprite.setPosition(position.x - 8.0f, position.y - 8.0f);
}

void Player::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::A)
        {
            xMove = -1;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            xMove = 1;
        }
        else if (event.key.code == sf::Keyboard::J)
        {
            velocity.y = JUMP;
        }
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::A)
        {
            xMove = 0;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            xMove = 0;
        }
        else if (event.key.code == sf::Keyboard::J)
        {
            velocity.y /= 2;
        }
    }
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(sprite);
}
