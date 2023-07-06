cmd_/home/sharath/Desktop/OS_Project/project.mod := printf '%s\n'   project.o | awk '!x[$$0]++ { print("/home/sharath/Desktop/OS_Project/"$$0) }' > /home/sharath/Desktop/OS_Project/project.mod
