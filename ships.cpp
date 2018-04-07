#include "ships.h"
#include <iostream>
#include "game.h"


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

void CShip::setAttack(int attack) {_attack = attack; }
void CShip::setLives(int lives) {_lives = lives; }
void CShip::setArmor(int armor) {_armor = armor; }

int CShip::getLives() const { return _lives; }
int CShip::getAttack() const { return  _attack; }
int CShip::getArmor() const { return _armor; }


int CBomberBuilder::buildLives(int lives) { ship->setLives(lives); }
int CBomberBuilder::buildAttack(int attack) {ship->setAttack(attack); }
int CBomberBuilder::buildArmor(int armor) {ship->setArmor(armor); }

int CFighterBuilder::buildLives(int lives) { ship->setLives(lives); }
int CFighterBuilder::buildAttack(int attack) {ship->setAttack(attack); }
int CFighterBuilder::buildArmor(int armor) {ship->setArmor(armor); }

std::shared_ptr<CShip> IShipBuilder::getShip(){return ship; }
void IShipBuilder::createShip() {ship.reset(new CShip); }

void CShipyard::setShipBuilder(std::shared_ptr<IShipBuilder> builder) {shipBuilder = builder; }
void CShipyard::setShipPrinter(std::shared_ptr<IShipPrinter> printer) {shipPrinter = printer; }
std::shared_ptr<CShip> CShipyard::getShip(){ return shipBuilder->getShip(); }



int CShipyard::constructShip(int money, int maxLives, int maxArmor, int maxAttack,
    int livesPrice, int armorPrice,  int attackPrice) {

    shipPrinter->printLives(money, std::min(maxLives, (money-armorPrice-attackPrice)/livesPrice));
    int lives = CInputReader::getValue(0, (money-armorPrice-attackPrice)/livesPrice);
    shipBuilder->buildLives(lives);
    money -= lives*livesPrice;

    shipPrinter->printAttack(money, std::min(maxAttack, (money-armorPrice)/attackPrice));
    int attack = CInputReader::getValue(0, (money-armorPrice)/attackPrice);
    shipBuilder->buildAttack(attack);
    money -= attack*attackPrice;

    shipPrinter->printArmor(money, std::min(maxArmor, money/armorPrice));
    int armor = CInputReader::getValue(0, money/armorPrice);
    shipBuilder->buildArmor(armor);
    money -= armor*armorPrice;
    return money;
}



