import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    counts = courses.groupby("class").count().reset_index()
    return counts.loc[counts["student"] >= 5, ["class"]]