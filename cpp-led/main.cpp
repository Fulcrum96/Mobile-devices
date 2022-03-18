#include"led.h"
//#include<string>
using namespace std;

int main(int argc, char* argv[]){
	CLED led1 = CLED(3);
	led1.TurnOn();
	return 0;
}

