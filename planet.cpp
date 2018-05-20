#include "planet.h"
#include "memory"
#include "game.h"

void CPlanet::reset() {
    city.clear();
    fleet.clear();
    CShipsGroup bombers;
    CShipsGroup fighters;
    CBuildingsGroup houses;
    CBuildingsGroup factories;
    CBuildingsGroup fortifications;

    CBomberBuilder bomberBuilder;
    CFighterBuilder fighterBuilder;
    for(int i = 0; i < Game::resetShipNumber; ++i){
        bomberBuilder.createShip();
        bomberBuilder.buildLives(Bomber::minLives);
        bomberBuilder.buildArmor(Bomber::minArmor);
        bomberBuilder.buildAttack(Bomber::minAttack);
        bombers.addShip(bomberBuilder.getShip());

        fighterBuilder.createShip();
        fighterBuilder.buildLives(Fighter::minLives);
        fighterBuilder.buildAttack(Fighter::minAttack);
        fighterBuilder.buildArmor(Fighter::minArmor);
        fighters.addShip(fighterBuilder.getShip());
    }

    auto factory = new CBuildingFactory;
    for(int i = 0; i < Game::resetHouse; ++i){
        houses.addBuilding(factory->createHouse());
    }

    for(int i = 0; i < Game::resetFactory; ++i){
        factories.addBuilding(factory->createFactory());
    }

    for(int i = 0; i < Game::resetFort; ++i){
        fortifications.addBuilding(factory->createFortification());
    }

    delete factory;

    city.push_back(houses);
    city.push_back(factories);
    city.push_back(fortifications);
    fleet.push_back(bombers);
    fleet.push_back(fighters);
}

void CWarPlanet::attackCity(IPlanet &otherPlanet, int mySquadronNum, int regionNum) {
    if(mySquadronNum >= planet->fleet.size())
        return;
    if(regionNum >= otherPlanet.city.size())
        return;
    double myAttack = planet->fleet[mySquadronNum].getAttack();
    double myProtection = planet->fleet[mySquadronNum].getArmor();
    otherPlanet.city[regionNum].decreaseProtection(myAttack);
    double hisAttack = otherPlanet.city[regionNum].getAttack();
    if(myProtection < hisAttack){
        planet->fleet[mySquadronNum].decreaseLives(hisAttack);
    }
    planet->fleet[mySquadronNum].clean();
    if(planet->fleet[mySquadronNum].getLives() <= 0){
        planet->fleet.erase(planet->fleet.begin()+mySquadronNum);
    }
    otherPlanet.city[regionNum].clean();

    if(otherPlanet.city[regionNum].getProtection() <= 0){
        otherPlanet.city.erase(otherPlanet.city.begin()+regionNum);
    }
}

void CWarPlanet::attackFleet(IPlanet &otherPlanet, int mySquadronNum, int otherSquadronNum) {
    if(mySquadronNum >= planet->fleet.size())
        return;
    if(otherSquadronNum >= otherPlanet.fleet.size())
        return;
    double myAttack = planet->fleet[mySquadronNum].getAttack();
    double myProtection = planet->fleet[mySquadronNum].getArmor();
    double hisAttack = otherPlanet.fleet[otherSquadronNum].getAttack();
    double hisProtection = otherPlanet.fleet[otherSquadronNum].getArmor();
    if(myProtection < hisAttack){
        planet->fleet[mySquadronNum].decreaseLives(hisAttack);
    }
    if(hisProtection < myAttack){
        otherPlanet.fleet[otherSquadronNum].decreaseLives(myAttack);
    }
    planet->fleet[otherSquadronNum].clean();
    if(planet->fleet[mySquadronNum].getLives() <= 0){
        planet->fleet.erase(planet->fleet.begin()+mySquadronNum);
    }
    otherPlanet.fleet[otherSquadronNum].clean();
    if(otherPlanet.fleet[otherSquadronNum].getLives() <= 0){
        otherPlanet.fleet.erase(otherPlanet.fleet.begin()+otherSquadronNum);
    }
}

void CEconomyPlanet::upgradeCityAttack(int regionNum, int points) {
    if(regionNum > planet->city.size()){
        return;
    }
    planet->city[regionNum].increaseAttack(points);
}

void CEconomyPlanet::upgradeCityIncome(int regionNum, int points) {
    if(regionNum > planet->city.size()){
        return;
    }
    planet->city[regionNum].increaseIncome(points);
}

void CEconomyPlanet::upgradeCityPeople(int regionNum, int points) {
    if(regionNum > planet->city.size()){
        return;
    }
    planet->city[regionNum].increasePeople(points);
}

void CEconomyPlanet::heal(int regionNum) {
    if(regionNum > planet->city.size()){
        return;
    }
    planet->city[regionNum].heal();
}

void CEconomyPlanet::upgradeCityMaxProtection(int regionNum, int points) {
    if(regionNum > planet->city.size()){
        return;
    }
    planet->city[regionNum].increaseMaxProtection(double(points));
}

void CWarPlanet::reset() {
    planet->reset();
}

void CEconomyPlanet::reset() {
    planet->reset();
}
