import pandas as pd

def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    total = employees.groupby(["emp_id", "event_day"]).sum().reset_index()
    total["total_time"] = total["out_time"] - total["in_time"]
    return total[["event_day", "emp_id", "total_time"]].rename(columns={"event_day": "day"})