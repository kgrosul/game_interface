#include "ships.h"
#include <iostream>
#include "game.h"
#include <vector>
#include <memory>


int CInputReader::getValue(int minValue, int maxValue) {
    bool flag = true;
    if(minValue == maxValue)
        return 0;
    int value;
    while(flag){
        std::cin >> value;
        if(value > maxValue || value < minValue){
            Printer::correctValue();
        } else {
            flag = false;
        }
    }

    return value;
}

void CFighterPrinter::printLives(int money, int maxLives) {
    std::cout << "Стандартный истрибитель имеет " << Fighter::minLives << " очков жизни." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << Fighter::liveUpdate << " галактионов."
              << std::endl;
    std::cout << "Максимальное количество очков для вас составляет " <<
              std::min(maxLives,money/Fighter::liveUpdate) << std::endl;

}

void CBomberPrinter::printLives(int money, int maxLives) {
    std::cout << "Стандартный бомбардировщик имеет " << Bomber::minLives << " очков жизни." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << Bomber::liveUpdate << " галактионов."
              << std::endl;
    std::cout << "Максимальное количество очков для вас составляет " <<
              std::min(maxLives,money/Bomber::liveUpdate) << std::endl;

}

void CFighterPrinter::printArmor(int money, int maxArmor) {
    std::cout << "Стандартный истрибитель имеет " << Fighter::minArmor << " очков брони." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << Fighter::armorUpdate << " галактионов."
              << std::endl;;
    std::cout << "Максимальное количество очков для вас составляет " <<
              std::min(maxArmor,money/Fighter::armorUpdate) << std::endl;
}

void CBomberPrinter::printArmor(int money, int maxArmor) {
    std::cout << "Стандартный истрибитель имеет " << Bomber::minArmor << " очков брони." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << Bomber::armorUpdate << " галактионов."
              << std::endl;;
    std::cout << "Максимальное количество очков для вас составляет " <<
              std::min(maxArmor,money/Bomber::armorUpdate) << std::endl;
}


void CFighterPrinter::printAttack(int money, int maxAttack) {
    std::cout << "Стандартный истрибитель имеет " << Fighter::minAttack << " очков атаки." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << Fighter::attackUpdate << " галактионов."
              << std::endl;
    std::cout << "Максимальное количество очков для вас составляет " <<
              std::min(maxAttack, money/Fighter::attackUpdate) << std::endl;
}

void CBomberPrinter::printAttack(int money, int maxAttack) {
    std::cout << "Стандартный истрибитель имеет " << Fighter::minAttack << " очков атаки." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << Fighter::attackUpdate << " галактионов."
              << std::endl;
    std::cout << "Максимальное количество очков для вас составляет " <<
              std::min(maxAttack, money/Fighter::attackUpdate) << std::endl;
}

void CShip::setAttack(double attack) {_attack = attack; }
void CShip::setLives(double lives) {_lives = lives; }
void CShip::setArmor(double armor) {_armor = armor; }

double CShip::getLives() const { return _lives; }
double CShip::getAttack() const { return  _attack; }
double CShip::getArmor() const { return _armor; }

void CShip::addShip(std::shared_ptr<CShip>) {
    assert(false);
}

void CShip::decreaseArmor(double value) {
    setArmor(getArmor()-value);
}

void CShip::decreaseAttack(double value) {
    setAttack(getAttack()-value);
}

void CShip::decreaseLives(double value) {
    setLives(getLives()-value);
}
void CShip::clean(){}

void CBomberBuilder::buildLives(double lives) { ship->setLives(lives); }
void CBomberBuilder::buildAttack(double attack) {ship->setAttack(attack); }
void CBomberBuilder::buildArmor(double armor) {ship->setArmor(armor); }

void CFighterBuilder::buildLives(double lives) { ship->setLives(lives); }
void CFighterBuilder::buildAttack(double attack) {ship->setAttack(attack); }
void CFighterBuilder::buildArmor(double armor) {ship->setArmor(armor); }

std::shared_ptr<CShip> IShipBuilder::getShip(){return ship; }
void IShipBuilder::createShip() {ship.reset(new CShip); }

void CShipyard::setShipBuilder(std::shared_ptr<IShipBuilder> builder) {shipBuilder = builder; }
void CShipyard::setShipPrinter(std::shared_ptr<IShipPrinter> printer) {shipPrinter = printer; }
std::shared_ptr<CShip> CShipyard::getShip(){ return shipBuilder->getShip(); }



int CShipyard::constructShip(int money, int maxLives, int maxArmor, int maxAttack,
    int livesPrice, int armorPrice,  int attackPrice) {

    shipPrinter->printLives(money, std::min(maxLives, (money-armorPrice-attackPrice)/livesPrice));
    double lives = CInputReader::getValue(0, (money-armorPrice-attackPrice)/livesPrice);
    shipBuilder->buildLives(lives);
    money -= lives*livesPrice;

    shipPrinter->printAttack(money, std::min(maxAttack, (money-armorPrice)/attackPrice));
    double attack = CInputReader::getValue(0, (money-armorPrice)/attackPrice);
    shipBuilder->buildAttack(attack);
    money -= attack*attackPrice;

    shipPrinter->printArmor(money, std::min(maxArmor, money/armorPrice));
    double armor = CInputReader::getValue(0, money/armorPrice);
    shipBuilder->buildArmor(armor);
    money -= armor*armorPrice;
    return money;
}


double CShipsGroup::getArmor() const {
    double result = 0;
    for(int i = 0; i < group.size(); ++i){
        result += group[i]->getArmor();
    }
    return result;
}

double CShipsGroup::getLives() const {
    double result = 0;
    for(int i = 0; i < group.size(); ++i){
        result += group[i]->getLives();
    }
    return result;
}

double CShipsGroup::getAttack() const {
    double result = 0;
    for(int i = 0; i < group.size(); ++i){
        result += group[i]->getAttack();
    }
    return result;
}

void CShipsGroup::addShip(std::shared_ptr<CShip> ship_ptr){
    group.emplace_back(ship_ptr);
}

void CShipsGroup::decreaseLives(double value) {
    for(int i = 0; i < group.size(); ++i){
        group[i]->decreaseLives(value/group.size());
    }
}
void CShipsGroup::decreaseArmor(double value) {
    for(int i = 0; i < group.size(); ++i){
        group[i]->decreaseArmor(value/group.size());
    }
}

void CShipsGroup::decreaseAttack(double value) {
    for(int i = 0; i < group.size(); ++i){
        group[i]->decreaseAttack(value/group.size());
    }
}

void CShipsGroup::clean() {
    std::vector<std::shared_ptr<CShip> > newGroup;
    for(int i = 0; i < group.size(); ++i){
        group[i]->clean();
        if(group[i]->getLives() > 0){
            newGroup.emplace_back(group[i]);
        }
    }
    group.clear();
    group = newGroup;
}


