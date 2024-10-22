## Sistemi Operativi
### Tools:
- Utilizzo [tmux](https://github.com/tmux/tmux) come multiplexer per comodità.
- Utilizzo [GitMe](https://github.com/Raven-s-Soul/GitMe). 
### Cheat Sheet:
- docker exec -it os2425 bash
   - Add a new terminal in the same docker instance
- My usualy **tmux comodity commads**, `Ctrl + b` followed by:
   - `w` select window
   - `c` new window
   - `x` delete pannel
   - `"` or `%` add vertical or orizonal pannel
   - `<Any arrow key>` or `o` select pannel
- **nano** easy text editor `Ctrl + <Key>`
### How to setup GitMe for os2425
```c
// 1) Step Clone
git clone https://github.com/Raven-s-Soul/GitMe
cd GitMe/GitMe
// 2) Step Edit macro.h
// #define REPOSITORY_NAME "GameSaves" -> "SistemiOperativi" or whatever
// 3) Step Compile
// if you have access to CMake or root/sudo use the .sh file from the main folder and your done
g++ -o GitMeOS main.cpp main.h macro.cpp macro.h commmands.cpp commands.h
// 4) Step Move the exec to /bin folder
// There are 2 folder, just use the usr/bin
mv GitMeOS ../../usr/bin
```
