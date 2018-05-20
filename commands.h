#ifndef GAME_COMMANDS_H
#define GAME_COMMANDS_H

#include "planet.h"
#include "memory"

/*!
 * Интерфейс команды атаки
 */
class IAttack{
protected:
    std::shared_ptr<CPlanet> my_planet; ///Указатель на планету текущего игрока
    std::shared_ptr<CPlanet> enemy_planet; ///Указатель на планету текущего противника

public:
    virtual ~IAttack() {}

    virtual void execute() =0;
};

/*!
 * Команда атаки города
 */
class CBuildingAttack: public IAttack{
    int squadron_num; ///Номер атакующего эскадрона
    int region_num; ///Номер атакуемого региона
public:
    CBuildingAttack(std::shared_ptr<CPlanet> new_my_planet, std::shared_ptr<CPlanet> new_enemy_planet);
    void execute();
};

/*!
 * Команда атаки флота противника
 */

class CFleetAttack: public IAttack{
    int my_squadron_num; ///Номер атакующего эскадрона
    int enemy_squadron_num; ///Номер атакуемого эскадрона
public:
    CFleetAttack(std::shared_ptr<CPlanet> new_my_planet, std::shared_ptr<CPlanet> new_enemy_planet);
    void execute();

};

/*!
* Команда воостановления зданий
*/

class CBuildingHeal{
protected:
    std::shared_ptr<CPlanet> my_planet; ///Указатель на планету текущего игрока
    int region_num; ///Номер региона, который надо восстановить
public:
    CBuildingHeal(std::shared_ptr<CPlanet> new_my_planet);
    void execute();
};


/*!
* Команда улучшения зданий
*/

class CBuildingUpgrade{
protected:
    std::shared_ptr<CPlanet> my_planet; ///Указатель на планету текущего игрока
    int region_num; ///Номер региона, который надо восстановить
public:
    CBuildingUpgrade(std::shared_ptr<CPlanet> new_my_planet);
    void execute();
};


#endif //GAME_COMMANDS_H
