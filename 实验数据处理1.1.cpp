//powered by 631
//bug report mcw18500606700@163.com 

#include "bits/stdc++.h"
using namespace std;

float shujuzu[10][21];
float t[3][10]={{1.84,1.32,1.20,1.14,1.11,1.09,1.08,1.07,1.06,1.03},{12.71,4.30,3.18,2.78,2.57,2.45,2.36,2.31,2.26,2.09},{63.66,9.92,5.84,4.60,4.03,3.71,3.50,3.36,3.26,2.86}};
float avgchamax,ub;
int z;
int bj=0;

float pingjunzhi(int j,int i)//平均值计算函数  pingjunzhi(int j,int i) 返回一组数据的平均值 
{
	float avg=0;
	int i0;
    for(i0=0;i0<i;i0++)
    {
    avg=avg+shujuzu[j][i0];
    }
    avg=avg/i;
    return avg;
}

float biaozhuncha(int j,int i,int n)//标准差  biaozhuncha(int j,int i,int n) n=1返回标准差  n=2返回最大平均值差  n=3返回平均值的实验标准差 
{
	float avg=pingjunzhi(j,i),avgcha=0,avgfangcha[i],avgfangchahe=0,s1,s2;
	int i0;
	for(i0=0;i0<i;i0++)
    {
        avgcha=shujuzu[j][i0]-avg;
        if(avgcha>=avgchamax)
        {
    	    avgchamax=avgcha;
	    }
	    else if(-avgcha>=avgchamax)
	    {
	    	avgchamax=-avgcha;
		}
        avgfangcha[i0]=avgcha*avgcha;
    }
    for(i0=0;i0<i;i0++)
    {
    	avgfangchahe=avgfangchahe+avgfangcha[i0];
	}
    avgfangchahe=avgfangchahe/(i-1);
    s1=sqrt(avgfangchahe);
    s2=s1/sqrt(i);
	if (n==1) return s1;
	if (n==2) return avgchamax;
	if (n==3) return s2;
}

int cudawucha(int j,int i)//粗大误差  cudawucha(int j,int i) 1为有 0为无 
{
	float s=biaozhuncha(j,i,1),avgchamax=biaozhuncha(j,i,2);
	int n=1;
	if(3*s>avgchamax) n=0;
	return n;
}

float zhongbuqiudingdu(int j,int i)//计算总不确定度  zhongbuqiudingdu(int j,int i) 返回总不确定度
{
	float tp,s=biaozhuncha(j,i,3),ua,u; 
	
	if (bj==0)
	{
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
        bj=1;
	}
	u=sqrt(ua*ua+ub*ub);
	return u;
}

float qiudao(float a,int x,int n) //求导，输入系数a与指数值 返回求导后的系数值（n=1）指数值（n=2）
{
	a=a*x;
	x=x-1;
	if (n==1) return a;
	if (n==2) return x;
} 

float piaodao(int j,int i)//
{
	int z[3],n,n0,n1,zj;
	float a[3],avg[3],y[3],s[3],aj,u;
	n=j;
	for(n0=0;n0<n;n0++)
	{
		printf("请输入第%d个变量前的系数:",n0+1);
	    scanf("%f",&a[n0]);
	    printf("请输入第%d个变量上的指数:",n0+1);
	    scanf("%d",&z[n0]);
	}
	for(n0=0;n0<n;n0++)
	{
		avg[n0]=pingjunzhi(n0,i);
	}	
	for(n0=0;n0<n;n0++)
	{
		aj=a[n0];
		zj=z[n0];
		a[n0]=qiudao(a[n0],z[n0],1);
		z[n0]=qiudao(a[n0],z[n0],2);
		for(n1=0,y[n0]=1;n1<n;n1++)
		{
			y[n0]=y[n0]*a[n1]*pow(avg[n1],z[n1]);
		}
		a[n0]=aj;
		z[n0]=zj;
		printf("第%d个不确定度传递系数为:%f\n",n0+1,y[n0]);
	}
	for(n0=0,u=0;n0<n;n0++)
	{
		s[n0]=zhongbuqiudingdu(n0,i);
		u=u+pow(y[n0],2)*pow(s[n0],2);
	}
	u=sqrt(u);
	return u;
}

int main()
{
	
	int i,j,i0,j0,n,n1;
	printf("输入数据组数(n)\n");
    scanf("%d",&j);
	printf("输入数据个数(n)\n");
    scanf("%d",&i);
    for(j0=0;j0<j;j0++)
    {
    	printf("\n第%d组\n",j0+1);
    	for(i0=0;i0<i;i0++)
    	{
    		scanf("%f",&shujuzu[j0][i0]);
		}
	}
	printf("\n计算平均值 请按1\n计算标准差 请按2\n计算有无粗大误差 请按3\n计算单条长度总不确定度 请按4\n计算函数不确定度 请按5:");
	scanf("%d",&n);
	switch (n)
	{
		case 1:
		{
			for(j0=0;j0<j;j0++)
			{
			    printf("\n第%d组平均值为%f",j0+1,pingjunzhi(j0,i));
		    }
		    break;
		}
		case 2:
		{
			for(j0=0;j0<j;j0++)
			{
			    printf("\n第%d组标准差为%f,",j0+1,biaozhuncha(j0,i,1));
		    }
		    break;
		}
		case 3:
		{
			for(j0=0;j0<j;j0++)
			{
				float avgchamax=biaozhuncha(j0,i,2);
			    printf("\n第%d组最大残差为%f,",j0+1,avgchamax);
			    n1=cudawucha(j0,i);
			    if(n1==0) printf("无粗大误差\n");
                else printf("有粗大误差\n");
		    }
		    break;
		}
		case 4:
		{
			for(j0=0;j0<j;j0++)
			{
			    printf("\n第%d组总不确定度为%f,",j0+1,zhongbuqiudingdu(j0,i));
		    }
		    break;
		}
		case 5:
		{
			printf("\n函数总不确定度为%f,",piaodao(j,i));
		    break;
		}
	}
	printf("按任意键提出 \n"); 
    system("pause") ;
	return 0;
}


//版本日志
//alpha1.0 实现初代基本功能
//alpha1.5 优化运行结束后停滞功能 
//beta 0.1 完成模块化设计，为之后新功能留出接口  
//1.0 重写了大量代码，改善了系统逻辑引入同时处理多组数据的功能 应该会是下次实验前的最后一个版本 
//1.1 对不起我还是更新了，吧总不确定度肝了出来，孩子要傻了QAQ 修复了上版本在特定情况下会出现的bug 
