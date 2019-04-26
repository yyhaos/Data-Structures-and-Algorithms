package test6;

public class main {
	//void test(int n);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int i=2;i<=1024;i*=2) {
			test(i);
		}
		//Matrix.show(a,n);
		//Matrix.show(b,n);
		
	}
	static void test(int n) {
		System.out.println("对"+n+"规模进行测试：");
		int[][] a=new int[n][n];
		int[][] b=new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				a[i][j]=(int) (Math.random()*1000);
				b[i][j]=(int) (Math.random()*1000);
			}
		}
		try {
			long startTime = System.currentTimeMillis(); 
			//Matrix.show(Matrix.multiply(a,b,n),n);
			Matrix.multiply(a,b,n);
			long endTime = System.currentTimeMillis(); 
			System.out.println("st乘法运行时间：" + (endTime - startTime) + "ms");
			startTime = System.currentTimeMillis(); 
			//Matrix.show(Matrix.multiply2(a,b,n),n);
			Matrix.multiply2(a,b,n);
			endTime = System.currentTimeMillis(); 
			System.out.println("普通乘法运行时间：" + (endTime - startTime) + "ms");

			
			
		} catch (Exception e) {
			System.out.println(e.getMessage());
			System.out.println("乘法错误");
		}
	}
}
