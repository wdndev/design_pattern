/**
 * @file        - 15_chain_of_responsibility.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 职责链模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 假如规定学生请假小于或等于 2 天，班主任可以批准；小于或等于 7 天，
// 系主任可以批准；小于或等于 10 天，院长可以批准；其他情况不予批准；

#include <iostream>
#include <string>
#include <memory>

/**
 * 抽象处理者：领导类
*/
class Leader
{
public:
    Leader() : m_next_leader(nullptr) {}

    using Ptr = std::shared_ptr<Leader>;

    void set_next(Leader::Ptr next_leader)
    {
        m_next_leader = next_leader;
    }

    Leader::Ptr get_next()
    {
        return m_next_leader;
    }

    virtual void handle_request(int leave_days) = 0;
private:
    Leader::Ptr m_next_leader;
};

/**
 * 具体处理者1：班主任类
*/
class ClassAdviser : public Leader
{
public:
    void handle_request(int leave_days) override
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

/**
 * 具体处理者2：系主任类
*/
class DepartmentHead  : public Leader
{
public:
    void handle_request(int leave_days) override
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

/**
 * 具体处理者3：院长类
*/
class Dean : public Leader
{
public:
    void handle_request(int leave_days) override
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

int main()
{
    
    Leader::Ptr teacher1 = std::make_shared<ClassAdviser>();
    Leader::Ptr teacher2 = std::make_shared<DepartmentHead>();
    Leader::Ptr teacher3 = std::make_shared<Dean>();

    // 组装职责链
    teacher1->set_next(teacher2);
    teacher2->set_next(teacher3);

    // 提交请求
    teacher1->handle_request(1);
    teacher1->handle_request(5);
    teacher1->handle_request(9);
    teacher1->handle_request(15);

    return 0;
}
