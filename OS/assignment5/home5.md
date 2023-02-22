## OS Home Assignment 5

---

_1) shell script to find the factorial value of any integer entered through the keyboard._

```bash
#!/bin/bash

echo "Enter a number:"
read num

fact=1
for (( i=1; i<=num; i++ ))
do
  fact=$((fact * i))
done

echo "The factorial of $num is: $fact"

```

---

_2) to generate all combinations of 1, 2 and 3._

```bash
#!/bin/bash

for i in 1 2 3
do
  for j in 1 2 3
  do
    for k in 1 2 3
    do
      echo "$i$j$k"
    done
  done
done

```

---

_3) print all prime numbers in a given range._

```bash
#!/bin/bash

echo "Enter the range:"
read start end

for (( i=start; i<=end; i++ ))
do
  is_prime=true

  if [ $i -lt 2 ]; then
    is_prime=false
  fi

  for (( j=2; j<=i/2; j++ ))
  do
    if [ $((i%j)) -eq 0 ]; then
      is_prime=false
      break
    fi
  done

  if [ "$is_prime" = true ]; then
    echo $i
  fi
done

```

---

_4) to calculate the sum of digits of any number entered through keyboard._

```bash
#!/bin/bash

echo "Enter a number:"
read num

sum=0
while [ $num -gt 0 ]
do
  digit=$((num%10))
  sum=$((sum + digit))
  num=$((num/10))
done

echo "The sum of digits is: $sum"

```

---

_5) Rajesh's basic salary (BASIC) is input through the keyboard. His dearness allowance (DA) is 52% of BASIC. House rent allowance (HRA) is 15% of BASIC. Contributory provident fund is 12% of (BASIC + DA). Write a shell script to calculate his gross salary and take home salary using the following formula:_
_Gross salary = BASIC + DA + HRA._

```bash
#!/bin/bash

echo "Enter Rajesh's basic salary:"
read BASIC

DA=$((52 * BASIC / 100))
HRA=$((15 * BASIC / 100))
CPF=$((12 * (BASIC + DA) / 100))
GROSS=$((BASIC + DA + HRA))
TAKE_HOME=$((GROSS - CPF))

echo "Rajesh's gross salary is: $GROSS"
echo "Rajesh's take home salary is: $TAKE_HOME"

```

---
