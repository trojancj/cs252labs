#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(){
    //pwd stuff
    char* cwd;
    char buff[PATH_MAX + 1];
    cwd = getcwd(buff, PATH_MAX+1);

    //fgets stuff
    char str[60];

    if(cwd != NULL){
        printf("%s>", cwd);
        printf("%s", fgets(str, 60, stdin));
    }
    return EXIT_SUCCESS;
}
