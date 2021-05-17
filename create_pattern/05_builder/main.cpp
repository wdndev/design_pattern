/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 建造者模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "builder.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    AbstractBuilderDecorator* bp = new ConcreteBuilderDecorator2();
    DirectorProjectMgr* m = new DirectorProjectMgr(bp);
    ProductParlour::Ptr pp = m->decorate();
    pp->show();
  
    delete m;
    delete bp;
    return 0;
}