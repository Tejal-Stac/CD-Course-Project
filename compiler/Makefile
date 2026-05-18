# ============================================================
# Makefile  —  Mini C Compiler
# Usage:
#   make          → build the compiler binary (minicc)
#   make clean    → remove generated files
#   make test     → compile test.c through minicc
# ============================================================

CC      = gcc
CFLAGS  = -Wall -Wno-unused-function -g

# All C source files (generated + hand-written)
SRCS    = lex.yy.c parser.tab.c \
          symtab.c ast.c semantic.c tac.c error.c main.c

TARGET  = minicc

# ── Default target ──
all: $(TARGET)

# Step 1: Flex generates lex.yy.c from lexer.l
lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

# Step 2: Bison generates parser.tab.c + parser.tab.h from parser.y
parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

# Step 3: Compile everything together
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# ── Clean ──
clean:
	del /f lex.yy.c parser.tab.c parser.tab.h $(TARGET).exe 2>nul || true

# ── Quick test ──
test: $(TARGET)
	echo "Running test.c through minicc..."
	./$(TARGET) test.c