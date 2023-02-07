## OS Lab Assignment 3

(use desktop view)

---

_a) List all the files beginning with the character "a" on the screen and also store them in a file called file1._<br>

```bash
ls -1 | grep "^a" > file1
```

---

_b) Sort the output of who and display on screen along with the total number of users. the same output except the number of users should be stored in a file file1._<br>

```bash
who | sort | tee >(wc -l | awk '{print 1 " users"}' > file1)
```

---

_c) Double space a file._<br>

```bash
sed G filename > outputfile
```

---

_d) Select lines 5 to 10 of a file._<br>

```bash
sed -n '5,10p' filename
```

---

_e) Find the user name and group id from the file/etc/passwd using the cut command._<br>

```bash
cut -d: -f1,4 /etc/passwd > outputfile
```

---

_f) Extract the names of the users from /etc/passwd after ignoring the first 10 entries._<br>

```bash
tail -n +11 /etc/passwd | cut -d: -f1
```

---

_g) Sort the file /etc/passwd on GUID (primary) and UID (secondary) so that the users with the same GUID are placed together. User with a lower UID should be placed higher in the list._<br>

```bash
sort -t: -k4,4 -k3,3n /etc/passwd
```

---

_h) List from etc/passwd the UID and the user having the highest UID._<br>

```bash
awk -F: '{print 3, 1}' /etc/passwd | sort -n -r | head -1
```

---

_i) Device a sequence which lists the 5 largest files in the current directory._<br>

```bash
ls -lS | head -5
```

---

_j) Remove duplicate lines from a file._<br>

```bash
sort file.txt | uniq > file_unique.txt
```

---

_k) Count the frequency of occurences of words in a file._<br>

```bash
grep -oE '[a-zA-Z]+' file.txt | sort | uniq -c | sort -nr
```

---

_l) Find "long" listing of the smallest 5 files in the /etc directory whose name contains the string ".conf", sorted by increasing file size._ <br>

```bash
find /etc -type f -name "\*.conf" -ls | sort -k7 | head -n 5
```

---

_m) Get a sorted list, with no duplicates, of all the users logged into the logged network._<br>

```bash
who | cut -d' ' -f1 | sort | uniq
```

---

_n) Find all files in your home directory that are more than a week old and end with .bak._ <br>

```bash
find ~ -type f -name "\*.bak" -mtime +7
```

---

_o) How many total lines are contained in all the files ending in .c in the current directory, printing only the total number of lines._<br>

```bash
find . -name "\*.c" -exec wc -l {} + | tail -n1 | awk '{print 1}'
```
