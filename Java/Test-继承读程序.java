class A{
    int t=1;
    double f(double x,double y){
        t=t*t;
        return  x+y+t;
    }
    static  int g(int n){
        return n*n;
    }
}
class B extends A{
    int t=2;
    double f(double x,double y){
        double m=super.f(x,y);
        System.out.println(t);
        return  m+x*y+super.t;
    }
    static int g(int n){
        int m=A.g(n);
        return m+n;
    }
}

public class Test {
    public static void main(String[] args) {
        B b=new B();
        System.out.println(b.f(10.0,8.0));
        System.out.println(b.g(3));
        A a=new B();
        System.out.println(a.t);
        System.out.println(a.f(10.0,8.0));
        System.out.println(a.g(3));
    }
}
