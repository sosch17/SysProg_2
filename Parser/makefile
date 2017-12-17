#
# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files fuer das Gesamtprojekt
OBJDIR = objs

# enthaelt die Objectfiles und das ausfuehrbare File zum Testen des Teilprojekts
BINDIRTEST = debug
#		Targets zum Bauen des Tests
#
OBJS = $(OBJDIR)/ParseTree.o
#
#
## Linken der Object-files, abhaengig von ParserTarget und TestParserTarget
## flag:
## -g --> debug Informationen erzeugen
## -o --> name des output-files
#
#makeTestParseTree: ParseTreeTarget TestParseTreeTarget  
#	g++ -g $(OBJDIR)/ParseTree.o $(BINDIRTEST)/TestParseTree.o -o $(BINDIRTEST)/ParseTree
#	
#
## compilieren des Files Parser.cpp zu Parser.o, 
## das Objekt-File ist abhängig von src/Parser.cpp und src/Parser.h
## flag:
## -c --> nur compilieren
## -g --> debug Informationen erzeugen
## -Wall --> alle meldungen erzeugen (Warning all)
#
#ParseTreeTarget : $(SRCDIR)/TestParseTree.cpp $(SRCDIR)/ParseTree.cpp $(HEADERDIR)/ParseTree.h ../Automat/$(HEADERDIR)/StateTypes.h ../Token/$(HEADERDIR)/Token.h ../ParseTree/$(HEADERDIR)/ParseTree.h $(HEADERDIR)/NodeTypes.h
#	g++ -g  -c -Wall $(SRCDIR)/ParseTree.cpp -o $(OBJDIR)/ParseTree.o 
##	g++ -g ../Token/$(OBJDIR)/*.o ../ParseTree/$(OBJDIR)/*.o ../Automat/$(OBJDIR)/*.o ../Buffer/$(OBJDIR)/*.o ../Symboltable/$(OBJDIR)/*.o
#
#
## TestParser.o ist abhängig von src/TestParser.cpp und src/Parser.h
#TestParseTreeTarget :  $(SRCDIR)/TestParseTree.cpp $(HEADERDIR)/ParseTree.h ../Automat/$(HEADERDIR)/StateTypes.h ../Token/$(HEADERDIR)/Token.h ../ParseTree/$(HEADERDIR)/ParseTree.h $(HEADERDIR)/NodeTypes.h
#	g++ -g  -c -Wall $(SRCDIR)/TestParseTree.cpp  -o $(BINDIRTEST)/TestParseTree.o 
##	g++ -g ../Token/$(OBJDIR)/*.o ../ParseTree/$(OBJDIR)/*.o $(OBJDIR)/*.o ../Automat/$(OBJDIR)/*.o ../Buffer/$(OBJDIR)/*.o ../Symboltable/$(OBJDIR)/*.o
#
#
#
## loeschen aller files im verzeichnis obj und debug, dann neu erzeugen
#
##cleanParseTree:
##	rm -f $(OBJDIR)/*.o
##	rm -f $(BINDIRTEST)/*
##	$(MAKE) makeTestParseTree
##	
#	
## dieses Target wird vom makefile des Gesamtprojekts verwendet
## objs fuer Gesamtprojekt loeschen und dann neu erzeugen
#ParseTreeOBJTarget:
#	$(MAKE) ParseTreeTarget
makeTestParseTree: $(OBJS) ParseTreeTest


$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp $(HEADERDIR)/%.h
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit


ParseTreeTest: $(SRCDIR)/TestParseTree.cpp $(HEADERDIR)/ParseTree.h ../Automat/$(HEADERDIR)/StateTypes.h ../Token/$(HEADERDIR)/Token.h $(HEADERDIR)/NodeTypes.h
	g++ -g  -c -Wall src/TestParseTree.cpp -o $(BINDIRTEST)/TestParseTree.o  
	g++ -g $(BINDIRTEST)/TestParseTree.o ../Buffer/$(OBJDIR)/Buffer.o ../Symboltable/$(OBJDIR)/*.o ../Token/$(OBJDIR)/Token.o ../Automat/$(OBJDIR)/Automat.o ../Scanner/$(OBJDIR)/*.o $(OBJDIR)/*.o -o $(BINDIRTEST)/ParseTreeTest

# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu erstellen

cleanParseTree:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) makeTestParseTree
	
	

