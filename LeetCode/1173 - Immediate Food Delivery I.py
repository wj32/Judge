import pandas as pd

def food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    immediate_count = (delivery["customer_pref_delivery_date"] == delivery["order_date"]).sum()
    return pd.DataFrame({"immediate_percentage": [round(100 * immediate_count / len(delivery), 2)]})
