## OS Lab Assignment 5

---

*1) write a shell script to find out whether an integer input the keyboard is an odd number or an even number*

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

*2) whether any year input through the keyboard is a leap year or not.*

```bash
#!/bin/bash

echo "Enter a year:"
read year

if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; then
  echo "$year is a leap year."
else
  echo "$year is not a leap year."
fi

```

---

*3) find the maximum of three numbers provided as command line arguments.*

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

*4) to check whether a given number is prime or not.*

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
