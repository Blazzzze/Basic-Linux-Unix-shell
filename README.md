# Basic-Linux-Unix-shell
I had implemented two types of bash commands:

1 **Internal commands**

2 **External commands**

Use make command to run the program on the terminal. 
In my program I'm using 3 internal commands and 5 external commands. Internal command is defined inside Main.c with the required function name. To use an external command, first I used fork command to create a child process and then I used execvp command to run the executable file placed in the directory. 

*__External Commands__*:- 

ls: - Tells the name of all files/folders present in current directory sorted in ascending order. Case for ls for different directory in one command is also handled.

Flag used:

1) -a, --all do not ignore entries starting with . 
2) -m fill width with a comma separated list of entries 

cat : - Concatenates the content of given numbers files and display on console. Prints error if any file is not present along with output of files presented.

Flag used: 

1) -n, --number number all output lines 
2) -E, --show-ends display $ at end of each line 

date: - Prints standard system date with console format.

Flag used: 

1) -u, --utc, --universal print or set Coordinated Universal Time (UTC) 
2) -R, --rfc-email output date and time in RFC 5322 format. 
( Example: Mon, 14 Nov 20022 02:34:56 -0600 ) 

rm:- use to delete listed files as arguments and shows error if any file doesn't exists. 

Flag used 

1) -v --verbose  explain what is being done 
2) -d, --dir remove empty directories

mkdir: - use to make new directory at the current pwd location.

Flag used:

1) -p, --parents no error if existing, make parent directories as needed 
2) -v, --verbose print a message for each created directory 

*__Internal Command__*:- 

I had implemented three Internal commands like ‘cd’, ‘echo’ and ‘pwd’ 

cd: - Helps in changing current directory followed by directory path and prints error if path doesn't exists.

Flag used: 

1) ‘..’ takes you to the previous directory.
2)’~’ takes you to the root directory

echo: - Prints the statement followed by this bsh command along with newline character.

Flag used: 

1) -n do not print trailing newline 
2)-E Disables interpretation of backslash escape sequences. This is the default.

pwd: - Helps to get current path of file and prints error if extra inputs are provided.

Flag used: 

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
