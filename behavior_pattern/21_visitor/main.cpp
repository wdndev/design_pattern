/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 访问者模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "visitor.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

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

    ICompany* mint_visitor = new Mint();
    std::cout << set_material->accept(mint_visitor)<< std::endl;

    delete art_visitor;
    delete mint_visitor;
    delete set_material;
    return 0;
}