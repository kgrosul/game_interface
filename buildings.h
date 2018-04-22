#ifndef GAME_BUILDINGS_H
#define GAME_BUILDINGS_H

#include <memory>
#include <vector>

/*!
 * \brief Здание
 */
class CBuilding{
    int _upgrades; ///Количество сделанных улучшений
    double _protection; ///Очки защиты
    int _people; ///Количество людей живущих или работающих здесь
    bool _isWorking; ///Эксплотируется ли здание
    double _maxProtection; ///Максимальное значение очков защиты
public:
    void setProtection(double protection);
    void setWorking(bool isWorking);
    void setUpgrades(int upgrades);
    void setPeople(int people);
    void setMaxProtection(double protection);
    double getMaxProtection() const;

    virtual double getProtection() const;
    int getUpgrades() const;
    bool getWorking() const;
    /*!
     * Функция возвращает 0 и используется только для корректной работы
     * классов-наследников
     */
    virtual int getCosts() const;
    /*!
    * Функция возвращает 0 и используется только для корректной работы
    * классов-наследников
    */
    virtual int getIncome() const;
    /*!
    * Функция возвращает 0 и используется только для корректной работы
    * классов-наследников
    */
    virtual double getAttack() const;
    virtual int getPeople() const;
    /*!
    * Функция возвращает 0 и используется только для корректной работы
    * классов-наследников
    */
    virtual int getFreePeople() const;
    /*!
     * Уменьшает количество очков защиты на value;
     */
    virtual void decreaseProtection(double value);
    /*!
    * Функция ничего не делает и используется только для корректной работы
    * классов-наследников. При её вызове из этого класса программа
    * завершается с ошибкой
    */
    virtual void addBuilding(std::shared_ptr<CBuilding> buildung_ptr);
    /*!
    * Функция используется только для корректной работы
    * классов-наследников
    */
    virtual void increasePeople(int value);
    /*!
    * Функция используется только для корректной работы
    * классов-наследников
    */
    virtual void increaseIncome(int value);
    /*!
    * Функция используется только для корректной работы
    * классов-наследников
    */
    virtual void increaseAttack(double value);
    /*!
    * Увеличивает максимально возможное количество очков защиты на value
    */
    virtual void increaseMaxProtection(double value);
    /*!
     * Делает значение _protection равным _maxProtection;
     */
    virtual void heal();
    /*!
    * Функция используется только для корректной работы
    * классов-наследников
    */
    virtual void clean();
};

/*!
 * \brief Жилой дом
 */
class CHouse: public CBuilding{
    /*!
     * Возврщает число людей живущих в доме
     */
    virtual int getFreePeople() const override;
    /*!
     * Увеличивает число людей живущих в доме на value
    */
    virtual void increasePeople(int value) override;

};

/*!
 * \brief Завод
 */
class CFactory: public CBuilding{
    int _income; ///Доход, получаемый с завода
public:
    void setIncome(int income);
    int getIncome() const override;
    void increaseIncome(int value) override; ///Увеличивает доход
};

/*!
 * \brief Укреплений
 */
class CFortification: public CBuilding{
    double _attack; ///Очки атаки
    int _costs; ///Расходы на содержание
public:
    void setAttack(double attack);
    void setCosts(int costs);
    int getCosts() const override;
    double getAttack() const override;
    int getIncome() const override;
    void increaseAttack(double value) override; ///Увеличивает количество очков атаки на value
};


/*!
 * \brief Фабрика для создания строений различного типа
 */
class CBuildingFactory{
public:
    virtual std::shared_ptr<CHouse> createHouse(); ///Создает дом
    virtual std::shared_ptr<CFactory> createFactory(); ///Создает завод
    virtual std::shared_ptr<CFortification> createFortification(); ///Создает укрепление
};


/*!
 * \brief Класс необходимый для вывода объекта класса Дом в консоль
 */
class CHousePrinter{
public:
    static void show(CHouse const &house); ///Выводит основную информацию
    static void updateShow(CHouse const &house); ///Выводит информацию по возможным улучщениям
    static void updateAsk(CHouse const &house); ///Выводит запрос на улучшение
};

/*!
 * \brief Класс необходимый для вывода объекта класса Укрепление в консоль
 */
class CFortificationPrinter{
public:
    static void show(CFortification const &fort); ///Выводит основную информацию
    static void updateShow(CFortification const &fort); ///Выводит информацию по возможным улучщениям
    static void updateAsk(CFortification const &fort); ///Выводит запрос на улучшение
};

/*!
 * \brief Класс необходимый для вывода объекта класса Завод в консоль
 */
class CFactoryPrinter{
public:
    static void show(CFactory const &factory); ///Выводит основную информацию
    static void updateShow(CFactory const &factory); ///Выводит информацию по возможным улучщениям
    static void updateAsk(CFactory const &factory); ///Выводит запрос на улучшение
};

/*!
 * \brief Класс описывающий район - группу зданий.
 *
 * Тут применяется паттерн Компоновщик;
 */
class CBuildingsGroup: public CBuilding{
private:
    std::vector<std::shared_ptr<CBuilding> > group;
public:
    int getFreePeople() const override; ///Возвращает количество людей, которые нигде не работают
    double getProtection() const override; ///Возвращает суммарное значение очков защиты
    double getAttack() const override; ///Возвращает суммарное значение очков атаки
    int getIncome() const override; ///Возвращает доход с региона
    void clean() override; ///Удаляет уничтоженные противником здания
    /*!
     * Уменьшает суммарное суммарное значение очков защиты на value
     */
    void decreaseProtection(double value) override;
    void addBuilding(std::shared_ptr<CBuilding> buildung_ptr) override;
    /*!
     * Увеличивает число людей, живущих в каждом жилом доме района на value
     */
    void increasePeople(int value) override;
    /*!
     * Увеличивает доход с каждого завода в районе на value
     */
    void increaseIncome(int value) override;
    /*!
     * Увеличичвает очки каждого укпрепления района на value
     */
    void increaseAttack(double value) override;
    /*!
     * Увеличивает максимально-возможное число очков защиты на value для
     * каждого здания района
     */
    void increaseMaxProtection(double value) override;
    void heal() override; ///Для каждого здания увеличивает число очков защиты до максимального

};



#endif //GAME_BUILDINGS_H
