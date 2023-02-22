# Write a program to add a new column to a dataframe.

import pandas as pd

df = pd.DataFrame({'A': ['foo', 'bar', 'baz'], 
                   'B': [1, 2, 3], 
                   'C': [1.0, 2.0, 3.0]})
df['D'] = [True, False, True]
print(df)

# OUTPUT
#      A  B    C      D
# 0  foo  1  1.0   True
# 1  bar  2  2.0  False
# 2  baz  3  3.0   True