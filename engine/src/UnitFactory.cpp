#include "../include/UnitFactory.hpp"
#include "../include/IObject.hpp"
#include "../include/TextureHandler.hpp"
#include "../../game/include/buildings/AirBase.hpp"
#include "../../game/include/buildings/MilitaryBase.hpp"
#include "../../game/include/buildings/Mine.hpp"
#include "../../game/include/buildings/SpaceStation.hpp"
#include "../../game/include/buildings/Tower.hpp"
#include "../../game/include/units/Melee.hpp"
#include "../../game/include/units/Probe.hpp"
#include "../../game/include/units/Ranged.hpp"
#include "../../game/include/units/Worker.hpp"
#include "../include/JsonParser.hpp"

namespace engine
{
    UnitFactoryPtr unitFactory = std::make_unique<UnitFactory>();

    std::shared_ptr<IObject> UnitFactory::create(game::ObjectType objType, TilePtr location, game::Ownership owner)
    {
        switch (objType)
        {
        case game::ObjectType::Melee:
        {
            auto stats = config->getStats("Melee");
            return std::make_shared<game::Melee>(game::Melee(stats["hp"], objType, *textures->getTexture("Melee"), location, stats["ms"], stats["range"], stats["ad"], stats["armour"], owner));
        }
        case game::ObjectType::Probe:
        {
            auto stats = config->getStats("Probe");
            return std::make_shared<game::Probe>(game::Probe(stats["hp"], objType, *textures->getTexture("Probe"), location, stats["ms"], stats["range"], stats["ad"], stats["armour"], owner));
        }
        case game::ObjectType::Ranged:
        {
            auto stats = config->getStats("Ranged");
            return std::make_shared<game::Ranged>(game::Ranged(stats["hp"], objType, *textures->getTexture("Ranged"), location, stats["ms"], stats["range"], stats["ad"], stats["armour"], owner));
        }
        case game::ObjectType::Worker:
        {
            auto stats = config->getStats("Worker");
            return std::make_shared<game::Worker>(game::Worker(stats["hp"], objType, *textures->getTexture("Worker"), location, stats["ms"], stats["range"], stats["ad"], stats["armour"], owner));
        }
        case game::ObjectType::AirBase:
        {
            // poznamka:
            // pocet materialov vstupujucich do konstruktorov pre budovy (ktore vedia stavat) oznacuje materialy potrebne na postavenie jednotky
            auto cost = config->getCost("Ranged");
            auto stats = config->getStats("AirBase");
            return std::make_shared<game::AirBase>(game::AirBase(stats["hp"], objType, *textures->getTexture("AirBase"), location, cost["iron"], cost["copper"], cost["silicon"], owner));
        }
        case game::ObjectType::MilitaryBase:
        {
            auto cost = config->getCost("Melee");
            auto stats = config->getStats("MilitaryBase");
            return std::make_shared<game::MilitaryBase>(game::MilitaryBase(stats["hp"], objType, *textures->getTexture("MilitaryBase"), location, cost["iron"], cost["copper"], cost["silicon"], owner));
        }
        case game::ObjectType::Mine:
        {
            auto cost = config->getCost("Mine");
            auto stats = config->getStats("Mine");
            return std::make_shared<game::Mine>(game::Mine(stats["hp"], objType, *textures->getTexture("Mine"), location, cost["iron"], cost["copper"], cost["silicon"], owner));
        }
        case game::ObjectType::SpaceStation:
        {
            auto cost = config->getCost("Worker");
            auto stats = config->getStats("SpaceStation");
            return std::make_shared<game::SpaceStation>(game::SpaceStation(stats["hp"], objType, *textures->getTexture("SpaceStation"), location, cost["iron"], cost["copper"], cost["silicon"], owner));
        }
        case game::ObjectType::Tower:
        {
            auto cost = config->getCost("Tower");
            auto stats = config->getStats("Tower");
            return std::make_shared<game::Tower>(game::Tower(stats["hp"], objType, *textures->getTexture("Tower"), location, stats["ms"], stats["range"], stats["ad"], stats["armour"], cost["iron"], cost["copper"], cost["silicon"], owner));
        }
        default:
            throw "Invalid object!";
        }

        return nullptr;
    }
}