import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    managers = employee.groupby("managerId").size().reset_index(name="count")
    managers = managers[managers["count"] >= 5]
    return employee.merge(managers, how="inner", left_on="id", right_on="managerId")[["name"]]
.