#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

void parseArgs(char *buffer, char** args, int argsSize, int *nargs);

int main(){
    //pwd stuff
    char* cwd;
    char buff[PATH_MAX + 1];
    cwd = getcwd(buff, PATH_MAX+1);

    //fgets stuff
    char str[60];

    if(cwd != NULL){
        printf("%s>", cwd);
        printf("%s\n", fgets(str, 60, stdin));
        char** args[10];
        parseArgs(fgets, args, 10); 
    }
    return EXIT_SUCCESS;
}

void parseArgs(char *buffer, char** args, int argsSize, int *nargs){
    char *bufArgs[argsSize];
    char **cp;
    char *wbuf;
    int i, j;

    wbuf=buffer;
    bufArgs[0]=buffer;
    args[0]=buffer;

    for(cp=bufArgs; (*cp=strsep(&wbuf, "\n\t")) != NULL;){
        if((*cp != '\0') && (++cp >= &bufArgs[argsSize]))
            break;
    }
    for(j=i=0; bufArgs[i] != NULL; i++){
        if(strlen(bufArgs[i]) > 0)
            args[j++]=bufArgs[i];
    }
    *nargs = j;
    args[j] = NULL;

}
