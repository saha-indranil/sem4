## OS Home Assignment 6

---

_1. Write a shell script to print the pattern for any number of line._

```
      *
    * * *
  * * * * *
* * * * * * *
```

```bash
#!/bin/bash

read -p "Enter number of lines: " n
for ((i=1; i<=n; i++))
do
    for ((j=1; j<=n-i; j++))
    do
        echo -n "  "
    done
    for ((j=1; j<=2*i-1; j++))
    do
        echo -n "* "
    done
    echo ""
done
```

---

_2. Write a shell script to test whether a given string is pallindrome._

```bash
#!/bin/bash

read -p "Enter a string: " str
rev_str=$(echo $str | rev)
if [ "$str" == "$rev_str" ]; then
    echo "The string is a palindrome."
else
    echo "The string is not a palindrome."
fi
```

---

_3. Write a shell script which counts the number of consonants and vowel in a given sentence._

```bash
#!/bin/bash

read -p "Enter a sentence: " sentence
sentence=$(echo $sentence | tr '[:upper:]' '[:lower:]')
vowel_count=0
consonant_count=0
for ((i=0; i<${#sentence}; i++))
do
    char=${sentence:$i:1}
    case $char in
        [aeiou])
            vowel_count=$((vowel_count+1))
            ;;
        [bcdfghjklmnpqrstvwxyz])
            consonant_count=$((consonant_count+1))
            ;;
        *)
            ;;
    esac
done

echo "The sentence '$sentence' contains $vowel_count vowels and $consonant_count consonants."
```

---

_4. Write a shell script to display the list of users as well as the number of users connected to the system._

```bash
#!/bin/bash

user_list=$(who | cut -d' ' -f1 | sort | uniq)
num_users=$(echo "$user_list" | wc -w)
echo "List of users connected to the system:"
echo "$user_list"
echo ""
echo "Number of users connected to the system: $num_users"
```
