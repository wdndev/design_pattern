/**
 * @file        - responsibility.h
 * @author      - wdn (you@domain.com)
 * @brief       - 职责链模式声明
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

// 抽象处理者：领导类
class Leader
{
public:
    using Ptr = std::shared_ptr<Leader>;

    void set_next(Leader::Ptr next)
    {
        m_next = next;
    }

    Leader::Ptr get_next()
    {
        return m_next;
    }

    virtual void handle_request(int leave_days) = 0;

private:
    Leader::Ptr m_next;
};

// 具体处理者1：班主任类
class ClassAdviser : public Leader
{
public:
    void handle_request(int leave_days)
    {
        if (leave_days <= 2)
        {
            std::cout << " 班主任批准您请假 " + std::to_string(leave_days) + " 天. " << std::endl;
        }
        else
        {
            if (get_next() != nullptr)
            {
                get_next()->handle_request(leave_days);
            }
            else
            {
                std::cout << " 请假天数太多，没有人批准该假条! " << std::endl;
            }
            
        }
        
    }
};

// 具体处理者2：系主任类
class DepartmentHead : public Leader
{
public:
    void handle_request(int leave_days)
    {
        if (leave_days <= 7)
        {
            std::cout << " 系主任批准您请假 " + std::to_string(leave_days) + " 天. " << std::endl;
        }
        else
        {
            if (get_next() != nullptr)
            {
                get_next()->handle_request(leave_days);
            }
            else
            {
                std::cout << " 请假天数太多，没有人批准该假条! " << std::endl;
            }
            
        }
        
    }
};

// 具体处理者3：院长类
class Dean : public Leader
{
public:
    void handle_request(int leave_days)
    {
        if (leave_days <= 10)
        {
            std::cout << " 院长批准您请假 " + std::to_string(leave_days) + " 天. " << std::endl;
        }
        else
        {
            if (get_next() != nullptr)
            {
                get_next()->handle_request(leave_days);
            }
            else
            {
                std::cout << " 请假天数太多，没有人批准该假条! " << std::endl;
            }
            
        }
        
    }
};
