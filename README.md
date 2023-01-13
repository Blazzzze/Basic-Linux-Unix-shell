# Basic-Linux-Unix-shell
How to operate : 
Use make command to run the program on the terminal. 
In my program I'm using 3 internal commands and 5 external commands. Internal command is defined inside Main.c with the required function name. To use an external command ,first I used fork command to create a child process and then I used execvp command to run the executable file placed in the directory. 
External Commands:- 
ls: 
flag used: 1) -a, --all do not ignore entries starting with . 
2) -m fill width with a comma separated list of entries 
cat : 
flag used: 1) -n, --number number all output lines 
2) -E, --show-ends display $ at end of each line 
date: 
flag used: 1) -u, --utc, --universal print or set Coordinated Universal Time (UTC) 
2) -R, --rfc-email output date and time in RFC 5322 format. 
( Example: Mon, 14 Nov 20022 02:34:56 -0600 ) 
rm:
flag used 1) -v --verbose  explain what is being done 
                2) -d, --dir remove empty directories
mkdir: 
flag used: 1) -p, --parents no error if existing, make parent directories as needed 
       		       2) -v, --verbose print a message for each created directory 
Internal Command:- 
cd: 
flag used: 
1) ‘..’ takes you to the previous directory.
2)’~’ takes you to the root directory
echo: 
flag used: 
1) -n do not print trailing newline 
2)-E Disables interpretation of backslash escape sequences. This is the default.
pwd: 
flag used: 
1) -L print the names the current working directory
2) -P Print a fully resolved name for the current directory, where all components of 	the names are actual directory names, and not symbolic links. 
Assumption: 
In my code the user first has to write “./a.out” and in the same line the user has to write the command space separated & then the corresponding command is executed. 
Testcase: 
./a.out ls 
./a.out ls -a 
./a.out ls -m
./a.out cat a.txt
./a.out cat a.txt b.txt
/a.out cat -E a.txt
/a.out cat -n  a.txt
./a.out mkdir a 
./a.out mkdir -p a 
./a.out mkdir -v a
./a.out rm a
./a.out rm -d a 
./a.out rm –v a  
./a.out date 
./a.out date -u 
./a.out date -R 
./a.out echo hello 
./a.out echo -n “how are you”
./a.out echo -E “how are you” 
./a.out pwd 
./a.out pwd -L
./a.out pwd -P
./a.out cd 
./a.out cd ..
./a.out cd ~  

