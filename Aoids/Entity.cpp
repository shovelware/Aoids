#include "Entity.hpp"

Entity::Entity()
{
	zeroKinematics();
}

Entity::Entity(sf::Texture* texture)
{
	zeroKinematics();
	sprite_.setTexture(*texture);

	sf::Vector2u size = texture->getSize();
	sprite_.setOrigin(size.x / 2, size.y / 2);
}

Entity::Entity(sf::Texture* texture, sf::Vector2f position, float orientation)
{
	zeroKinematics();
	sprite_.setTexture(*texture);

	sf::Vector2u size = texture->getSize();
	sprite_.setOrigin(size.x / 2, size.y / 2);

	position_ = position;
	orientation_ = orientation;
}

void Entity::zeroKinematics()
{
	position_ = velocity_ = sf::Vector2f(0.f, 0.f);
	orientation_ = rotation_ = 0.f;
}

#pragma region Accessors
void Entity::setPosition(sf::Vector2f position)
{
	position_ = position;
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	velocity_ = velocity;
}

void Entity::setOrientation(float orientation)
{
	orientation_ = orientation;
}

void Entity::setRotation(float rotation)
{
	rotation_ = rotation;
}

sf::Vector2f Entity::getPosition() const 
{
	return position_;
}

sf::Vector2f Entity::getVelocity() const
{
	return velocity_;
}

float Entity::getOrientation() const 
{
	return orientation_;
}

float Entity::getRotation() const 
{
	return rotation_;
}
#pragma endregion

void Entity::rotate(float rotation)
{
	rotation_ += rotation;
}

void Entity::impulse(sf::Vector2f velocity)
{
	velocity_ += velocity;
}

void Entity::speedUp()
{
}

void Entity::speedDown()
{
}

void Entity::update(sf::Time dt)
{
	//update values
	position_ += sf::Vector2f(velocity_.x * dt.asMilliseconds(), velocity_.y * dt.asMilliseconds());
	orientation_ += rotation_ * dt.asMilliseconds();

	rotation_ = 0;

	//check for overflow in rotation???
	//while (orientation_ >= 360)
	//{
	//	orientation_ -= 360;
	//}

	//sync sprite
	sprite_.setPosition(position_);
	sprite_.setRotation(orientation_);

	//

}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite_);
}
