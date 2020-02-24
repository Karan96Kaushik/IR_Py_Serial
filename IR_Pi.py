print("Started")

from serial import Serial
import sys
import time

port = Serial("/dev/ttyUSB0", baudrate=9600, timeout=3.0)
port.write(":0102520011bmsD1~") #":0102520011bmsD1~"

def read_in():
    lines = sys.stdin.readlines()
    #print(lines)
    #Since our input would only be having one line, parse our JSON data from that
    return lines[0]

def write_out(cmd):
    port.write(cmd) #":0102520011bmsD1~"

def main():
    while True:
        lines = ":0102520011bmsD1~"
        
        if lines != '':
            write_out(lines)

        rcv = port.read(300)
        sys.stdout.write(repr(rcv))
        #sys.stdout.flush()
        
        lines = ":000100000E09~"#read_in()
        
        if lines != '':
            write_out(lines)

        rcv = port.read(300)
        sys.stdout.write(repr(rcv))
        sys.stdout.flush()
        time.sleep(3)
        #sys.stdout.write("\n")
    



#start process
if __name__ == '__main__':
    main()