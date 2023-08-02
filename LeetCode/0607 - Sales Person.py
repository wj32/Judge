import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    orders_company = orders.merge(company, how="left", on="com_id")
    red_sales_ids = orders_company[orders_company["name"] == "RED"]["sales_id"].drop_duplicates()
    return sales_person.loc[~sales_person["sales_id"].isin(red_sales_ids), ["name"]]
