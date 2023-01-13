## OS Day 1

---

_a) List the names of the users logged in and their total count without displaying any further details._<br>
**$who -q**<br>
_b) Find out your terminal’s device name._<br>
**$tty**<br>
_c) Display current date in the form dd/mm/yyyy._<br>
**$date +%d/%m/%y**<br>
_d) Find out your machine’s name and the version of the operating system._<br>
**$uname -nr**<br>
_e) Clear the screen and place the cursor at row 12, column 25._<br>
**$clear** <br>
**$tput cup 12 25** <br>
_f) Find the decimal equivalent of 1101001._ <br>
**$bc**<br>
**ibase=2**<br>
**1101001**<br>
**105**<br>
**quit**<br>
_g) Find out the users who are idling._<br>
**$w**<br>
_h) Use man to get help_<br>
**$man tty**<br>
_i) Ensure that bc displays the results of all divisions using three decimal places._<br>
**$bc**<br>
**scale=3**<br>
**10/3**<br>
**3.333**<br>
**10/5**<br>
**2.000**<br>
**quit**<br>
