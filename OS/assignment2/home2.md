## OS Home Assignment 2

---

<img src="./home2img.jpg" width="100%" alt="file structure">

```bash
$ mkdir -p ROOT/{Folder1,Folder2,Folder3/{Text5,Text6},Folder4}
$ cd ROOT
$ touch Folder1/{Text1.txt,Text2.txt} Folder2/{Text3.txt,Text4.txt} Folder4/{Text7.txt,Text8.txt}
$ cd Folder1
$ cat>Text1.txt
who
who -a
tty
ctrl+z
$ cat>Text2.txt
name: dogesh
sec: a
roll: 100
ctrl+z
$ cd ../Folder2
$ cat>Text3.txt
man who
ctrl+z
$ cat>Text4.txt
tty
w
ctrl+z
cd ..
```

---

_1. Run the files text1,text3._<br>

```bash
$ sh Folder1/Text1.txt<br>
$ sh Folder2/Text3.txt
```

---

_2. For text4 do the typescripting._<br>

```bash
$ script Folder2/Text4.typescript<br>
$ sh Folder2/Text4.txt<br>
$ exit
```

---

_3. Change the name of Typescripting to T1._<br>

```bash
$ mv Folder2/Text4.typescript Folder2/T1.typescript
```

---

_4. Copy the content of Text1 to Text8._<br>

```bash
$ cp Folder1/Text1.txt Folder4/Text8.txt
```

---

_5. Copy the content of Text3 and Text4 to Text7._<br>

```bash
$ cat Folder2/Text3.txt Folder2/Text4.txt>Folder4/Text7.txt
```

---

_6. Move the file Text2 to directory Text5._<br>

```bash
$ mv Folder1/Text2.txt Folder3/Text5
```

---

_7. Combine Text3 and Text4 to a file named COMBINETEXT._<br>

```bash
$ cat Folder2/Text3.txt Folder2/Text4.txt > Folder2/COMBINETEXT.txt
```

---

_8. Change the permission of Text5 whose contents can be read by you, write and execute by group and no permission for 3rd user level._<br>

```bash
$ chmod 430 Folder3/Text5
```

---

_9. Delete the directory Folder3._<br>

```bash
$ rm -rv Folder3
```
