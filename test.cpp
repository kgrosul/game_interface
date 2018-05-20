#include <gtest/gtest.h>
#include "game.h"
#include "ships.h"
#include "buildings.h"
#include "planet.h"

TEST(House, people){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getPeople(),House::minPeople);
}

TEST(House, protection){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getProtection(),House::minProtection);
}

TEST(House, costs){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getCosts(), 0);
}

TEST(House, income){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getIncome(), 0);
}

TEST(House, maxProtection){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CHouse> house = factory->createHouse();
    delete factory;
    ASSERT_EQ(house->getMaxProtection(),House::minProtection);
}

TEST(Factory, people){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getPeople(),Factory::minPeople);
}

TEST(Factory, protection){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getProtection(),Factory::minProtection);
}

TEST(Factory, maxProtection){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getMaxProtection(),Factory::minProtection);
}

TEST(Factory, income){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CFactory> facc = factory->createFactory();
    delete factory;
    ASSERT_EQ(facc->getIncome(),Factory::minIncome);
}

TEST(Fortification, people){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getPeople(), Fort::minPeople);
}

TEST(Fortification, costs){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getCosts(), Fort::minCosts);
}

TEST(Fortification, protection){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getProtection(), Fort::minProtection);
}

TEST(Fortification, maxProtection){
    auto factory = new CBuildingFactory;
    std::shared_ptr<CFortification> fort = factory->createFortification();
    delete factory;
    ASSERT_EQ(fort->getMaxProtection(),Fort::minProtection);
}

