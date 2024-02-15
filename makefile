all: processes taskmanager

processes: processes.c
  gcc -o processes processes.c

taskmanager: taskmanager.c processes.h processes.c
  gcc -o taskmanager taskmanager.c processes.c

clean:
  rm -f processes taskmanager
