#include "buildings.h"
#include <iostream>
#include <grp.h>
#include "game.h"


void CBuilding::setProtection(double protection) {_protection = protection; }
void CBuilding::setWorking(bool isWorking) {_isWorking = isWorking; }
void CBuilding::setUpgrades(int upgrades) {_upgrades = upgrades; }
void CBuilding::setPeople(int people) {_people = people; }
double CBuilding::getProtection() const { return  _protection; }
bool CBuilding::getWorking() const { return _isWorking; }
int CBuilding::getUpgrades() const { return _upgrades; }
int CBuilding::getIncome() const { return 0; }
double CBuilding::getAttack() const { return 0; }
int CBuilding::getCosts() const { return 0;}
int CBuilding::getPeople() const { return _people; }
int CBuilding::getFreePeople() const { return -getPeople(); }
void CBuilding::clean() {}
void CBuilding::increaseAttack(double value) {}
void CBuilding::increaseIncome(int value) {}
void CBuilding::increasePeople(int value) {}
void CBuilding::setMaxProtection(double protection) { _maxProtection = protection; }
double CBuilding::getMaxProtection() const { return _maxProtection; }
void CBuilding::heal() {setProtection(getMaxProtection()); }
void CBuilding::increaseMaxProtection(double value) {setMaxProtection(getMaxProtection()+value); }

void CBuilding::decreaseProtection(double value) {_protection-=value; }
void CBuilding::addBuilding(std::shared_ptr<CBuilding> buildung_ptr) {assert(false);}


int CHouse::getFreePeople() const { return getPeople(); }
void CHouse::increasePeople(int value) {setPeople(getPeople() + value); }

void CFactory::setIncome(int income) {_income = income; }
int CFactory::getIncome() const { return  _income; }
void CFactory::increaseIncome(int value) {setIncome(getIncome() + value); }


void CFortification::setAttack(double attack) {_attack = attack; }
void CFortification::setCosts(int costs) {_costs = costs;}
double CFortification::getAttack() const { return _attack; }
int CFortification::getCosts() const { return  _costs; }
int CFortification::getIncome() const { return -getCosts();}
void CFortification::increaseAttack(double value) {setAttack(getAttack() + value);}



std::shared_ptr<CHouse> CBuildingFactory::createHouse() {
    std::shared_ptr<CHouse> house(new CHouse);
    house->setUpgrades(0);
    house->setMaxProtection(House::minProtection);
    house->setProtection(House::minProtection);
    house->setWorking(true);
    house->setPeople(House::minPeople);
    return house;
}

std::shared_ptr<CFactory> CBuildingFactory::createFactory() {
    std::shared_ptr<CFactory> factory(new CFactory);
    factory->setUpgrades(0);
    factory->setMaxProtection(Factory::minProtection);
    factory->setIncome(Factory::minIncome);
    factory->setPeople(Factory::minPeople);
    factory->setProtection(Factory::minProtection);
    factory->setWorking(true);
    return factory;
}



std::shared_ptr<CFortification> CBuildingFactory::createFortification() {
    std::shared_ptr<CFortification> fort(new CFortification);
    fort->setUpgrades(0);
    fort->setMaxProtection(Fort::minProtection);
    fort->setWorking(true);
    fort->setPeople(Fort::minPeople);
    fort->setProtection(Fort::minProtection);
    fort->setCosts(Fort::minCosts);
    fort->setAttack(Fort::minAttack);
    return fort;
}



void CHousePrinter::show(CHouse const &house) {
    std::cout << "Текущее состояние дома:" << std::endl;
    std::cout << "Жителей: " << house.getPeople() << std::endl;
    std::cout << "Расходы на содержание: " << house.getCosts() << std::endl;
    std::cout << "Уровень защиты: " << house.getProtection() << std::endl;
}

void CHousePrinter::updateShow(CHouse const &house) {
    std::cout << "Вы можете увеличить население дома на " << House::upgradePeople << " человек." << std::endl;
    std::cout << "Или уровень защиты на " << House::upgradeProtection << std::endl;
    std::cout << "Cамо улучшение обойдется в " << House::upgradePrice << " галактионов." << std::endl;
}

void CHousePrinter::updateAsk(CHouse const &house) {
    std::cout << "Что вы хотите улучшить - население[1] или защиту[2] ?" << std::endl;
}

