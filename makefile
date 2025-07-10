# Compilador y flags
CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11

# Directorios
SRCDIR := .
BUILDDIR := build
TARGET := main  # Cambiado a 'main'

# Archivos fuente (.cpp) y objetos (.o)
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)" ! -name "main.cpp")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
MAIN := main.cpp
MAINOBJ := $(BUILDDIR)/$(MAIN:.$(SRCEXT)=.o)

# Encabezados (.h)
HEADERS := $(shell find $(SRCDIR) -type f -name "*.h")

# Regla principal
$(TARGET): $(OBJECTS) $(MAINOBJ)
	@echo " Enlazando..."
	@$(CXX) $^ -o $(TARGET)

# Regla para el objeto principal
$(MAINOBJ): $(MAIN) $(HEADERS)
	@mkdir -p $(BUILDDIR)
	@echo " Compilando $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regla para objetos de clases
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(SRCDIR)/%.h
	@mkdir -p $(BUILDDIR)
	@echo " Compilando $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpieza
clean:
	@echo " Limpiando..."
	@rm -rf $(BUILDDIR) $(TARGET)

.PHONY: clean