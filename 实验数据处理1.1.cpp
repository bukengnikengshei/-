//powered by 631
//bug report mcw18500606700@163.com 

#include "bits/stdc++.h"
using namespace std;

float shujuzu[10][21];
float t[3][10]={{1.84,1.32,1.20,1.14,1.11,1.09,1.08,1.07,1.06,1.03},{12.71,4.30,3.18,2.78,2.57,2.45,2.36,2.31,2.26,2.09},{63.66,9.92,5.84,4.60,4.03,3.71,3.50,3.36,3.26,2.86}};
float avgchamax,ub;
int z;
int bj=0;

float pingjunzhi(int j,int i)//ƽ��ֵ���㺯��  pingjunzhi(int j,int i) ����һ�����ݵ�ƽ��ֵ 
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

float biaozhuncha(int j,int i,int n)//��׼��  biaozhuncha(int j,int i,int n) n=1���ر�׼��  n=2�������ƽ��ֵ��  n=3����ƽ��ֵ��ʵ���׼�� 
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

int cudawucha(int j,int i)//�ִ����  cudawucha(int j,int i) 1Ϊ�� 0Ϊ�� 
{
	float s=biaozhuncha(j,i,1),avgchamax=biaozhuncha(j,i,2);
	int n=1;
	if(3*s>avgchamax) n=0;
	return n;
}

float zhongbuqiudingdu(int j,int i)//�����ܲ�ȷ����  zhongbuqiudingdu(int j,int i) �����ܲ�ȷ����
{
	float tp,s=biaozhuncha(j,i,3),ua,u; 
	
	if (bj==0)
	{
		printf("����ȡ�Ŷȣ�95or86or99��\n");
        scanf("%d",&z) ;
        if(z==68&&i<=10)tp=t[0][i-2];
        if(z==95&&i<=10)tp=t[1][i-2];
        if(z==99&&i<=10)tp=t[2][i-2];
        if(z==68&&i==20)tp=t[0][9];
        if(z==95&&i==20)tp=t[1][9];
        if(z==99&&i==20)tp=t[2][9];
	    ua=tp*s;
        printf("����b�಻ȷ����(����)\n");
        scanf("%f",&ub);
        bj=1;
	}
	u=sqrt(ua*ua+ub*ub);
	return u;
}

float qiudao(float a,int x,int n) //�󵼣�����ϵ��a��ָ��ֵ �����󵼺��ϵ��ֵ��n=1��ָ��ֵ��n=2��
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
		printf("�������%d������ǰ��ϵ��:",n0+1);
	    scanf("%f",&a[n0]);
	    printf("�������%d�������ϵ�ָ��:",n0+1);
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
		printf("��%d����ȷ���ȴ���ϵ��Ϊ:%f\n",n0+1,y[n0]);
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
	printf("������������(n)\n");
    scanf("%d",&j);
	printf("�������ݸ���(n)\n");
    scanf("%d",&i);
    for(j0=0;j0<j;j0++)
    {
    	printf("\n��%d��\n",j0+1);
    	for(i0=0;i0<i;i0++)
    	{
    		scanf("%f",&shujuzu[j0][i0]);
		}
	}
	printf("\n����ƽ��ֵ �밴1\n�����׼�� �밴2\n�������޴ִ���� �밴3\n���㵥�������ܲ�ȷ���� �밴4\n���㺯����ȷ���� �밴5:");
	scanf("%d",&n);
	switch (n)
	{
		case 1:
		{
			for(j0=0;j0<j;j0++)
			{
			    printf("\n��%d��ƽ��ֵΪ%f",j0+1,pingjunzhi(j0,i));
		    }
		    break;
		}
		case 2:
		{
			for(j0=0;j0<j;j0++)
			{
			    printf("\n��%d���׼��Ϊ%f,",j0+1,biaozhuncha(j0,i,1));
		    }
		    break;
		}
		case 3:
		{
			for(j0=0;j0<j;j0++)
			{
				float avgchamax=biaozhuncha(j0,i,2);
			    printf("\n��%d�����в�Ϊ%f,",j0+1,avgchamax);
			    n1=cudawucha(j0,i);
			    if(n1==0) printf("�޴ִ����\n");
                else printf("�дִ����\n");
		    }
		    break;
		}
		case 4:
		{
			for(j0=0;j0<j;j0++)
			{
			    printf("\n��%d���ܲ�ȷ����Ϊ%f,",j0+1,zhongbuqiudingdu(j0,i));
		    }
		    break;
		}
		case 5:
		{
			printf("\n�����ܲ�ȷ����Ϊ%f,",piaodao(j,i));
		    break;
		}
	}
	printf("���������� \n"); 
    system("pause") ;
	return 0;
}


//�汾��־
//alpha1.0 ʵ�ֳ�����������
//alpha1.5 �Ż����н�����ͣ�͹��� 
//beta 0.1 ���ģ�黯��ƣ�Ϊ֮���¹��������ӿ�  
//1.0 ��д�˴������룬������ϵͳ�߼�����ͬʱ����������ݵĹ��� Ӧ�û����´�ʵ��ǰ�����һ���汾 
//1.1 �Բ����һ��Ǹ����ˣ����ܲ�ȷ���ȸ��˳���������Ҫɵ��QAQ �޸����ϰ汾���ض�����»���ֵ�bug 
