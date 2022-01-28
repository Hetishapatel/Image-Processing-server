# Priority based pre-threaded Image-Processing-server
The goal of the project is to develop an image processing server that interacts with clients through a pool of worker threads using the producer consumer model.
The server consists of a main thread and a set of worker threads with the main thread running at a higher priority than the worker threads. The main thread repeatedly accepts connection requests from clients and places the resulting connected descriptors in a bounded buffer. Each worker thread repeatedly removes a descriptor from the buffer, services the client, and then waits for the next descriptor. All the threads are scheduled with the FIFO policy. The image server applies image processing operations on the image input by the client. 
These image processing operations are derived from the open source OpenCV library.
# Steps followed inorder to achieve the goal
1) Simple implementation of client-server communication where server accepts the request from the client and returns the image without processing.
2) Server accepts the request from client and returns gray iamge to the client. The server is not threaded.
3) Threaded version of the server.
4) The main thread is given priority over the 3 worker threads. 
