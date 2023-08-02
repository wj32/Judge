import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    student_subjects = students.merge(subjects, how="cross")
    attended_exams = student_subjects.merge(examinations, how="inner", on=["student_id", "subject_name"]).groupby(["student_id", "student_name", "subject_name"]).size().reset_index(name="attended_exams")
    return student_subjects.merge(attended_exams, how="left", on=["student_id", "student_name", "subject_name"]).fillna(0).sort_values(["student_id", "subject_name"])
