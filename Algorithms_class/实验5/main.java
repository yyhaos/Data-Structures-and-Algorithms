package test5;

import java.io.IOException;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int l=10;
		int tar[]=new int[l+5];
		tar[0]=(int) (1+Math.random()*10.0%3);
		for(int i=1;i<l;i++)
			tar[i]=(int)(1+Math.random()*10%3)+tar[i-1];
		System.out.println("数组为：");
		for(int i=0;i<l;i++)
			System.out.print(tar[i]+" ");
		System.out.println("\n共"+l+"个数");
		while(true) {
			System.out.println("输入想要查询的数");
			byte []bt = new byte[10000];
			int len=0;
			try {
				len = System.in.read(bt);
			} catch (IOException e) {
				System.out.println("输入数字过长");
				continue;
			}
			String str=new String(bt).substring(0,len-2);
			int t=0;
			try {
				t=Integer.parseInt(str);
			}catch(Exception e) {
				System.out.println("输入数字格式错误 重新输入一个整数");
				continue;
			}
			int ans=F.find(t,tar,l);
			if(ans>0)
			System.out.println(t+"在数组的第"+F.find(t,tar,l)+"位");
			else
				System.out.println(t+"在数组没有找到");
			
			
		}
	}

}
