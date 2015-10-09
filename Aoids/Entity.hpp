#ifndef ENTITY_H
#define ENTITY_H

#include <SFML\Graphics.hpp>

class Entity : public sf::Drawable {
private:
	sf::Vector2f position_;
	sf::Vector2f velocity_;
	float orientation_;
	float rotation_;

	//Sprite
	sf::Sprite sprite_;

public:
	//Constructors
	Entity();
	Entity(sf::Texture* texture);
	Entity(sf::Texture* texture, sf::Vector2f position, float orientation);

	//Accessors - Set
	void setPosition(sf::Vector2f position);
	void setVelocity(sf::Vector2f velocity);
	void setOrientation(float orientation);
	void setRotation(float rotation);
	//Accessors - Get
	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
	float getOrientation() const;
	float getRotation() const;

	//Update & Draw
	void update(sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	//Reset
	void zeroKinematics();

	//Controllers
	void rotate(float rotation);
	void impulse(sf::Vector2f velocity);
	void speedUp();
	void speedDown();
};
#endif