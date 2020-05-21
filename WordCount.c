#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char c;
	int num_c=0;
	int num_w=0;
	FILE *fpr;
	if(argc<=2)
	{ 
		printf("需要有两个输入参数!\n");
		exit(0);
	}
	if((fpr=fopen(argv[2],"r"))==NULL)
	{ 
		printf("不能打开文件!\n");
		exit(0);
	}
	fseek(fpr,0L,0);
	
	while(!feof(fpr))
	{ 
		fread(&c, 1, 1, fpr);
		switch(c)
		{
			case 0X20://空格
			case 0X2C://逗号
			case 0X0A://换行
			{
				num_c+=1;
				num_w+=1;
				break;
			}
			default:
				num_c++;
			
		}
	}
	if(strcmp(argv[1],"-c\0")==0)
		printf("字符数%d\n",num_c);
	else 
	{
		if(strcmp(argv[1],"-w\0")==0)
			printf("单词数%d\n",num_w);
		else
			printf("输入参数不合法！\n");
	}
	return 0;
	
}