import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    return views.loc[views["author_id"] == views["viewer_id"], ["author_id"]].rename(columns={"author_id": "id"}).sort_values(["id"]).drop_duplicates()
