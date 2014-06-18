 // XXX uniqID XXX 2f8ce762a4f0544ddd5536127bb805a1 XXX

#include "easy.hpp"
#include "../Bullet.hpp"
#include "../BulletBuffer.hpp"
#include "../../../Math/Trig.hpp"

#include <random>

static std::mt19937 rng;

extern const Bullet::StepFunc bullet_3f1f1a216936ac8f3fa5a0b083e8ff9b_2f8ce762a4f0544ddd5536127bb805a1[] =
{
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1,
    stepfunc_ae9f735c6401a821cc04ce1cd68278bf_2f8ce762a4f0544ddd5536127bb805a1,
    NULL
};


void stepfunc_72b13477beb9686c3e16ed03ea57916a_2f8ce762a4f0544ddd5536127bb805a1(Bullet *p)
{
    {
        p->lastAngle = p->lastAngle + (Trig::degToRad(
                    0.0
                    ));

        p->lastSpeed = p->lastSpeed + (
                    0.2
                    );

        Bullet* bi = BulletBuffer::makeNewBullet();
        if (bi != NULL)
        {
            bi->initialize(p->getPosition(), p->lastAngle, p->lastSpeed, nullptr);
        }
    }
}

void stepfunc_fa41394e25ea4c208aaa075a4a74a526_2f8ce762a4f0544ddd5536127bb805a1(Bullet *p)
{
    {
        p->lastAngle = p->lastAngle + (Trig::degToRad(
                    -20.0
                    ));

        p->lastSpeed = (
                    1.3
                    );
        Bullet* bi = BulletBuffer::makeNewBullet();
        if (bi != NULL)
        {
            bi->initialize(p->getPosition(), p->lastAngle, p->lastSpeed, nullptr);
        }
    }

    for (unsigned int i = 0; i < 13; ++i)
    {
        stepfunc_72b13477beb9686c3e16ed03ea57916a_2f8ce762a4f0544ddd5536127bb805a1(p);
    }
}
void stepfunc_eeeddcf3b4ef8a9b382bb0135216989a_2f8ce762a4f0544ddd5536127bb805a1(Bullet *p)
{
    {
        p->lastAngle = p->getAngle() + (Trig::degToRad(
                    25.0+rng()*30.0
                    ));

        p->lastSpeed = (
                    1.3
                    );
        Bullet* bi = BulletBuffer::makeNewBullet();

        if (bi != NULL)
        {
            bi->initialize(p->getPosition(), p->lastAngle, p->lastSpeed, nullptr);
        }
    }
    for (unsigned int i = 0; i < 13; ++i)
    {
        stepfunc_72b13477beb9686c3e16ed03ea57916a_2f8ce762a4f0544ddd5536127bb805a1(p);
    }

    for (unsigned int i = 0; i < 4; ++i)
    {
        stepfunc_fa41394e25ea4c208aaa075a4a74a526_2f8ce762a4f0544ddd5536127bb805a1(p);
    }

    p->setWait(30.0 - 1.0 * 20.0);
}

void stepfunc_ae9f735c6401a821cc04ce1cd68278bf_2f8ce762a4f0544ddd5536127bb805a1(Bullet *p)
{
    BulletBuffer::destroy(p);
}


Bullet *genBulletFunc_2f8ce762a4f0544ddd5536127bb805a1(float posx, float posy)
{
    Bullet* bi = BulletBuffer::makeNewBullet();

    if (bi != NULL)
    {
        bi->initialize(sf::Vector2f(posx, posy), Bullet::DEFAULT_ANGLE, 0, bullet_3f1f1a216936ac8f3fa5a0b083e8ff9b_2f8ce762a4f0544ddd5536127bb805a1);
    }

    return bi;
}

