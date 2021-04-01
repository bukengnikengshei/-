//powered by 631 
#include "bits/stdc++.h"
using namespace std;
int main()
{
    printf("标准差及不确定度计算——by631\n");
	float a[10],avg=0,avb,avba,avc[10],avd=0,s,ua,ub,u,tp;
    float t[3][10]={{1.84,1.32,1.20,1.14,1.11,1.09,1.08,1.07,1.06,1.03},{12.71,4.30,3.18,2.78,2.57,2.45,2.36,2.31,2.26,2.09},{63.66,9.92,5.84,4.60,4.03,3.71,3.50,3.36,3.26,2.86}};
    int i,j=0,n=0,z;
    printf("输入组数(n)\n");
    scanf("%d",&i);
    printf("输入详细数据(空格隔开)\n");
    for(j=0;j<i;j++)
    {
    scanf("%f",&a[j]);
    avg=avg+a[j];
    }
    avg=avg/i;
    for(j=0;j<i;j++)
    {
        avb=a[j]-avg;
        if(avb>=avba)
        {
    	    avba=avb;
	    }
	    else if(-avb>=avba)
	    {
	    	avba=-avb;
		}
        avc[j]=avb*avb;
    }
    for(j=0;j<i;j++)
    {
    	avd=avd+avc[j];
	}
    avd=avd/(i-1);
    s=sqrt(avd);
    if(3*s>avba) n=1;
    printf("平均值%f\n试验标准差%f\n最大残差%f\n",avg,s,avba);
    if(n=1) printf("无粗大误差\n");
    else printf("有粗大误差\n");
    printf("输入取信度（95or86or99）\n");
    scanf("%d",&z) ;
    if(z==68&&i<=10)tp=t[0][i-2];
    if(z==95&&i<=10)tp=t[1][i-2];
    if(z==99&&i<=10)tp=t[2][i-2];
    if(z==68&&i==20)tp=t[0][9];
    if(z==95&&i==20)tp=t[1][9];
    if(z==99&&i==20)tp=t[2][9];
	ua=tp*s;
    printf("输入b类不确定度(误差极限)\n");
    scanf("%f",&ub);
	u=sqrt(ua*ua+ub*ub);
	printf("总不确定度为%f \n（按任意键退出）",u);
	system("pause") ;
    return 0;
}
