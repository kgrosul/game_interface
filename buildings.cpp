#include "buildings.h"
#include <iostream>
#include "game.h"



void CBuilding::setPeople(int people) {_people = people; }
void CBuilding::setProtection(int protection) {_protection = protection; }
void CBuilding::setWorking(bool isWorking) {_isWorking = isWorking; }
void CBuilding::setCosts(int costs) {_costs = costs; }
void CBuilding::setUpgrades(int upgrades) {_upgrades = upgrades; }
int CBuilding::getPeople() const { return _people; }
int CBuilding::getCosts() const { return _costs; }
int CBuilding::getProtection() const { return  _protection; }
bool CBuilding::getWorking() const { return _isWorking; }
int CBuilding::getUpgrades() const { return _upgrades; }

void CHouse::setIncomePerPerson(int income) {_incomePerPerson = income; }
int CHouse::getIncomePerPerson() const { return _incomePerPerson; }

void CLaboratory::setSpeed(int speed) {_speed = speed; }
int CLaboratory::getSpeed() const { return _speed; }

void CFactory::setIncome(int income) {_income = income; }
int CFactory::getIncome() const { return  _income; }


void CFortification::setAttack(int attack) {_attack = attack; }
int CFortification::getAttack() const { return _attack; }


std::shared_ptr<CHouse> CEarthBuildingFactory::createHouse() {
    std::shared_ptr<CHouse> house(new CEarthHouse);
    house->setUpgrades(0);
    house->setCosts(House::minCosts);
    house->setIncomePerPerson(House::minIncomePerPerson);
    house->setProtection(House::minProtection);
    house->setWorking(true);
    house->setPeople(House::minPeople);
    return house;
}

std::shared_ptr<CHouse> CMartianBuildingFactory::createHouse() {
    std::shared_ptr<CHouse> house(new CMartianHouse);
    house->setUpgrades(0);
    house->setCosts(House::minCosts);
    house->setIncomePerPerson(House::minIncomePerPerson);
    house->setProtection(House::minProtection);
    house->setWorking(true);
    house->setPeople(House::minPeople);
    return house;
}

std::shared_ptr<CFactory> CEarthBuildingFactory::createFactory() {
    std::shared_ptr<CFactory> factory(new CEarthFactory);
    factory->setUpgrades(0);
    factory->setCosts(0);
    factory->setIncome(Factory::minIncome);
    factory->setPeople(Factory::minPeople);
    factory->setProtection(Factory::minProtection);
    factory->setWorking(true);
    return factory;
}

std::shared_ptr<CFactory> CMartianBuildingFactory::createFactory() {
    std::shared_ptr<CFactory> factory(new CMartianFactory);
    factory->setUpgrades(0);
    factory->setCosts(0);
    factory->setIncome(Factory::minIncome);
    factory->setPeople(Factory::minPeople);
    factory->setProtection(Factory::minProtection);
    factory->setWorking(true);
    return factory;
}

std::shared_ptr<CLaboratory> CEarthBuildingFactory::createLaboratory() {
    std::shared_ptr<CLaboratory> lab(new CEarthLaboratory);
    lab->setUpgrades(0);
    lab->setWorking(true);
    lab->setPeople(Lab::minPeople);
    lab->setProtection(Lab::minProtection);
    lab->setCosts(Lab::minCosts);
    lab->setSpeed(Lab::minSpeed);
    return lab;
}

std::shared_ptr<CLaboratory> CMartianBuildingFactory::createLaboratory() {
    std::shared_ptr<CLaboratory> lab(new CMartianLaboratory);
    lab->setUpgrades(0);

    lab->setWorking(true);
    lab->setPeople(Lab::minPeople);
    lab->setProtection(Lab::minProtection);
    lab->setCosts(Lab::minCosts);
    lab->setSpeed(Lab::minSpeed);
    return lab;
}

std::shared_ptr<CFortification> CEarthBuildingFactory::createFortification() {
    std::shared_ptr<CFortification> fort(new CEarthFortification);
    fort->setUpgrades(0);
    fort->setWorking(true);
    fort->setPeople(Fort::minPeople);
    fort->setProtection(Fort::minProtection);
    fort->setCosts(Fort::minCosts);
    fort->setAttack(Fort::minAttack);
    return fort;
}


std::shared_ptr<CFortification> CMartianBuildingFactory::createFortification() {
    std::shared_ptr<CFortification> fort(new CMartianFortification);
    fort->setUpgrades(0);
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
    std::cout << "Доход с одного жителя: "  << house.getIncomePerPerson() << std::endl;
    std::cout << "Расходы на содержание: " << house.getCosts() << std::endl;
    std::cout << "Уровень защиты: " << house.getProtection() << std::endl;
}

void CHousePrinter::updateShow(CHouse const &house) {
    std::cout << "Вы можете увеличить население дома на " << House::upgradePeople << " человек." << std::endl;
    std::cout << "Также вы можете увеличть плату за проживание с человека на "
              << House::upgradeIncome << " галактион." << std::endl;
    std::cout << "Или уровень защиты на " << House::upgradeProtection << std::endl;
    std::cout << "Однако при любом улучшении расходы на содержание станут больше на: "
              << House::upgradeCosts << " галактионов." <<std::endl;
    std::cout << "А само улучшение обойдется в " << House::upgradePrice << " галактионов." << std::endl;
}

void CHousePrinter::updateAsk(CHouse const &house) {
    std::cout << "Что вы хотите улучшить - население[1], доход[2] или защиту[3] ?" << std::endl;
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


void CLaboratoryPrinter::show(CLaboratory const &lab) {
    std::cout << "Текущее состояние лаборатории:" << std::endl;
    std::cout << "Работников: " << lab.getPeople() << std::endl;
    std::cout << "Расходы на содержание: " << lab.getCosts() << std::endl;
    std::cout << "Уровень защиты: " << lab.getProtection() << std::endl;
    std::cout << "Максимальное количество параллельных иследований: " << lab.getSpeed() << std::endl;
}

void CLaboratoryPrinter::updateShow(CLaboratory const &lab) {
    std::cout << "Вы можете увеличить количество одновременно проводимых исследований на " << Lab::upgradeSpeed << std::endl;
    std::cout << "Или уровень защиты на " << Lab::upgradeProtection << std::endl;
    std::cout << "При увеличении количества исследований количество необходмиых сотрудников увеличится на"
              << Lab::upgradePeople << " человек." <<std::endl;
    std::cout << "При любом улучшении расходы на содержание станут больше на: "
              << Lab::upgradeCosts << " галактионов." <<std::endl;
    std::cout << "Каждое улучшений обойдется в " << Lab::upgradePrice << " галактионов." << std::endl;

}

void CLaboratoryPrinter::updateAsk(CLaboratory const &lab) {
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