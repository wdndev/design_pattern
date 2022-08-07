/**
 * @file        - 18_visitor.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 访问者模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 艺术公司利用“铜”可以设计出铜像，利用“纸”可以画出图画；
// 造币公司利用“铜”可以印出铜币，利用“纸”可以印出纸币。
// 对“铜”和“纸”这两种元素，两个公司的处理方法不同。

#include <iostream>
#include <string>
#include <memory>
#include <list>

// 前置声明
class Paper;
class Cuprum;

/**
 *  抽象访问者：公司
*/
class ICompany
{
public:
    virtual std::string create(Paper* elem) = 0;
    virtual std::string create(Cuprum* elem) = 0;
};

/**
 * 具体访问者：艺术公司
*/
class ArtCompany : public ICompany
{
public:
    std::string create(Paper* elem) override;

    std::string create(Cuprum* elem) override;
};

/**
 * 具体访问者：造币公司 
*/
class MintCompany : public ICompany
{
public:
    std::string create(Paper* elem) override;

    std::string create(Cuprum* elem) override;
};

/**
 * 抽象元素：材料
*/
class IMaterial
{
public:
    virtual ~IMaterial() {}
    virtual std::string accept(ICompany* visitor) = 0;

    std::string get_material_name()
    {
        return m_material_name;
    }
protected:
    std::string m_material_name;
};

/**
 * 具体元素：纸
*/
class Paper : public IMaterial
{
public:
    Paper() : IMaterial()
    {
        m_material_name = "paper";
    }

    std::string accept(ICompany* visitor) override;
};

/**
 * 具体元素：铜
*/
class Cuprum  : public IMaterial
{
public:
    Cuprum () : IMaterial()
    {
        m_material_name = "cuprum ";
    }

    std::string accept(ICompany* visitor) override;
};

/**
 * 对象结构角色：材料集
*/
class SetMaterial
{
public:
    std::string accept(ICompany* visitor);

    void add(IMaterial* elem);

    void remove(IMaterial* elem);
private:
    std::list<IMaterial*> m_list;
};


// 具体访问者：艺术公司
std::string ArtCompany::create(Paper* elem)
{
    return "使用 " + elem->get_material_name() + " 制作了" + "讲学图！";
}

std::string ArtCompany::create(Cuprum* elem)
{
    return "使用 " + elem->get_material_name() + " 制作了" + "铜像！";
}

// 具体访问者：造币公司
std::string MintCompany::create(Paper* elem)
{
    return "使用 " + elem->get_material_name() + " 制作了" + "纸币！";
}

std::string MintCompany::create(Cuprum* elem)
{
    return "使用 " + elem->get_material_name() + " 制作了" + "铜币！";
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

void SetMaterial::add(IMaterial* elem)
{
    m_list.push_back(elem);
}

void SetMaterial::remove(IMaterial* elem)
{
    m_list.remove(elem);
}


int main()
{
    SetMaterial* set_material = new SetMaterial();
    IMaterial* paper_material = new Paper();
    IMaterial* cuprum_material = new Cuprum();

    set_material->add(paper_material);
    set_material->add(cuprum_material);

    ICompany* art_visitor = new ArtCompany();

    std::cout << set_material->accept(art_visitor) << std::endl;

    std::cout << "----------" << std::endl;

    ICompany* mint_visitor = new MintCompany();
    std::cout << set_material->accept(mint_visitor)<< std::endl;

    delete art_visitor;
    delete mint_visitor;
    delete set_material;
    return 0;
}


