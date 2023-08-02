import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    df = orders.groupby("customer_number").count().reset_index()
    return df.nlargest(1, ["order_number"])[["customer_number"]]
