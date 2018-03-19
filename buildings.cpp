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
void CHouse::show() const {
    std::cout << "Текущее состояние дома:" << std::endl;
    std::cout << "Жителей: " << getPeople() << std::endl;
    std::cout << "Доход с одного жителя: "  << getIncomePerPerson() << std::endl;
    std::cout << "Расходы на содержание: " << getCosts() << std::endl;
    std::cout << "Уровень защиты: " << getProtection() << std::endl;
}



void CLaboratory::show() const {
    std::cout << "Текущее состояние лаборатории:" << std::endl;
    std::cout << "Работников: " << getPeople() << std::endl;
    std::cout << "Расходы на содержание: " << getCosts() << std::endl;
    std::cout << "Уровень защиты: " << getProtection() << std::endl;
    std::cout << "Максимальное количество параллельных иследований: " << getSpeed() << std::endl;

}
void CLaboratory::setSpeed(int speed) {_speed = speed; }
int CLaboratory::getSpeed() const { return _speed; }

void CFactory::setIncome(int income) {_income = income; }
int CFactory::getIncome() const { return  _income; }
void CFactory::show() const {
    std::cout << "Текущее состояние завода:" << std::endl;
    std::cout << "Работников: " << getPeople() << std::endl;
    std::cout << "Уровень защиты: " << getProtection() << std::endl;
    std::cout << "Доход: " << getIncome() << std::endl;
}

void CFortification::setAttack(int attack) {_attack = attack; }
int CFortification::getAttack() const { return _attack; }
void CFortification::show() const {
    std::cout << "Текущее состояние укрепления:" << std::endl;
    std::cout << "Солдат: " << getPeople() << std::endl;
    std::cout << "Расходы на содержание: " << getCosts() << std::endl;
    std::cout << "Уровень защиты: " << getProtection() << std::endl;
    std::cout << "Уровень атаки: " << getAttack() << std::endl;
}

std::shared_ptr<CHouse> CEarthBuildingFactory::createHouse() {
    std::shared_ptr<CHouse> house(new CEarthHouse);
    house->setUpgrades(0);
    house->setCosts(CData::getInstance().houseMinCosts);
    house->setIncomePerPerson(CData::getInstance().houseMinIncomePerPerson);
    house->setProtection(CData::getInstance().houseMinProtection);
    house->setWorking(true);
    house->setPeople(CData::getInstance().houseMinPeople);
    return house;
}

std::shared_ptr<CHouse> CMartianBuildingFactory::createHouse() {
    std::shared_ptr<CHouse> house(new CMartianHouse);
    house->setUpgrades(0);
    house->setCosts(CData::getInstance().houseMinCosts);
    house->setIncomePerPerson(CData::getInstance().houseMinIncomePerPerson);
    house->setProtection(CData::getInstance().houseMinProtection);
    house->setWorking(true);
    house->setPeople(CData::getInstance().houseMinPeople);
    return house;
}

std::shared_ptr<CFactory> CEarthBuildingFactory::createFactory() {
    std::shared_ptr<CFactory> factory(new CEarthFactory);
    factory->setUpgrades(0);
    factory->setCosts(0);
    factory->setIncome(CData::getInstance().factoryMinIncome);
    factory->setPeople(CData::getInstance().factoryMinPeople);
    factory->setProtection(CData::getInstance().factoryMinProtection);
    factory->setWorking(true);
    return factory;
}

std::shared_ptr<CFactory> CMartianBuildingFactory::createFactory() {
    std::shared_ptr<CFactory> factory(new CMartianFactory);
    factory->setUpgrades(0);
    factory->setCosts(0);
    factory->setIncome(CData::getInstance().factoryMinIncome);
    factory->setPeople(CData::getInstance().factoryMinPeople);
    factory->setProtection(CData::getInstance().factoryMinProtection);
    factory->setWorking(true);
    return factory;
}

std::shared_ptr<CLaboratory> CEarthBuildingFactory::createLaboratory() {
    std::shared_ptr<CLaboratory> lab(new CEarthLaboratory);
    lab->setUpgrades(0);
    lab->setWorking(true);
    lab->setPeople(CData::getInstance().labMinPeople);
    lab->setProtection(CData::getInstance().labMinProtection);
    lab->setCosts(CData::getInstance().labMinCosts);
    lab->setSpeed(CData::getInstance().labMinSpeed);
    return lab;
}

std::shared_ptr<CLaboratory> CMartianBuildingFactory::createLaboratory() {
    std::shared_ptr<CLaboratory> lab(new CMartianLaboratory);
    lab->setUpgrades(0);

    lab->setWorking(true);
    lab->setPeople(CData::getInstance().labMinPeople);
    lab->setProtection(CData::getInstance().labMinProtection);
    lab->setCosts(CData::getInstance().labMinCosts);
    lab->setSpeed(CData::getInstance().labMinSpeed);
    return lab;
}

