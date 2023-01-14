## OS Day 1

---

_a) List the names of the users logged in and their total count without displaying any further details._<br>

**$who -q**

---

_b) Find out your terminal’s device name._<br>

**$tty**

---

_c) Display current date in the form dd/mm/yyyy._<br>

**$date +%d/%m/%y**

---

_d) Find out your machine’s name and the version of the operating system._<br>

**$uname -nr**

---

_e) Clear the screen and place the cursor at row 12, column 25._<br>

**$clear** <br>
**$tput cup 12 25**

---

_f) Find the decimal equivalent of 1101001._ <br>

**$echo "ibase=2; 1101001" | bc**

---

_g) Find out the users who are idling._<br>

**$w**

---

_h) Use man to get help_<br>

**$man tty**

---

_i) Ensure that bc displays the results of all divisions using three decimal places._<br>

**$echo "scale=3; 22/7" | bc**

---
