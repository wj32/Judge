import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    department_max_salary = employee.merge(department, how="left", left_on="departmentId", right_on="id", suffixes=("", "_dpt")).groupby("departmentId").max()
    merged = employee.merge(department_max_salary, how="left", left_on="departmentId", right_on="departmentId", suffixes=("", "_max"))
    return merged.loc[merged["salary"] == merged["salary_max"], ["name_dpt", "name", "salary"]].rename(columns={
        "name_dpt": "Department",
        "name": "Employee",
        "salary": "Salary",
    })