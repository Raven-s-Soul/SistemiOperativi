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
   - `[` Scrolling mode
   - `?` tmux in console guide
- **nano** easy text editor `Ctrl + <Key>`
### How to setup GitMe for os2425
1) Step Clone
```diff
git clone https://github.com/Raven-s-Soul/GitMe
cd GitMe/GitMe
```
2) Step Edit macro.h
```diff
+ #define REPOSITORY_NAME "GameSaves" -> "SistemiOperativi" or whatever
```
3) Step Compile
```diff
- if you have access to CMake or root/sudo use the .sh file from the main folder and your done
g++ -o GitMeOS main.cpp main.h macro.cpp macro.h commmands.cpp commands.h
```
4) Step Log in GitHub ... (Hard)
```diff
git config --global user.name "yourUsername"
git config --global user.email "your@gmail.com"
git config --global user.password "your personal access token"
- you can find them in .gitconfig file in the home folder
git config --global credential.helper store
git config advice.addIgnoredFile false
- usefull config to set
```
<s> 5) Step Move the exec to /bin folder </s>

5) Step .... use it from home since you got no perms
```diff
./GitMeOS ./<whatever>
- Make sure you got no "/" afer the folder name... the tab usualy add / after
- At least until GitMe get updated
```

[Make your Personal Access Token](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens#creating-a-fine-grained-personal-access-token) (Actualy mid)
#### My settings:
Only select repositories and no expiration date.
- AttestationsAccess: Read-only
- Commit statusesAccess: Read and write
- ContentsAccess: Read and write
- Merge queuesAccess: Read and write
- MetadataAccess: Read-only

***

***<p style="align:center;">MIT License, si estende a tutti branch della repository.</p>***
