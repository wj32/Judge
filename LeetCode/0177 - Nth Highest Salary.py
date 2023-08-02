import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    salaries = employee["salary"].drop_duplicates()
    if N <= len(salaries):
        result = salaries.nlargest(N).iloc[-1]
    else:
        result = None
    return pd.DataFrame(data={"result": [result]})
