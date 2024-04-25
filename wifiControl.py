import socket
import time
import threading

# Set up socket connection
HOST = '0.0.0.0'  # Raspberry Pi's IP address
PORT = 12345       # Choose any available port
BUFFER_SIZE = 1024

# Global variable to track whether a movement key is currently pressed
movement_key_pressed = False

# Function to handle movement based on the pressed key
def handle_movement(key):
    global movement_key_pressed
    while movement_key_pressed:
        print("Moving", key)
        # Send command to Arduino (e.g., ser.write(key.encode()))
        time.sleep(0.1)  # Adjust sleep time as needed

# Create a TCP/IP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen(1)

print("Waiting for connection...")
client_socket, client_address = server_socket.accept()
print("Connection established with:", client_address)

try:
    while True:
        # Receive data from the client
        data = client_socket.recv(BUFFER_SIZE).decode().strip()
        
        # Process received command and send corresponding control command to Arduino
        if data == 'w':
            # Start moving forward
            movement_key_pressed = True
            threading.Thread(target=handle_movement, args=('w',)).start()
        elif data == 's':
            # Start moving backward
            movement_key_pressed = True
            threading.Thread(target=handle_movement, args=('s',)).start()
        elif data == 'a':
            # Start turning left
            movement_key_pressed = True
            threading.Thread(target=handle_movement, args=('a',)).start()
        elif data == 'd':
            # Start turning right
            movement_key_pressed = True
            threading.Thread(target=handle_movement, args=('d',)).start()
        elif data == 'x':
            # Stop
            movement_key_pressed = False
            print("Stopping")
            # Send command to Arduino
        else:
            print("Invalid command:", data)

except KeyboardInterrupt:
    print("\nExiting program.")

finally:
    # Close the socket connection
    client_socket.close()
    server_socket.close()
