1. list all the files beginning with the character "a" on the screen and also store them in a file called file1
ls -1 | grep "^a" > file1

2. sort the output of who and display on screen along with the total number of users. the same output except the number of users should be stored in a file file1
who | sort | tee >(wc -l | awk '{print $1 " users"}' > file1)

3. double space a file
who | sort | tee >(wc -l | awk '{print $1 " users"}' > file1)

4. select lines 5 to 10 of a file
sed -n '5,10p' filename

5. find the user name and group id from the file/etc/passwd using the cut command
cut -d: -f1,4 /etc/passwd > outputfile

6. extract the names of the users from /etc/passwd after ignoring the first 10 entries
tail -n +11 /etc/passwd | cut -d: -f1

