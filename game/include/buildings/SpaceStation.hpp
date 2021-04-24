#pragma once
#include "IBuilding.hpp"

namespace game
{
	class SpaceStation : public IBuilding
	{
	private:

	protected:

	public:
		SpaceStation(unsigned short hp,
					 ObjectType type,
					 const sf::Texture& texture,
					 engine::TilePtr location,
					 unsigned short ironCost,
					 unsigned short copperCost,
					 unsigned short siliconCost,
					 Ownership owner);

		virtual void attack(std::shared_ptr<IObject>, std::shared_ptr<engine::ObjectManager>) override {};
		virtual void move(engine::TilePtr, PlayerState&) override {};
		virtual unsigned char getMoveSpeed() override { return 0; };
		virtual void update(std::shared_ptr<engine::Map> map,
							std::shared_ptr<engine::ObjectManager> objMan,
							bool toUpdate,
							PlayerState& playerState,
							ObjectType objType) override;
		void makeWorker(engine::TilePtr);

		std::string getName() override;
	};
}