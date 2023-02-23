## OS Lab Assignment 5

---

_1) Write a shell script to find out whether an integer input the keyboard is an odd number or an even number._

```bash
#!/bin/bash

echo "Enter an integer:"
read num

if [ $((num % 2)) -eq 0 ]; then
  echo "$num is an even number."
else
  echo "$num is an odd number."
fi
```

---

_2) Write a shell script to find out whether any year input through the keyboard is a leap year or not. If no argument is supplied the current year should be assumed._

```bash
#!/bin/bash

if [ -z "$1" ]
then
    year=$(date +"%Y")
else
    year=$1
fi

if (( year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ))
then
    echo "$year is a leap year"
else
    echo "$year is not a leap year"
fi
```

---

_3) Write a shell script to find the maximum of three numbers provided as command line arguments._

```bash
#!/bin/bash

if [ $# -ne 3 ]; then
  echo "Error: Please provide exactly three integer arguments."
  exit 1
fi

num1=$1
num2=$2
num3=$3

if [ $num1 -ge $num2 ] && [ $num1 -ge $num3 ]; then
  echo "Maximum number is: $num1"
elif [ $num2 -ge $num1 ] && [ $num2 -ge $num3 ]; then
  echo "Maximum number is: $num2"
else
  echo "Maximum number is: $num3"
fi
```

---

_4) Write a shell script to check whether a given number is prime or not._

```bash
#!/bin/bash

echo "Enter a number:"
read num

if [ $num -lt 2 ]; then
  echo "$num is not a prime number."
  exit 0
fi

for (( i=2; i<=num/2; i++ ))
do
  if [ $((num%i)) -eq 0 ]; then
    echo "$num is not a prime number."
    exit 0
  fi
done

echo "$num is a prime number."
```
