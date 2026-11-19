#include <stdio.h>
long long calls;
long long power_linear(long long b,int e){calls++;if(e==0)return 1;return b*power_linear(b,e-1);}
long long power_fast(long long b,int e){calls++;if(e==0)return 1;long long h=power_fast(b,e/2);return (e%2)?h*h*b:h*h;}
int digital_root(int n){if(n<0)n=-n;if(n<10)return n;int s=0;while(n){s+=n%10;n/=10;}return digital_root(s);}
int main(void){calls=0;long long x=power_linear(2,30);printf("linear: %lld in %lld calls\\n",x,calls);calls=0;long long v=power_fast(2,30);printf("fast : %lld in %lld calls\\n",v,calls);printf("digital root 9875 = %d\\n",digital_root(9875));return 0;}
