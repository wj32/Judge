import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    N = 2
    salaries = employee["salary"].drop_duplicates()
    if N <= len(salaries):
        result = salaries.nlargest(N).iloc[-1]
    else:
        result = None
    return pd.DataFrame(data={"SecondHighestSalary": [result]})
