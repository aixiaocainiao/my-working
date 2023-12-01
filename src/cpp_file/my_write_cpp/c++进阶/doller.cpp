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
版权声明：本文为CSDN博主「无泡汽水」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_65150735/article/details/129172524
    
    
*/
#include <iostream>
// using namespace std;
#include <thread>
#include <mutex>
#include <vector>
// #include <
#define KEMU 5
#define MAX_SCORE 100
#define MIN_SCORE 0
class Stu
{
public:
    Stu(string name,std::vector<int>scores)
    {
        m_Name = name;
        average = 0.0;
        this->hasFiled = false;
        this->m_Scores = scores;
        // m_Score = score;
        t1 = std::thread(Stu::main_thread,this);
        
    }
    void main_thread()
    {
        std::lock_guard<std::muetx> lock(mut);
        int total = 0;
        for(int score:scores){
            total += score;
            if(score < 60){
                hasFiled = true;
            }
        }
        average = static_cast<double>(total)/scores.size();
    }
    ~Stu()
    {
        m_Name = "";
        average = 0;
        scores.clear();
        hasFiled = false;
        if(t1.joinable){
            t1.join();
        }
    }
protected:
    string m_Name;
    std::vector<int>m_Scores;
    double average;
    bool hasFiled;
    int m_Score;
    std::thread t1;
    std::mutex mut;

};
void menu()
{


}

void my_Sort()
{
    std::cout<< "开始排序了 请选择你要记性的排序方式" << std::endl;
    std::cout<< "1 顺序  从高到低 2 逆序 分数从低到高" << std::endl;
    int index;
    cin >> index;
    switch (index)
    {
    case 1:
        
        /* code */
        break;
    case 2:
        break;
    default:
        break;
    }


}
int main(int argc, char const *argv[])
{

    std::cout << "请您选择以下那种情况" << std::endl;
    int numStudent;
    std::cout << "Enter the number of student: " ;
    std::cin >> numStudent;
    std::vector<Stu> students;
    for(int i =0;i < numStudent;++i){
        string name;
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> name;
        // student.push_back(Stu(name));
        // Stu student(name);
        std::vector<int>Scores;
        std::cout << "Enter " << name << "'s scores for each subject (separated by spaces): ";
        for (int j = 0; j < KEMU; ++j) {
            int score;
            cin >> score;
            Scores.push_back(score);
        }
        Stu student(name,Scores);
        students.push_back(student);

    }
    return 0;
}
