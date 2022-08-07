/**
 * @file        - singleton.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 单例模式头文件
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

#include <iostream>
#include <string>

class Number
{
public:
    // 2.定义公有访问方法
    static Number* get_instance();

    static void set_type(std::string type)
    {
        m_type = type;
        delete m_instance;
        m_instance = NULL;
    }

    virtual void set_value(int value)
    {
        m_value = value;
    }

    virtual int get_value()
    {
        return m_value;
    }

protected:
    int m_value;
    // 4.将构造函数放在protected关键字下，防止函数构造
    Number() {}
private:
    // 1. 定义私有静态属性
    static std::string m_type;
    static Number* m_instance;
};

class Octal: public Number
{
    // 6.支持继承
public:
    friend class Number;

    void set_value(int value) override
    {
        m_value = value;
    }
protected:
    Octal() {}
};

Number* Number::get_instance()
{
    // 3. 通过公有方法初始化实例类
    if(!m_instance)
    {
        if (m_type == "octal")
            m_instance = new Octal();
        else
            m_instance = new Number();
    }
    return m_instance;
}

std::string Number::m_type = "decimal";
Number* Number::m_instance = NULL;

int main()
{
    // 5.使用者只能使用 get_instance() 访问函数生成单例，不能使用构造函数
    Number::get_instance()->set_value(42);
    std::cout << "value is " << Number::get_instance()->get_value() << std::endl;

    Number::set_type("octal");
    Number::get_instance()->set_value(64);
    std::cout << "value is " << Number::get_instance()->get_value() << std::endl;


    return 0;
}