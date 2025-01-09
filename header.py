import re
import pathlib

def functions_from_file(file_path:pathlib.Path):
	content: list[str]
	with open(file_path) as f:
		content = f.readlines()
	loc = content[12:]

	for line in loc:
		re_match = re.search(r'^\w+\t\*?\w+\(.+\)$', line)
		if re_match is not None:
			print(f"{re_match.group()};")

for path in pathlib.Path('.').glob('**/*.c'):
    functions_from_file(path)