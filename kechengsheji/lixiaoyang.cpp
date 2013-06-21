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
   cout<<"\tѧ�ţ�";
   cin>>node->num;

   cout<<"\t������";
   cin>>node->name;

   cout<<"\tϵ��";
   cin>>node->major;

   cout<<"\t�༶��";
   cin>>node->clas;

   cout<<"\t����������";
   cin>>node->math;
 
   cout<<"\tӢ�������";
   cin>>node->English;

   cout<<"\tC++������";
   cin>>node->C;
   
   node->next=NULL;
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
    char cla[10],maj[10],name[10];
    Student *node=list->head,*find=NULL;
    
    if(flag==0) //��ѯѧ����Ϣ 
    {
                     cout<<"\t*************************************\n";
                     cout<<"\t*****     1,��ϵ���ѯ��       ******\n";
                     cout<<"\t*****     2,���༶��ѯ��       ******\n";
                     cout<<"\t*****     3,�������ɼ���ѯ��   ******\n";
                     cout<<"\t*****     4,��Ӣ��ɼ���ѯ��   ******\n";
                     cout<<"\t*****     5,��C���Գɼ���ѯ��  ******\n";
                     cout<<"\t*****     6,��ѧ��������ѯ��   ******\n";
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
                 case 6:cout<<"\t��������Ҫ��ѯѧ����C���Գɼ���";
                        cin>>name;break; 
                 default:cout<<"\t�������\n";
           }
        cout<<"\n\tѧ��\t����\tϵ��\t�༶\t����\tӢ��\tC����\n\n"; 
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
               default:if(flag == 0)cout<<"\t���޴��ˣ�\n";
          }
          
           if(flag==1) //�޸�ѧ����Ϣ   �е����� 
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
                   cin>>node->math;
                  cout<<"\t\tӢ�������";
                   cin>>node->English;
                  cout<<"\t\tC++������";
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
       cout<<"\t��������Ҫɾ��ѧ��������";
       cin>>name; 
       if(node==NULL)
       return 0;
         if(!(node->name == name))
         {
                    list->head = node->next;
                    delete node;
                    cout<<"�Ѿ��ɹ�ɾ����ѧ����Ϣ��\n";
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
                       cout<<"�Ѿ��ɹ�ɾ����ѧ����Ϣ��\n";
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
      cout<<"\n\tѧ��\t����\tϵ��\t�༶\t����\tӢ��\tC����\n\n"; 
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
	cout<<"\t----------    �ɼ��������ϵͳ     ----------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t----------------    �˵�     ----------------\n";
	cout<<"\t---------------------------------------------\n";
	cout<<"\t*****       1,���ѧ����Ϣ��            *****\n";
	cout<<"\t*****       2,��ѯѧ����Ϣ��            *****\n";
	cout<<"\t*****       3,�޸�ѧ����Ϣ��            *****\n";
	cout<<"\t*****       4,ɾ��ѧ����Ϣ��            *****\n";
	cout<<"\t*****       5,��ʾ����ѧ����Ϣ��        *****\n";
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
                cout<<"\t\t���ʧ��\n";
                break;
         case 2:
         case 3:system("cls");s1.find_mod(list,n-2);break; 
         case 4:system("cls");
                s1.deleteStu(list);break;
         case 5:system("cls");s1.show(list);break;
         default:system("cls");cout<<"\t\t�������";
       }
      getchar();
    }
    
    Write_File(list);
	getchar();
    return 0;
}
