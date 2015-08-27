# -----------------------------------------------
#   Make  Brushup
# -----------------------------------------------

# ------------------------------
#   DEFINITIONS
# ------------------------------

# Flag to replace gcc,  $(CC) = gcc
CC= gcc

# Files to compile
FILES= brush_main.c brush_util.c

# CLEAN definition - git rid of compiled stuff
CLEAN= rm -rf *.o brush 

# Output as excecuteable
OUT = brush

# ------------------------------
#   BODY
# ------------------------------
    
brush: $(FILES)
	$(CC) -o $(OUT) -g -Wall $(FILES)
    
# -----------------------------------------------
# When you type 'make clean', you get rid of
# all of the *.o and the 'story' file.
# -----------------------------------------------
clean:
	$(CLEAN)    
    
rebuild: clean brush