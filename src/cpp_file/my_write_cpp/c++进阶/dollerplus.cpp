/*
    奖学金评定系统设计
    一，系统功能

    （1）能输入若干个学生的科目成绩，每个学生一组成绩数据；

    （2）计算每个学生的平均成绩，并对有不及格学生做标记；

    （3）用户可选择不同的排序方法对学生平均成绩进行排序；

    （4）选取平均成绩前5位的同学为奖学金获得者（如果该生有成绩不及格则不能获得奖学金），并输出学生的姓名及综合成绩（平均分）；

    （5）用户可选择是否输出含有不及格科目的学生。

    注：假设考试科目满分都为100，及格线都为60。
————————————————
*/
#include <iostream>
// using namespace std;
#include <string>
#include <algorithm>
// #include <
#include <vector>
#include <thread>
#include <mutex>
class Student
{
public:
    Student(std::string name){

        scores.clear();
        average_score = 0;
        ScoreIsOK = false;
        DollerIsOK = false;
        this->name = name;
        // t1 = std::thread(&Student::cal_average,this);
    }
    void cal_average()
    {
        // average_score =
        // std::lock_guard<std::mutex>lock(mux);
        int total = 0;
        for(auto sco : scores){
            total += sco;
            if(sco < 60){
                ScoreIsOK = true;
            }
        }
        std::cout << "总成绩为: " << total << std::endl;

        average_score = static_cast<double>(total)/scores.size();//安全类型转换
        // if(average_score < )
    }
    ~Student(){    
        // if(t1.joinable){
        //     t1.join();
        // }
    }
public:
    std::string name;
    double average_score;
    std::vector<double>scores;
    bool ScoreIsOK;
    bool DollerIsOK;
    // std::thread t1;
    // std::mutex mux;


};
bool cmp_shun(Student s1,Student s2)
{
    return s1.average_score > s2.average_score;
}
bool cmp_fan(Student s1,Student S2)
{

    return s1.average_score < S2.average_score;
}
// void mySort(const std::vector<Student>&stu){
//     std::vector<Student>mystu;
//     double score;
//     for(auto st:stu){
//         //冒泡排序
//         for(int i = 0;i < stu.size()-1;i++)
//         {
//             for(int j = i+1;j < stu.size()-1;j++){
//                 if(st.average_score > )
//             }

//         }
//         if(st.average_score > )
//     }

