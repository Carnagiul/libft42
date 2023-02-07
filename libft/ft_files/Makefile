#Compiler and Linker
CC          := gcc

#The Target Binary Program
TARGET      := ft_library_files.a
PROJECT		:= "42 Library Files"

IS_LIB		:= TRUE

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := Sources
INCDIR      := Includes
BUILDDIR    := Objects
TARGETDIR   := Binaries
RESDIR      := Ressources
SRCEXT      := c
DEPEXT      := log
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -Wall -Werror -Wextra -Ofast -Wunreachable-code
LIB         := -Wall -Werror -Wextra -Ofast -Wunreachable-code
INC         := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

COUNT_MAX = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT)| wc -l | tr -d '[:space:]')
COUNT = $(shell find $(BUILDDIR) -type f -name *.$(OBJEXT) | wc -l | tr -d '[:space:]')

#Defauilt Make
all: display resources $(TARGET)

display:
	@bash .sh_tool/display.sh $(PROJECT)

#Remake
re: fclean all

#Copy Resources from Resources Directory to Target Directory
resources: directories
# 	@cp $(RESDIR)/* $(TARGETDIR)/

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

#Clean only Objecst
clean:
	@$(RM) -rf $(BUILDDIR)

#Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGETDIR)

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	@if [ $(IS_LIB) = 'TRUE' ]; then ar rc $(TARGETDIR)/$(TARGET) $(OBJECTS); ranlib $(TARGETDIR)/$(TARGET); else $(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB) ; fi
#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp
	@$(call plus,$(COUNT), 1)
	@printf "Compiling Source \033[32m%d\033[37m / \033[31m%d\033[37m\n" `expr $(COUNT) + 1` $(COUNT_MAX)
	@sleep 0.1

#Non-File Targets
.PHONY: all re clean fclean resources