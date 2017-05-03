# server.py 
import socket                                         
import time

def communicate( n_port = 9999, n_requests = 5):
    # create a socket object
    serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 

    # get local machine name
    host = socket.gethostname()                           

    port = n_port

    # bind to the port
    serversocket.bind((host, port))                                  

    # queue up to 5 requests
    serversocket.listen(n_requests);                       

    while True:
        # establish a connection
        clientsocket,addr = serversocket.accept()      

        print("Got a connection from %s" % str(addr))
        
        currentTime = time.ctime(time.time()) + "\r\n"
        clientsocket.send(currentTime.encode('ascii'))
        clientsocket.close()

def main():
    print("Server is running");
    communicate();


main()
