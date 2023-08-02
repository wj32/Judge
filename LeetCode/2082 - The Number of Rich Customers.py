import pandas as pd

def count_rich_customers(store: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame(data={"rich_count": [int(store[store["amount"] > 500][["customer_id"]].nunique())]})
