/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 职责链模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "responsibility.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    
    Leader::Ptr teacher1 = std::make_shared<ClassAdviser>();
    Leader::Ptr teacher2 = std::make_shared<DepartmentHead>();
    Leader::Ptr teacher3 = std::make_shared<Dean>();

    // 组装职责链
    teacher1->set_next(teacher2);
    teacher2->set_next(teacher3);

    // 提交请求
    teacher1->handle_request(5);

    return 0;
}