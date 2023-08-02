import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return customers.loc[~customers["id"].isin(orders["customerId"]), ["name"]].rename(columns={"name": "Customers"})
