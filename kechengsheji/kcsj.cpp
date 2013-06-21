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
   cout<<"\tѧ�ţ�";
   cin>>node->num;

   cout<<"\t������";
   cin>>node->name;

   cout<<"\tϵ��";
   cin>>node->major;

   cout<<"\t�༶��";
   cin>>node->clas;

   cout<<"\t����������";
   cin>>node->math_sc;
 
   cout<<"\tӢ�������";
   cin>>node->English_sc;

   cout<<"\tC++������";
   cin>>node->C_sc;
   
   node->next = NULL;
   return node;
}

int Student::Add_info(StuNode* list,Student* node) //����1����
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

int Student::find_mod(StuNode* list,int flag) //��ѯ���޸�ѧ����Ϣ  ����2,3����
{
    int n,mat=0,English=0,Csc=0;
    string maj,cla,name;
    Student *node=list->head,*find=NULL;
    
    if(flag==0) //��ѯѧ����Ϣ 
    {
                     cout<<"\t*************************************\n";
                     cout<<"\t*****     1,��ϵ���ѯ��       ******\n";
                     cout<<"\t*****     2,���༶��ѯ��       ******\n";
                     cout<<"\t*****     3,�������ɼ���ѯ��   ******\n";
                     cout<<"\t*****     4,��Ӣ��ɼ���ѯ��   ******\n";
                     cout<<"\t*****     5,��C���Գɼ���ѯ��  ******\n";
                     cout<<"\t*************************************\n\n"; 
                     cout<<"������ѡ��[ ]\b\b";
                 cin>>n;
          if(!list)
          return -1;
          switch(n)
          {
                 case 1:cout<<"\t��������Ҫ��ѯѧ����ϵ��";
                        cin>>maj;break;
                 case 2:cout<<"\t��������Ҫ��ѯѧ���İ༶��";
                        cin>>cla;break;
                 case 3:cout<<"\t��������Ҫ��ѯѧ���ĸ����ɼ���";
                        cin>>mat;break;
                 case 4:cout<<"\t��������Ҫ��ѯѧ����Ӣ��ɼ���";
                        cin>>English;break;
                 case 5:cout<<"\t��������Ҫ��ѯѧ����C���Գɼ���";
                        cin>>Csc;break; 
                 default:cout<<"\t�������\n";
           }
        cout<<"\n\tѧ��\t����\tϵ��\t�༶\t����\tӢ��\tC����\n\n"; 
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
          
           if(flag==1) //�޸�ѧ����Ϣ 
           {
                cout<<"\t��������Ҫ�޸�ѧ��������";
                 cin>>name;
                  if(!(node->name == name))
                  cout<<"\t\tѧ�ţ�";
                   cin>>node->num;
                  cout<<"\t\t������";
                   cin>>node->name;
                  cout<<"\t\tϵ��";
                   cin>>node->major;
                  cout<<"\t\t�༶��";
                   cin>>node->clas;
                  cout<<"\t\t����������";
                   cin>>node->math_sc;
                  cout<<"\t\tӢ�������";
                   cin>>node->English_sc;
                  cout<<"\t\tC���Է�����";
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
	cout<<"\t----------    �ɼ��������ϵͳ     ----------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t----------------    �˵�     ----------------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t*****       1,���ѧ����Ϣ��            *****\n";
	cout<<"\t*****       2,��ѯѧ����Ϣ��            *****\n";
	cout<<"\t*****       3,�޸�ѧ����Ϣ��            *****\n";
	cout<<"\t*****       0,�˳���ϵͳ��              *****\n";
	cout<<"\t---------------------------------------------\n\n";
	cout<<"������ѡ��[ ]\b\b";
    cin>>n;
    return n;
}

int Student::Free_Node(StuNode* list)                  //�ͷ�
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

int Student::Read_File(StuNode* list)                           //��ȡ�ļ���Ϣ
{
     FILE* fp;
     Student* p = (Student*)malloc(sizeof(class Student));
     
     if((fp = fopen("data","rb")) == NULL)      //���ļ� 
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

void Write_File(StuNode* list)            //д���ļ� 
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
                printf("\t\t���ʧ��\n");
                break;
         case 2:
         case 3:system("cls");s1.find_mod(list,n-2);break; 
         default:system("cls");printf("\t\t�������");
       }
      getchar();
    }
    
    Write_File(list);
	getchar();
    return 0;
}