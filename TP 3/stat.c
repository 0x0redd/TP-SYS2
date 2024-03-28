#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int system(const char *a);
int main(){
	system("stat %i stat.c");
	return 0;}