std::shared_ptr<CFortification> CEarthBuildingFactory::createFortification() {
    std::shared_ptr<CFortification> fort(new CEarthFortification);
    fort->setUpgrades(0);
    fort->setWorking(true);
    fort->setPeople(CData::getInstance().fortMinPeople);
    fort->setProtection(CData::getInstance().fortMinProtection);
    fort->setCosts(CData::getInstance().fortMinCosts);
    fort->setAttack(CData::getInstance().fortMinAttack);
    return fort;
}


std::shared_ptr<CFortification> CMartianBuildingFactory::createFortification() {
    std::shared_ptr<CFortification> fort(new CMartianFortification);
    fort->setUpgrades(0);
    fort->setWorking(true);
    fort->setPeople(CData::getInstance().fortMinPeople);
    fort->setProtection(CData::getInstance().fortMinProtection);
    fort->setCosts(CData::getInstance().fortMinCosts);
    fort->setAttack(CData::getInstance().fortMinAttack);
    return fort;
}

void CEarthHouse::upgrade() {
    if (getUpgrades() == CData::getInstance().earthMaxHouseUpgrade) {
        CData::getInstance().noUpgradesAvaliable();
        return;
    }

    if (CData::getInstance().earthMoney < CData::getInstance().houseUpgradePrice) {
        CData::getInstance().noMoney();
        return;
    }

    show();
    CData::getInstance().houseUpdateShow();
    CData::getInstance().houseUpdateAsk();
    int result = -1;
    do {
        std::cin >> result;
    } while (result < 1 || result > 3);
    switch (result) {
        case 1:
            setPeople(getPeople() + CData::getInstance().houseUpgradePeople);
            break;
        case 2:
            setIncomePerPerson(getIncomePerPerson() + CData::getInstance().houseUpgradeIncome);
            break;

        case 3:
            setProtection(getProtection() + CData::getInstance().houseUpgradeProtection);
    }

    setCosts(getCosts() + CData::getInstance().houseUpgradeCosts);
    CData::getInstance().earthMoney -= CData::getInstance().houseUpgradePrice;
    setUpgrades(getUpgrades()+1);

}

void CMartianHouse::upgrade() {
    if (getUpgrades() == CData::getInstance().martianMaxHouseUpgrade) {
        CData::getInstance().noUpgradesAvaliable();
        return;
    }

    if (CData::getInstance().martianMoney < CData::getInstance().houseUpgradePrice) {
        CData::getInstance().noMoney();
        return;
    }

    show();
    CData::getInstance().houseUpdateShow();
    CData::getInstance().houseUpdateAsk();
    int result = -1;
    do {
        std::cin >> result;
    } while (result < 1 || result > 3);
    switch (result) {
        case 1:
            setPeople(getPeople() + CData::getInstance().houseUpgradePeople);
            break;
        case 2:
            setIncomePerPerson(getIncomePerPerson() + CData::getInstance().houseUpgradeIncome);
            break;

        case 3:
            setProtection(getProtection() + CData::getInstance().houseUpgradeProtection);
    }

    setCosts(getCosts() + CData::getInstance().houseUpgradeCosts);
    CData::getInstance().martianMoney -= CData::getInstance().houseUpgradePrice;
    setUpgrades(getUpgrades()+1);

}


void CEarthFactory::upgrade() {
    if (getUpgrades() == CData::getInstance().earthMaxFactoryUpgrade){
        CData::getInstance().noUpgradesAvaliable();
        return;
    }
    if (CData::getInstance().earthMoney < CData::getInstance().factoryUpgradePrice) {
        CData::getInstance().noMoney();
        return;
    }

    show();
    CData::getInstance().factoryUpdateShow();
    CData::getInstance().factoryUpdateAsk();
    int result = -1;
    do {
        std::cin >> result;
    } while (result < 1 || result > 2);
    switch (result) {
        case 1:
            setIncome(getIncome() + CData::getInstance().factoryUpgradeIncome);
            break;
        case 2:
            setProtection(getProtection() + CData::getInstance().factoryUpgradeProtection);
    }
    setPeople(getPeople() + CData::getInstance().factoryUpgradePeople);
    CData::getInstance().earthMoney -= CData::getInstance().factoryUpgradePrice;
    setUpgrades(getUpgrades()+1);
}

