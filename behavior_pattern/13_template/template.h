/**
 * @file        - template.h
 * @author      - wdn (you@domain.com)
 * @brief       - 模板模式声明
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#pragma once

#include <iostream>
#include <string>

// 抽象类：出国留学
class StudyAbroad
{
public:
    void template_method()      // 模板方法
    {
        looking_for_school();   // 索取学校资料
        apply_for_enrol();      // 入学申请
        apply_for_passport();   // 办理因私出国护照、出境卡和公证
        apply_for_visa();       // 申请签证
        ready_go_abroad();      // 体检、订机票、准备行装
        arriving();             // 抵达
    }

    void apply_for_passport()
    {
        std::cout << "三.办理因私出国护照、出境卡和公证：" << std::endl
                  << "  1）持录取通知书、本人户口簿或身份证向户口所在地公安机关申请办理因私出国护照和出境卡." << std::endl
                  << "  2）办理出生公证书，学历、学位和成绩公证，经历证书，亲属关系公证，经济担保公证." << std::endl;
    }

    void apply_for_visa()
    {
        std::cout << "四.申请签证：" << std::endl
                  << "  1）准备申请国外境签证所需的各种资料，包括个人学历、成绩单、工作经历的证明；个人及家庭收入、资金和财产证明；家庭成员的关系证明等." << std::endl
                  << "  2）向拟留学国家驻华使(领)馆申请入境签证。申请时需按要求填写有关表格，递交必需的证明材料，缴纳签证。有的国家(比如美国、英国、加拿大等)在申请签证时会要求申请人前往使(领)馆进行面试." << std::endl;
    }

    void ready_go_abroad()
    {
        std::cout << "五.体检、订机票、准备行装;" << std::endl
                  << "  1）进行身体检查、免疫检查和接种传染病疫苗;" << std::endl
                  << "  2）确定机票时间、航班和转机地点." << std::endl;
    }

    virtual void looking_for_school() = 0;
    virtual void apply_for_enrol() = 0;
    virtual void arriving() = 0;

};

// 具体子类：美国留学
class StudyInAmerica : public StudyAbroad
{
public:
    void looking_for_school() override
    {
        std::cout << "一.索取学校以下资料：" << std::endl
                  << "  1）对留学意向国家的政治、经济、文化背景和教育体制、学术水平进行较为全面的了解;" << std::endl
                  << "  2）全面了解和掌握国外学校的情况，包括历史、学费、学制、专业、师资配备、教学设施、学术地位、学生人数等;" << std::endl
                  << "  3）了解该学校的住宿、交通、医疗保险情况如何;" << std::endl
                  << "  4）该学校在中国是否有授权代理招生的留学中介公司?" << std::endl
                  << "  5）掌握留学签证情况;" << std::endl
                  << "  6）该国政府是否允许留学生合法打工?" << std::endl
                  << "  7）毕业之后可否移民?" << std::endl
                  << "  8）文凭是否受到我国认可?" << std::endl;
    }

    void apply_for_enrol() override
    {
        std::cout << "二.入学申请:" << std::endl
                  << "  1）填写报名表；" << std::endl
                  << "  2）将报名表、个人学历证明、最近的学习成绩单、推荐信、个人简历、托福或雅思语言考试成绩单等资料寄往所申请的学校;" << std::endl
                  << "  3）为了给签证办理留有充裕的时间，建议越早申请越好，一般提前1年就比较从容." << std::endl;
    }

    void arriving() override
    {
        std::cout << "六.抵达目标学校:" << std::endl
                  << "  1）安排住宿;" << std::endl
                  << "  2）了解校园及周边环境." << std::endl;
    }
};