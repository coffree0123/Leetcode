import os


def generate_readme():
    # Filename format: [number]_[difficulty]_[problem_filename]
    path = './solutions/'
    file_list = sorted(os.listdir(
        path), key=lambda file: int(file.split('_')[0]))
    language_dict = {'java': 'Java', 'py': 'Python', 'cpp': 'C++'}

    f = open("README.md", "w")
    f.write("LeetCode\n")
    f.write("========\n\n")
    f.write("### LeetCode Algorithm\n\n")
    f.write("| # | Title | My solution | Language | Difficulty |\n")
    f.write("|---| ----- | -------- | ---------- | ---------- |\n")

    for file in file_list:
        number = file.split('_')[0]
        difficulty = file.split('_')[1]
        title = file.split('_')[2].split('.')[0]
        title_link = "https://leetcode.com/problems/" + \
            title.replace(" ", "-").lower()
        code_link = "https://github.com/coffree0123/Leetcode/blob/master/solutions/" + \
            file.replace(" ", "%20")
        language = language_dict.get(file.split('.')[1], 'None')

        cur_line = "|{}|[{}]({})|[code]({})|{}|{}|\n".format(
            number, title, title_link, code_link, language, difficulty)
        f.write(cur_line)


def generate_sol():
    # Generate solution in fine format: [number]_[difficulty]_[problem_filename]
    problem = input("Enter problem name:")
    number = problem.split('. ')[0]
    title = problem.split('. ')[1]

    difficulty_dict = {0: "Easy", 1: "Medium", 2: "Hard"}

    while True:
        try:
            print("Choose from the following difficulty options:")
            print("(0). Easy (1). Medium (2). Hard")
            difficulty = difficulty_dict.get(
                int(input("Enter difficulty:")), None)

            if difficulty is None:
                print("No such difficulty.")
                continue

            break
        except ValueError:
            print("Oops!  That was no valid number.  Try again...")

    # Current default only cpp language
    file_name = "./solutions/'{}_{}_{}.cpp'".format(number, difficulty, title)
    os.system("vim {}".format(file_name))


def save_github():
    print("Generating new README.md...")
    generate_readme()
    os.system("git add .")

    commit_str = input("Entering git commit log:")

    if commit_str == '':
        commit_str = "Done by auto commit"

    commit_str = "-m '{}'".format(commit_str)

    os.system("git commit {}".format(commit_str))
    os.system("git push")


if __name__ == '__main__':
    os.system("git pull")

    while True:
        os.system("clear")
        print("Choose from the following options:")
        print("(0). Generate README.md (1). Add solution (2). Auto save")
        print("Press Ctrl-c to exit.")

        try:
            arg = int(input("Type the option:"))
            if arg == 0:
                generate_readme()
            elif arg == 1:
                generate_sol()
            elif arg == 2:
                save_github()
            else:
                print("[ValueError] No such argument:{}\n".format(arg))
                continue

            input("Type any key to continue...")

        except ValueError:
            print("Oops!  That was no valid number.  Try again...\n")

        except KeyboardInterrupt:
            print("\n")
            print("Exiting...")
            break
