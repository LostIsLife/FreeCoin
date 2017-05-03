# client.py  
import socket

def communicate(n_port = 9999, byte_limit = 1024):
    # create a socket object
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
    
    # get local machine name
    host = socket.gethostname()                           

    port = n_port

    # connection to hostname on the port.
    s.connect((host, port))                               

    # Receive no more than 1024 bytes
    tm = s.recv(byte_limit)                                     

    s.close()

    print("The time got from the server is %s" % tm.decode('ascii'))

def main():
    print("Client is running");
    communicate()


main()
