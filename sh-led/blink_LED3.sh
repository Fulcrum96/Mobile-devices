#!/bin/bash
LED3_PATH=/sys/class/leds/beaglebone:green:usr3
 
function removeTrigger
{
         echo "none" >> "$LED3_PATH/trigger"
}
 
echo "The LED3 user is starting"
 if [ "$1" == "on" ]; then
         removeTrigger
         echo "1" >> "$LED3_PATH/brightness"
 elif [ "$1" == "off" ]; then
         removeTrigger
         echo "0" >> "$LED3_PATH/brightness"
 elif [ "$1" == "blink" ]; then
	removeTrigger
	echo "1" >> "$LED3_PATH/brightness"
	sleep 0.5
	echo "0" >> "$LED3_PATH/brightness"
	sleep 0.5
 fi
 echo "Done"                
