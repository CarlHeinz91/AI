#ifndef WORLD_HPP
#define WORLD_HPP


#include <iostream>
#include <list>
#include <functional>

#include "Element.hpp"
#include "Creature.hpp"
#include "Herbivore.hpp"
#include "Carnivore.hpp"
#include "Food.hpp"

#include "myUsefulMath.hpp"



class World : public Element
{
private:
	sf::RectangleShape mWorldBackground;

	std::list<Carnivore*> mListOfCarnivores;
	std::list<Herbivore*> mListOfHerbivores;
	std::list<Food*> mListOfFood;

	sf::Vector2f mWorldSize;
	sf::Time mSimulationTime;

	unsigned int const mNumOfFood = 1000;
	sf::Time mFoodSpawningTime = sf::seconds(0.02f);
	sf::Time mTimeSinceLastFoodSpawn = sf::seconds(0.f);


public:
	World();
	World(sf::Vector2u worldSize);
	~World() override;

	void update(sf::Time frametime) override;
	void render(sf::RenderWindow *renderWindow) override;
	void handleEvents() override;


private:
	void calculateWhatCreaturesSee();
	void herbiesEatFood();
	void carniesEatHerbies();
	void spawnFood(sf::Time frametime);
	void creaturesDieWithoutFood();
	void creaturesReproduce();

	sf::Vector2f periodicDistance(sf::Vector2f creature1Pos, sf::Vector2f creature2Pos) const;
	bool checkForOverlap(Creature *creature1, Creature *creature2) const;
};

//Define which Brain shall be used
typedef ListBrain USED_BRAIN;




#endif //WORLD_HPP