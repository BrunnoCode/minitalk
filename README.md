**Minitalk: Inter-Process Communication in C**

Minitalk is a simple inter-process communication system in C, designed to transmit text messages between a client process and a server process. It operates using Unix signals, allowing processes to communicate efficiently and asynchronously.

**Operation:**

1. **Server:** The server is started first. It waits to receive a message from the client.
2. **Client:** The client sends a text message to the server.
3. **Communication:** The client's message is sent to the server using Unix signals.
4. **Processing:** The server receives the signals, interprets them, and reconstructs the original message.
5. **Display:** The message received by the server is displayed on the standard output.

**Key Components:**

- **Signals:** Minitalk uses the Unix signals `SIGUSR1` and `SIGUSR2` for communication between client and server processes.
- **Structures:** Data structures are used to store important information,