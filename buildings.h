#ifndef GAME_BUILDINGS_H
#define GAME_BUILDINGS_H

#include <memory>


class CBuilding{
protected:
    int _upgrades;
    int _people;
    int _protection;
    bool _isWorking;
    int _costs;
public:
    void setPeople(int people);
    void setProtection(int protection);
    void setWorking(bool isWorking);
    void setCosts(int costs);
    void setUpgrades(int upgrades);

    int getPeople() const;
    int getProtection() const;
    int getUpgrades() const;
    bool getWorking() const;
    int getCosts() const;

    virtual void upgrade() = 0;
};


class CHouse: public CBuilding{
private:
    int _incomePerPerson;
public:
    void setIncomePerPerson(int income);
    int getIncomePerPerson() const;
    virtual void upgrade() = 0;

};


class CLaboratory: public CBuilding{
private:
    int _speed;
public:
    void setSpeed(int speed);
    int getSpeed() const;
    virtual void upgrade() = 0;
};

class CFactory: public CBuilding{
    int _income;
public:
    void setIncome(int income);
    int getIncome() const;
    virtual void upgrade() = 0;
};

class CFortification: public CBuilding{
    int _attack;
public:
    void setAttack(int attack);
    int getAttack() const;
    virtual void upgrade() = 0;
};

class CEarthHouse: public CHouse{
    void upgrade(){};
};

class CEarthLaboratory: public CLaboratory{
    void upgrade(){};
};

class CEarthFactory: public CFactory{
    void upgrade(){};
};

class CEarthFortification: public CFortification{
    void upgrade(){};
};


class CMartianHouse: public CHouse{
    void upgrade(){};
};

class CMartianLaboratory: public CLaboratory{
    void upgrade(){};
};

class CMartianFactory: public CFactory{
    void upgrade(){};
};

class CMartianFortification: public CFortification{
    void upgrade(){};
};

class CBuildingFactory{
    virtual std::shared_ptr<CHouse> createHouse() = 0;
    virtual std::shared_ptr<CLaboratory> createLaboratory() = 0;
    virtual std::shared_ptr<CFactory> createFactory() = 0;
    virtual std::shared_ptr<CFortification> createFortification() = 0;
};

class CEarthBuildingFactory: public CBuildingFactory{
public:
    std::shared_ptr<CHouse> createHouse();
    std::shared_ptr<CLaboratory> createLaboratory();
    std::shared_ptr<CFactory> createFactory();
    std::shared_ptr<CFortification> createFortification();
};

class CMartianBuildingFactory: public CBuildingFactory{
public:
    std::shared_ptr<CHouse> createHouse();
    std::shared_ptr<CLaboratory> createLaboratory();
    std::shared_ptr<CFactory> createFactory();
    std::shared_ptr<CFortification> createFortification();
};



class CHousePrinter{
public:
    static void show(CHouse const &house);
    static void updateShow(CHouse const &house);
    static void updateAsk(CHouse const &house);
};

class CFortificationPrinter{
public:
    static void show(CFortification const &fort);
    static void updateShow(CFortification const &fort);
    static void updateAsk(CFortification const &fort);
};

class CLaboratoryPrinter{
public:
    static void show(CLaboratory const &lab);
    static void updateShow(CLaboratory const &lab);
    static void updateAsk(CLaboratory const &lab);
};

class CFactoryPrinter{
public:
    static void show(CFactory const &factory);
    static void updateShow(CFactory const &factory);
    static void updateAsk(CFactory const &factory);
};






#endif //GAME_BUILDINGS_H
