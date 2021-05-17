/**
 * @file        - product.h
 * @author      - wdn (you@domain.com)
 * @brief       - 抽象工厂模式声明
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

// 抽象产品：方便统一处理 Link 和 Tray 的类
class AbstractProduct
{
public:
    virtual ~AbstractProduct() {}
    AbstractProduct(const std::string& caption) : m_caption(caption) {}
    virtual std::string makeHTML() = 0;

protected:
    std::string m_caption;
};

// 抽象零件:表示 HTML 链接的类
class AbstractProductLink : public AbstractProduct
{
public:
    virtual ~AbstractProductLink() {}
    AbstractProductLink(const std::string& caption, const std::string& url) : AbstractProduct(caption), m_url(url) {}

protected:
    std::string m_url;
};

// 抽象零件：表示含有 Link 和 Tray 的类
class AbstractProductTray : public AbstractProduct
{
public:
    virtual ~AbstractProductTray() {}
    AbstractProductTray(const std::string& caption) : AbstractProduct(caption) {}
    void add_item(AbstractProduct* item)
    {
        m_item_list.push_back(item);
    }
protected:
    std::vector<AbstractProduct*> m_item_list;
};

// 抽象产品：表示 HTML 页面的类
class AbstractProductPage
{
public:
    virtual ~AbstractProductPage() {}
    AbstractProductPage(const std::string& title, const std::string& author) : m_title(title), m_author(author) {}
    void add_item(AbstractProduct *item)
    {
        m_item_list.push_back(item);
    }

    void output()
    {
        std::cout << makeHTML() << std::endl;
    }

    virtual std::string makeHTML() = 0;
protected:
    std::string m_title;
    std::string m_author;
    std::vector<AbstractProduct*> m_item_list;
};

// 具体零件：表示 HTML 的链接的类
class ConcreteProductLink : public AbstractProductLink
{
public:
    using AbstractProductLink::AbstractProductLink;
    std::string makeHTML() override
    {
        return "<li><a href=\"" + m_url + "\"> " + m_caption + "</a> </li>\n";
    }
};

// 具体零件：表示含有 Link 和 Tray 的类
class ConcreteProductTary : public AbstractProductTray
{
public:
    using AbstractProductTray::AbstractProductTray;
    std::string makeHTML() override
    {
        std::string str;
        str.append("<li>\n");
        str.append(m_caption + "\n");
        str.append("<ul>\n");

        for (auto item : m_item_list)
        {
            str.append(item->makeHTML());
        }

        str.append("</ul>\n");
        str.append("</li>\n");
        return str;
    }
};

// 具体零件：表示HTML页面的类
class ConcreteProductPage : public AbstractProductPage
{
public:
    using AbstractProductPage::AbstractProductPage;
    std::string makeHTML() override
    {
        std::string str;
        str.append("<html><head><title>" + m_title + "</head></title>\n");
        str.append("<body>\n");
        str.append("<h1>" + m_title + "</h1>\n");
        str.append("<ul>\n");

        for (auto item : m_item_list)
        {
            str.append(item->makeHTML());
        }
        str.append("</ul>\n");
        str.append("<address>" + m_author + "</address>\n");
        str.append("</body>\n");
        str.append("</html>");
        return str;
    }
};