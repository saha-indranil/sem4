# Use pandas to identify the student who got lowest marks in more than 2 subjects.

import pandas as pd

data = {'Student': ['Alice', 'Bob', 'Charlie', 'Dave', 'Eve'],
        'Maths': [80, 70, 60, 50, 40],
        'Science': [70, 60, 50, 40, 30],
        'English': [60, 50, 40, 30, 20]}
df = pd.DataFrame(data)

num_subjects = 2
min_marks = df.min()
num_lowest = (df == min_marks).sum(axis=1)
students = df['Student'][num_lowest > num_subjects].tolist()

if students:
    print(f"The student(s) who got lowest marks in more than {num_subjects} subjects are: {students}")
else:
    print(f"No student got lowest marks in more than {num_subjects} subjects")


# OUTPUT
# The student(s) who got lowest marks in more than 2 subjects are: ['Eve']