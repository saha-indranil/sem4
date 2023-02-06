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
