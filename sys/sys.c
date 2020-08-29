#include<stdio.h>
#include<sys/utsname.h>

int main(void){
    struct utsname sys;
    uname(&sys);
	
    printf("Running on a %s processor, %s - %s, release %s. node: %s", sys.machine,  sys.sysname, sys.version, sys.nodename);

    return 0;
}
