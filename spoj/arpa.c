#include<stdio.h>
int main()  
{  
    long long x1,y1,x2,y2,x3,y3,k1,k2,d1,d2;  
    scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);  
    d1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);  
    d2=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);  
    if(d1!=d2)  
    {  
        printf("No\n");  
        return 0;  
    }  
    if((x2-x3)*(y1-y2)==(x1-x2)*(y2-y3))  
    {  
        printf("No\n");  
    }  
    else  
        printf("Yes\n");  
    return 0;  
}  
