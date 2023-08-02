import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({
        "category": ["Low Salary", "Average Salary", "High Salary"],
        "accounts_count": [
            (accounts["income"] < 20000).sum(),
            ((accounts["income"] >= 20000) & (accounts["income"] <= 50000)).sum(),
            (accounts["income"] > 50000).sum(),
        ]
    })