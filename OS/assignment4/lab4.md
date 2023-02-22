## OS Lab Assignment 4

---

*a) Find out the PID of your login shell.*

```bash
$ echo "$SHELL"
$ ps
```

---

*b) Remove the header line from the ps output.*

```bash
$ ps --no-headers
```

---

*c) List all processes that you are currently running on your machine, sorted by the command name in alphabetical order (i.e. a process running acroread should be listed before a process running zwgc). The output should consist only of the processes you are running and nothing else (i.e. if you are running 6 processes, the output should only have 6 lines).*

```bash
$ ps|sort -d
```

---

*d) Display the files in the current directory that contain the string MCA HITK in either upper- or lowercase.*

```bash
$ grep -i "MCA HITK" *
```

---

*e) Store in a variable the number of lines containing the word MCA in the files mca1, mca2 and mca3.*

```bash
$ lines=$(grep -c "MCA" mca1 mca2 mca3)
```

---

*f) If you did not have the wc command, how would you use grep to count the number of users currently using the system?*

```bash
$ who | grep -c ".*"
```

---

*g) Remove blank lines from a file using grep.*

```bash
$ grep -v '^$' file.txt
```

---

*h) List the ordinary files in your current directory that are not writable by the owner.*

```bash
$ find . -type f ! -perm -200 -ls
```

---

*i) Locate lines ending and beginning with a dot and containing anything between them.*

```bash
$ grep "^\..*\.$" file.txt
```

---

*j) Locate lines that are less than 100 characters in length.*

```bash
$ grep "^.\{0,99\}$" *
```