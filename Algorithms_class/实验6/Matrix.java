package test6;

public class Matrix {
	static int [][] minus(int [][] p,int [][]q , int n ) {
		int M[][]=new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				M[i][j]=p[i][j]-q[i][j];
			}
		}
		return M;
	}
	static int [][] add(int [][] p,int [][]q , int n ) {
		int M[][]=new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				M[i][j]=p[i][j]+q[i][j];
			}
		}
		return M;
	}
	static int [][] together(int[][] a11,int [][] a12,int[][] a21,int [][] a22,int n) {
		int [][] M=new int[n*2][n*2];
		for(int i=0;i<n*2;i++) {
			for(int j=0;j<n*2;j++) {
				if(i<n && j<n) {
					M[i][j]=a11[i][j];
				}
				if(i<n && j>=n) {
					M[i][j]=a12[i][j-n];
				}
				if(i>=n && j<n) {
					M[i][j]=a21[i-n][j];
				}
				if(i>=n && j>=n) {
					M[i][j]=a22[i-n][j-n];
				}
			}
		}
		return M;
	}
	static int [][] M11(int [][]p,int n) {
		int [][] ans=new int [n/2][n/2];
		for(int i=0;i<n/2;i++) {
			for(int j=0;j<n/2;j++) {
				ans[i][j]=p[i][j];
			}
		}
		return ans;
	}
	static int [][] M12(int [][]p,int n) {
		int [][] ans=new int [n/2][n/2];
		for(int i=0;i<n/2;i++) {
			for(int j=0;j<n/2;j++) {
				ans[i][j]=p[i][n/2+j];
			}
		}
		return ans;
	}
	static int [][] M21(int [][]p,int n) {
		int [][] ans=new int [n/2][n/2];
		for(int i=0;i<n/2;i++) {
			for(int j=0;j<n/2;j++) {
				ans[i][j]=p[n/2+i][j];
			}
		}
		return ans;
	}
	static int [][] M22(int [][]p,int n) {
		int [][] ans=new int [n/2][n/2];
		for(int i=0;i<n/2;i++) {
			for(int j=0;j<n/2;j++) {
				ans[i][j]=p[n/2+i][n/2+j];
			}
		}
		return ans;
	}
	static int [][] multiply (int [][]p,int[][]q,int n){
		int size=n;
//		if(size!=p.size || size<=0)
//		{
//			//throw new Exception("¾ØÕó³Ë·¨´íÎó£¬³ö´íµÄ¾ØÕó´óĞ¡£º"+String.valueOf(size) );
//			System.out.println("¾ØÕó³Ë·¨´íÎó ´íÎó¾ØÕó´óĞ¡Îª£º"+size+" ºÍ "+b.size);
//			return new Matrix();
//		}
		if(size<=2) {
			return multiply2(p,q,n);
		}
		if(size>=4) {
			int[][] a11=M11(p,n);
			int[][] a12=M12(p,n);
			int[][] a21=M21(p,n);
			int[][] a22=M22(p,n);
			int[][] b11=M11(q,n);
			int[][] b12=M12(q,n);
			int[][] b21=M21(q,n);
			int[][] b22=M22(q,n);
			
			
			int[][] m1=multiply(a11,minus(b12,b22,n/2),n/2);
			int[][] m2=multiply(add(a11,a12,n/2),b22,n/2);
			int[][] m3=multiply(add(a21,a22,n/2),b11,n/2);
			int[][] m4=multiply(a22,minus(b21,b11,n/2),n/2);
			int[][] m5=multiply(add(a11,a22,n/2),add(b11,b22,n/2),n/2);
			int[][] m6=multiply(minus(a12,a22,n/2),add(b21,b22,n/2),n/2);
			int[][] m7=multiply(minus(a11,a21,n/2),add(b11,b12,n/2),n/2);
			
			int[][] ans=new int[n][n];
			ans=together(add(minus(add(m5,m4,n/2),m2,n/2),m6,n/2),
					add(m1,m2,n/2),
					add(m3,m4,n/2),
					minus(minus(add(m5,m1,n/2),m3,n/2),m7,n/2),
					n/2);
			
			return ans;
		}
		return new int[1][1];
	}
	static int [][] multiply2 (int [][]p,int[][]q,int n){
		int[][] ans=new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				ans[i][j]=0;
				for(int k=0;k<n;k++) {
					ans[i][j]+=p[i][k]*q[k][j];
				}
			}
		}
		return ans;
	}
	static void show(int a[][],int size) {
		System.out.println("¾ØÕó´óĞ¡Îª£º"+size);
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++) {
				System.out.print(a[i][j]+" ");
			}
			System.out.println("");
		}
	}
}
