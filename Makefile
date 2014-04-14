# ------------------------------------------------------------------------------------------#
# THIS MAKEFILE IS PART OF IRRGAME.															#
#																							#
# Author: 		Henri Keeble																#
# Date Created:	4/4/2014																	#
# Usage: 		DO NOT MODIFY THIS FILE. Call 'make debug' and 'make release' to build		#
#				debug and release builds. Use 'make clean' to clean all object files.		#
#-------------------------------------------------------------------------------------------#

include MakeConfigure

# ----- TARGETS ----- #
all:
	@echo "Please use either 'make debug' or 'make release' targets when building."

# ----- DEBUG TARGET -----
debug: $(COPY_DATA) $(OBJECTS)
	@echo "Compiling objects for target '$@'..."
	$(CC) $(CCFLAGS) -g $(OBJECTS) -o $(BLD_DIR)/$(EXEC) $(INCL_DIR) $(LIB_DIRS) $(LIBS)

# ----- RELEASE TARGET -----
release: $(COPY_DATA) $(OBJECTS)
	@echo "Compiling objects..."
	$(CC) $(CCFLAGS) $(OBJECTS) -o $(BLD_DIR)$(EXEC) $(INCL_DIR) $(LIB_DIRS) $(LIBS)

# ----- CLEAN TARGET -----
clean:
	rm -r obj/unix/debug/*.o
	rm -r obj/unix/release/*.o
	rm -r obj/windows/debug/*.o
	rm -r obj/windows/release/*.o

# ----- PATTERN RULE FOR .CPP TO .O -----
$(INT_DIR)/%.o : $(SRC_DIR)/%.cpp
	@echo "Compiling: " $< " into " $(INT_DIR)/$(basename $(notdir $<)).o
	$(CC) $(PRP_DIR) $(CCFLAGS) -c $< -o $(INT_DIR)/$(basename $(notdir $<)).o $(INCL_DIR)

# ----- COPY DATA TARGET -----
$(COPY_DATA):
	@echo "Copying data files..."
	cp -r ./data/  $(BLD_DIR)
