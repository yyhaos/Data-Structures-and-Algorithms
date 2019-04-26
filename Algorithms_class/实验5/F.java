package test5;

public class F {
	static int find(int t,int tar[],int len) {
		int l=0,r=len-1,mid;
		while(l<r) {
			mid=(l+r)/2;
			if(t>tar[mid]) {
				l=mid+1;
				continue;
			}
			else if(t<tar[mid]) {
				r=mid-1;
				continue;
			}
			else {
				return mid+1;
			}
		}
		if(tar[l]==t)
			return l+1;
		return 0;
	}
}
