#include <stdio.h>
#include <stdlib.h>

//Structure to hold each value and its frequency
typedef struct freqs {
        int num;
        int freq;
}entry;

//Prototypes
void readScores(int* a, int* count);
void displayScores(int* a, int* count);
void calcHistogram(entry histo[], int* a, int* county, int* count);
void displayHistogram(entry histo[], int* county);
void sortHistogram(entry histo[], entry histo2[], int* county);
void displayHistogram(entry histo[], int* county);

int main(){
	//Create empty array	
	int a[100];
	//Will be used to count how many elements are in the array
	int count = 0;
	//Import scores into the array
	readScores(a, &count);
	//Display the scores
	displayScores(a, &count);
	//Create empty array with max size of number of elements
	entry histo[count];
	int z;
	for(z=0;z<count;z++){
        (*(histo + z)).num = -1;
	}
	//End size of the second array
	int county = 0;
	//Counts up occurrences of each
	calcHistogram(histo, a, &county, &count);
    //Prints out the unsorted structure
    displayHistogram(histo, &county);
    //Creates a second empty structure of entries
    entry histo2[county];
    //Sorts the first array by putting the things into the second array
    sortHistogram(histo, histo2, &county);
    //Displays the scores of the second sorted structure
	displayHistogram(histo2, &county);	
	return(0);
}
//Reads in the values and populates the first array
void readScores(int* a, int* count){
	int c = 0;
	int endOfFile = scanf("%d", (a+c));
	while (endOfFile != EOF){
		c++;
		endOfFile = scanf("%d", (a+c));
	}
	*count = c;
}
//Display the scores of the first array
void displayScores(int* a, int* count){
	int j;
	for(j=0; j<*count; j++){
		printf("Score %d: %d\n", j, *(a+j));
	}
	printf("\n");
}
//Move the entries from a to histo and records the occurrences of each
void calcHistogram(entry histo[], int* a, int* county, int* count){
	int i;
	int j = 0;
	for(i = 0; i <= *count; i++){
		while(((*(histo + j)).num != -1) && ((*(histo + j)).num != *(a+i))){
			j++;
		}
		if((*(histo+j)).num == -1){
			(*(histo+j)).num = *(a+i);
			(*(histo+j)).freq = 1;
			*county += 1;
		}
		else if((*(histo+j)).num == *(a+i)){
			(*(histo+j)).freq++;
		}
		else{
			printf("We have problem\n");
		}
		j=0;
	}
}
//Prints out new array contents
void displayHistogram(entry histo[], int* county){
	int j;
	for (j=0;j<*county-1;j++){
		printf("Value %d: freq %d\n", (*(histo+j)).num, (*(histo+j)).freq);
	}
	printf("\n");
}
//Sorts the array based on frequency from highest to lowest
void sortHistogram(entry h1[], entry h2[], int* county){
    int max = 0;
    int i;
    for(i=0; i<*county; i++){
        if ((*(h1+i)).freq > max){
            max = (*(h1+i)).freq;
        }
        else{}
    }
    int j;      //Gets max freq and goes down to 1
    int m;      //Scans first structure and looks for matches
    int z = 0;  //Index of where to insert into the sorted array
    for(j=max; j>0; j--){
        for(m=0; m<*county; m++){
            if((*(h1+m)).freq == j){
                (*(h2+z)).num = (*(h1+m)).num;
                (*(h2+z)).freq = (*(h1+m)).freq;
                z += 1;
            }
            else{}
        }
    }
}
