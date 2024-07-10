CPPS = src/main.cpp src/inventory_manager.cpp
HS = include/*
CC = clang
CXX = clang++
EXE = program_inventory.exe
BUILD_CMD = \
	$(CXX) \
	-I ./include \
	-I ./lib/tabulate/include/ \
	-I ./lib/sqlite_orm-1.8.2/include \
	-I ./lib/sqlite-amalgamation-3460000 \
	$(SQLITE_OBJECT_FILE) \
	$(CPPS) \
	-o $(EXE)
SQLITE_OBJECT_FILE = sqlite3.obj

all: $(EXE) compile_commands.json

build: $(EXE)

$(EXE): $(CPPS) $(HS) $(SQLITE_OBJECT_FILE)
	$(BUILD_CMD)

$(SQLITE_OBJECT_FILE):
	$(CC) -c ./lib/sqlite-amalgamation-3460000/sqlite3.c -o $(SQLITE_OBJECT_FILE)

compile_commands.json: $(CPPS) $(HS)
	bear -- $(BUILD_CMD)
