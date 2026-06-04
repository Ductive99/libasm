# libasm

rebuilding some libc functions in x86_64 using nasm.

### List of rebuilt functions

| Function | Description (My implementation)                                                    |
| -------- | ---------------------------------------------------------------------------------- |
| strcmp   | compares two strings                                                               |
| strcpy   | copies one source string into a destination string                                 |
| strlen   | returns the length of a string                                                     |
| write    | calls the 2nd linux kernel system call - writes a message to a file (descriptor)   |
| read     | calls the 1st linux kernel system call  - reads a message from a file (descriptor) |
| strdup   | calls malloc and returns the address                                               |

### Resources I found useful

- [Nasm Documentation](https://www.nasm.us/xdoc/2.15.05/html/nasmdoc3.html)
- [Linux Kernel x86_64 entry files](https://github.com/torvalds/linux)
- [Calling Conventions](https://wiki.osdev.org/Calling_Conventions)
- [Introduction to Dynamic Linking](https://www.technovelty.org/linux/plt-and-got-the-key-to-code-sharing-and-dynamic-libraries.html)
- Common sense
- A lot of research

I am still a beginner, and that's the best thing about it.
