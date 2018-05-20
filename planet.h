#ifndef GAME_PLANET_H
#define GAME_PLANET_H

#include "buildings.h"
#include "ships.h"
#include "game.h"
#include <string>

class CWarPlanet;
class CEconomyPlanet;

/*!
 * Интерфейс необходимый для использования паттерна Декоратор
 */
class IPlanet{
    friend class CWarPlanet;
    friend class CEconomyPlanet;

public:
    std::vector<CBuildingsGroup> city; ///Vector районов города
    std::vector<CShipsGroup> fleet; ///Vector эскадрилий
    virtual void reset() = 0; ///Зaполняет city и fleet стартовыми значениями

};

class CPlanet: public IPlanet{
public:
    virtual void reset() override;
};

/*!
 * Военная сущность планеты
 */
class CWarPlanet: public IPlanet{
private:
    std::shared_ptr<IPlanet> planet; ///Указатель на планету
public:
    CWarPlanet(std::shared_ptr<IPlanet> planet_ptr): planet(planet_ptr){};
    /*!
     * Атакует флот противника
     * @param otherPlanet ссылка на атакуемую планету
     * @param mySquadronNum номер эскадрильи, которая наносит удар
     * @param otherSquadronNum номер эскадрильи, по которой наносят удар
     */
    void attackFleet(IPlanet& otherPlanet, int mySquadronNum, int otherSquadronNum);
    /*!
    * Атакует город противника
    * @param otherPlanet ссылка на атакуемую планету
    * @param mySquadronNum номер эскадрильи, которая наносит удар
    * @param regionNum номер района, по которому наносят удар
 */
    void attackCity(IPlanet& otherPlanet, int mySquadronNum, int regionNum);
    void reset() override;
};

/*!
 * Экономическая сущность планеты
 */
class CEconomyPlanet: public IPlanet{
private:
    std::shared_ptr<IPlanet> planet; ///Указатель на планету
public:
    CEconomyPlanet(std::shared_ptr<IPlanet> planet_ptr): planet(planet_ptr){};
    /*!
     * Увеличивает количество людей, проживающих в регионе
     * @param regionNum номер региона
     * @param points - на сколько людей становится больше в каждом доме
     */
    void upgradeCityPeople(int regionNum, int points);
    /*!
    * Увеличивает количество очков атаки для данного региона
    * @param regionNum номер региона
    * @param points - на сколько мощнее становится укрепление
    */
    void upgradeCityAttack(int regionNum, int points);
    /*!
    * Увеличивает доход данного региона
    * @param regionNum номер региона
    * @param points - на сколько больше галактионов приносит один завод
    */
    void upgradeCityIncome(int regionNum, int points);
    /*!
     * Увеличивает максимально-возможное количество очков защиты
     * для зданий в данном регионе
     * @param regionNum номер региона
     * @param points - на сколько увеличивается это количество
     */
    void upgradeCityMaxProtection(int regionNum, int points);
    /*!
     * Восстанавливает все еще не уничтоженные здания в регионе
     * @param regionNum номер региона
     */
    void heal(int regionNum);
    void reset() override;

};

#endif //GAME_PLANET_H
