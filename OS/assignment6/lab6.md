## OS Lab Assignment 6

---

_1. Write a shell program that takes a number from user and prints the reverse of the number._

```bash
#!/bin/bash

read -p "Enter a number: " num
reverse=$(echo $num | rev)
echo "The reverse of $num is $reverse"
```

---

_2. Write a shell script to determine whether two numbers input through keyboard are prime to each other._

```bash
#!/bin/bash

read -p "Enter the first number: " num1
read -p "Enter the second number: " num2
while [ $num2 -ne 0 ]
do
    temp=$num1
    num1=$num2
    num2=$((temp % num2))
done

if [ $num1 -eq 1 ]
then
    echo "$num1 and $num2 are prime to each other"
else
    echo "$num1 and $num2 are not prime to each other"
fi
```

---

_3. Write a shell script to find whether a number is divisible by 11._

```bash
#!/bin/bash

read -p "Enter a number: " num
if [ $((num % 11)) -eq 0 ]
then
    echo "$num is divisible by 11"
else
    echo "$num is not divisible by 11"
fi
```

---

_4. Write a shell script that produces a shell calculator to perform the following operations: addition, subtraction, multiplication, division_

```bash
#!/bin/bash

add() {
    echo $(($1 + $2))
}
subtract() {
    echo $(($1 - $2))
}
multiply() {
    echo $(($1 * $2))
}
divide() {
    echo $(($1 / $2))
}

read -p "Enter the first number: " num1
read -p "Enter the operator (+, -, *, /): " op
read -p "Enter the second number: " num2

case $op in
    "+") result=$(add $num1 $num2);;
    "-") result=$(subtract $num1 $num2);;
    "*") result=$(multiply $num1 $num2);;
    "/") result=$(divide $num1 $num2);;
    *) echo "Invalid operator entered"; exit 1;;
esac

echo "Result: $result"
```
