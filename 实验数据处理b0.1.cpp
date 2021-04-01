//powered by 631 
#include "bits/stdc++.h"
using namespace std;

int bzc(int g)//求和、平均值、标准差 
{
	
	int i,j,n=0; 
	printf("输入组数(n)\n");
    scanf("%d",&i);
	float a[100],avg=0,avb,avba,avc[100],avd=0,s;
    printf("输入详细数据(空格隔开)\n");
    for(j=0;j<i;j++)
    {
    scanf("%f",&a[j]);
    avg=avg+a[j];
    }
    printf("和\n",avg);
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
    printf("平均值%f\n试验标准差%f\n",avg,s);
    return 0; 
}

int bqd(int g)
{
    float a[100],avg=0,avb,avba,avc[100],avd=0,s,ua,ub,u,tp;
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
	printf("总不确定度为%f \n",u); 
	return 0; 
	} 



int main()
{
    int wdnmd=0;
	printf("欢迎使用实验数值计算系统——by631\n");
    printf("求和、平均值、标准差输入 1 \n求测量值的不确定值输入 2\n");
    scanf("%d",&wdnmd);
    if(wdnmd==1) bzc(wdnmd);
    if(wdnmd==2) bqd(wdnmd);
    printf("按任意键提出 \n"); 
    system("pause") ;
    return 0;
}

//版本日志
//alpha1.0 实现初代基本功能
//alpha1.5 优化运行结束后停滞功能 
//beta 0.1 完成模块化设计，为之后新功能留出接口 