void CFactoryPrinter::show(CFactory const &factory) {
    std::cout << "Текущее состояние завода:" << std::endl;
    std::cout << "Работников: " << factory.getPeople() << std::endl;
    std::cout << "Уровень защиты: " << factory.getProtection() << std::endl;
    std::cout << "Доход: " << factory.getIncome() << std::endl;
}

void CFactoryPrinter::updateShow(CFactory const &factory) {
    std::cout << "Вы можете увеличить количество получаемого дохода на " << Factory::upgradeIncome << " галактионов." << std::endl;
    std::cout << "Или уровень защиты на " << Factory::upgradeProtection << std::endl;
    std::cout << "При увеличении дохода количество необходмиых сотрудников увеличится на"
              << Factory::upgradePeople << " человек." <<std::endl;
    std::cout << "Каждое улучшений обойдется в " << Factory::upgradePrice << " галактионов." << std::endl;

}

void CFactoryPrinter::updateAsk(CFactory const &factory) {
    std::cout << "Что вы хотите улучшить - количество исследований[1] или защиту[2] ?" << std::endl;

}


void CFortificationPrinter::show(CFortification const &fort) {
    std::cout << "Текущее состояние укрепления:" << std::endl;
    std::cout << "Солдат: " << fort.getPeople() << std::endl;
    std::cout << "Расходы на содержание: " << fort.getCosts() << std::endl;
    std::cout << "Уровень защиты: " << fort.getProtection() << std::endl;
    std::cout << "Уровень атаки: " << fort.getAttack() << std::endl;
}

void CFortificationPrinter::updateShow(CFortification const &fort) {
    std::cout << "Вы можете увеличить уровень защиты на" << Fort::upgradeAttack << std::endl;
    std::cout << "Или уровень защиты на " << Fort::upgradeProtection << std::endl;
    std::cout << "При увеличении количества исследований количество необходмиых солдат увеличится на"
              <<  Fort::upgradePeople << " человек." <<std::endl;
    std::cout << "При любом улучшении расходы на содержание станут больше на: "
              << Fort::upgradeCosts << " галактионов." <<std::endl;
    std::cout << "Каждое улучшений обойдется в " << Fort::upgradePrice << " галактионов." << std::endl;

}

void CFortificationPrinter::updateAsk(CFortification const &fort) {
    std::cout << "Что вы хотите улучшить - атаку[1] или защиту[2] ?" << std::endl;
}


int CBuildingsGroup::getFreePeople() const {
    int result = 0;
    for(int i = 0; i < group.size(); ++i){
        result += group[i]->getFreePeople();
    }
    return result;
}


double CBuildingsGroup::getProtection() const {
    double result = 0;
    for(int i = 0; i < group.size(); ++i){
        result += group[i]->getProtection();
    }
    return result;
}

double CBuildingsGroup::getAttack() const {
    double result = 0;
    for(int i = 0; i < group.size(); ++i){
        result += group[i]->getAttack();
    }
    return result;
}


int CBuildingsGroup::getIncome() const {
    int result = 0;
    for(int i = 0; i < group.size(); ++i){
        result += group[i]->getIncome();
    }
    return result;
}

void CBuildingsGroup::clean() {
    std::vector<std::shared_ptr<CBuilding> > newGroup;
    for(int i = 0; i < group.size(); ++i){
        group[i]->clean();
        if(group[i]->getProtection() > 0){
            newGroup.emplace_back(group[i]);
        }
    }

    group = newGroup;
}

void CBuildingsGroup::decreaseProtection(double value) {
    for(int i = 0; i < group.size(); ++i){
        group[i]->decreaseProtection(value/group.size());
    }
}

void CBuildingsGroup::addBuilding(std::shared_ptr<CBuilding> buildung_ptr) {
    group.emplace_back(buildung_ptr);
}

void CBuildingsGroup::increasePeople(int value) {
    for(int i = 0;i < group.size(); ++i){
        group[i]->increasePeople(value);
    }
}

void CBuildingsGroup::increaseAttack(double value) {
    for(int i = 0;i < group.size(); ++i){
        group[i]->increaseAttack(value);
    }
}

void CBuildingsGroup::increaseIncome(int value) {
    for(int i = 0;i < group.size(); ++i){
        group[i]->increaseIncome(value);
    }
}

void CBuildingsGroup::heal() {
    for(int i = 0; i < group.size(); ++i){
        group[i]->heal();
    }
}

void CBuildingsGroup::increaseMaxProtection(double value) {
    for(int i = 0; i < group.size(); ++i){
        group[i]->increaseMaxProtection(value);
    }
}

