## OS Day 2

(use desktop view)

---

_a) Create a directory structure in your home directory (cse, two subdirectories cprogs and projects under cse) while being in your home directory._<br>

**$cd \~**<br>
**$mkdir cse**<br>
**$mkdir cse/cprogs cse/projects**

---

_b) Change to the directory projects._<br>

**$cd cse/projects**

---

_c) Create a file called biodata and store your name, age, sex, and address in it._<br>

**$cat>biodata.txt**<br>
**name: lord puneet**<br>
**age: 69**<br>
**sex: alpha male**<br>
**address: earth**<br>
**ctrl+z**

---

_d) Make a copy of the file biodata into another file text within the directory cprogs._<br>

**$cp biodata.txt ../cprogs/text.txt**

---

_e) Move the file text from cprogs to projects._<br>

**$mv ../cprogs/text.txt .**

---

_f) Combine the contents of the file biodata and text into another file datatext._<br>

**$cat biodata.txt text.txt>datatext.txt**

---

_g) Rename the file text to newtext._<br>

**$mv text.txt newtext.txt**<br>

---

_h) Change the permissions of the file newtext to rw-rw-rw-._<br>

**$chmod 666 newtext.txt**<br>

---

_i) List all filenames starting with ‘a’ or ‘b’ or ‘m’._<br>

**$find . -type f -name "[a-b-m]\*"**<br>

---

_j) List all filenames that end with a digit._<br>

**\$find . -type f -name "\*[0-9].\*"**

---

_k) List all files in the current directory whose second character is a digit._<br>

**\$find . -type f -name "?[0-9]\*"**

---

_l) Use command(s) to create a directory in your home directory called KeepOut whose contents can be read only by you._<br>

**$cd \~**<br>
**$mkdir KeepOut**<br>
**$chmod 400 KeepOut**