// }
int main(int argc, char const *argv[])
{
    int StuNum,Kemu;
    std::cout << "请您选择要输入多少个学生的成绩: " << std::endl;
    std::cin >> StuNum;
    std::cout << "请您选择要输入多少门课程的成绩: " << std::endl;
    std::cin >> Kemu;
    std::vector<Student>studets;
    for(int i = 0;i < StuNum;++i){
        std::vector<double>scores;
        std::string name;
        
        std::cout << "请输入第" << i+1 << "学生的名字: " << std::endl;
        std::cin >> name;
        for(int j = 0;j < Kemu;++j){
            int m_score;
            std::cout << "请输入这个学生的第[" << j+1 << "]成绩:" << std::endl;
            std::cin >>m_score;
            scores.push_back(m_score);
        }
        Student stu(name);
        stu.scores = scores;
        stu.cal_average();
        studets.push_back(stu);


    }
    //排序
    // std::cout << ""
    std::cout<< "开始排序了 请选择你要记性的排序方式" << std::endl;
    std::cout<< "1 顺序  从高到低 2 逆序 分数从低到高" << std::endl;
    int index = 0;
    std::cin >> index;
    switch (index)
    {
    case 1:
        std::cout << " --------  " << std::endl;
        // mySort(studets);
        sort(studets.begin(),studets.end(),cmp_shun);
        for(auto su:studets){
            std::cout << "姓名为: " << su.name << " 平均分为: " << su.average_score << std::endl;
        }
        std::cout << "顺序排序结束了" << std::endl;
        std::cout << "下面为奖学金获得者(排除了前五名中单科成绩不合格的学生)" << std::endl;
        for(std::vector<Student>::iterator it = studets.begin();it != studets.begin()+4;it++){
                for(std::vector<double>::iterator si = it->scores.begin();si != it->scores.end();si++)
                {
                    if(*si < 60)
                    {
                        it->DollerIsOK = true;

                    }
                    

                    
                }
                if(it->DollerIsOK){
                        std::cout << "该生源不再打印" << std::endl;
                }
                else{

                    std::cout << "姓名为: " << it->name << " 平均分为: " << it->average_score << "为奖学金获得者" << std::endl;

                }


        }
        // for(int i = 0;i < studets.size();i++)
        // {
        // }
        /* code */
        break;
    case 2:
        std::cout << " --------  " << std::endl;
        // mySort(studets);
        sort(studets.begin(),studets.end(),cmp_fan);
        for(auto su:studets){
            std::cout << "姓名为: " << su.name << " 平均分为: " << su.average_score << std::endl;
        }
        std::cout << "逆序排序结束了" << std::endl;
        std::cout << "下面为奖学金获得者(排除了前五名中单科成绩不合格的学生)" << std::endl;
        for(std::vector<Student>::iterator it = studets.end();it != studets.end()-4;it--){
                for(std::vector<double>::iterator si = it->scores.begin();si != it->scores.end();si++)
                {
                    if(*si < 60)
                    {
                        it->DollerIsOK = true;

                    }
                    
                    
                }
                if(it->DollerIsOK){
                        std::cout << "该生源不再打印" << std::endl;
                }
                else{

                    std::cout << "姓名为: " << it->name << " 平均分为: " << it->average_score << "为奖学金获得者" << std::endl;

                }



        }

        break;
    
    default:
        break;
    }
    std::cout << "请您选择是否要输出不合格学生" << std::endl;
    std::cout << "输入1 为输出 输入0为不输出" << std::endl;
    bool isOut;
    std::cin >>isOut;
    while (isOut)
    {
        for(auto su:studets){
            if(su.ScoreIsOK)
                std::cout << "姓名为: " << su.name << " 单科存在不合格 为不合格学生 " << std::endl;
        }
        isOut =false;
    }
    
    
    // //迭代器
    // for(auto stu : studets){

    // }
    return 0;
}
/*
测试
    6个学生 2门成绩
    zz 65 89  平均分 77  总成绩154
    xx 59 100   平均分  79.5 总成绩 159
    cc 85 65    平均分  75 总成绩 150
    vv 55 45    平均分  50 总成绩 100 
    bb 78 79    平均分 78.5  总成绩 157
    nn 54 95    平均分  74.5 总成绩 149

测试:
请您选择要输入多少个学生的成绩: 
6
请您选择要输入多少门课程的成绩: 
2
请输入第1学生的名字: 
zz
请输入第一个学生的第[1]成绩:
65
请输入第一个学生的第[2]成绩:
89
总成绩为: 154
请输入第2学生的名字: 
xx
请输入第一个学生的第[1]成绩:
59
请输入第一个学生的第[2]成绩:
100
总成绩为: 159
请输入第3学生的名字: 
cc
请输入第一个学生的第[1]成绩:
85
请输入第一个学生的第[2]成绩:
65
总成绩为: 150
请输入第4学生的名字: 
vv
请输入第一个学生的第[1]成绩:
55
请输入第一个学生的第[2]成绩:
45
总成绩为: 100
请输入第5学生的名字: 
bb
请输入第一个学生的第[1]成绩:
78
请输入第一个学生的第[2]成绩:
79
总成绩为: 157
请输入第6学生的名字: 
nn
请输入第一个学生的第[1]成绩:
54
请输入第一个学生的第[2]成绩:
95
总成绩为: 149
开始排序了 请选择你要记性的排序方式
1 顺序  从高到低 2 逆序 分数从低到高
1
 --------  
姓名为: xx 平均分为: 79.5
姓名为: bb 平均分为: 78.5
姓名为: zz 平均分为: 77
姓名为: cc 平均分为: 75
姓名为: nn 平均分为: 74.5
姓名为: vv 平均分为: 50
顺序排序结束了
下面为奖学金获得者(排除了前五名中单科成绩不合格的学生)
该生源不再打印
姓名为: bb 平均分为: 78.5为奖学金获得者
姓名为: zz 平均分为: 77为奖学金获得者
姓名为: cc 平均分为: 75为奖学金获得者
请您选择是否要输出不合格学生
输入1 为输出 输入0为不输出
1
姓名为: xx 单科存在不合格 为不合格学习 
姓名为: nn 单科存在不合格 为不合格学习 
姓名为: vv 单科存在不合格 为不合格学习 

*/