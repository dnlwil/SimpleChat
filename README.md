# TCP Chat – Simple Multithreaded Client/Server in C

A lightweight, educational TCP communication application written in C for Linux using posix API.

It demonstrates how to build a two‑threaded client and server, where:
- one thread receives messages from the socket,
- the other thread sends messages from stdin.


# How It Works


  Server

  - Creates a socket (socket())
  - Binds the socket to a port (bind())
  - Starts listening for incoming connections (listen())
  - Accepts a client connection (accept())
  - Spawns a receiving thread (rcv_messages)
  - The main thread sends messages (snd_messages)

  Client

  - Creates a socket (socket())
  - Connects to the server (connect())
  - Spawns a sending thread (snd_messages)
  - The main thread receives messages (rcv_messages)

# Build
  Just use makefile with the commands:
  - make server
  - make client
  - or
  - gcc server.c socket.c -o server
  - gcc client.c socket.c -o client

# Run
  - In one terminal: ./server
  - In second terminal ./client
  - start sending messages to each other
