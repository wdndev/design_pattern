# -*- coding: utf-8 -*-
#  @file        - 13_template.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 模板模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 出国留学手续一般经过以下流程：索取学校资料，提出入学申请，办理因私出国护照、出境卡和公证，
# 申请签证，体检、订机票、准备行装，抵达目标学校等，其中有些业务对各个学校是一样的，
# 但有些业务因学校不同而不同，所以比较适合用模板方法模式来实现。

import abc

class AbstractStudyAbroad(metaclass=abc.ABCMeta):
    """ 抽象类：出国留学
    """

    def template_method(self):
        self.looking_for_school()
        self.apply_for_enrol()
        self.apply_for_passport()
        self.apply_for_visa()
        self.ready_go_abroad()
        self.arriving()

    @abc.abstractmethod
    def looking_for_school(self):
        pass

    @abc.abstractmethod
    def apply_for_enrol(self):
        pass

    @abc.abstractmethod
    def arriving(self):
        pass

    def apply_for_passport(self):
        print("三.办理因私出国护照、出境卡和公证：")
        print("  1）持录取通知书、本人户口簿或身份证向户口所在地公安机关申请办理因私出国护照和出境卡.")
        print("  2）办理出生公证书，学历、学位和成绩公证，经历证书，亲属关系公证，经济担保公证.")

    def apply_for_visa(self):
        print("四.申请签证：")
        print("  1）准备申请国外境签证所需的各种资料，包括个人学历、成绩单、工作经历的证明；个人及家庭收入、资金和财产证明；家庭成员的关系证明等.")
        print("  2）向拟留学国家驻华使(领)馆申请入境签证。申请时需按要求填写有关表格，递交必需的证明材料，缴纳签证。有的国家(比如美国、英国、加拿大等)在申请签证时会要求申请人前往使(领)馆进行面试.")

    def ready_go_abroad(self):
        print("五.体检、订机票、准备行装;")
        print("  1）进行身体检查、免疫检查和接种传染病疫苗;" )
        print("  2）确定机票时间、航班和转机地点.")


class ConcreteStudyInAmerica(AbstractStudyAbroad):
    """
    """
    def looking_for_school(self):
        print("一.索取学校以下资料：")
        print("  1）对留学意向国家的政治、经济、文化背景和教育体制、学术水平进行较为全面的了解;")
        print("  2）全面了解和掌握国外学校的情况，包括历史、学费、学制、专业、师资配备、教学设施、学术地位、学生人数等;")
        print("  3）了解该学校的住宿、交通、医疗保险情况如何;")
        print("  4）该学校在中国是否有授权代理招生的留学中介公司?")
        print("  5）掌握留学签证情况;")
        print("  6）该国政府是否允许留学生合法打工?")
        print("  7）毕业之后可否移民?")
        print("  8）文凭是否受到我国认可?")

    def apply_for_enrol(self):
        print("二.入学申请:")
        print("  1）填写报名表；")
        print("  2）将报名表、个人学历证明、最近的学习成绩单、推荐信、个人简历、托福或雅思语言考试成绩单等资料寄往所申请的学校;")
        print("  3）为了给签证办理留有充裕的时间，建议越早申请越好，一般提前1年就比较从容.")

    def arriving(self):
        print("六.抵达目标学校:")
        print("  1）安排住宿;")
        print("  2）了解校园及周边环境.")

def main():
    tm = ConcreteStudyInAmerica()
    tm.template_method()


if __name__ == "__main__":
    main()