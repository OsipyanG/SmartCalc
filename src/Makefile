TARGET = SmartCalc

CC = gcc
CFLAGS = -Wall -Werror -Wextra -lm -std=c11

all: clean install
	
SRC=$(wildcard ./model/*.c ./controller/*.c)
TEST_SRC=$(wildcard tests/*.c) 

OBJ=$(patsubst %.c,%.o,$(SRC))
TEST_OBJ=$(patsubst tests/%.c,%.o,$(TEST_SRC))
GCOV_TEST_OBJ=$(patsubst %, gcov_%, $(OBJ))
TEST_MODUlES = test_modules

OS = $(shell uname -s)
 
ifeq ($(OS), Darwin)
TEST_FLAGS=-lcheck
OPEN=open
else ifeq ($(shell hostnamectl | grep -o 'Ubuntu'), Ubuntu)
TEST_FLAGS=-lpthread -lcheck -lsubunit
OPEN=open
else
TEST_FLAGS=-lpthread -lm -lcheck
OPEN=xdg-open
endif
GCOV_FLAGS=-ftest-coverage --coverage

.PHONY: all clean clang-format test



install:
	@echo "Start installation"
	@mkdir -p ../build
	@cd view && qmake && make && make clean && rm -rf Makefile && mv SmartCalc ../../build/$(TARGET).app
	@cp -R ../build/$(TARGET).app ~/Desktop/$(TARGET).app
	@echo "┏=========================================┓"
	@echo "┃    The installation was successful.     ┃"
	@echo "┗=========================================┛"

uninstall:
	@rm -rf ~/Desktop/SmartCalc.app ../build
	@echo "Uninstall completed successfully"

dvi:
	@$(OPEN) ../README_RUS.md

dist: all
	@mkdir -p ../dist
	@cp -R ../build/$(TARGET).app ../dist
	@cp ../README_RUS.md ../dist && cp ../README.md ../dist
	@cd ../dist && tar cvzf $(TARGET)_v1.0.tgz *
	@cd ../dist && rm -rf $(TARGET).app README.md README_RUS.md
	@echo "The build was successfully archived"


test: $(OBJ) $(TEST_OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o ./unit_tests $(TEST_FLAGS)
	./unit_tests

gcov_report:  $(OBJ)
	@echo "┏=========================================┓"
	@echo "┃     Generating your html report ...     ┃"
	@echo "┗=========================================┛"
	@$(CC) --coverage $(CFLAGS)  $(TEST_FLAGS) ./model/*.c ./controller/*.c ./tests/*.c -o ./tests/$(TEST_MODUlES)
	@./tests/$(TEST_MODUlES)
	@mkdir -p tests/modules_gcov
	@mv ./tests/*.gcno ./tests/modules_gcov/ && mv ./tests/*.gcda ./tests/modules_gcov/
	@lcov -t "test_coverage" -o test_coverage.info -c -d .
	@genhtml -o report test_coverage.info
	@$(OPEN) report/index.html
	@rm -rf *.gcda *.gcno report/test_coverage.info tests/modules_gcov tests/controller_gcov

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o: tests/%.c
	$(CC) -c $(CFLAGS) $< -o $@ $(TEST_FLAGS)

gcov_%.o: %.c
	$(CC) -c $(CFLAGS) $(GCOV_FLAGS) $< -o ./$@ $(TEST_FLAGS)

clang-format:
	@clang-format -i ./controller/*.c ./controller/*.h ./model/*.c ./model/headers/*.h ./view/*.cpp ./view/*.h 

clean:
	@rm -rf report/
	@rm -rf *.o unit_tests gcov_unit_tests *.info
	@rm -rf  ./tests/test_modules
	@rm -rf  ./view/*.o ./view/.qmake.stash ./view/ui_mainwindow.h ./view/Makefile
	@rm -rf  ./model/*.o
	@rm -rf  ./controller/*.o
	@rm -rf  ../dist/ ../build
	 