TEST(Fortification, attack){
    auto factory = new CBuildingFactory;
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

TEST(CShipsGroup, getLives){
    CBomberBuilder builder;
    CShipsGroup shipsGroup;
    int result = 0;
    for(int i = 0; i < 10; ++i){
        builder.createShip();
        builder.buildLives(1000);
        shipsGroup.addShip(builder.getShip());
    }
    ASSERT_EQ(shipsGroup.getLives(),1000*10);
}

TEST(CShipsGroup, getArmor){
    CBomberBuilder builder;
    CShipsGroup shipsGroup;
    int result = 0;
    for(int i = 0; i < 10; ++i){
        builder.createShip();
        builder.buildArmor(1000);
        shipsGroup.addShip(builder.getShip());
    }
    ASSERT_EQ(shipsGroup.getArmor(),1000*10);
}

TEST(CShipsGroup, getAttack){
    CBomberBuilder builder;
    CShipsGroup shipsGroup;
    int result = 0;
    for(int i = 0; i < 10; ++i){
        builder.createShip();
        builder.buildAttack(1000);
        shipsGroup.addShip(builder.getShip());
    }
    ASSERT_EQ(shipsGroup.getAttack(),1000*10);
}

TEST(CShipsGroup, decreaseAttack){
    CBomberBuilder builder;
    CShipsGroup shipsGroup;
    int result = 0;
    for(int i = 0; i < 10; ++i){
        builder.createShip();
        builder.buildAttack(1000);
        shipsGroup.addShip(builder.getShip());
    }
    shipsGroup.decreaseAttack(1000);
    ASSERT_DOUBLE_EQ(shipsGroup.getAttack(),1000*9);
}

TEST(CShipsGroup, decreaseLives){
    CBomberBuilder builder;
    CShipsGroup shipsGroup;
    int result = 0;
    for(int i = 0; i < 10; ++i){
        builder.createShip();
        builder.buildLives(1000);
        shipsGroup.addShip(builder.getShip());
    }
    shipsGroup.decreaseLives(1000);
    ASSERT_DOUBLE_EQ(shipsGroup.getLives(),1000*9);
}

TEST(CShipsGroup, decreaseArmor){
    CBomberBuilder builder;
    CShipsGroup shipsGroup;
    int result = 0;
    for(int i = 0; i < 10; ++i){
        builder.createShip();
        builder.buildArmor(1000);
        shipsGroup.addShip(builder.getShip());
    }
    shipsGroup.decreaseArmor(1000);
    ASSERT_DOUBLE_EQ(shipsGroup.getArmor(),1000*9);
}

TEST(CShipsGroup, clean){
    CBomberBuilder builder;
    CShipsGroup shipsGroup;
    int result = 0;
    for(int i = 0; i < 10; ++i){
        builder.createShip();
        builder.buildLives(1000);
        shipsGroup.addShip(builder.getShip());
    }
    shipsGroup.decreaseLives(100000);
    shipsGroup.clean();
    ASSERT_DOUBLE_EQ(shipsGroup.getLives(),0);
}

TEST(CBuildingsGroup,getFreePeople){
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for(int i = 0; i < 10; ++i){
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }

    ASSERT_EQ(buildingsGroup.getFreePeople(),House::minPeople*10-
                                         (Fort::minPeople+Factory::minPeople)*10 );

}

TEST(CBuildingsGroup,getAttack){
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for(int i = 0; i < 10; ++i){
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }

    ASSERT_EQ(buildingsGroup.getAttack(),Fort::minAttack*10);

}

TEST(CBuildingsGroup,getProtection){
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for(int i = 0; i < 10; ++i){
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }

    ASSERT_EQ(buildingsGroup.getProtection(),
              (Fort::minProtection + House::minProtection + Factory::minProtection) * 10);

}

TEST(CBuildingsGroup,getIncome){
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for(int i = 0; i < 10; ++i){
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }

    ASSERT_EQ(buildingsGroup.getIncome(),Factory::minIncome*10 - 10* Fort::minCosts);

}

TEST(CBuildingsGroup, decreaseProtection){
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for(int i = 0; i < 10; ++i){
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }

    buildingsGroup.decreaseProtection(300);
    ASSERT_EQ(buildingsGroup.getProtection(),
              (Factory::minProtection + House::minProtection + Fort::minProtection - 30) * 10);
}

TEST(CBuildingsGroup, clean){
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for(int i = 0; i < 10; ++i){
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }

    buildingsGroup.decreaseProtection(30000000);
    buildingsGroup.clean();
    ASSERT_EQ(buildingsGroup.getProtection(), 0);
}

TEST(CBuildingsGroup, heal) {
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for (int i = 0; i < 10; ++i) {
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }

    buildingsGroup.decreaseProtection(30000000);
    buildingsGroup.heal();
    ASSERT_EQ(buildingsGroup.getProtection(),
              10 * (Fort::minProtection + House::minProtection + Factory::minProtection));
}

TEST(CBuildingsGroup, increaseMaxProtection) {
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for (int i = 0; i < 10; ++i) {
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }
    buildingsGroup.increaseMaxProtection(1);
    buildingsGroup.heal();
    ASSERT_EQ(buildingsGroup.getProtection(),
              10 * (Fort::minProtection + House::minProtection + Factory::minProtection + 3));
}


TEST(CBuildingsGroup, increasePeople){
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for (int i = 0; i < 10; ++i) {
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }
    int res = buildingsGroup.getFreePeople();
    buildingsGroup.increasePeople(1);

    ASSERT_EQ(res + 10, buildingsGroup.getFreePeople());
}

TEST(CBuildingsGroup, increaseIncome){
    auto factory = new CBuildingFactory;
    CBuildingsGroup buildingsGroup;
    for (int i = 0; i < 10; ++i) {
        buildingsGroup.addBuilding(factory->createHouse());
        buildingsGroup.addBuilding(factory->createFactory());
        buildingsGroup.addBuilding(factory->createFortification());

    }
    int res = buildingsGroup.getIncome();
    buildingsGroup.increaseIncome(1);

    ASSERT_EQ(res + 10, buildingsGroup.getIncome());

}

TEST(CWarPlanet, attackFleet){
    std::shared_ptr<CPlanet> planet1(new CPlanet);
    std::shared_ptr<CPlanet> planet2(new CPlanet);
    planet1->reset();
    planet2->reset();
    double res1 = planet2->fleet[0].getLives();
    CWarPlanet warPlanet1(planet1);
    warPlanet1.attackFleet(*planet2 ,0,0);
    ASSERT_NE(res1, planet2->fleet[0].getLives());
}

TEST(CPlanetDecorator, test1){
    std::shared_ptr<CPlanet> planet1(new CPlanet);
    std::shared_ptr<CPlanet> planet2(new CPlanet);
    planet1->reset();
    planet2->reset();
    double res1 = planet2->fleet[0].getLives();
    CWarPlanet warPlanet1(planet1);
    warPlanet1.attackFleet(*planet2 ,0,0);
    ASSERT_NE(res1, planet2->fleet[0].getLives());
}

TEST(CPlanetDecorator, test2){
    std::shared_ptr<CPlanet> planet1(new CPlanet);
    std::shared_ptr<CPlanet> planet2(new CPlanet);
    planet1->reset();
    planet2->reset();
    int start_size = planet2->city.size();
    CWarPlanet warPlanet1(planet1);
    warPlanet1.attackCity(*planet2 ,0,0);
    ASSERT_EQ(start_size-1, planet2->city.size());
}


TEST(CPlanetDecorator, test3){
    std::shared_ptr<CPlanet> planet1(new CPlanet);
    std::shared_ptr<CPlanet> planet2(new CPlanet);
    planet1->reset();
    planet2->reset();
    planet2->city[0].decreaseProtection(9);
    CEconomyPlanet economyPlanet(planet2);
    economyPlanet.heal(0);
    ASSERT_EQ(10, planet2->city[0].getProtection());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
