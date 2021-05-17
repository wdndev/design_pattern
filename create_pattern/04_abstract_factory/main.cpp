/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 工厂模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "abstract_factory.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    std::shared_ptr<AbstractFactory> factory(FactoryHelper::get_factory("ConcreteFactory"));
    assert(factory != nullptr);
    std::shared_ptr<AbstractProductLink> people(factory->create_link(u8"people", u8"http://www.people.com.cn/"));
    std::shared_ptr<AbstractProductLink> gmw(factory->create_link(u8"gmw", u8"http://www.gmw.com.cn/"));
    std::shared_ptr<AbstractProductLink> us_yahoo(factory->create_link(u8"us_yahoo", u8"http://www.yahoo.com/"));
    std::shared_ptr<AbstractProductLink> jp_yahoo(factory->create_link(u8"jp_yahoo", u8"http://www.yahoo.com.jp/"));
    std::shared_ptr<AbstractProductLink> google(factory->create_link(u8"google", u8"http://www.google.com"));

    std::shared_ptr<AbstractProductTray> trayNews(factory->create_tray("news"));
    trayNews->add_item(people.get());
    trayNews->add_item(gmw.get());

    std::shared_ptr<AbstractProductTray> trayYahoo(factory->create_tray("yahoo!"));
    trayYahoo->add_item(us_yahoo.get());
    trayYahoo->add_item(jp_yahoo.get());

    std::shared_ptr<AbstractProductTray> traySearch(factory->create_tray("traySearch"));
    trayYahoo->add_item(trayYahoo.get());
    trayYahoo->add_item(google.get());

    std::shared_ptr<AbstractProductPage> page(factory->create_page("LinkPage", "tao"));
    page->add_item(trayNews.get());
    page->add_item(traySearch.get());
    page->output();

    return 0;
}