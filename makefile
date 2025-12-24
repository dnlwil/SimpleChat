#Makefile

server_files = server.c socket.c
client_files = client.c socket.c

server: text
	gcc $(server_files) -o server -Wall -Wextra -pedantic
	echo "Server built."

clean:
	rm server client

client: text
	gcc $(client_files) -o client -Wall -Wextra -pedantic
	echo "Client built."

text:
	echo "Compiling..."

.SILENT:
