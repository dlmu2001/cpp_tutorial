#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void func1() {
    int i=0;
    for(;i<10;i++) {
     char* buf = malloc(sizeof(char)*100);
     memset(buf,0,100);
     memcpy(buf,"test",4);
     printf("func1,i=%d\n",i);
     free(buf);
    }
}
void func2() {
    int i=0;
    for(;i<100;i++) {
	printf("func2,i=%d\n",i);
    }
}
void func3() {
    int i=0;
    for(;i<100;i++) {
        printf("*****func3,i=%d\n",i);
	if (i%2 ==0) 
	    func1();
        else 
	    func2();
    }
}
int main(int argc,char *argv[]) {
    printf("Hello World!\n");
    printf("argc=%d]\n",argc);
    printf("argv[0]=%s\n",argv[0]);
    int i=0;
    for(;i<10;i++) {
        printf("main,circle %d\n",i);
	func3();
    }
    return 0;
}

