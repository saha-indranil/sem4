# Write a program using pandas to convert the datatype of a column of a dataframe.

import pandas as pd

df = pd.DataFrame({'A': ['dog', 'bar', 'baz'], 
                   'B': [1, 2, 3], 
                   'C': [1.0, 2.0, 3.0]})
print("Datatype =",df.dtypes['B'])
df['B'] = df['B'].astype(float)
print("Updated Datatype =",df.dtypes['B'])  

# OUTPUT
# Datatype = int64
# Updated Datatype = float64