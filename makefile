#
#	baut das komplette Scanner Projekt
#
OBJDIR = objs

AUTOMATDIR = Automat

BUFFERDIR = Buffer

TOKENDIR = Token

SYMBOLTABLEDIR = Symboltable

SCANNERDIR = Scanner

PARSETREEDIR = Parser



all:	automatOBJs bufferOBJs tokenOBJs symboltableOBJs scanner parsetreeOBJs
	@echo "target all"

	
# rm 	remove
# -f	force, ohne nachfragen
clean:
	rm -f $(AUTOMATDIR)/$(OBJDIR)/*.o
	rm -f $(BUFFERDIR)/$(OBJDIR)/*.o
	rm -f $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o
	rm -f $(TOKENDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/debug/*
	rm -f $(PARSETREEDIR)/$(OBJDIR)/*.o
	

automatOBJs:
	$(MAKE) -C $(AUTOMATDIR) AutomatOBJTarget
	
bufferOBJs:
	$(MAKE) -C $(BUFFERDIR) BufferOBJTarget
	
tokenOBJs:
	$(MAKE) -C $(TOKENDIR) TokenOBJTarget

symboltableOBJs:
	$(MAKE) -C $(SYMBOLTABLEDIR) SymboltableOBJTarget
	
scanner: 
	$(MAKE) -C $(SCANNERDIR) makeTestScanner
	
parsetreeOBJs:
	$(MAKE) -C $(PARSETREEDIR) makeTestParseTree

	