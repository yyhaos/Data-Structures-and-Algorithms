#include<iostream>
#include <stdio.h>
#include <malloc.h>
#include <fstream>
#include <string>
using namespace std;
int priority(int type,const int operate) //type=1 isp    type=2 icp
{
    if(type==1)
    {
        switch(operate)
        {
            case '#':return 0;
            case '(':return 1;
            case '^':return 7;
            case '*':return 5;
            case '/':return 5;
            case '%':return 5;
            case '+':return 3;
            case '-':return 3;
            case ')':return 8;
        }
    }
    else
    {
        switch(operate)
        {
            case '#':return 0;
            case '(':return 8;
            case '^':return 6;
            case '*':return 4;
            case '/':return 4;
            case '%':return 4;
            case '+':return 2;
            case '-':return 2;
            case ')':return 1;
        }
    }
}
int trans(string a,int len) //�ַ���ת����
{
    int ans=0;
    for(int i=0;i<len;i++)
    {
        ans*=10;
        ans+=a[i]-'0';
    }
    return ans;
}
typedef struct node {            //ջ����
     int Data;
     struct node *link;            //�������ָ��
} LinkNode, *LinkStack;      //��ʽջ
bool Push ( LinkStack& S,int tmpD);
void initStack ( LinkStack& S )
{   //ջ��ʼ��
    S = NULL;	       //�ÿ�ջ
    Push(S,'#');
}

bool stackEmpty ( LinkStack& S )
{    //��ջ�շ�
     return S == NULL;
}
int power(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans*=a;
        }
        b/=2;
        a=a*a;
    }
    return ans;
}
bool Push ( LinkStack& S,int tmpD)
{  //��ջ
     LinkNode *p = (LinkNode *) malloc ( sizeof(LinkNode )); 		           //�����½��
     if ( p == NULL )
         { printf ("��㴴��ʧ��!\n");  exit (1); }
     p->Data = tmpD;  			     	//��㸳ֵ
     p->link = S;
     S = p;
     //printf("In : %d\n",tmpD);
     return true;     //����ջ��
}

bool Pop ( LinkStack& S, int & x ) {    //��ջ
     if ( stackEmpty(S) ) return false;
     LinkNode * p = S;
     x = p->Data;
     S = p->link; 	    //ժ��ԭջ��
     free (p);

     //printf("Out : %d\n",x);
     return true; 	 	//�ͷ�ԭջ�����
}

bool getTop ( LinkStack& S, int& x ) {
//��ջ��Ԫ��
     if ( stackEmpty (S) ) return false;
     x = S->Data;  return true;
}

void Print(LinkStack &S,int type)
{
    if(type==1)
    {
        if(S==NULL)
            return;
        Print(S->link,type);
        if(S->Data!=35)
            printf("_%d",S->Data);
    }
    else
    {
        if(S==NULL)
            return;
        Print(S->link,type);
        if(S->Data!='#')
            printf("_%c",S->Data);
        else
            printf("%c",S->Data);
    }
}

int main ()
{
    int ans;
    ifstream OpenFile("test.txt");    //�����ļ������ֲ�ͬ�Ķ���
    string str;

    while(getline(OpenFile,str))
    {
        LinkStack OPTR,OPND;
        initStack(OPTR);
        initStack(OPND);
        cout<<"��ʽ��"<<str<<endl;
//        str[str.length()+1]='\0';
//        str[str.length()]='#';
        int i=0;
        while(1)
        {
            if(str[i]=='\0')
                str[i]='#';
            //printf("i=%d\n",i);
            if(str[i]>='0' && str[i] <='9')
            {
                int j;
                for(j=0;str[i+j];j++)
                {
                    if(str[i+j]>='0' && str[i+j]<='9')
                        continue;
                    break;
                }
                string tmp=str.substr(i,j);
                //cout<<tmp<<endl;
                int num=trans(tmp,j);
                Push(OPND,num);
                printf("Case:��������\t��ȡ��ֵΪ [%d]\tֱ�ӽ�OPNDջ\n",num);
                printf("OPND:#");
                Print(OPND,1);
                printf("\n");
                //cout<<num<<endl;


                i+=j;
            }
            else
            {

                int top;
                Pop(OPTR,top);
                printf("Case:����������\t��ȡ������Ϊ [%c]\t��OPTR��topԪ��[%c]�Ƚ�\t�����",str[i],top);
                //printf("%c %d vs %c %d\n",str[i],str[i],top,top);
                if(priority(1,top) < priority(2,str[i]))
                {
                    printf("ֱ�ӽ�OPTRջ\n");
                    Push(OPTR,top);
                    Push(OPTR,str[i]);
                    i++;
                }
                else if(priority(1,top) > priority(2,str[i]))
                {
                    int num1,num2;
                    Pop(OPND,num2);
                    Pop(OPND,num1);
                    switch(top)
                    {
                        case '+':num1=num1+num2;break;
                        case '^':num1=power(num1,num2);break;
                        case '*':num1=num1*num2;break;
                        case '/':num1=num1/num2;break;
                        case '%':num1=num1%num2;break;
                        case '-':num1=num1-num2;break;
                    }
                    Push(OPND,num1);
                    printf("ȡ����������%c���� �����OPNDջ\n",top);
                    printf("OPND:#");
                    Print(OPND,1);
                    printf("\n");
                }
                else
                {
                    if(str[i]==')')
                    {
                        printf("���������໥������ ����\n");
                        i++;
                        continue;
                    }
                    else
                    {
                        printf("����#���໥������ ֹͣ\n");
                        break;
                    }
                }
                printf("OPTR:");
                Print(OPTR,2);
                printf("\n");
            }
        }
        Pop(OPND,ans);
        printf("�������:");
        cout<<str;
        printf("=%d\n--------\n",ans);
    }

    printf("����\"test.txt\"����ʽ����ȷ��:\n");
    printf("��ȷ����:2^(3+7)+10000/20=%d\n",power(2,(3+7))+10000/20);
    printf("��ȷ����:((11-22)*44)*(55-66)=%d\n",((11-22)*44)*(55-66));
    printf("��ȷ����:(3+5)%3*4=%d\n",(3+5)%3*4);
    return 0;
}

