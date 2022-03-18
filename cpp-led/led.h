/* class LED for manage BBB leds
 * Gustavo Mart√nez Mondrag√n 14/03/2022*/
#ifndef LED_H
#define LED_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>


class CLED{
	private:
		std::string path;
		int ledNumber;
		virtual void WriteLED(std::string filename, std::string value);
		virtual void RemoveTrigger();
	public:
		CLED(int ledNumber); //class creator
		virtual ~CLED(); //class deconstructor
		virtual void TurnOn();
};

#endif
