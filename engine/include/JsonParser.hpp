#pragma once
#include "../../rapidjson/document.h"
#include "../../rapidjson/filereadstream.h"
#include <string>
#include <memory>
#include <map>
#include "Map.hpp"

namespace engine
{
	class JsonParser;
	extern std::unique_ptr<JsonParser> config;

	class JsonParser
	{
	private:
		rapidjson::Document m_gameConfigFile;
		std::string m_configType;

		void setConfigType(const std::string&);

		std::map<std::string, std::map<std::string, int>> m_costs;
		std::map<std::string, std::map<std::string, int>> m_stats;

		void parseCosts();
		void parseStats();

	public:

		bool setGameConfig(const std::string&, const std::string&);
		unsigned short getMapHeight();
		unsigned short getMapWidth();
		unsigned short getNumberOfPlanets();
		unsigned getTileSize() const;
		unsigned char getMaxRadiusOfPlanet();
		unsigned char getTileSize();
		std::map<std::string, std::string> getTextures();
		std::map<std::string, int> getCost(const std::string& unit);
		std::map<std::string, int> getStats(const std::string& unit);
	};
}