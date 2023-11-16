# minitalk-42-core
Server and client in C that communicate via 2 unix signals (SIGUSR1 & SIGUSR2) to exchange a string as exercise of the 42 core curriculum. 

The client first sends a handshake with its own process id to the server which then will ACK every bit sent by the client with a SIGUSR1 signal to ensure transmission of the signals in correct order.

<img width="1189" alt="Screen Shot 2023-11-16 at 1 26 38 PM" src="https://github.com/f321x/minitalk-42-core/assets/51097237/9b0c2754-012d-4bc1-b4f9-c7ed2826ac93">

