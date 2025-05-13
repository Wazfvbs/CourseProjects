package test;

public class Ta1 {
	static int i=10;
	int t;
	
	{
		t=1;
		System.out.println("111111111111");
		
	}
	
	static {
		i=20;
		System.out.println("222222222");
	}
	
	public Ta1() {
		System.out.println("3333333333");
	}
	
	static void f() {
		System.out.println(i);
		//System.out.println(t);
	}
	
	void g() {
		System.out.println(i);
		System.out.println(t);
		
	}

}
