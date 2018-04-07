#ifndef GAME_GAME_H
#define GAME_GAME_H


namespace House{
    static int minPeople = 100;
    static int minProtection = 10;
    static int price = 200;
    static int minCosts = 50;
    static int minIncomePerPerson = 1;
    static int upgradePrice = 100;
    static int upgradePeople = 100;
    static int upgradeCosts = 25;
    static int upgradeIncome = 1;
    static int upgradeProtection = 10;
}

namespace Lab{
    static int minPeople = 30;
    static int price = 1000;
    static int minProtection = 20;
    static int minCosts = 100;
    static int minSpeed = 1;

    static int upgradePrice = 500;
    static int upgradePeople = 30;
    static int upgradeProtection = 20;
    static int upgradeCosts = 75;
    static int upgradeSpeed = 1;
}

namespace Factory{
    static int price = 500;
    static int minPeople = 200;
    static int minProtection = 5;
    static int minIncome = 200;

    static int upgradePrice = 250;
    static int upgradePeople = 100;
    static int upgradeProtection = 10;
    static int upgradeIncome = 200;
}


namespace Fort{
    static int minPeople = 20;
    static int minProtection = 100;
    static int minPrice = 100;
    static int minCosts = 50;
    static int minAttack = 20;

    static int upgradePrice = 100;
    static int upgradeProtection = 50;
    static int upgradeAttack = 10;
    static int upgradeCosts = 25;
    static int upgradePeople = 10;
}

namespace Fighter {
    static int minPrice = 10;
    static int minArmor = 2;
    static int minAttack = 5;
    static int minLives = 10;
    static int liveUpdate = 1;
    static int armorUpdate = 1;
    static int attackUpdate = 1;
}

namespace Bomber {
    static int minPrice = 40;
    static int minArmor = 8;
    static int minAttack = 20;
    static int minLives = 40;
    static int liveUpdate = 1;
    static int armorUpdate = 1;
    static int attackUpdate = 1;
}


namespace Mars {
    static int fighterMaxArmor = 3;
    static int fighterMaxAttack = 7;
    static int fighterMaxLives = 15;

    static int bomberMaxArmor = 14;
    static int bomberMaxAttack = 30;
    static int bomberMaxLives = 60;

    static int maxHouseUpgrade = 0;
    static int maxFortUpgrade = 0;
    static int maxLabUpgrade = 0;
    static int maxFactoryUpgrade = 0;

    static int money = 1000;
}

namespace Earth {
    static int fighterMaxArmor = 3;
    static int fighterMaxAttack = 7;
    static int fighterMaxLives = 15;

    static int bomberMaxArmor = 14;
    static int bomberMaxAttack = 30;
    static int bomberMaxLives = 60;

    static int maxHouseUpgrade = 0;
    static int maxFortUpgrade = 0;
    static int maxLabUpgrade = 0;
    static int maxFactoryUpgrade = 0;

    static int money = 1000;
}


class Printer{
public:
    static void noUpgradesAvaliable(){
        std::cout << "Вы больше не можете улучшать это здание. Однако, возможно, в лаборатории знают\n"
                  << "как это исправить. Обратитесь туда." << std::endl;
    }

    static void noMoney(){
        std::cout << "Кажется, у вас недостаточно денег:(" << std::endl;
    }

    static void correctValue(){
        std::cout << "Введите корректное значение" << std::endl;
    }

    
};



#endif //GAME_GAME_H
