/* led.cpp */
#include"led.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

CLED::CLED(int ledNumber){
	this->ledNumber = ledNumber; //Solo para argumentos que sean numeros
	std::ostringstream s;
	s << LED_PATH << ledNumber;
	path =std::string(s.str()); //convert to string
}

void CLED::WriteLED(std::string filename, std::string value){
	std::ofstream fs;
	fs.open((path+filename).c_str());
	fs << value;
	fs.close();
}

void CLED::RemoveTrigger(){
	WriteLED("/trigger", "none");
}

void CLED::TurnOn(){
	std::cout << "LED Turn On" << ledNumber << "on" << std::endl;
	RemoveTrigger();
	WriteLED("/brightness", "1");
}

CLED::~CLED(){
	std::cout << "destroying LED " << path << std::endl;
}
