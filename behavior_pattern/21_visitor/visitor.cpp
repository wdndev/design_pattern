/**
 * @file        - visitor.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 访问者模式实现
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "visitor.h"

// 具体访问者：艺术公司
std::string ArtCompany::create(Paper* element)
{
    return "使用 " + element->m_material_name + " 制作了" + "讲学图！";
}

std::string ArtCompany::create(Cuprum* element)
{
    return "使用 " + element->m_material_name + " 制作了" + "铜像！";
}

// 具体访问者：造币公司
std::string Mint::create(Paper* element)
{
    return "使用 " + element->m_material_name + " 制作了" + "纸币！";
}

std::string Mint::create(Cuprum* element)
{
    return "使用 " + element->m_material_name + " 制作了" + "铜币！";
}

// 具体元素：纸
std::string Paper::accept(ICompany* visitor)
{
    return (visitor->create(this));
}

// 具体元素：铜
std::string Cuprum::accept(ICompany* visitor)
{
    return (visitor->create(this));
}

// 对象结构角色：材料集
std::string SetMaterial::accept(ICompany* visitor)
{
    std::string tmp = "";
    for(auto s : m_list)
    {
        tmp += s->accept(visitor) + " ";
    }
    return tmp;
}

void SetMaterial::add(IMaterial* element)
{
    m_list.push_back(element);
}

void SetMaterial::remove(IMaterial* element)
{
    m_list.remove(element);
}