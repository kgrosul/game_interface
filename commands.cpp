#include "commands.h"
#include "game.h"


CBuildingAttack::CBuildingAttack(std::shared_ptr<CPlanet> new_my_planet,std::shared_ptr<CPlanet> new_enemy_planet) {
    my_planet = new_my_planet;
    enemy_planet= new_enemy_planet;

    bool flag = true;
    while(flag){
        std::cout << "У Вас есть " << my_planet->fleet.size() << " эскадронов" << std::endl;
        std::cout << "У проивника есть " << enemy_planet->city.size() << " городов" << std::endl;

        std::cout << "Введите корректные номер эскадрона, который вы хотите поcлать в "
                     "атаку и номер города, который вы хотите атаковать" <<std::endl;
        int new_fleet_num;
        int new_city_num;
        std::cin >> new_fleet_num >> new_city_num;
        if(new_fleet_num < my_planet->fleet.size() && new_city_num < enemy_planet->city.size()){
            squadron_num = new_fleet_num;
            region_num = new_city_num;
            flag = false;
        }
    }
}

void CBuildingAttack::execute() {
    CWarPlanet warPlanet(my_planet);
    warPlanet.attackCity(*enemy_planet, squadron_num, region_num);
    std::cout << "У проивника осталось " << enemy_planet->city.size() << " городов" << std::endl;

}


CFleetAttack::CFleetAttack(std::shared_ptr<CPlanet> new_my_planet, std::shared_ptr<CPlanet> new_enemy_planet) {
    my_planet = new_my_planet;
    enemy_planet= new_enemy_planet;
    bool flag = true;
    while(flag){
        std::cout << "У Вас есть " << my_planet->fleet.size() << " эскадронов" << std::endl;
        std::cout << "У проивника есть " << my_planet->fleet.size()<< " эскадронов" << std::endl;

        std::cout << "Введите корректные номер эскадрона, который вы хотите поcлать в "
                     "атаку и номер эскадрона, который вы хотите атаковать" <<std::endl;
        int squadron1;
        int squadron2;
        std::cin >> squadron1 >> squadron2;
        if(squadron1 < my_planet->fleet.size() && squadron2 < enemy_planet->fleet.size()){
            my_squadron_num = squadron1;
            enemy_squadron_num = squadron2;
            flag = false;
        }
    }
}

void CFleetAttack::execute() {
    CWarPlanet warPlanet(my_planet);
    warPlanet.attackFleet(*enemy_planet, my_squadron_num, enemy_squadron_num);
    std::cout << "У проивника осталось " << enemy_planet->fleet.size() << " эскадронов" << std::endl;
}


CBuildingUpgrade::CBuildingUpgrade(std::shared_ptr<CPlanet> new_my_planet) {
    my_planet = new_my_planet;

    bool flag = true;
    while(flag) {
        std::cout << "У Вас есть " << my_planet->city.size() << " городов" << std::endl;
        std::cout << "Введите корректный номер города, который вы хотите улучшить" << std::endl;
        int city;
        std::cin >> city;
        if (city < my_planet->city.size()) {
            region_num = city;
            flag= false;
        }
    }

}

void CBuildingUpgrade::execute() {
    CEconomyPlanet economyPlanet(my_planet);
    economyPlanet.upgradeCityAttack(region_num, House::upgradeAttack);
    economyPlanet.upgradeCityMaxProtection(region_num, House::upgradeProtection);
}

CBuildingHeal::CBuildingHeal(std::shared_ptr<CPlanet> new_my_planet) {
    my_planet = new_my_planet;
    bool flag = true;
    while(flag) {
        std::cout << "У Вас есть " << my_planet->city.size() << " городов" << std::endl;
        std::cout << "Введите корректный номер города, который вы хотите восстановить" << std::endl;
        int city;
        std::cin >> city;
        if (city < my_planet->city.size()) {
            region_num = city;
            flag= false;
        }
    }
}

void CBuildingHeal::execute() {
    CWarPlanet warPlanet(my_planet);
    CEconomyPlanet economyPlanet(my_planet);
}