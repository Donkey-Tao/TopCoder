#include <sstream>
#Include <string>
// ȱ���Ǵ����������ת���ٶȽ���..
// ���ֵ��ַ���
string num2str(double i)
{
        stringstream ss;
        ss << i;
        return ss.str();
}
// �ַ���������
int str2num(string s)
 {   
        int num;
        stringstream ss(s);
        ss>>num;
        return num;
}

// C library�е�sprintf, sscanf ��Ը���
//���ֵ��ַ���
int H, M, S;
string time_str;
H=seconds/3600;
M=(seconds%3600)/60;
S=(seconds%3600)%60;
char ctime[10];
sprintf(ctime, "%d:%d:%d", H, M, S);             // ������ת�����ַ���
time_str=ctime; 

// �ַ���������
char    str[] = "15.455";
int     i;
float     fp;
sscanf( str, "%d", &i );         // ���ַ���ת��������   i = 15
sscanf( str, "%f", &fp );      // ���ַ���ת���ɸ����� fp = 15.455000
//��ӡ
printf( "Integer: = %d ",  i+1 );
printf( "Real: = %f ",  fp+1 ); 
return 0;                                                // ���

// C��׼�����ṩ�� atoi, atof, atol
char    str[] = "15.455";
double     db;
int     i;
db = atof(str);   // db = 15.455
i = atoi(str);    // i = 15