import pandas as pd

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    return activities.groupby("sell_date").aggregate(
        num_sold=pd.NamedAgg(column="product", aggfunc="nunique"),
        products=pd.NamedAgg(column="product", aggfunc=lambda xs: ",".join(sorted(set(xs)))),
    ).sort_values("sell_date").reset_index()
