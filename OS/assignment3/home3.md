## OS Home Assignment 3

---

_1. Write and execute the following UNIX commands._ <br>
_(i) Create two files._ <br>

```bash
$ touch file1 file2
```

_(ii) Combine the two files._ <br>

```bash
$ cat file1 file2 > combinedfile
```

_(iii) Search a specific word from any one of the file._<br>

```bash
$ grep "word" file1
```

_(iv) Search a specific file from a directory._<br>

```bash
$ find /path/to/dir -name "filename"
```

---

_2. Under the same directory create 8 files with any extension of your choice but at least 3 file names must start with letter d and has extension .sh & 2 files with letter t. Note that no file should be empty._ <br>

```bash
$ echo "File 1" > d1.sh
$ echo "File 2" > d2.sh
$ echo "File 3" > d3.sh
$ echo "File 4" > t1
$ echo "File 5" > t2
$ echo "File 6" > file6.txt
$ echo "File 7" > file7.txt
$ echo "File 8" > file8.txt
```

---

_3. Sort the output of who and display on screen along with total number of users. The same output except the number of users should be stored in a file file1_. <br>

```bash
$ who | sort > file1
$ wc -l file1
```

---

_4. Write a shell script to implement a basic calculator (+,-,/,\*)_ <br>

```bash
#!/bin/bash
echo "Enter two numbers: "
read num1
read num2
echo "Enter an operator (+,-,*,/): "
read operator
if [ "$operator" = "+" ]; then
  result=$(($num1 + $num2))
elif [ "$operator" = "-" ]; then
  result=$(($num1 - $num2))
elif [ "$operator" = "*" ]; then
  result=$(($num1 * $num2))
elif [ "$operator" = "/" ]; then
  result=$(($num1 / $num2))
else
  echo "Invalid operator"
  exit 1
fi
echo "Result: $result"

```

---

_5. Write and execute the following UNIX commands._ <br>
_(i) To view all the files and directories._ <br>

```bash
$ ls -al
```

_(ii) To view only the directories._ <br>

```bash
$ ls -d */
```

_(iii) To view only the files in a directory._ <br>

```bash
$ ls -p | grep -v /
```

_(iv) Display the working directory._ <br>

```bash
$ pwd
```

_(v) Rename file1 to file2. if file2 exists prompt for confirmation before overwriting it._ <br>

```bash
if [ -f file2 ]; then
  read -p "file2 already exists, overwrite? (y/n) " choice
  if [ "$choice" = "y" ]; then
    mv file1 file2
  fi
else
  mv file1 file2
fi
```

---

_6. Write and execute the following UNIX commands._ <br>
_i. Create a directory SAMPLE under your home directory._ <br>

```bash
$ mkdir ~/SAMPLE
```

_ii. Create a sub-directory by name TRIAL under SAMPLE._ <br>

```bash
$ mkdir ~/SAMPLE/TRIAL
```

_iii. Change to SAMPLE._ <br>

```bash
$ cd ~/SAMPLE
```

_iv. Change to your home directory._ <br>

```bash
$ cd ~
```

_v. Change from home directory to TRIAL by using absolute and relative pathname._ <br>

```bash
$ cd ~/SAMPLE/TRIAL
$ cd ../TRIAL
```

_vi. Remove directory TRIAL._ <br>

```bash
$ rm -r ~/SAMPLE/TRIAL
```

---

_7. Write and execute the following UNIX commands._ <br>
_i. start a script in your home directory_ <br>

```bash
$ cd ~
$ touch script.sh
$ chmod +x script.sh
```

_ii. in your cs330 lab directory create three new directories named 'weather', 'assignment', and 'web' (if you do not have a cs330 lab directory then create it)_ <br>

```bash
if [ ! -d cs330_lab ]; then
  $ mkdir cs330_lab
fi
$ cd cs330_lab
$ mkdir weather
$ mkdir assignment
$ mkdir web
```

_iii. change the permissions of the directory 'web' to -rwxr-xr-x using the octal form of chmod_ <br>

```bash
$ chmod 755 web
```

_iv. change your working directory to weather_ <br>

```bash
$ cd weather
```

_v. without using a text editor create three files called 'today', 'tomorrow', and 'deer'_ <br>

```bash
$ touch today tomorrow deer
```

_vi. check the permissions with ls -l_ <br>

```bash
$ ls -l
```

_vii. change the permissions of 'deer' to -rwx r-- r--_ <br>

```bash
$ chmod 744 deer
```

_viii. change the permissions of 'today' to -rw- r-- r--_ <br>

```bash
$ chmod 754 today
```

_ix. check the permissions with ls -l_ <br>

```bash
$ ls -l
```

---

_8. Write a shell script which will take a filename as input and apply READ & EXECUTE permissions only for the owner and group._ <br>

```bash
#!/bin/bash

filename=$1
if [ ! -e $filename ]; then
  echo "Error: file $filename does not exist."
  exit 1
fi
chmod 550 $filename
echo "Success: READ and EXECUTE permissions added for owner and group on $filename"
```
