#include <iostream>
#include "ships.h"
#include "buildings.h"
#include "game.h"
#include "planet.h"
#include "commands.h"

int main() {
    std::cout << "Добро пожаловать в игру!";
    std::shared_ptr<CPlanet> planet1(new CPlanet);
    std::shared_ptr<CPlanet> planet2(new CPlanet);

    planet1->reset();
    planet2->reset();
    while(true){
        if(planet1->city.size() == 0 || planet1->fleet.size() == 0){
            std::cout << "Второй игрок победил";
            return 0;
        }
        if(planet2->city.size() == 0 || planet2->fleet.size() == 0){
            std::cout << "Первый игрок победил";
            return 0;
        }

        std::cout << "Ходит первый игрок. Что вы хотите сделать?\n 1 - атаковать город\n"
                     "2 - атаковать флот\n3 - улучшить свой город?\n4 - востановить свой город." <<std::endl;


        bool flag = true;
        while(flag){
            flag = false;
            int num;
            std::cin >> num;
            if(num == 1){
                auto command = CBuildingAttack(planet1, planet2);
                command.execute();
            } else if(num == 2){
                auto command = CFleetAttack(planet1, planet2);
                command.execute();
            } else if(num == 3){
                auto command = CBuildingUpgrade(planet1);
                command.execute();
            } else if(num == 4){
                auto command = CBuildingHeal(planet1);
                command.execute();
            } else {
                std::cout << "Введите корректное число." << std::endl;
                flag = true;
            }
        }


        std::cout << "Ходит второй игрок. Что вы хотите сделать?\n 1 - атаковать город\n"
                     "2 - атаковать флот\n3 - улучшить свой город?\n4 - востановить свой город." <<std::endl;


        flag = true;
        while(flag){
            flag = false;
            int num;
            std::cin >> num;
            if(num == 1){
                auto command = CBuildingAttack(planet2, planet1);
                command.execute();
            } else if(num == 2){
                auto command = CFleetAttack(planet2, planet1);
                command.execute();
            } else if(num == 3){
                auto command = CBuildingUpgrade(planet2);
                command.execute();
            } else if(num == 4){
                auto command = CBuildingHeal(planet2);
                command.execute();
            } else {
                std::cout << "Введите корректное число." << std::endl;
                flag = true;
            }
        }
    }

    return 0;
}