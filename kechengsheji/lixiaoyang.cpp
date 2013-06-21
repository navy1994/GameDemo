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
	   char name[10];
	   char major[10];
	   char clas[10];
	   int math;
	   int English;
	   int C;
   public:
	  Student* creat_stu();
	  int Add_info(StuNode* list,Student* node);
	  int find_mod(StuNode* list,int flag);
	  int deleteStu(StuNode* list);
	  int show(StuNode* list);
	  int Free_Node(StuNode* list);
	  int Read_File(StuNode* list);
	  Student* next;
	  friend class StuNode;
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
   cin>>node->math;
 
   cout<<"\t英语分数：";
   cin>>node->English;

   cout<<"\tC++分数：";
   cin>>node->C;
   
   node->next=NULL;
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
    char cla[10],maj[10],name[10];
    Student *node=list->head,*find=NULL;
    
    if(flag==0) //查询学生信息 
    {
                     cout<<"\t*************************************\n";
                     cout<<"\t*****     1,按系别查询！       ******\n";
                     cout<<"\t*****     2,按班级查询！       ******\n";
                     cout<<"\t*****     3,按高数成绩查询！   ******\n";
                     cout<<"\t*****     4,按英语成绩查询！   ******\n";
                     cout<<"\t*****     5,按C语言成绩查询！  ******\n";
                     cout<<"\t*****     6,按学生姓名查询！   ******\n";
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
                 case 6:cout<<"\t请输入您要查询学生的C语言成绩：";
                        cin>>name;break; 
                 default:cout<<"\t输入错误！\n";
           }
        cout<<"\n\t学号\t姓名\t系别\t班级\t高数\t英语\tC语言\n\n"; 
    }
    
    while(node)
    {
          switch(n)
          {
                case 1:if(!strcmp(node->major , maj)) 
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math<<"\t"<<node->English<<"\t"<<node->C<<endl;
                       break;
                case 2:if(!strcmp(node->clas , cla))
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math<<"\t"<<node->English<<"\t"<<node->C<<endl;
                       break;
                case 3:if(node->math == mat)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math<<"\t"<<node->English<<"\t"<<node->C<<endl;
                       break;
                case 4:if(node->English == English)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math<<"\t"<<node->English<<"\t"<<node->C<<endl;
                       break;
                case 5:if(node->C == Csc)
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math<<"\t"<<node->English<<"\t"<<node->C<<endl;
                       break;
                case 6:if(!strcmp(node->name , name))
                       cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math<<"\t"<<node->English<<"\t"<<node->C<<endl;
                       break;
               default:if(flag == 0)cout<<"\t查无此人！\n";
          }
          
           if(flag==1) //修改学生信息   有点问题 
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
                   cin>>node->math;
                  cout<<"\t\t英语分数：";
                   cin>>node->English;
                  cout<<"\t\tC++分数：";
                   cin>>node->C;
               break;
           } 
           
           
           
        else
        {
          find = node;
          node = node->next;
        }   
      }
      getchar();
    return 0;
}

int Student::deleteStu(StuNode* list)
{
       char name[10];
       Student *node=list->head,*q=NULL;
       cout<<"\t请输入你要删除学生姓名：";
       cin>>name; 
       if(node==NULL)
       return 0;
         if(!(node->name == name))
         {
                    list->head = node->next;
                    delete node;
                    cout<<"已经成功删除该学生信息！\n";
         }
         else
         {
                 while(node->name != name&&node->next!=NULL)
                 {
                              q = node;  
                              node = node->next;          
                 }   
                            
                 if(node->name == name)
                 {
                             q->next=node->next;
                             delete node;
                       cout<<"已经成功删除该学生信息！\n";
                 }
         }
         
   getchar();
   return 0;
}

int Student::show(StuNode* list)
{
    Student *node=list->head,*q=NULL;
    int n=0;
    if(!n)
    {
      cout<<"\n\t学号\t姓名\t系别\t班级\t高数\t英语\tC语言\n\n"; 
      n++;
    }
    while(node)
    {
      cout<<"\t"<<node->num<<"\t"<<node->name<<"\t"<<node->major<<"\t"<<node->clas<<
					   "\t"<<node->math<<"\t"<<node->English<<"\t"<<node->C<<endl;
    q = node;  
    node = node->next;
    }  
    getchar();
    return 0;
}

int menu()
{
    int n;
    system("cls"); 
	cout<<"\t---------------------------------------------\n";
	cout<<"\t----------    成绩管理分析系统     ----------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t----------------    菜单     ----------------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t*****       1,添加学生信息！            *****\n";
	cout<<"\t*****       2,查询学生信息！            *****\n";
	cout<<"\t*****       3,修改学生信息！            *****\n";
	cout<<"\t*****       4,删除学生信息！            *****\n";
	cout<<"\t*****       5,显示所有学生信息！        *****\n";
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
                cout<<"\t\t添加失败\n";
                break;
         case 2:
         case 3:system("cls");s1.find_mod(list,n-2);break; 
         case 4:system("cls");
                s1.deleteStu(list);break;
         case 5:system("cls");s1.show(list);break;
         default:system("cls");cout<<"\t\t输入错误！";
       }
      getchar();
    }
    
    Write_File(list);
	getchar();
    return 0;
}
