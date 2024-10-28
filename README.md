## Sistemi Operativi
### Tools:
>- Utilizzo [tmux](https://github.com/tmux/tmux) come multiplexer per comodità.
>- Utilizzo [GitMe](https://github.com/Raven-s-Soul/GitMe). 

<details>
<summary><b>Cheat Sheet</b></summary><br>
<details>
<summary>docker</summary><br>

>| Comando | spiegazione |
>| :--: | :-- |
>| docker exec -it os2425 bash | Add a new terminal in the same docker instance |
>| docker container start os2425 | Start os2425 |
>| docker container attach os2425 | Attach to os2425 |
</details>

<details>
<summary>tmux</summary><br>

>- My usualy **tmux comodity commads**, `Ctrl + b` followed by:
>  
>| Key | spiegazione |
>| :--: | :-- |  
>| `w` | select window |
>| `c` | new window |
>| `x` | delete pannel |
>| `"` or `%` | add vertical or orizonal pannel |
>| `<Any arrow key>` or `o` | select pannel |
>| `[` | Scrolling mode |
>| `?` | tmux in console guide |
</details>

> **nano** easy text editor `Ctrl + <Key>`

<details>
<summary>How to setup GitMe for os2425</summary><br>
  
>1) Step Clone
>```diff
>git clone https://github.com/Raven-s-Soul/GitMe.git
>cd GitMe/GitMe
>```
>2) Step Edit macro.h
>```diff
>+ #define REPOSITORY_NAME "GameSaves" -> "SistemiOperativi" or whatever
>```
>3) Step Compile
>```diff
>- if you have access to CMake or root/sudo use the .sh file from the main folder and your done
>g++ -o GitMeOS main.cpp main.h macro.cpp macro.h commmands.cpp commands.h
>```
>4) Step Log in GitHub ... (Hard)
>```diff
>git config --global user.name "yourUsername"
>git config --global user.email "your@email.dot"
>git config --global user.password "yourPersonalAccessToken"
>- you can find them in .gitconfig file in the home folder
>git config --global credential.helper store
>git config advice.addIgnoredFile false
>- usefull config to set
>```
><s> 5) Step Move the exec to /bin folder </s>
>
>5) Step .... use it from home since you got no perms
>```diff
>./GitMeOS ./<whatever>
>- Make sure you got no "/" afer the folder name... the tab usualy add / after
>- At least until GitMe get updated
>```
>
>[Make your Personal Access Token](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens#creating-a-fine-grained-personal-access-token) (Actualy mid)
>
><details>
><summary>My settings</summary><br>
>   
>>Only select repositories and no expiration date.
>>- AttestationsAccess: Read-only
>>- Commit statusesAccess: Read and write
>>- ContentsAccess: Read and write
>>- Merge queuesAccess: Read and write
>>- MetadataAccess: Read-only
></details> <!-- My Settings  -->
</details> <!-- GitMe  -->
</details> <!-- Cheat Sheet  -->

***

>| Comando | spiegazione |
>| :--: | :-- |
>| `sudo` | esegui come amministratore |
>| `I` | pipe operatore <br> output @1 è input @2 |
>| `>` | scrivi dentro @ <br> ls > ls.txt |
>| `>>` | scrivi infondo dentro @ <br>  ls >> ls.txt  |
>| `pwd` | mostra la directory |
>| `nano` | text editor |
>| `watch ps` | track process |
>| `man @1 @2` | manuale, @1 index del manuale, @2 argomento cercato |
>| `ls` + `-a` | mostra i file, -a anche i file nascosti |
>| `clear` | pulisce il terminale |
>| `cd `| muoviti in a directory, ./ = here .. / = parent |
>| `cat @` | leggi file |
>| `less @`| leggi file poco |
>| `more @`| leggi file di più|
>|`tail`| leggi fondo file|
>|`touch`| crea un file |
>| `mkdir @`| crea cartella @ |
>| `rm -@ @`| rimuovi @, se directory -r |
>| `cp @1 @2`| copia @1 in @2 |
>| `mv @1 @2`| muovi @1 in @2 |
>|`tree`| mostra la directory tree|
>|`top`| mostra informazioni generali |
>|`htop`| top con gli steroidi |

<!--
| A | B |
| `###` | ### <br> <details> <summary>Example: </summary><br> ### </details> |

Todo
journal
-->

***

***<p style="align:center;">MIT License, si estende a tutti branch della repository.</p>***
