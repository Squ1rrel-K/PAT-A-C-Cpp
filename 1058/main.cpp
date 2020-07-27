#include<cstdio>
#include<cstring>
int main(){
    long long  a,b,c,x,y,z;
    scanf("%lld.%lld.%lld %lld.%lld.%lld",&a,&b,&c,&x,&y,&z);
    long long sum = a*29*17 + b*29 + c + x*29*17 + y*29 + z;
    printf("%lld.%lld.%lld\n",sum/(29*17),sum%(17*29)/29,sum%(17*29)%29);
    return 0;
}