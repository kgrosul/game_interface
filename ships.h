#ifndef GAME_SHIPS_H
#define GAME_SHIPS_H

#include <vector>
#include <memory>

class CShipsGroup;

class CInputReader{
public:
    static int getValue(int minValue, int maxValue);
};

/*!
 * Интерфейс для класса, выводящего информациию о классе CShip в консоль
 */

class IShipPrinter{
public:
    virtual  void printLives(int money, int maxLives) = 0;
    virtual  void printArmor(int money, int maxArmor) = 0;
    virtual  void printAttack(int money, int maxAttack) = 0;

};

/*!
 * Класс, печатающий информацию об истрибителе
 */

class CFighterPrinter: public IShipPrinter{
public:
    CFighterPrinter(){};
    void printLives(int money, int maxLives) override;
    void printArmor(int money, int maxArmor) override;
    void printAttack(int money, int maxAttack) override;

};
/*!
 * Класс, печатающий информацию о бомбардировщике
 */

class CBomberPrinter: public IShipPrinter{
public:
    CBomberPrinter(){};
    void printLives(int money, int maxLives) override;
    void printArmor(int money, int maxArmor) override;
    void printAttack(int money, int maxAttack) override;
};

/*!
 * Космический корбаль
 */

class CShip{
    friend class CFighterBuilder;
    friend class CBomberBuilder;

    double _attack; ///Атака
    double _armor; ///Броня
    double _lives; ///Жизни

    void setAttack(double attack);
    void setArmor(double armor);
    void setLives(double lives);

public:
    virtual double getAttack() const;
    virtual double getArmor() const;
    virtual double getLives() const;

    virtual void decreaseAttack(double value); ///Уменьшает очки атаки на value
    virtual void decreaseLives(double value); ///Уменьшает жизни на value
    virtual void decreaseArmor(double value); ///Уменьшает броню на value

    virtual void clean(); ///Ничего не делает, нужен для работы классов-наследников

    /*!
     * Ничего не делает, нужен для работы классов-наследников. В случае вызова
     * Программа заврешается с ошибкой.
     */
    virtual void addShip(std::shared_ptr<CShip>);
    CShip(){}
    ~CShip(){}
};
/*!
 * Интерфейс для конструктора корабля
 */
class IShipBuilder{
protected:
    std::shared_ptr<CShip> ship;
public:
    virtual ~IShipBuilder(){}
    std::shared_ptr<CShip> getShip();
    void createShip();
    virtual void buildLives(double lives) = 0;
    virtual void buildAttack(double attack) = 0;
    virtual void buildArmor(double armor) = 0;
};
/*!
 * Конструктор истребителя
 */
class CFighterBuilder: public  IShipBuilder{
public:
    CFighterBuilder():IShipBuilder(){}
    ~CFighterBuilder(){}
    void buildLives(double lives) override;
    void buildAttack(double attack) override;
    void buildArmor(double armor) override;

};

/*!
 * Конструектор бомабардировщика
 */
class CBomberBuilder: public  IShipBuilder{
public:
    CBomberBuilder():IShipBuilder(){}
    ~CBomberBuilder(){}
    void buildLives(double lives) override;
    void buildAttack(double attack) override;
    void buildArmor(double armor) override;

};
/*!
 * Директор, который использует переданного уме конструктора для создания нужного
 * космического корабля
 */
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
                      int livesPrice, int armorPrice,  int attackPrice);

};

/*!
 * Класс описывающий эскадрилью
 */
class CShipsGroup: public CShip{
private:
    std::vector<std::shared_ptr<CShip> > group;
public:
    double getAttack() const override; ///Возвращает суммарное значение атаки
    double getArmor() const override; ///Возвращает суммарное значение брони
    double getLives() const override; ///Возвращает суммарное значение жизней

    void decreaseAttack(double value) override; ///Уменьшает суммарное значение атаки на value
    void decreaseLives(double value) override; ///Уменьшает суммарное значение жизни на value
    void decreaseArmor(double value) override; ///Уменьшает суммарное значение брони на value

    void addShip(std::shared_ptr<CShip> ship_ptr) override; ///Добавляет новый корабль

    void clean() override; ///Удаляет уничтоженные корабли

};


#endif //GAME_SHIPS_H
