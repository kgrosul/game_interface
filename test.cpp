#include <gtest/gtest.h>
#include "game.h"
#include "ships.h"
#include "buildings.h"

TEST(earthBomber, armor){
    CShipyard shipyard;
    CEarthBomberBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getArmor(), CData::getInstance().bomberMinArmor);
}

TEST(earthBomber, lives){
    CShipyard shipyard;
    CEarthBomberBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getLives(), CData::getInstance().bomberMinLives);
}

TEST(earthBomber, attack){
    CShipyard shipyard;
    CEarthBomberBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getAttack(), CData::getInstance().bomberMinAttack);
}

TEST(earthFighter, armor){
    CShipyard shipyard;
    CEarthFighterBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getArmor(), CData::getInstance().fighterMinArmor);
}

TEST(earthFighter, lives){
    CShipyard shipyard;
    CEarthFighterBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getLives(), CData::getInstance().fighterMinLives);
}

TEST(earthFighter, attack){
    CShipyard shipyard;
    CEarthFighterBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getAttack(), CData::getInstance().fighterMinAttack);
}

TEST(martianBomber, armor){
    CShipyard shipyard;
    CMartianBomberBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getArmor(), CData::getInstance().bomberMinArmor);
}

TEST(martainBomber, lives){
    CShipyard shipyard;
    CMartianBomberBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getLives(), CData::getInstance().bomberMinLives);
}

TEST(martianBomber, attack){
    CShipyard shipyard;
    CMartianBomberBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getAttack(), CData::getInstance().bomberMinAttack);
}

TEST(martianFighter, armor){
    CShipyard shipyard;
    CEarthFighterBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getArmor(), CData::getInstance().fighterMinArmor);
}

TEST(martianFighter, lives){
    CShipyard shipyard;
    CMartianFighterBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getLives(), CData::getInstance().fighterMinLives);
}

TEST(martianFighter, attack){
    CShipyard shipyard;
    CMartianFighterBuilder builder;
    shipyard.setShipBuilder(&builder);
    shipyard.constructShip(1000);
    std::shared_ptr<CShip> ship = shipyard.getShip();
    ASSERT_EQ(ship->getAttack(), CData::getInstance().fighterMinAttack);
}


TEST(earthHouse, people){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getPeople(),CData::getInstance().houseMinPeople);
}

TEST(earthHouse, protection){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getProtection(),CData::getInstance().houseMinProtection);
}

TEST(earthHouse, costs){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getCosts(),CData::getInstance().houseMinCosts);
}

TEST(earthHouse, income){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getIncomePerPerson(),CData::getInstance().houseMinIncomePerPerson);
}

TEST(martianHouse, people){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getPeople(),CData::getInstance().houseMinPeople);
}

TEST(martianHouse, protection){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getProtection(),CData::getInstance().houseMinProtection);
}

TEST(martianHouse, costs){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getCosts(),CData::getInstance().houseMinCosts);
}

TEST(martianHouse, income){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getIncomePerPerson(),CData::getInstance().houseMinIncomePerPerson);
}




TEST(earthFactory, people){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getPeople(),CData::getInstance().factoryMinPeople);
}

TEST(earthFactory, protection){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getProtection(),CData::getInstance().factoryMinProtection);
}



TEST(earthFactory, income){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getIncome(),CData::getInstance().factoryMinIncome);
}

TEST(martianFactory, people){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getPeople(),CData::getInstance().factoryMinPeople);
}

TEST(martianFactory, protection){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getProtection(),CData::getInstance().factoryMinProtection);
}



TEST(martianFactory, income){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getIncome(),CData::getInstance().factoryMinIncome);
}


TEST(earthLab, people){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getPeople(), CData::getInstance().labMinPeople);
}

TEST(earthLab, protection){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getProtection(), CData::getInstance().labMinProtection);
}


TEST(earthLab, speed){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getSpeed(), CData::getInstance().labMinSpeed);
}


TEST(earthLab, costs){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getCosts(), CData::getInstance().labMinCosts);
}


TEST(martianLab, people){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getPeople(), CData::getInstance().labMinPeople);
}

TEST(martianLab, protection){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getProtection(), CData::getInstance().labMinProtection);
}


TEST(martianLab, speed){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getSpeed(), CData::getInstance().labMinSpeed);
}


TEST(martianLab, costs){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getCosts(), CData::getInstance().labMinCosts);
}

TEST(earthFortification, people){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getPeople(), CData::getInstance().fortMinPeople);
}

TEST(earthFortification, costs){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getCosts(), CData::getInstance().fortMinCosts);
}


TEST(earthFortification, protection){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getProtection(), CData::getInstance().fortMinProtection);
}


TEST(earthFortification, attack){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getAttack(), CData::getInstance().fortMinAttack);
}

TEST(martianFortification, people){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getPeople(), CData::getInstance().fortMinPeople);
}

TEST(martianFortification, costs){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getCosts(), CData::getInstance().fortMinCosts);
}


TEST(martianFortification, protection){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getProtection(), CData::getInstance().fortMinProtection);
}


TEST(martianFortification, attack){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getAttack(), CData::getInstance().fortMinAttack);
}


int main(int argc, char **argv) {
    std::cout << "\n\n!!!!!!!!!!!!!!! На все вопросы надо отвечать: 0 !!!!!!!!!!!!!!!!!\n\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}





