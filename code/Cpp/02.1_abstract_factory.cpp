/**
 * @file        - 02.1_abstract_factory.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 抽象工厂
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

#include <iostream>
#include <string>

/**
 * 抽象产品
*/
class AbstractShape
{
public:
    AbstractShape() 
    {
        m_id = m_total++;
    }

    virtual void draw() = 0;
protected:
    int m_id;
    static int m_total;
};
int AbstractShape::m_total = 0;

/**
 * 具体产品1
*/
class ConcreteCircle : public AbstractShape
{
public:
    void draw() override
    {
        std::cout << "Circle " << m_id << ": draw" << std::endl;
    }
};

/**
 * 具体产品2
*/
class ConcreteSquare : public AbstractShape
{
public:
    void draw() override
    {
        std::cout << "Square " << m_id << ": draw" << std::endl;
    }
};

/**
 * 具体产品3
*/
class ConcreteEllipse : public AbstractShape
{
public:
    void draw() override
    {
        std::cout << "Ellipse " << m_id << ": draw" << std::endl;
    }
};

/**
 * 具体产品4
*/
class ConcreteRectangle : public AbstractShape
{
public: 
    void draw() override
    {
        std::cout << "Rectangle " << m_id << ": draw" << std::endl;
    }
};

/**
 * 抽象工厂
*/
class AbstractFactory
{
public:
    virtual AbstractShape* create_curved_instance() = 0;
    virtual AbstractShape* create_straight_instance() = 0;
};

/**
 * 具体工厂1
*/
class ConcreateSimpleShapeFactiry : public AbstractFactory
{
public:
    AbstractShape* create_curved_instance() override
    {
        return new ConcreteCircle;
    }

    AbstractShape* create_straight_instance() override
    {
        return new ConcreteSquare;
    }
};

/**
 * 具体工厂2
*/
class ConcreateRobustShapeFactiry : public AbstractFactory
{
public:
    AbstractShape* create_curved_instance() override
    {
        return new ConcreteEllipse;
    }

    AbstractShape* create_straight_instance() override
    {
        return new ConcreteRectangle;
    }
};

#define SIMPLE 1

int main()
{
#ifdef SIMPLE
    AbstractFactory* factory = new ConcreateSimpleShapeFactiry;
#elif ROBUST
    AbstractFactory* factory = new ConcreateRobustShapeFactiry;
#endif
    AbstractShape* shapes[3];

    shapes[0] = factory->create_curved_instance();   // shapes[0] = new Ellipse;
    shapes[1] = factory->create_straight_instance(); // shapes[1] = new Rectangle;
    shapes[2] = factory->create_curved_instance();   // shapes[2] = new Ellipse;

    for (int i=0; i < 3; i++) 
    {
        shapes[i]->draw();
    }    

    return 0;
}