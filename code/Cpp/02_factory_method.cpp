/**
 * @file        - 02_factory_method.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 工厂模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

#include <iostream>
#include <string>

/**
 *抽象基类
*/
class Document
{
public:
    Document(const std::string& name) : m_name(name) {}

    virtual void open() = 0;
    virtual void close() = 0;

    std::string get_name()
    {
        return m_name;
    }

private:
    std::string m_name;
};

/**
 * 具体派生类
*/
class MyDocument : public Document
{
public:
    MyDocument(const std::string& name) : Document(name) {}

    void open()
    {
        std::cout  << "   MyDocument: Open()" << std::endl;
    }

    void close()
    {
        std::cout  << "   MyDocument: Open()" << std::endl;
    }
};

class Application
{
public:
    Application() : m_index(0)
    {
        std::cout << "Application: ctor" << std::endl;
    }


    void new_document(const std::string& name)
    {
        std::cout << "Application: new document() " << std::endl;
        m_doc[m_index] = create_document(name);
        m_doc[m_index++]->open();
    }

    void open_document() {};

    void report_docs()
    {
        std::cout << "Application: report_docs()" << std::endl;
        for (int i = 0; i < m_index; i++)
            std::cout << "    " << m_doc[i]->get_name() << std::endl;
    }

    virtual Document* create_document(std::string name) = 0;

private:
    int m_index;
    Document* m_doc[10];
};

class MyApplication : public Application
{
public:
    MyApplication()
    {
        std::cout << "MyApplication: ctor" << std::endl;
    }

    Document* create_document(std::string name) override
    {
        std::cout << "   MyApplication: CreateDocument()" << std::endl;
        return new MyDocument(name);
    }
};

int main()
{
    MyApplication app;

    app.new_document("foo");
    app.new_document("bar");

    app.report_docs();

    return 0;
}


