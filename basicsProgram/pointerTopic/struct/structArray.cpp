//**************************
// Author:  yh
// Time:    2022/3/12
//**************************
#include <stdio.h>
#include <vector>
#include <string>

// 1.����ṹ������ ���ҳ�ʼ��
/*struct �ṹ����
{
    ��Ա�б�
}������[���鳤��];*/

/*struct �ṹ����
{
    ��Ա�б�
}������[���鳤��] = {��ʼֵ};*/
// 2.�ȶ���һ���ṹ������ ��ȥ����ṹ������
// �ṹ������ ������[���鳤��]

//�Խṹ�������ʼ�� �ڶ������������� = {��ʼֵ};
#define NUM 5
struct Student {
  int num;
  char name[20];
  int socre;
  Student() = default;
  Student(const Student &stu) {
  
  }
  Student &operator=(const Student &stu) {
  
  }
};

class MyStudent {
public:
    std::vector<Student> myStudent;
};

int main() {
//    struct Student std[NUM] = {
//        {10101, "zhang", 78},
//        {10102, "wang", 56},
//        {10103, "li", 34},
//        {10104, "zhao", 79},
//        {10105, "liu", 12},
//    };
//    struct Student temp;
    // bubble sort
//    for(int i = NUM - 1; i > 0; --i) {
//        bool flag = false;
//        for(int j = 1; j <= i; ++j) {
//            if(std[j].socre < std[j - 1].socre) {
//                temp = std[j - 1];
//                std[j - 1] = std[j];
//                std[j] = temp;
//                flag = true;
//            }
//        }
//        if(!flag) {
//            break;
//        }
//    }
//
    MyStudent myStudent;
    myStudent.myStudent =
        {
            {
                78,
                "hello",
                36,
            }
        };

//    for (auto s: std1) {
//        printf("%d, %s, %d\n", s.num, s.name, s.socre);
//    }
    return 0;
}
