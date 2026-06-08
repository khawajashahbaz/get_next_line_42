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
#### To better Understand Buffer Function for each call
> [!CAUTION]
> If User doesn't want to read till end of File (EOF), User should call get_next_line(-1); before closing fd to properly free the leftover buffer memory. That caused the failure last as Evaluator was taking it Memory leak.

*If you use static char buffer[BUFFER_SIZE + 1]; instead of static char *buffer;, the evaluator is 100% correct: it completely eliminates the "Still Reachable" Valgrind warning when you quit early.*

**Why it defeats Valgrind (Heap vs. BSS Segment)**
Valgrind only tracks memory that you manually request from the OS while the program is running (which happens when you use malloc, calloc, or ft_strjoin). This memory goes to the Heap. If you don't free the Heap, Valgrind flags it.
When you declare `static char buffer[BUFFER_SIZE + 1];`, you are not using the Heap. You are telling the compiler to reserve a permanent, fixed block of memory in the BSS Segment of your RAM before the program even starts.
Because you never malloc'd this buffer, you never have to free() it. When the program quits, the OS just deletes the entire BSS segment automatically. Valgrind stays perfectly quiet!
###### How the Fixed Array Architecture Works
Because the array is a fixed size, you can't just keep ft_strjoining text into it infinitely. You have to treat the array like a sliding conveyor belt.

Read Directly: You call ```read(fd, buffer, BUFFER_SIZE)```.
Extract: You calculate where the \n is, malloc exactly enough memory for the final line, and copy the letters over. 
> [!NOTE]
**The 42 subject states:** "Your program must compile with the flag -D BUFFER_SIZE=n." Francinette and Moulinette will rigorously test your code with -D BUFFER_SIZE=10000000 (10 million).

**My Dynamic Approach (char *)**: If the file is only 5 letters long, My code safely reads those 5 letters, mallocs exactly 5 bytes for the stash, and uses almost 0 memory, even though the limit was 10 million. It is highly optimized.
**The Fixed Size Array's Approach (`char buffer[10000000]`):** When the program boots up, the computer instantly carves out 10 Megabytes of permanent RAM for that static array. Even if the file only has 1 character inside it, that 10MB block of RAM is locked and wasted for the entire lifetime of the program.

```c
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int			fd;
	char		*line;
	static char	buffer[BUFFER_SIZE];
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("FIle couldn't be opened \n");
	}
	else
	{
		printf("File is opened \n");
	}
	// read(fd, buffer, sizeof(buffer) - 1);
	// printf("1st call: %s \n", buffer);
	// read(fd, buffer, sizeof(buffer) - 1);
	// printf("2nd call: %s \n", buffer);
	// read(fd, buffer, sizeof(buffer) - 1);
	// printf("3rd call: %s \n", buffer);
	// read(fd, buffer, sizeof(buffer) - 1);
	// printf("3rd call: %s \n", buffer);
	line = get_next_line(fd);
	printf("Line start : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Line start : %s", line);
	free(line);

	get_next_line(-1);
	close(fd);
	return (0);
}
```

## Resources

- [man 2 read](https://man7.org/linux/man-pages/man2/read.2.html)
- [Malloc Tutorial](https://danluu.com/malloc-tutorial/)
- [Understanding File Descriptors in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Static Variables in C](https://www.geeksforgeeks.org/static-keyword-in-c/)
- [Norminette Documentation](https://github.com/42School/norminette)

**AI Usage:**  
AI was used in this project to assist with documentation structure, README drafting, and formulating explanations of the main algorithm and technical choices. All source code has been written, revised, and tested by the author according to 42’s academic policy.

## Additional Information

- **Technical choices**: Minimal reliance on standard library functions. Custom string manipulation functions implemented as needed for compliance with project rules.
