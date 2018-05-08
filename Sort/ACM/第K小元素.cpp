#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=4182
int main ()
{
	map <int , int > th;
	int n , k ;
	scanf("%d%d",&n,&k);
	int a[n];
	for(int i = 0 ; i<n;i++)
	{
		scanf("%d",&a[i]);
		th[a[i]]=i;
	}
	sort(a,a+n);
	printf("%d %d",a[k-1],th[a[k-1]]);
	return 0;
}
