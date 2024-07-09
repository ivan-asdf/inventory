cpps = src/*
hs = include/*
BUILD_CMD = \
	g++ \
	-I ./include \
	-I ./lib/tabulate/include/ \
	-I ./lib/sqlite_orm-1.8.2/include \
	-I ./lib/sqlite-amalgamation-3460000 \
	$(SQLITE_OBJECT_FILE) \
	src/*

SQLITE_OBJECT_FILE = sqlite3

all: a.out compile_commands.json


a.out: $(cpps) $(hs) $(SQLITE_OBJECT_FILE)
	$(BUILD_CMD)

$(SQLITE_OBJECT_FILE):
	gcc -c ./lib/sqlite-amalgamation-3460000/sqlite3.c -o $(SQLITE_OBJECT_FILE)

compile_commands.json: $(cpps) $(hs)
	bear -- $(BUILD_CMD)
