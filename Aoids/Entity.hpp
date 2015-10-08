#ifndef ENTITY_H
#define ENTITY_H

#include <SFML\Graphics.hpp>

class Entity : public sf::Drawable {
public:
	sf::Vector2f position_;
	sf::Vector2f velocity_;
	float orientation_;
	float rotation_;
private:
	Entity();
	Entity(sf::Vector2f position, float orientation);
	void update(sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif