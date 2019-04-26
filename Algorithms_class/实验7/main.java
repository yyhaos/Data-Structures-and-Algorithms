package test7;

import java.util.Arrays;

public class main {
	static int INF=999999999;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		test(500);
	}
	static void test (int n) {
		//int n=100;
		//double max=n;
		int [] a=new int[n];
		System.out.println("大小为"+n+"的原数组：");
		for(int i=0;i<n;i++) {
			a[i]=(int) (Math.random()*1000);
			System.out.print(a[i]+" ");
		}
		System.out.println("\n分别查询第1小到第n小的数：");
		for(int i=1;i<=n;i++) {
			System.out.print(find(a,n,i)+" ");
		}
		System.out.println("\n排好序的原数组：");
		Arrays.sort(a,0,n);
		for(int i=0;i<n;i++) {
			System.out.print(a[i]+" ");
		}
	}
	public static int find(int a[],int n,int k) {
		if(n<=50) {//太小直接找
			Arrays.sort(a, 0, n);
			return a[k-1];
		}
		else {
			int cnt=n/5;
			int []zhong=new int[cnt];
			for(int i=0;i<cnt;i++) {
				Arrays.sort(a, i*5, i*5+5);
				zhong[i]=a[2+i*5];
			}
			int mid=find(zhong,cnt,(cnt+1)/2);//找mid
			
			int a1,a2,a3;
			a1=a2=a3=0;
			int [] A1=new int[n];
			int [] A2=new int[n];
			int [] A3=new int[n];
			for(int i=0;i<n;i++) {//划分
				if(a[i]<mid) {
					A1[a1++]=a[i];
				}
				else if(a[i]==mid) {
					// A2[a2++]=a[i];
					a2++;
				}
				else {
					A3[a3++]=a[i];
				}
			}
			
			if(a1>=k) {//分情况
				return find(A1,a1,k);
			}
			else if(a1+a2>=k) {
				return mid;
			}
			else {
				return find(A3,a3,k-a1-a2);
			}
		}
	}
}
