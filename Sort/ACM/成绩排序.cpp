#include<bits/stdc++.h>
using namespace std;
//Problem    :   http://acm.bnu.edu.cn/bnuoj/problem_show.php?pid=4042
struct student
{
    char name[12];
    char id[15];
    double score;
};

bool cmp(student a, student b)  //  if student a should be lower than student b, return true.
{
    if(a.score != b.score)
        return a.score<b.score;
    else
    {
        //int a_id,b_id, th=0;
        /*int th;
        for(th=0;th<15;th++)
        {
            if(a.id[th]!=b.id[th])
                return a.id[th]<b.id[th];
        }
        */
        //printf("cmp id %s %s %d\n",a.id,b.id,strcmp(a.id,b.id));
        return strcmp(a.id,b.id)>=0;
    }
}

int main ()
{
    int N, i, j;
    struct student s[1005];

    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s %s %lf",s[i].name,s[i].id,&s[i].score);
    }
    //sort(s,s+(N-1)*sizeof(s[0]),cmp);
    for(i=0;i<N-1;i++)
        for(j=0;j<N-i-1;j++)
        {
            //printf("cmp %d %d %d\n",j,j+1,cmp(s[j],s[j+1]));
            if (cmp(s[j],s[j+1]))
                swap(s[j],s[j+1]);
        }

    for(i=0;i<N;i++)
    {
        printf("%s %s %.2f",s[i].name,s[i].id,s[i].score);
        if(i!=N-1)
            printf("\n");
    }
    return 0;
}

