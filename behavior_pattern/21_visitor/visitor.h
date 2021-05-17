/**
 * @file        - visitor.h
 * @author      - wdn (you@domain.com)
 * @brief       - 访问者模式声明
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>

class Paper;
class Cuprum;

// 抽象访问者：公司
class ICompany
{
public:
    virtual std::string create(Paper* element) = 0;
    virtual std::string create(Cuprum* element) = 0;
};

// 具体访问者：艺术公司
class ArtCompany : public ICompany
{
public:
    std::string create(Paper* element) override;
    std::string create(Cuprum* element) override;
};

// 具体访问者：造币公司
class Mint : public ICompany
{
public:
    std::string create(Paper* element) override;
    std::string create(Cuprum* element) override;
};

// 抽象元素：材料
class IMaterial
{
public:
    virtual ~IMaterial() {}
    virtual std::string accept(ICompany* visitor) = 0;

    std::string m_material_name;
};

// 具体元素：纸
class Paper : public IMaterial
{
public:
    Paper() : IMaterial() 
    {
        m_material_name = "paper";
    }
    std::string accept(ICompany* visitor) override;
};

// 具体元素：铜
class Cuprum : public IMaterial
{
public:
    Cuprum() : IMaterial() 
    {
        m_material_name = "cuprum";
    }
    std::string accept(ICompany* visitor) override;
};

// 对象结构角色：材料集
class SetMaterial
{
public:
    std::string accept(ICompany* visitor);

    void add(IMaterial* element);

    void remove(IMaterial* element);

private:
    std::list<IMaterial*> m_list;
};