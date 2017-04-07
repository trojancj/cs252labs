#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Structure to hold each value and its frequency
typedef struct freq {
        char* num;
        int freq;
}Histogram;

//Prototypes
char** readScores(int* count);
void displayScores(char** a, int* count);
int calcHistogram(Histogram** histo, char** a, int* count);
void displayHistogram(Histogram histo[], int* county);
void sortHistogram(Histogram histo[], Histogram histo2[], int* county);
void displayHistogram(Histogram histo[], int* county);

int main(){
	int count = 0;
	char** a = readScores(&count);
	displayScores(a, &count);
    Histogram* histo;
	int county = calcHistogram(&histo, a, &count);
    displayHistogram(histo, &county);
    Histogram histo2[county];
    sortHistogram(histo, histo2, &county);
	displayHistogram(histo2, &county);	
	return(0);
}
//Reads in the values and populates the first array
char** readScores(int* count){
    char** a = (char**)malloc(100 * sizeof(char*));
    int j;
    for(j=0;j<=100;j++){
        a[j] = (char*)malloc(15 * sizeof(char));
    }
	int c = 0;
	int endOfFile = scanf("%s", a[c]);
	while (endOfFile != EOF){
		c++;
		endOfFile = scanf("%s", a[c]);
	}
	*count = c;
    return a;
}
//Display the scores of the first array
void displayScores(char** a, int* count){
	int j;
	for(j=0; j<*count; j++){
		printf("Word %d: %s\n", j, a[j]);
	}
	printf("\n");
}
//Move the entries from a to histo and records the occurrences of each
int calcHistogram(Histogram** histo, char** a, int* count){

    Histogram* q = (Histogram*)malloc((*count) * sizeof(Histogram));
    int z;
    for(z=0;z<*count;z++){
        q[z].num = "aaa";
    }
	int i;
	int j = 0;
    int k = 0;
	for(i = 0; i <= *count; i++){
		while((strcmp(q[j].num, "aaa") != 0) && (strcmp(q[j].num, a[i]) != 0)){
			j++;
		}
		if(strcmp(q[j].num, "aaa") == 0){
			q[j].num = a[i];
			q[j].freq = 1;
			k += 1;
		}
		else if(strcmp(q[j].num, a[i]) == 0){
			q[j].freq++;
		}
		else{
			printf("We have problem\n");
		}
		j=0;
	}
    *histo = q;
    free(q);
    return k;
}
//Prints out new array contents
void displayHistogram(Histogram histo[], int* county){
	int j;
	for (j=0;j<*county-1;j++){
		printf("Word: %s Freq: %d\n", histo[j].num, histo[j].freq);
	}
	printf("\n");
}
//Sorts the array based on frequency from highest to lowest
void sortHistogram(Histogram h1[], Histogram h2[], int* county){
    int max = 0;
    int i;
    for(i=0; i<*county; i++){
        if (h1[i].freq > max){
            max = h1[i].freq;
        }
        else{}
    }
    int j;      //Gets max freq and goes down to 1
    int m;      //Scans first structure and looks for matches
    int z = 0;  //Index of where to insert into the sorted array
    for(j=max; j>0; j--){
        for(m=0; m<*county; m++){
            if(h1[m].freq == j){
                h2[z].num = h1[m].num;
                h2[z].freq = h1[m].freq;
                z += 1;
            }
            else{}
        }
    }
}
