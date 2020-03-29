from serial import Serial
import sys
from time import sleep 

port = Serial("/dev/ttyUSB0", baudrate=9600, timeout=3.0)

vol_up = "NEC:551502015$32%"
vol_down = "NEC:551534655$32%"
power = "NEC:551489775$32%"
play = "NEC:551509410$32%"
ok = "NEC:551494365$32%"
source = "NEC:551538735$32%"
left = "NEC:551542815$32%"

def read_in():
    lines = sys.stdin.readlines()
    #print(lines)
    #Since our input would only be having one line, parse our JSON data from that
    return lines[0]

def write_out(cmd):
    port.write(cmd) #":0102520011bmsD1~"

def main():
    #port.write(play)
    sleep(0.1)
    port.write(power)

    
#start process
if __name__ == '__main__':
    main()