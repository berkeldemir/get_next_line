![42-getnextline](https://github.com/user-attachments/assets/cf6ec260-184a-4259-90a4-4b5e40c4bc7b)
![project-badge](https://badgen.net/badge/get_next_line/125%25/blue?icon=terminal)
![user-badge](https://badgen.net/badge/created%20by/%40berkeldemir/yellow?icon=github)
![intra-badge](https://badgen.net/badge/intra/%40beldemir/cyan?icon=slack)

## Being able to read what's inside a file, wow!

In this project of 42 Cursus, you will create a function which reads another line of a file each time.

## 🖥️ Installation

Follow the instructions in your terminal:
```bash
git clone https://github.com/berkeldemir/get_next_line.git
cd get_next_line
```

## ⌨️ Usage

To try how it works you can create a basic main.c in the root of repository:

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int  main(void)
{
  int    fd;
  char  *line;

  fd = open("example.txt", O_RDONLY, 0777);
  if (fd < 0)
    return (1);
  while ((line = get_next_line(fd)) != NULL)
  {
    printf("%s\n", line);
    free(line);
  }
  return (0);
}
```
and of course you need an example.txt file also in the root of repository.

then type this in your terminal:

```bash
gcc -o main main.c get_next_line.c get_next_line_utils.c
./main
```

you should see each line in your example.txt correctly.

## 👨‍💻 Code

There is couple of topics i want to talk about for get_next_line:

### 1. Buffer Size

Buffer size is how many characters are you getting for every iteration, if i would need to visualize it:

**\<WIP\>**
