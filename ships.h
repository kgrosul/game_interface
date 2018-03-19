#ifndef GAME_SHIPS_H
#define GAME_SHIPS_H

#include <vector>
#include <memory>
class CShip{
    friend class CEarthFighterBuilder;
    friend class CEarthBomberBuilder;
    friend class CMartianFighterBuilder;
    friend class CMartianBomberBuilder;


    int _attack;
    int _armor;
    int _lives;

    void setAttack(int attack);
    void setArmor(int armor);
public:
    void setLives(int lives);
    int getAttack() const;
    int getArmor() const;
    int getLives() const;
    CShip(){}
    ~CShip(){}
};

class IShipBuilder{
protected:
    std::shared_ptr<CShip> ship;
public:
    virtual ~IShipBuilder(){}
    std::shared_ptr<CShip> getShip();
    void createShip();
    virtual int buildLives(int money) = 0;
    virtual int buildAttack(int money) = 0;
    virtual int buildArmor(int money) = 0;
};

class CEarthFighterBuilder: public  IShipBuilder{
public:
    CEarthFighterBuilder():IShipBuilder(){}
    ~CEarthFighterBuilder(){}
    int buildLives(int money);
    int buildAttack(int money);
    int buildArmor(int money);

};

class CMartianFighterBuilder: public  IShipBuilder{
public:
    CMartianFighterBuilder():IShipBuilder(){}
    ~CMartianFighterBuilder(){}
    int buildLives(int money);
    int buildAttack(int money);
    int buildArmor(int money);


};


class CEarthBomberBuilder: public  IShipBuilder{
public:
    CEarthBomberBuilder():IShipBuilder(){}
    ~CEarthBomberBuilder(){}
    int buildLives(int money);
    int buildAttack(int money);
    int buildArmor(int money);

};

class CMartianBomberBuilder: public  IShipBuilder{
public:
    CMartianBomberBuilder():IShipBuilder(){}
    ~CMartianBomberBuilder(){}
    int buildLives(int money);
    int buildAttack(int money);
    int buildArmor(int money);

};

class CShipyard{
private:
    IShipBuilder* shipBuilder;
public:
    CShipyard(): shipBuilder(nullptr){};
    ~CShipyard(){}
    void setShipBuilder(IShipBuilder* builder);
    std::shared_ptr<CShip> getShip();
    int constructShip(int money);

};


#endif //GAME_SHIPS_H
