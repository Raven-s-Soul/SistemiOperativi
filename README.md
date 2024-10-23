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
   - `?` tmux in console guide
- **nano** easy text editor `Ctrl + <Key>`
### How to setup GitMe for os2425
1) Step Clone
```c
git clone https://github.com/Raven-s-Soul/GitMe
cd GitMe/GitMe
```
2) Step Edit macro.h
```c
// #define REPOSITORY_NAME "GameSaves" -> "SistemiOperativi" or whatever
```
3) Step Compile
```c
// if you have access to CMake or root/sudo use the .sh file from the main folder and your done
g++ -o GitMeOS main.cpp main.h macro.cpp macro.h commmands.cpp commands.h
```
<s> 4) Step Move the exec to /bin folder </s><br>
4) use it from home since you got no perms
```
./GitMeOS ./<whatever>
// Make sure you got no "/" afer the folder name... the tab usualy add / after
// At least until GitMe get updated
```
