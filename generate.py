import os

def generate_readme():

    path = './solutions/'
    file_list = os.listdir(path)
    print(file_list)

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
        title_link = "https://leetcode.com/problems/" + title.replace(" ", "-").lower()
        code_link = "https://github.com/coffree0123/Leetcode/blob/master/solutions/" + file.replace(" ", "%20")
        language = file.split('.')[1]

        cur_line = "|{}|[{}]({})|[code]({})|{}|{}|\n".format(number, title, title_link, code_link, language, difficulty)
        f.write(cur_line)

if __name__ == '__main__':
    generate_readme()