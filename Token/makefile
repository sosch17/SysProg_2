#
#		Targets zum Bauen des Tests
#

# Linken der Object-files, abhaengig von TokenTarget und TestTokenTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

#makeTestToken: TokenTarget TestTokenTarget  
#	g++ -g objs/Token.o debug/TestToken.o -o debug/TokenTest
	

# compilieren des Files Token.cpp zu Token.o, 
# das Objekt-File ist abhängig von src/Token.cpp und src/Token.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)

TokenTarget:  src/Token.cpp includes/Token.h
	g++	-g  -c -Wall src/Token.cpp -o objs/Token.o  


# TestToken.o ist abhängig von src/TestToken.cpp und src/Token.h
#TestTokenTarget :  src/TestToken.cpp includes/Token.h
#	g++ -g  -c -Wall src/TestToken.cpp  -o debug/TestToken.o  



# loeschen aller files im verzeichnis obj und debug, dann neu erzeugen

cleanToken:
	rm -f objs/*.o
	rm -f debug/*
#	$(MAKE) makeTestToken
	
	
# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer Gesamtprojekt loeschen und dann neu erzeugen
TokenOBJTarget:
	$(MAKE) TokenTarget

