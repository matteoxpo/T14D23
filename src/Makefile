.PHONY: state_sort state_search clear_state
CC =gcc
CFLAGS = -Wall -Werror -Wextra
BUILD = ../build/

EXECUTABLE = Quest_

state_sort:
	$(CC) $(CFLAGS) state_sort.c date_struct.c module_io.c  binary_files_common_functions.c -o $(BUILD)$(EXECUTABLE)1

state_search:
	$(CC) $(CFLAGS) state_search.c date_struct.c module_io.c  binary_files_common_functions.c -o $(BUILD)$(EXECUTABLE)2

clear_state:
	$(CC) $(CFLAGS) clear_state.c date_struct.c module_io.c  binary_files_common_functions.c -o $(BUILD)$(EXECUTABLE)3

clean:
	-rm $(BUILD)$(EXECUTABLE)1
	-rm $(BUILD)$(EXECUTABLE)2
	-rm $(BUILD)$(EXECUTABLE)3