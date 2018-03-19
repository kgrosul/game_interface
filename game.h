#ifndef GAME_GAME_H
#define GAME_GAME_H

class CData
{
private:
    CData() {}
    CData( const CData&);
    CData& operator=( CData& );
public:
    static CData& getInstance() {
        static CData  instance;
        return instance;
    }

    int houseMinPeople = 100;
    int houseMinProtection = 10;
    int housePrice = 200;
    int houseMinCosts = 50;
    int houseMinIncomePerPerson = 1;

    int labMinPeople = 30;
    int labPrice = 1000;
    int labMinProtection = 20;
    int labMinCosts = 100;
    int labMinSpeed = 1;

    int factoryPrice = 500;
    int factoryMinPeople = 200;
    int factoryMinProtection = 5;
    int factoryMinIncome = 200;

    int fortMinPeople = 20;
    int fortMinProtection = 100;
    int fortMinPrice = 100;
    int fortMinCosts = 50;
    int fortMinAttack = 20;

    int fighterMinPrice = 10;
    int fighterMinArmor = 2;
    int fighterMinAttack = 5;
    int fighterMinLives = 10;
    int fighterLiveUpdate = 1;
    int fighterArmorUpdate = 1;
    int fighterAttackUpdate = 1;

    int bomberMinPrice = 40;
    int bomberMinArmor = 8;
    int bomberMinAttack = 20;
    int bomberMinLives = 40;
    int bomberLiveUpdate = 1;
    int bomberArmorUpdate = 1;
    int bomberAttackUpdate = 1;


    int houseUpgradePrice = 100;
    int houseUpgradePeople = 100;
    int houseUpgradeCosts = 25;
    int houseUpgradeIncome = 1;
    int houseUpgradeProtection = 10;

    int labUpgradePrice = 500;
    int labUpgradePeople = 30;
    int labUpgradeProtection = 20;
    int labUpgradeCosts = 75;
    int labUpgradeSpeed = 1;

    int factoryUpgradePrice = 250;
    int factoryUpgradePeople = 100;
    int factoryUpgradeProtection = 10;
    int factoryUpgradeIncome = 200;

    int fortUpgradePrice = 100;
    int fortUpgradeProtection = 50;
    int fortUpgradeAttack = 10;
    int fortUpgradeCosts = 25;
    int fortUpgradePeople = 10;

    void houseUpdateShow(){
        std::cout << "Вы можете увеличить население дома на " << houseUpgradePeople << " человек." << std::endl;
        std::cout << "Также вы можете увеличть плату за проживание с человека на "
                  << houseUpgradeIncome << " галактион." << std::endl;
        std::cout << "Или уровень защиты на " << houseUpgradeProtection << std::endl;
        std::cout << "Однако при любом улучшении расходы на содержание станут больше на: "
                  << houseUpgradeCosts << " галактионов." <<std::endl;
        std::cout << "А само улучшение обойдется в " << houseUpgradePrice << " галактионов." << std::endl;

    }

    void noUpgradesAvaliable(){
        std::cout << "Вы больше не можете улучшать это здание. Однако, возможно, в лаборатории знают\n"
                  << "как это исправить. Обратитесь туда." << std::endl;
    }

    void houseUpdateAsk(){
        std::cout << "Что вы хотите улучшить - население[1], доход[2] или защиту[3] ?" << std::endl;
    }

    void noMoney(){
        std::cout << "Кажется, у вас недостаточно денег:(" << std::endl;
    }


    void factoryUpdateShow(){
        std::cout << "Вы можете увеличить количество получаемого дохода на " << factoryUpgradeIncome << " галактионов." << std::endl;
        std::cout << "Или уровень защиты на " << factoryUpgradeProtection << std::endl;
        std::cout << "При увеличении дохода количество необходмиых сотрудников увеличится на"
                  << factoryUpgradePeople << " человек." <<std::endl;
        std::cout << "Каждое улучшений обойдется в " << factoryUpgradePrice << " галактионов." << std::endl;
    }

    void factoryUpdateAsk(){
        std::cout << "Что вы хотите улучшить - доход[1] или защиту[2] ?" << std::endl;
    }

    void labUpdateShow(){
        std::cout << "Вы можете увеличить количество одновременно проводимых исследований на " << labUpgradeSpeed << std::endl;
        std::cout << "Или уровень защиты на " << labUpgradeProtection << std::endl;
        std::cout << "При увеличении количества исследований количество необходмиых сотрудников увеличится на"
                  << labUpgradePeople << " человек." <<std::endl;
        std::cout << "При любом улучшении расходы на содержание станут больше на: "
                  << labUpgradeCosts << " галактионов." <<std::endl;
        std::cout << "Каждое улучшений обойдется в " << labUpgradePrice << " галактионов." << std::endl;

    }

    void labUpdateAsk(){
        std::cout << "Что вы хотите улучшить - количество исследований[1] или защиту[2] ?" << std::endl;
    }

    void fortUpdateShow(){
        std::cout << "Вы можете увеличить уровень защиты на" << fortUpgradeAttack << std::endl;
        std::cout << "Или уровень защиты на " << fortUpgradeProtection << std::endl;
        std::cout << "При увеличении количества исследований количество необходмиых солдат увеличится на"
                  <<  fortUpgradePeople << " человек." <<std::endl;
        std::cout << "При любом улучшении расходы на содержание станут больше на: "
                  << fortUpgradeCosts << " галактионов." <<std::endl;
        std::cout << "Каждое улучшений обойдется в " << fortUpgradePrice << " галактионов." << std::endl;
    }

    void fortUpdateAsk(){
        std::cout << "Что вы хотите улучшить - атаку[1] или защиту[2] ?" << std::endl;
    }

    int earthFighterMaxArmor = 3;
    int earthFighterMaxAttack = 7;
    int earthFighterMaxLives = 15;

    int earthBomberMaxArmor = 14;
    int earthBomberMaxAttack = 30;
    int earthBomberMaxLives = 60;

    int martianFighterMaxArmor = 3;
    int martianFighterMaxAttack = 7;
    int martianFighterMaxLives = 15;

    int martianBomberMaxArmor = 14;
    int martianBomberMaxAttack = 30;
    int martianBomberMaxLives = 60;

    int earthMaxHouseUpgrade = 0;
    int earthMaxFortUpgrade = 0;
    int earthMaxLabUpgrade = 0;
    int earthMaxFactoryUpgrade = 0;

    int martianMaxHouseUpgrade = 0;
    int martianMaxFortUpgrade = 0;
    int martianMaxLabUpgrade = 0;
    int martianMaxFactoryUpgrade = 0;

    int earthMoney = 1000;
    int martianMoney = 1000;
};

#endif //GAME_GAME_H
