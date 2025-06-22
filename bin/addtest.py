import os
import re
import subprocess

def get_filename_in(number):
    return os.path.join("tests", f"sample-{number}.in")
def get_filename_out(number):
    return os.path.join("tests", f"sample-{number}.out")

if os.path.isdir("tests"):
    matcher_in = re.compile(r"sample-(\d+)\.in$")
    matcher_out = re.compile(r"sample-(\d+)\.out$")
    matched_numbers_in = []
    matched_numbers_out = []
    for fname in os.listdir("tests"):
        m_in = re.match(matcher_in, fname)
        if m_in:
            matched_numbers_in.append(int(m_in.group(1)))
        m_out = re.match(matcher_out, fname)
        if m_out:
            matched_numbers_out.append(int(m_out.group(1)))

    matched_numbers_in.sort()
    matched_numbers_out.sort()
    common_numbers = set(matched_numbers_in) & set(matched_numbers_out)
    max_common_number = max(common_numbers) if common_numbers else 0
    new_number = max_common_number + 1

    with open(get_filename_in(new_number), "w") as f:
        with open(get_filename_in(max_common_number), "r") as src:
            f.write(src.read())
        pass
    with open(get_filename_out(new_number), "w") as f:
        with open(get_filename_out(max_common_number), "r") as src:
            f.write(src.read())
        pass
    print(f"created new test files: {get_filename_in(new_number)} and {get_filename_out(new_number)}")

    # Move subprocess.run calls here, after files are closed
    subprocess.run(["code", get_filename_in(new_number)], shell=True)
    subprocess.run(["code", get_filename_out(new_number)], shell=True)
else:
    print("directory tests not found.")