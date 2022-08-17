.PHONY: state_sort state_search
CC =gcc
CFLAGS = -Wall -Werror -Wextra
BUILD = ../build/
SOURCES =  $(BUILD)cipher.c  $(BUILD)module_io.c
OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE1 = Quest_1
EXECUTABLE2 = Quest_2

state_sort:
	$(CC) $(CFLAGS) state_sort.c date_struct.c module_io.c  binary_files_common_functions.c -o $(BUILD)$(EXECUTABLE1)

state_search:
	# $(CC) $(CFLAGS) -DLOGGING_CIPHER cipher.c logger.c module_io.c -o $(BUILD)$(EXECUTABLE2)

rebuild: claen all

clean:
	-rm *.o
	-rm  $(BUILD)*.o
