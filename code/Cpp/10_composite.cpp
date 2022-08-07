/**
 * @file        - 10_composite.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 组合模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 假如李先生到“天街e角”生活用品店购物，
// 用 1 个红色小袋子装了 2 包特产（单价 7.9 元）、1 张地图（单价 9.9 元）；
// 用 1 个白色小袋子装了 2 包香菇（单价 68 元）和 3 包红茶（单价 180 元）；
// 用 1 个中袋子装了前面的红色小袋子和 1 个景德镇瓷器（单价 380 元）；
// 用 1 个大袋子装了前面的中袋子、白色小袋子和 1 双李宁牌运动鞋（单价 198 元）。
// 最后“大袋子”中的内容有：{
//      1 双李宁牌运动鞋（单价 198 元）、
//      白色小袋子{2 包香菇（单价 68 元）、
//      3 包红茶（单价 180 元）}、
//      中袋子{1 个景德镇瓷器（单价 380 元）、
//      红色小袋子{2 包特产（单价 7.9 元）、
//      1 张地图（单价 9.9 元）}}}，
// 现在要求编程显示李先生放在大袋子中的所有商品信息并计算要支付的总价。

#include <iostream>
#include <string>
#include <memory>
#include <map>

/**
 * 抽象构件（Component）角色：物品
*/
class Articles
{
public:
    using Ptr = std::shared_ptr<Articles>;
    virtual float calculation() = 0;
    virtual void show() = 0;
};

/**
 * 树叶构件（Leaf）角色：货物
*/
class Goods : public Articles
{
public:
    Goods(const std::string& name, int quantity, float unit_price)
        : Articles(), 
          m_name(name), m_quantity(quantity), m_unit_price(unit_price) {}
    
    float calculation() override
    {
        return m_quantity * m_unit_price;
    }

    void show() override
    {
        std::cout << m_name 
                  << " (数量 " + std::to_string(m_quantity) + ", 单价: " + std::to_string(m_unit_price) + " RMB.)"
                  << std::endl;
    }

private:
    std::string m_name;     // 名字
    int m_quantity;         // 数量
    float m_unit_price;     // 单价
};

/**
 * 树枝构件（Composite）角色：袋子
*/
class Bags : public Articles
{
public:
    using Ptr = std::shared_ptr<Bags>;
    Bags(std::string name) : Articles(), m_name(name) {}

    void add(const std::string& goods_name, Articles::Ptr goods_ptr)
    {
        m_bags.insert({goods_name, goods_ptr});
    }

    void remove(const std::string& goods_name)
    {
        for(auto it = m_bags.begin(); it != m_bags.end(); it++)
        {
            if(it->first == goods_name)
            {
                m_bags.erase(it);
                break;
            } 
        }
    }

    Articles::Ptr get_goods(const std::string& goods_name)
    {
        for(auto it = m_bags.begin(); it != m_bags.end(); it++)
        {
            if(it->first == goods_name)
            {
                return it->second;
            } 
        }
    }

    float calculation() override
    {
        float s= 0.0;
        for(auto it = m_bags.begin(); it != m_bags.end(); it++)
        {
            s += it->second->calculation();
        }
        return s;
    }

    void show() override
    {
        for(auto it = m_bags.begin(); it != m_bags.end(); it++)
        {
            it->second->show();
        }
    }
private:
    // 袋子名称
    std::string m_name;
    // 袋子里面物品 《名称， 指针》
    std::map<std::string, Articles::Ptr> m_bags;
};

int main()
{
    Bags::Ptr big_bag = std::make_shared<Bags>("大袋子: ");
    Bags::Ptr medium_bag = std::make_shared<Bags>("中袋子: ");
    Bags::Ptr small_red_bag = std::make_shared<Bags>("红色小袋子: ");
    Bags::Ptr small_white_bag = std::make_shared<Bags>("白色小袋子: ");
    
    Articles::Ptr sp = std::make_shared<Goods>(" 特产 ", 2, 7.9);
    small_red_bag->add(" 特产 ", sp);
    sp = std::make_shared<Goods>(" 地图 ", 1, 9.9);
    small_red_bag->add(" 地图 ", sp);

    sp = std::make_shared<Goods>(" 香菇 ", 2, 68);
    small_white_bag->add(" 香菇 ", sp);
    sp = std::make_shared<Goods>(" 红茶 ", 3, 180);
    small_white_bag->add(" 红茶 ",sp);
    
    sp = std::make_shared<Goods>(" 景德镇瓷器 ", 1, 380);
    medium_bag->add(" 景德镇瓷器 ", sp);
    medium_bag->add("红色小袋子 ", small_red_bag);

    sp = std::make_shared<Goods>(" 李宁牌运动鞋 ", 1, 198);
    big_bag->add(" 李宁牌运动鞋 ", sp);
    big_bag->add("白色小袋子 ", small_white_bag);
    big_bag->add("中袋子: ", medium_bag);
    
    std::cout << "您选购的商品有: " << std::endl;
    big_bag->show();
    std::cout << " 要支付的总价为 : " << big_bag->calculation()  << " RMB." << std::endl;

    big_bag->remove(" 李宁牌运动鞋 ");
    std::cout << "您选购的商品有: " << std::endl;
    big_bag->show();
    std::cout << " 要支付的总价为 : " << big_bag->calculation()  << " RMB." << std::endl;

    return 0;
}


