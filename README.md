# socket-programming
SDSU Socket Programming assignment in C.

This repository consists of three programs: client1, client2, and server. Client1 will send a C struct comprising of an integer value, a character value and a float value to the server process. The server  doubles the integer value (a 2 becomes a 4), adds 1 to the float value (a 2.3 becomes a 3.3) and increases the character value to the next higher 
character with a roll over (i.e a ‘z’ becomes ‘a’, ‘b’ becomes a ‘c’). The server then prints the original values that it received and the modified values as well (label these values as “Before” and “After” values). The server then transmits these values to client2 and prints the values that it received from the server. All processes are then terminated.
