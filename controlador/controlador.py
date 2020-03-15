import serial, time
arduino = None
def run():
    global arduino
    
    entrada = input();
    if(entrada is not None):
        arduino.flushInput()
        arduino.flushOutput()
        arduino.write(entrada.encode())
        rawString = arduino.readline()
        arduino.flushInput()
        arduino.flushOutput()


if __name__ == "__main__":
    arduino = serial.Serial("COM3", 9600)
    time.sleep(1)
    while(True):
        run()