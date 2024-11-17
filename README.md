# get_next_line

**get_next_line** is a custom implementation of a function that reads a line from a file descriptor, one at a time.  
  
The function uses a buffer for reading input, with the size of the buffer determined by a **`BUFFER_SIZE`** value. The user can define this size during compilation for optimal performance based on their needs.

## Features

- Reads a single line (including `\n`) from a file descriptor with each call.
- Supports multiple file descriptors simultaneously.(*_bonus files)
- Handles variable buffer sizes defined by `BUFFER_SIZE`.
- Efficient memory management to minimize leaks.

## Files

The project consists of three files:

- **`get_next_line.h`**: Header file containing function prototypes and necessary includes.
- **`get_next_line.c`**: Core logic for the `get_next_line` function.
- **`get_next_line_utils.c`**: Helper functions for string manipulation and memory management.

## Installation

To include **get_next_line** in your project, clone the repository and compile the library:

```bash
git clone git@github.com:shatilovdr/42-get_next_line.git
cd 42-get_next_line
```

1.  Include the function header in your source code:
```c
#include "get_next_line.h"
```
2.  Compile your program along with the get_next_line files:
```bash 
   gcc -Wall -Wextra -Werror my_program.c get_next_line.c get_next_line_utils.c -o my_program
```
(Optional) Append a BUFFER_SIZE during compilation to specify the size of the reading buffer:
```bash 
   -D BUFFER_SIZE=64
```
  

3.  Use get_next_line to read lines from a file descriptor:
```c
int fd = open("example.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s\n", line);
    free(line);
}
close(fd);
```

## Example
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
