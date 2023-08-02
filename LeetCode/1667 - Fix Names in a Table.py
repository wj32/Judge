import pandas as pd

def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    users["name"] = users["name"].str.slice(stop=1).str.upper().str.cat(users["name"].str.slice(start=1).str.lower())
    return users.sort_values(["user_id"])
