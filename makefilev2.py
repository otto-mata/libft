import pathlib
from pprint import pprint as pp

TARGET_NAME="libft.a"
COMP="cc"
COMP_FLAGS="-Wall -Werror -Wextra -std=c89"
LIB="ar rcs"

cwd = pathlib.Path(".")
dirs = {}
for file in cwd.glob("**/*.c"):
    path_parts = str(file).split("/")
    file_name = path_parts[-1]
    path_parts = path_parts[:-1]
    if (len(path_parts) == 0):
        var_name = "CWD"
    else:
        var_name = "_".join([part.upper() for part in path_parts])
    if var_name not in dirs.keys():
        dirs[var_name] = dict()
        dirs[var_name]['path'] = "/".join(path_parts[:-1])
        dirs[var_name]['files'] = []
    path_dict = {'name': file_name, 'relative_path':"/".join(path_parts[1:])}
    dirs[var_name]['files'].append(path_dict)


path_str = ""
files_str = ""
full_path_str = ""
obj_str = ""
obj_vars = []

for key in dirs:
    entry = dirs[key]
    path_str += f"{key}_SRC_PATH=./{entry['path']}/\n"
    files_str_part = f"{key}_SRC_FILES="
    for i, file in enumerate(entry['files']):
        if i > 0:
            files_str_part += '\t'
        files_str_part += file['name']
        if i < len(entry['files']) - 1:
            files_str_part += " \\\n"
    files_str += files_str_part + '\n'
    full_path_str += f"{key}_FULL_PATH=$(addprefix $({key}_SRC_PATH), $({key}_SRC_FILES))\n"
    obj_vars.append(f"{key}_OBJ")
    obj_str += f"{key}_OBJ=$({key}_FULL_PATH:.c=.o)\n"

makefile_head = f"""#This makefile was auto generated, ain't no way I'm writing all that by hand
NAME={TARGET_NAME}
CC={COMP}
CFLAGS={COMP_FLAGS}
AR={LIB}
"""
obj_vars_formatted = " ".join([f"$({var})" for var in obj_vars])
clean_rule = "\n\t".join([f"rm -f $({var})" for var in obj_vars])
rules = f"""
$(NAME): {obj_vars_formatted}
\t$(AR) $@ $^

all: $(NAME)

clean:
\t{clean_rule}

fclean: clean
\trm -f $(NAME)

re: fclean all

default: all

.PHONY: default all re fclean clean"""
makefile_content = makefile_head + path_str + files_str + full_path_str + obj_str + rules
pp(makefile_content)

# with open('Makefile.2', 'w') as file:
#     file.write(makefile_content)