#include <gtest/gtest.h>
#include "game.h"
#include "ships.h"
#include "buildings.h"

TEST(earthHouse, people){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getPeople(),House::minPeople);
}

TEST(earthHouse, protection){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getProtection(),House::minProtection);
}

TEST(earthHouse, costs){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getCosts(),House::minCosts);
}

TEST(earthHouse, income){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getIncomePerPerson(),House::minIncomePerPerson);
}

TEST(martianHouse, people){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getPeople(), House::minPeople);
}

TEST(martianHouse, protection){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getProtection(), House::minProtection);
}

TEST(martianHouse, costs){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getCosts(),House::minCosts);
}

TEST(martianHouse, income){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getIncomePerPerson(),House::minIncomePerPerson);
}


TEST(earthFactory, people){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getPeople(),Factory::minPeople);
}

TEST(earthFactory, protection){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getProtection(),Factory::minProtection);
}



TEST(earthFactory, income){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getIncome(),Factory::minIncome);
}

TEST(martianFactory, people){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getPeople(),Factory::minPeople);
}

TEST(martianFactory, protection){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getProtection(), Factory::minProtection);
}



TEST(martianFactory, income){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getIncome(), Factory::minIncome);
}


TEST(earthLab, people){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getPeople(), Lab::minPeople);
}

TEST(earthLab, protection){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getProtection(), Lab::minProtection);
}


TEST(earthLab, speed){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getSpeed(), Lab::minSpeed);
}


TEST(earthLab, costs){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getCosts(), Lab::minCosts);
}


TEST(martianLab, people){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getPeople(), Lab::minPeople);
}

TEST(martianLab, protection){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getProtection(), Lab::minProtection);
}


TEST(martianLab, speed){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getSpeed(), Lab::minSpeed);
}


TEST(martianLab, costs){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CLaboratory> lab = factory->createLaboratory();
    delete factory;
    ASSERT_EQ(lab->getCosts(), Lab::minCosts);
}

TEST(earthFortification, people){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getPeople(), Fort::minPeople);
}

TEST(earthFortification, costs){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getCosts(), Fort::minCosts);
}


TEST(earthFortification, protection){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getProtection(), Fort::minProtection);
}


TEST(earthFortification, attack){
    auto factory = new CEarthBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getAttack(), Fort::minAttack);
}

TEST(martianFortification, people){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getPeople(), Fort::minPeople);
}

TEST(martianFortification, costs){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getCosts(), Fort::minCosts);
}


TEST(martianFortification, protection){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getProtection(), Fort::minProtection);
}


TEST(martianFortification, attack){
    auto factory = new CMartianBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getAttack(), Fort::minAttack);
}

TEST(fighterBuilder, attack){
    CFighterBuilder builder;
    builder.createShip();
    int x = rand();
    builder.buildAttack(x);
    ASSERT_EQ(builder.getShip()->getAttack(), x);
}

TEST(fighterBuilder, armor){
    CFighterBuilder builder;
    builder.createShip();
    int x = rand();
    builder.buildArmor(x);
    ASSERT_EQ(builder.getShip()->getArmor(), x);
}

TEST(fighterBuilder, lives){
    CFighterBuilder builder;
    builder.createShip();
    int x = rand();
    builder.buildLives(x);
    ASSERT_EQ(builder.getShip()->getLives(), x);
}




TEST(BomberBuilder, attack){
    CBomberBuilder builder;
    builder.createShip();
    int x = rand();
    builder.buildAttack(x);
    ASSERT_EQ(builder.getShip()->getAttack(), x);
}

TEST(BomberBuilder, armor){
    CBomberBuilder builder;
    builder.createShip();
    int x = rand();
    builder.buildArmor(x);
    ASSERT_EQ(builder.getShip()->getArmor(), x);
}

TEST(BomberBuilder, lives){
    CBomberBuilder builder;
    builder.createShip();
    int x = rand();
    builder.buildLives(x);
    ASSERT_EQ(builder.getShip()->getLives(), x);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}





