#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<string.h>

int main(int argc, const char *argv[])
{
	FILE *fp;
	time_t ctime;
	int linecount = 1;
	char buff[32];
	struct tm * ctimestr;
	fp = fopen("test.txt", "a+");
	if(fp == NULL){
		perror("fopen");
		return -1;
	}

	//计算已有行号
	while(fgets(buff, 32, fp) != NULL){//fgets读完一行换下一行，直至没有
		if(buff[strlen(buff) - 1] == '\n'){//判断buff是不是读完一整行了，防止没读完循环了接着读同一行
		linecount++;
		}else{
			printf("The size of buff is small\n");
			return -1;
		}
	}
	while(1){
	ctime = time(NULL);
	printf("ctime:%d\n", (int)ctime);//此时打印的是1970年到现在的秒数
	ctimestr = localtime(&ctime);
	printf("%d  %d-%02d-%02d %02d:%02d:%02d\n", linecount, ctimestr->tm_year + 1900,
			ctimestr->tm_mon + 1, ctimestr->tm_mday,
			ctimestr->tm_hour, ctimestr->tm_min, ctimestr->tm_sec );
	fprintf(fp, "%d  %d-%02d-%02d %02d:%02d:%02d\n", linecount, ctimestr->tm_year + 1900,
			ctimestr->tm_mon + 1, ctimestr->tm_mday,
			ctimestr->tm_hour, ctimestr->tm_min, ctimestr->tm_sec );
	fflush(fp);
	linecount ++;
	sleep(1);
	}
	
	
	return 0;
}
