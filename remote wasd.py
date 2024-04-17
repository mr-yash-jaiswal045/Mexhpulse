import serial
import keyboard
import time

# Define serial port and baud rate
ser = serial.Serial('COM8', 9600, timeout=1)

try:
    while True:
        # Check for WASD key presses
        if keyboard.is_pressed('w'):
            ser.write('w'.encode())
            time.sleep(0.1)  # Add a small delay to avoid rapid key presses
        elif keyboard.is_pressed('a'):
            ser.write('a'.encode())
            time.sleep(0.1)
        elif keyboard.is_pressed('s'):
            ser.write('s'.encode())
            time.sleep(0.1)
        elif keyboard.is_pressed('d'):
            ser.write('d'.encode())
            time.sleep(0.1)

        # Check if 'x' key is pressed to stop the car
        elif keyboard.is_pressed('x'):
            ser.write('x'.encode())
            time.sleep(0.1)

except KeyboardInterrupt:
    print("\nExiting program.")

finally:
    # Close the serial port
    ser.close()
