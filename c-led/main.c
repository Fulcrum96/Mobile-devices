//This project turns on, off or toggle an LED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LED3_PATH "/sys/class/leds/beaglebone:green:usr3"
#define bled "/brightness"
#define tled "/trigger"

//Protypes:
void writeLED(char fileName[], char value[]);
void removeTrigger();

//main:
////////////////////////////////////////////////////////
int main(int argc, char* argv[]){
	printf("Starting app");
	removeTrigger();
	writeLED(bled, "1");
	printf("Done");
	return 0;
	//strcmp(argv[1], "on")==0;
}	

////////////////////////////////////////////////////////
void writeLED(char fileName[], char value[]){
	FILE* fp;
	char fullName[150];
	sprintf(fullName, LED3_PATH "%s", fileName);
	fp = fopen(fullName, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}

void removeTrigger(){
	writeLED(tled, "none");
}	