void CMartianFactory::upgrade() {
    if (getUpgrades() == CData::getInstance().martianMaxFactoryUpgrade){
        CData::getInstance().noUpgradesAvaliable();
        return;
    }
    if (CData::getInstance().martianMoney < CData::getInstance().factoryUpgradePrice) {
        CData::getInstance().noMoney();
        return;
    }

    show();
    CData::getInstance().factoryUpdateShow();
    CData::getInstance().factoryUpdateAsk();
    int result = -1;
    do {
        std::cin >> result;
    } while (result < 1 || result > 2);
    switch (result) {
        case 1:
            setIncome(getIncome() + CData::getInstance().factoryUpgradeIncome);
            break;
        case 2:
            setProtection(getProtection() + CData::getInstance().factoryUpgradeProtection);
    }
    setPeople(getPeople() + CData::getInstance().factoryUpgradePeople);
    CData::getInstance().martianMoney -= CData::getInstance().factoryUpgradePrice;
    setUpgrades(getUpgrades()+1);

}

void CEarthLaboratory::upgrade() {
    if (getUpgrades() == CData::getInstance().earthMaxLabUpgrade){
        CData::getInstance().noUpgradesAvaliable();
        return;
    }
    if (CData::getInstance().earthMoney < CData::getInstance().labUpgradePrice) {
        CData::getInstance().noMoney();
        return;
    }

    show();
    CData::getInstance().labUpdateShow();
    CData::getInstance().labUpdateAsk();
    int result = -1;
    do {
        std::cin >> result;
    } while (result < 1 || result > 2);
    switch (result) {
        case 1:
            setSpeed(getSpeed()+CData::getInstance().labUpgradeSpeed);
            setPeople(getPeople() + CData::getInstance().labUpgradePeople);
            break;
        case 2:
            setProtection(getProtection() + CData::getInstance().labUpgradeProtection);
    }
    setCosts(getCosts() + CData::getInstance().labUpgradeCosts);
    CData::getInstance().earthMoney -= CData::getInstance().labUpgradePrice;
    setUpgrades(getUpgrades()+1);
}

void CMartianLaboratory::upgrade() {
    if (getUpgrades() == CData::getInstance().martianMaxLabUpgrade){
        CData::getInstance().noUpgradesAvaliable();
        return;
    }
    if (CData::getInstance().martianMoney  < CData::getInstance().labUpgradePrice) {
        CData::getInstance().noMoney();
        return;
    }

    show();
    CData::getInstance().labUpdateShow();
    CData::getInstance().labUpdateAsk();
    int result = -1;
    do {
        std::cin >> result;
    } while (result < 1 || result > 2);
    switch (result) {
        case 1:
            setSpeed(getSpeed()+CData::getInstance().labUpgradeSpeed);
            setPeople(getPeople() + CData::getInstance().labUpgradePeople);
            break;
        case 2:
            setProtection(getProtection() + CData::getInstance().labUpgradeProtection);
    }
    setCosts(getCosts() + CData::getInstance().labUpgradeCosts);
    CData::getInstance().martianMoney  -= CData::getInstance().labUpgradePrice;
    setUpgrades(getUpgrades()+1);
}

void CEarthFortification::upgrade() {
    if (getUpgrades() == CData::getInstance().earthMaxFortUpgrade){
        CData::getInstance().noUpgradesAvaliable();
        return;
    }
    if (CData::getInstance().earthMoney < CData::getInstance().fortUpgradePrice) {
        CData::getInstance().noMoney();
        return;
    }

    show();
    CData::getInstance().fortUpdateShow();
    CData::getInstance().fortUpdateAsk();
    int result = -1;
    do {
        std::cin >> result;
    } while (result < 1 || result > 2);
    switch (result) {
        case 1:
            setAttack(getAttack() + CData::getInstance().fortUpgradeAttack);
            setPeople(getPeople() + CData::getInstance().fortUpgradePeople);
            break;
        case 2:
            setProtection(getProtection() + CData::getInstance().fortUpgradeProtection);
    }
    setCosts(getCosts() + CData::getInstance().fortUpgradeCosts);
    CData::getInstance().earthMoney -= CData::getInstance().fortUpgradePrice;
    setUpgrades(getUpgrades()+1);
}

void CMartianFortification::upgrade() {
    if (getUpgrades() == CData::getInstance().martianMaxFortUpgrade){
        CData::getInstance().noUpgradesAvaliable();
        return;
    }
    if (CData::getInstance().martianMoney < CData::getInstance().fortUpgradePrice) {
        CData::getInstance().noMoney();
        return;
    }

    show();
    CData::getInstance().fortUpdateShow();
    CData::getInstance().fortUpdateAsk();
    int result = -1;
    do {
        std::cin >> result;
    } while (result < 1 || result > 2);
    switch (result) {
        case 1:
            setAttack(getAttack() + CData::getInstance().fortUpgradeAttack);
            setPeople(getPeople() + CData::getInstance().fortUpgradePeople);
            break;
        case 2:
            setProtection(getProtection() + CData::getInstance().fortUpgradeProtection);
    }
    setCosts(getCosts() + CData::getInstance().fortUpgradeCosts);
    CData::getInstance().martianMoney -= CData::getInstance().fortUpgradePrice;
    setUpgrades(getUpgrades()+1);
}
