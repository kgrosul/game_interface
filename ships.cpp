#include "ships.h"
#include <iostream>
#include "game.h"



void CShip::setAttack(int attack) {_attack = attack; }
void CShip::setLives(int lives) {_lives = lives; }
void CShip::setArmor(int armor) {_armor = armor; }

int CShip::getLives() const { return _lives; }
int CShip::getAttack() const { return  _attack; }
int CShip::getArmor() const { return _armor; }


std::shared_ptr<CShip> IShipBuilder::getShip(){return ship; }
void IShipBuilder::createShip() {ship.reset(new CShip); }

void CShipyard::setShipBuilder(IShipBuilder* builder){ shipBuilder = builder; }
std::shared_ptr<CShip> CShipyard::getShip(){ return shipBuilder->getShip(); }

int CEarthFighterBuilder::buildLives(int money) {
    
    std::cout << "Стандартный истрибитель имеет " << CData::getInstance().fighterMinLives << " очков жизни." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().fighterLiveUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().earthFighterMaxLives,money/CData::getInstance().fighterLiveUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setLives(CData::getInstance().fighterMinLives + addPoints);
            return addPoints * CData::getInstance().fighterLiveUpdate;
        }
    } while(flag);
}

int CEarthFighterBuilder::buildArmor(int money) {
    std::cout << "Стандартный истрибитель имеет " << CData::getInstance().fighterMinArmor << " очков брони." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().fighterArmorUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().earthFighterMaxArmor, money/CData::getInstance().fighterArmorUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setArmor(CData::getInstance().fighterMinArmor + addPoints);
            return addPoints * CData::getInstance().fighterArmorUpdate;
        }
    } while(flag);

}

int CEarthFighterBuilder::buildAttack(int money) {
    std::cout << "Стандартный истрибитель имеет " << CData::getInstance().fighterMinAttack << " очков атаки." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().fighterAttackUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().earthFighterMaxAttack, money/CData::getInstance().fighterAttackUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setAttack(CData::getInstance().fighterMinAttack + addPoints);
            return addPoints * CData::getInstance().fighterAttackUpdate;
        }
    } while(flag);

}

int CMartianFighterBuilder::buildLives(int money) {
    std::cout << "Стандартный истрибитель имеет " << CData::getInstance().fighterMinLives << " очков жизни." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().fighterLiveUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().martianFighterMaxLives,money/CData::getInstance().fighterLiveUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setLives(CData::getInstance().fighterMinLives + addPoints);
            return addPoints * CData::getInstance().fighterLiveUpdate;
        }
    } while(flag);
}

int CMartianFighterBuilder::buildArmor(int money) {
    std::cout << "Стандартный истрибитель имеет " << CData::getInstance().fighterMinArmor << " очков брони." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().fighterArmorUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().martianFighterMaxArmor,money/CData::getInstance().fighterArmorUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setArmor(CData::getInstance().fighterMinArmor + addPoints);
            return addPoints * CData::getInstance().fighterArmorUpdate;
        }
    } while(flag);

}

int CMartianFighterBuilder::buildAttack(int money) {
    std::cout << "Стандартный бомбардировщик имеет " << CData::getInstance().fighterMinAttack << " очков атаки." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().fighterAttackUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().martianFighterMaxAttack,money/CData::getInstance().fighterAttackUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setAttack(CData::getInstance().fighterMinAttack + addPoints);
            money -= addPoints * CData::getInstance().fighterAttackUpdate;
        }
    } while(flag);
}



int CEarthBomberBuilder::buildLives(int money) {
    auto Data = CData::getInstance().earthBomberMaxArmor;
    std::cout << "Стандартный бомбардировщик имеет " << CData::getInstance().bomberMinLives << " очков жизни." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().bomberLiveUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().earthBomberMaxLives,money/CData::getInstance().bomberLiveUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setLives(CData::getInstance().bomberMinLives + addPoints);
            return addPoints * CData::getInstance().bomberLiveUpdate;
        }
    } while(flag);
}

int CEarthBomberBuilder::buildArmor(int money) {
    std::cout << "Стандартный бомбардировщик имеет " << CData::getInstance().bomberMinArmor << " очков брони." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().bomberArmorUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().earthBomberMaxArmor, money/CData::getInstance().bomberArmorUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setArmor(CData::getInstance().bomberMinArmor + addPoints);
            return addPoints * CData::getInstance().bomberArmorUpdate;
        }
    } while(flag);

}

int CEarthBomberBuilder::buildAttack(int money) {
    std::cout << "Стандартный бомбардировщик имеет " << CData::getInstance().bomberMinAttack << " очков атаки." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().bomberAttackUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().earthBomberMaxAttack, money/CData::getInstance().bomberAttackUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setAttack(CData::getInstance().bomberMinAttack + addPoints);
            return addPoints * CData::getInstance().bomberAttackUpdate;
        }
    } while(flag);

}

int CMartianBomberBuilder::buildLives(int money) {
    std::cout << "Стандартный бомбардировщик имеет " << CData::getInstance().bomberMinLives << " очков жизни." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().bomberLiveUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().martianBomberMaxLives,money/CData::getInstance().bomberLiveUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setLives(CData::getInstance().bomberMinLives + addPoints);
            return addPoints * CData::getInstance().bomberLiveUpdate;
        }
    } while(flag);
}

int CMartianBomberBuilder::buildArmor(int money) {
    std::cout << "Стандартный бомбардировщик имеет " << CData::getInstance().bomberMinArmor << " очков брони." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().bomberArmorUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().martianBomberMaxArmor,money/CData::getInstance().bomberArmorUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setArmor(CData::getInstance().bomberMinArmor + addPoints);
            return addPoints * CData::getInstance().bomberArmorUpdate;
        }
    } while(flag);

}

int CMartianBomberBuilder::buildAttack(int money) {
    std::cout << "Стандартный бомбардировщик имеет " << CData::getInstance().bomberMinAttack << " очков атаки." << std::endl;
    std::cout << "За каждое дополнительное очко надо заплатить " << CData::getInstance().bomberAttackUpdate << " галактионов."
              << std::endl;

    int maxPoints = std::min(CData::getInstance().martianBomberMaxAttack,money/CData::getInstance().bomberAttackUpdate);
    std::cout << "Максимальное количество очков для вас составляет " << maxPoints << std::endl;
    bool flag = false;
    int price = 0;
    int addPoints;
    do {
        if(flag){
            std::cout << "Введите корректное количество дополнительный очков жизни." << std::endl;

        }
        std::cout << "Введите количество дополнительный очков жизни." << std::endl;
        std::cin >> addPoints;
        if(addPoints < 0 || addPoints > maxPoints) {
            flag = true;
        } else {
            flag = false;
            ship->setAttack(CData::getInstance().bomberMinAttack + addPoints);
            money -= addPoints * CData::getInstance().bomberAttackUpdate;
        }
    } while(flag);
}




int CShipyard::constructShip(int money) {
    shipBuilder->createShip();
    money -= shipBuilder->buildLives(money);
    money -= shipBuilder->buildArmor(money);
    money -= shipBuilder->buildAttack(money);
    return money;
}



