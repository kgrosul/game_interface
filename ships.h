#ifndef GAME_SHIPS_H
#define GAME_SHIPS_H

#include <vector>
#include <memory>

class CInputReader{
public:
    static int getValue(int minValue, int maxValue);
};


class IShipPrinter{
public:
    virtual  void printLives(int money, int maxLives) = 0;
    virtual  void printArmor(int money, int maxArmor) = 0;
    virtual  void printAttack(int money, int maxAttack) = 0;

};

class CFighterPrinter: public IShipPrinter{
public:
    CFighterPrinter(){};
    void printLives(int money, int maxLives);
    void printArmor(int money, int maxArmor);
    void printAttack(int money, int maxAttack);

};

class CBomberPrinter: public IShipPrinter{
public:
    CBomberPrinter(){};
    void printLives(int money, int maxLives);
    void printArmor(int money, int maxArmor);
    void printAttack(int money, int maxAttack);
};

class CShip{
    friend class CFighterBuilder;
    friend class CBomberBuilder;

    int _attack;
    int _armor;
    int _lives;

    void setAttack(int attack);
    void setArmor(int armor);
    void setLives(int lives);
public:
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
    virtual int buildLives(int lives) = 0;
    virtual int buildAttack(int attack) = 0;
    virtual int buildArmor(int armor) = 0;
};

class CFighterBuilder: public  IShipBuilder{
public:
    CFighterBuilder():IShipBuilder(){}
    ~CFighterBuilder(){}
    int buildLives(int lives);
    int buildAttack(int attack);
    int buildArmor(int armor);

};


class CBomberBuilder: public  IShipBuilder{
public:
    CBomberBuilder():IShipBuilder(){}
    ~CBomberBuilder(){}
    int buildLives(int lives);
    int buildAttack(int attack);
    int buildArmor(int armor);

};

class CShipyard{
private:
    std::shared_ptr<IShipBuilder> shipBuilder;
    std::shared_ptr<IShipPrinter> shipPrinter;
public:
    CShipyard(): shipPrinter(nullptr), shipBuilder(nullptr) {};
    ~CShipyard(){}
    void setShipBuilder(std::shared_ptr<IShipBuilder> builder);
    void setShipPrinter(std::shared_ptr<IShipPrinter> printer);
    std::shared_ptr<CShip> getShip();
    int constructShip(int money, int maxLives, int maxArmor, int maxAttack,
                      int livesPrice, int armorPrice,  int attackPrice) ;

};


#endif //GAME_SHIPS_H
