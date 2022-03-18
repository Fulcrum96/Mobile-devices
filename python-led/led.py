#!/usr/bin/python
import sys #reconocer lo que hay en la terminal
LED_PATH = "/sys/class/leds/beaglebone:green:usr3"

def writeLED(fileName, value, path=LED_PATH):
    """
    Ayuda de la rutina
    writeLED(fileName, value, path=LED_PATH)
    """
    fo = open(path + fileName, "w")
    fo.write(value)
    fo.close()
    return

def removeTrigger():
    writeLED("/trigger","none")
    return

print("Starting App")
#removeTrigger()
#writeLED("/brightness", "1")
#print("LED3 on")
#print("Finish App")
if len(sys.argv)!=2:
    print("Incorrect number of arguments")
    sys.exit(2)
    
if sys.argv[1] == "on":
    print("LED on")
    removeTrigger()
    writeLED("/brightness", "1")
    print("LED3 on")
elif sys.argv[1] == "off":
    print("LED off")
    removeTrigger()
    writeLED("/brightness", "0")
    print("LED3 off")
else:
    print("Wrong command!!!")
    
print("Script done")    
