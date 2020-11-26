#include "Cards/OffensiveCardWarrior.h"

OffensiveCardWarrior::OffensiveCardWarrior(std::string label, std::string path, int costAction, int value) : OffensiveCard(label, path, costAction, value) {}

OffensiveCardWarrior::~OffensiveCardWarrior() {}

OffensiveCardWarrior::OffensiveCardWarrior(const OffensiveCardWarrior &other) : OffensiveCard(other) {}

OffensiveCardWarrior &OffensiveCardWarrior::operator=(const OffensiveCardWarrior &rhs)
{
    if (this != &rhs)
    {
        OffensiveCard::operator=(rhs);
    }
    return *this;
}

OffensiveCardWarrior *OffensiveCardWarrior::clone() const
{
    return new OffensiveCardWarrior(*this);
}

void OffensiveCardWarrior::activateEffect(Entity &entity)
{
    // Todo
}

void Card::draw(sf::RenderTarget& target, sf::RenderStates states)
{
    m_texture.loadFromFile(path);
    //m_sprite.setTexture(m_texture,states);
    target.draw(m_sprite, states);
}
