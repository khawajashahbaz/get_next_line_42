*This project has been created as part of the 42 curriculum by mshahbaz.*

# get_next_line

## Description

`get_next_line` is a C function designed to read a file or input stream line by line, returning each line with every call. The main goal is to allow efficient and convenient processing of input data one line at a time, making it valuable for student projects, file parsing, and text-based applications.

This project follows the 42 school norms and does not use standard library functions except those allowed by the subject. The function handles reading from any valid file descriptor and manages memory to avoid leaks.

## Algorithm

To implement `get_next_line`, a static buffer is used to store data between function calls. The algorithm continuously reads chunks of data from the file descriptor into the buffer until a newline character or the end of file is found. When a line is detected, it is extracted and returned, with any leftover data kept for the next call.

**Why this algorithm?**

- **Efficiency**: Reading in chunks minimizes system calls and handles large files effectively.
- **Static buffer**: Maintains residual data, ensuring lines are not split incorrectly across multiple reads.
- **Memory safety**: Proper allocation and deallocation prevents leaks even when input isn’t perfectly formatted.

This approach balances simplicity, safety, and performance within the constraints of the C language and 42’s coding standards.

## Instructions

1. **Compilation**

To compile the project, use the following command in your terminal:
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```
You can adjust `BUFFER_SIZE` as needed.

2. **Usage**

Include `get_next_line.h` in your project and call `get_next_line()` by passing a valid file descriptor.

**Example:**
```c
int fd = open("input.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## Resources

- [man 2 read](https://man7.org/linux/man-pages/man2/read.2.html)
- [42 Subject PDF](https://github.com/42Paris/42subjects)
- [Malloc Tutorial](https://danluu.com/malloc-tutorial/)
- [Understanding File Descriptors in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Static Variables in C](https://www.geeksforgeeks.org/static-keyword-in-c/)
- [Norminette Documentation](https://github.com/42School/norminette)
- [Official 42 Intranet](https://intra.42.fr/)

**AI Usage:**  
AI was used in this project to assist with documentation structure, README drafting, and formulating explanations of the main algorithm and technical choices. All source code has been written, revised, and tested by the author according to 42’s academic policy.

## Additional Information

- **Feature list**: Handles any file descriptor, works with any line length, manages memory safely, follows 42 project guidelines.
- **Technical choices**: Minimal reliance on standard library functions. Custom string manipulation functions implemented as needed for compliance with project rules.
