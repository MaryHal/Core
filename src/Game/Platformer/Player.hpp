#ifndef _Player_hpp_
#define _Player_hpp_

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable,
               public sf::Transformable
{
    private:
        static constexpr float GRAVITY  = 100.0f;

        // How much I'd like to move horizontally in pixels per second
        static constexpr float HORI_VEL = 400.0f;

        // Max speed in pixels per frame.
        static constexpr float HORI_VEL_CAP = HORI_VEL / 60.0f;

        static constexpr float JUMP = -25.0f;

        // More or less a constant to induce a skidding effect.
        static constexpr float DAMPING = 0.7f;

    private:
        sf::Vector2f position;
        sf::Vector2f velocity;

        int xMove;

        sf::RectangleShape sprite;

    public:
        Player();
        virtual ~Player() override;

        void update(sf::Time dt);
        void handleEvent(const sf::Event& event);

    protected:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif /* _Player_hpp_ */
