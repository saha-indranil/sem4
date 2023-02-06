_a) list all the files beginning with the character "a" on the screen and also store them in a file called file1_<br>

ls -1 | grep "^a" > file1

---

_b) sort the output of who and display on screen along with the total number of users. the same output except the number of users should be stored in a file file1_<br>

who | sort | tee >(wc -l | awk '{print $1 " users"}' > file1)

---

_c) double space a file_<br>

who | sort | tee >(wc -l | awk '{print $1 " users"}' > file1)

---

_d) select lines 5 to 10 of a file_<br>

sed -n '5,10p' filename

---

_e) find the user name and group id from the file/etc/passwd using the cut command_<br>

cut -d: -f1,4 /etc/passwd > outputfile

---

_f) extract the names of the users from /etc/passwd after ignoring the first 10 entries_<br>

tail -n +11 /etc/passwd | cut -d: -f1

---

_g) sort the file /etc/passwd on GUID (primary) and UID (secondary) so that the users with the same GUID are placed together. User with a lower UID should be placed higher in the list_<br>

sort -t: -k4,4 -k3,3n /etc/passwd

---

_h) list from etc/passwd the UID and the user having the highest UID_<br>

awk -F: '{print $3, $1}' /etc/passwd | sort -n -r | head -1

---

_i) device a sequence which lists the 5 largest files in the current directory_<br>

ls -lS | head -5

---

_j)remove duplicate lines from a file_<br>

sort file.txt | uniq > file_unique.txt

---

_k)count the frequency of occurences of words in a file_<br>

grep -oE '[a-zA-Z]+' file.txt | sort | uniq -c | sort -nr

---

  _l)find "long" listing of the smallest 5 files in the /etc directory whose name contains the string ".conf", sorted by increasing file size_<br>

find /etc -type f -name "*.conf" -ls | sort -k7 | head -n 5

---

_m)get a sorted list, with no duplicates, of all the users logged into the logged network_<br>

who | cut -d' ' -f1 | sort | uniq

---

_n)find all files in your home directory that are more than a week old and end with .bak_<br>

find ~ -type f -name "*.bak" -mtime +7

---

_o)how many total lines are contained in all the files ending in .c in the current directory, printing only the total number of lines_<br>

find . -name "*.c" -exec wc -l {} + | tail -n1 | awk '{print $1}'
