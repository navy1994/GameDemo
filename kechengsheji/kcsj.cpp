#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Student;

class StuNode
{
  public:
    Student* head;
    Student* tail;
    int num;
};

class Student
{
   private:
	   int num;
	   string name;
	   string major;
	   string clas;
	   int math_sc;
	   int English_sc;
	   int C_sc;
   public:
	  Student* creat_stu();
	  int Add_info(StuNode* list,Student* node);
	  int find_mod(StuNode* list,int flag);
	  int Free_Node(StuNode* list);
	  int Read_File(StuNode* list);
	  Student* next;
};

StuNode* creat_node(StuNode* list)
{
    if(list)
    return NULL;
    list=(StuNode*)malloc(sizeof(class StuNode));
    list->head=NULL;
    list->tail=NULL;
    list->num=0;
    return list;
}

Student* Student::creat_stu()
{
   Student* node=(Student*)malloc(sizeof(class Student));
   if(!node)
  return NULL;
   cout<<"\t学号：";
   cin>>node->num;

   cout<<"\t姓名：";
   cin>>node->name;

   cout<<"\t系别：";
   cin>>node->major;

   cout<<"\t班级：";
   cin>>node->clas;

   cout<<"\t高数分数：";
   cin>>node->math_sc;
 
   cout<<"\t英语分数：";
   cin>>node->English_sc;

   cout<<"\tC++分数：";
   cin>>node->C_sc;
   
   node->next = NULL;
   return node;
}

int Student::Add_info(StuNode* list,Student* node) //输入1调用
{
	if(!list||!node)
 	return -1;
 	if(!list->head)
 	{
      list->head = node;
      list->tail = node;
    }
    else
    {
 	  list->tail->next = node;
 	  list->tail=node;
	}
	
	list->num++;
	return 0;
}

int Student::find_mod(StuNode* list,int flag) //查询和修改学生信息  输入2,3调用
{
    int n,mat=0,English=0,Csc=0;
    string maj,cla,name;
    Student *node=list->head,*find=NULL;
    
    if(flag==0) //查询学生信息 
    {
                     cout<<"\t*************************************\n";
                     cout<<"\t*****     1,按系别查询！       ******\n";
                     cout<<"\t*****     2,按班级查询！       ******\n";
                     cout<<"\t*****     3,按高数成绩查询！   ******\n";
                     cout<<"\t*****     4,按英语成绩查询！   ******\n";
                     cout<<"\t*****     5,按C语言成绩查询！  ******\n";
                     cout<<"\t*************************************\n\n"; 
                     cout<<"请输入选项[ ]\b\b";
                 cin>>n;
          if(!list)
          return -1;
          switch(n)
          {
                 case 1:cout<<"\t请输入您要查询学生的系别：";
                        cin>>maj;break;
                 case 2:cout<<"\t请输入您要查询学生的班级：";
                        cin>>cla;break;
                 case 3:cout<<"\t请输入您要查询学生的高数成绩：";
                        cin>>mat;break;
                 case 4:cout<<"\t请输入您要查询学生的英语成绩：";
                        cin>>English;break;
                 case 5:cout<<"\t请输入您要查询学生的C语言成绩：";
                        cin>>Csc;break; 
                 default:cout<<"\t输入错误！\n";
           }
        cout<<"\n\t学号\t姓名\t系别\t班级\t高数\t英语\tC语言\n\n"; 
    }
    
    while(node)
    {
          switch(n)
          {
                case 1:if(!(node->major == maj)) 
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
                case 2:if(!(node->clas == cla))
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
                case 3:if(node->math_sc == mat)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
                case 4:if(node->English_sc == English)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break;
                case 5:if(node->C_sc == Csc)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math_sc<<"\t"<<node->English_sc<<"\t"<<node->C_sc<<endl;
                       break; 
          }
          
           if(flag==1) //修改学生信息 
           {
                cout<<"\t请输入你要修改学生姓名：";
                 cin>>name;
                  if(!(node->name == name))
                  cout<<"\t\t学号：";
                   cin>>node->num;
                  cout<<"\t\t姓名：";
                   cin>>node->name;
                  cout<<"\t\t系别：";
                   cin>>node->major;
                  cout<<"\t\t班级：";
                   cin>>node->clas;
                  cout<<"\t\t高数分数：";
                   cin>>node->math_sc;
                  cout<<"\t\t英语分数：";
                   cin>>node->English_sc;
                  cout<<"\t\tC语言分数：";
                   cin>>node->C_sc;
               break;
           } 
        else
        {
          find = node;
          node = node->next;
        }
      }
    return 0;
}

int menu()
{
    int n;
	cout<<"\t---------------------------------------------\n";
	cout<<"\t----------    成绩管理分析系统     ----------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t----------------    菜单     ----------------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t*****       1,添加学生信息！            *****\n";
	cout<<"\t*****       2,查询学生信息！            *****\n";
	cout<<"\t*****       3,修改学生信息！            *****\n";
	cout<<"\t*****       0,退出该系统！              *****\n";
	cout<<"\t---------------------------------------------\n\n";
	cout<<"请输入选项[ ]\b\b";
    cin>>n;
    return n;
}

int Student::Free_Node(StuNode* list)                  //释放
{
    while(list->head)
    {
          list->tail = list->head;
          list->head = list->head->next;
          free(list->tail);
    }
    
    free(list);
    return 0;
}

int Student::Read_File(StuNode* list)                           //读取文件信息
{
     FILE* fp;
     Student* p = (Student*)malloc(sizeof(class Student));
     
     if((fp = fopen("data","rb")) == NULL)      //打开文件 
            return -1;
      
     while(fread(p,sizeof(class Student),1,fp))
     {
            p->next = NULL;
            Add_info(list,p);
            p = (Student*)malloc(sizeof(class Student));
     }
     
	 fclose(fp);
	 return 0;
}

void Write_File(StuNode* list)            //写入文件 
{
	Student* p = list->head;
    FILE* fp = fopen("data","wb");

	while(p)
	{
	   fwrite(p,sizeof(class Student),1,fp);
	   p = p -> next; 
	}
	
	fclose(fp);
}


int main()
{
	StuNode* list=NULL;
	Student s1;
    string name;
    int n;
    while(!(list=creat_node(list)))
    s1.Read_File(list);
    while(n=menu())
    {
       switch(n)
       {
	     case 1:system("cls");if(s1.Add_info(list,s1.creat_stu())==-1)
                printf("\t\t添加失败\n");
                break;
         case 2:
         case 3:system("cls");s1.find_mod(list,n-2);break; 
         default:system("cls");printf("\t\t输入错误！");
       }
      getchar();
    }
    
    Write_File(list);
	getchar();
    return 0;
}