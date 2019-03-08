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
int trans(string a,int len) //字符串转数字
{
    int ans=0;
    for(int i=0;i<len;i++)
    {
        ans*=10;
        ans+=a[i]-'0';
    }
    return ans;
}
typedef struct node {            //栈定义
     int Data;
     struct node *link;            //结点链接指针
} LinkNode, *LinkStack;      //链式栈
bool Push ( LinkStack& S,int tmpD);
void initStack ( LinkStack& S )
{   //栈初始化
    S = NULL;	       //置空栈
    Push(S,'#');
}

bool stackEmpty ( LinkStack& S )
{    //判栈空否
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
{  //进栈
     LinkNode *p = (LinkNode *) malloc ( sizeof(LinkNode )); 		           //创建新结点
     if ( p == NULL )
         { printf ("结点创建失败!\n");  exit (1); }
     p->Data = tmpD;  			     	//结点赋值
     p->link = S;
     S = p;
     //printf("In : %d\n",tmpD);
     return true;     //链入栈顶
}

bool Pop ( LinkStack& S, int & x ) {    //退栈
     if ( stackEmpty(S) ) return false;
     LinkNode * p = S;
     x = p->Data;
     S = p->link; 	    //摘下原栈顶
     free (p);

     //printf("Out : %d\n",x);
     return true; 	 	//释放原栈顶结点
}

bool getTop ( LinkStack& S, int& x ) {
//看栈顶元素
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
    ifstream OpenFile("test.txt");    //两种文件有两种不同的定义
    string str;

    while(getline(OpenFile,str))
    {
        LinkStack OPTR,OPND;
        initStack(OPTR);
        initStack(OPND);
        cout<<"算式是"<<str<<endl;
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
                printf("Case:遇到数字\t读取数值为 [%d]\t直接进OPND栈\n",num);
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
                printf("Case:遇到操作符\t读取操作符为 [%c]\t与OPTR的top元素[%c]比较\t结果是",str[i],top);
                //printf("%c %d vs %c %d\n",str[i],str[i],top,top);
                if(priority(1,top) < priority(2,str[i]))
                {
                    printf("直接进OPTR栈\n");
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
                    printf("取两个数进行%c运算 后进入OPND栈\n",top);
                    printf("OPND:#");
                    Print(OPND,1);
                    printf("\n");
                }
                else
                {
                    if(str[i]==')')
                    {
                        printf("左右括号相互抵消后 继续\n");
                        i++;
                        continue;
                    }
                    else
                    {
                        printf("都是#号相互抵消后 停止\n");
                        break;
                    }
                }
                printf("OPTR:");
                Print(OPTR,2);
                printf("\n");
            }
        }
        Pop(OPND,ans);
        printf("程序答案是:");
        cout<<str;
        printf("=%d\n--------\n",ans);
    }

    printf("给出\"test.txt\"里算式的正确答案:\n");
    printf("正确答案是:2^(3+7)+10000/20=%d\n",power(2,(3+7))+10000/20);
    printf("正确答案是:((11-22)*44)*(55-66)=%d\n",((11-22)*44)*(55-66));
    printf("正确答案是:(3+5)%3*4=%d\n",(3+5)%3*4);
    return 0;
}

